#include "GfcUtils/GfcTransform.h"
#include "GfcEngine/Writer.h"
#include "GfcSchema/Model.h"
#include "GfcSchema/EntityAttribute.h"
#include "GfcEngine/GfcEngineUtils.h"
#include "GfcEngine/PropValue.h"
#include "GfcEngine/ModelCompatibility.h"
#include "GfcEngine/ClassCompatibility.h"
#include "GfcEngine/AttributeCompatibility.h"
#include "GfcEngine/Converter.h"
#include "GfcUtils/GfcShapeTransformer.h"
#include "GfcUtils/GfcElementTransformer.h"
#include "GfcEngine/EntityUpgrader.h"
#include <memory>
#include <assert.h>

class CNewEntityRefConverter : public gfc::engine::CConverter
{
public:
    CNewEntityRefConverter(GfcTransform* pOwner): m_pOwner(pOwner){}
    virtual void doTransform(gfc::engine::CPropValue* pFrom, gfc::engine::CPropValue* pTo)
    {
        auto nNewRef = m_pOwner->getEntityRef(pFrom->asEntityRef());
        if(nNewRef != -1)
            pTo->setAsEntityRef(nNewRef);
    }
    virtual CConverter* clone()
    {
        return new CNewEntityRefConverter(*this);
    }
private:
    GfcTransform* m_pOwner;
};

GfcTransform::GfcTransform(gfc::engine::IContainer * pContainer): m_pContainer(pContainer), m_pWriter(nullptr), m_pModel(nullptr), m_pObjectCompatibility(nullptr), m_pEntityUpgrader(nullptr)
{
    m_pEntityUpgrader = new gfc::engine::CEntityUpgrader;
}

GfcTransform::~GfcTransform()
{
    delete m_pEntityUpgrader;
    clear();
}

void GfcTransform::setSchema(gfc::schema::CModel* pSrcModel, gfc::schema::CModel* pDestModel)
{
    assert(pSrcModel);
    assert(pDestModel);
    m_pEntityUpgrader->init(pDestModel, pSrcModel);
    //changeIDConverter(L"Gfc2Project");
    //changeIDConverter(L"Gfc2Building");
    //changeIDConverter(L"Gfc2Floor");
    //changeIDConverter(L"Gfc2Object");
    changeEntityRefConverter();
    //changeStringConverter();
    m_pObjectCompatibility = m_pEntityUpgrader->model()->find(L"Gfc2Object");
    m_pModel = pDestModel;
}

void GfcTransform::setWriter(gfc::engine::CWriter * pWriter)
{
    assert(pWriter);
    m_pWriter = pWriter;
}

bool GfcTransform::transform()
{
    if (nullptr == m_pModel)
        return false;
    if (nullptr == m_pWriter || !m_pWriter->isOpen())
        return false;
    clear();
    // 转Project
    auto nProjectRef = transformProject();
    // 转Building
    auto oBuildingMap = transformBuilding(nProjectRef);
    // 转Floor
    auto oFloorMap = transformFloor(oBuildingMap);
    // 转Element and ElementType
    transformElement(oFloorMap);
    // 记录关系
    writeRelAggregates();
    return true;
}

gfc::engine::EntityRef GfcTransform::getEntityRef(gfc::engine::EntityRef nSrc)
{
    auto itr = m_oTransformMap.find(nSrc);
    if (itr == m_oTransformMap.end())
    {
        auto pSrc = m_pContainer->getEntity(nSrc);
        auto pDest = transformEntity(pSrc);
        return pDest ? write(pSrc->ref(), pDest) : -1;
    }
    else
        return itr->second;
}

void GfcTransform::transformProjectPropertySet(SrcEntityPtr & pSrcEntity, DestEntityPtr & pDestEntity)
{
}

void GfcTransform::transformBuildingPropertySet(SrcEntityPtr & pSrcEntity, DestEntityPtr & pDestEntity)
{
}

void GfcTransform::transformFloorPropertySet(SrcEntityPtr & pSrcEntity, DestEntityPtr & pDestEntity)
{
}

void GfcTransform::writeRelAggregates()
{
    for (auto itr : m_oRelAggregates)
    {
        auto pRelAggregates = createEntity(L"Gfc2RelAggregates");
        pRelAggregates->setAsEntityRef(L"RelatingObject", itr.first);
        auto pValue = pRelAggregates->valueByName(L"RelatedObjects");
        if (pValue)
        {
            for (auto nRef : itr.second)
            {
                pValue->add(new gfc::engine::CEntityRefValue(nRef));
            }
        }
        write(itr.first, pRelAggregates);
    }
}

GfcTransform::DestEntityPtr GfcTransform::createEntity(const std::wstring & sEntityName)
{
    return DestEntityPtr(gfc::engine::CEngineUtils::createEntity(m_pModel, sEntityName));
}

GfcTransform::DestEntityPtr GfcTransform::transformEntity(SrcEntityPtr& pSrcEntity)
{
    auto pDestEntity = DestEntityPtr(m_pEntityUpgrader->update(pSrcEntity.get()));
    return pDestEntity;
}

void GfcTransform::writeRelDefinesByProperties(gfc::engine::EntityRef nRelatingPropertySet, gfc::engine::EntityRef nRelatedObject)
{
    auto pRel = createEntity(L"Gfc2RelDefinesByProperties");
    pRel->setAsEntityRef(L"RelatingPropertySet", nRelatingPropertySet);
    auto pValue = pRel->valueByName(L"RelatedObjects");
    pRel->addEntityRef(L"RelatedObjects", nRelatedObject);
    writer()->writeEntity(pRel.get());
}

gfc::engine::EntityRef GfcTransform::transformProject()
{
    gfc::engine::EntityRef nProjectRef = -1;
    auto pItr = m_pContainer->getEntities(L"Gfc2Project");
    pItr->first();
    if (!pItr->isDone())
    {
        auto pProject = pItr->current();
        
        auto pNewProject = transformEntity(pProject);
        if (pNewProject)
        {
            nProjectRef = write(pProject->ref(), pNewProject);
            transformProjectPropertySet(pProject, pNewProject);
        }
        else
            assert(false);
    }
    return nProjectRef;
}

void GfcTransform::getPropertySetList(gfc::engine::EntityRef nRef, std::vector<SrcEntityPtr>& oList)
{
    auto itr = m_pContainer->getEntities(L"Gfc2RelDefinesByProperties");
    itr->first();
    while (!itr->isDone())
    {
        auto pRel = itr->current();
        auto pValue = pRel->valueByName(L"RelatedObjects");
        assert(pValue);
        if (pValue)
        {
            for (int i = 0; i < pValue->getCount(); i++)
            {
                if (pValue->getItems(i)->asEntityRef() == nRef)
                {
                    oList.push_back(pRel->asEntity(L"RelatingPropertySet"));
                    break;
                }
            }
        }
        itr->next();
    }
}

GfcTransform::GfcEntityRefMap GfcTransform::transformBuilding(gfc::engine::EntityRef nProjectRef)
{
    GfcEntityRefMap oResult;
    auto pItr = m_pContainer->getEntities(L"Gfc2Building");
    pItr->first();
    while (!pItr->isDone())
    {
        auto pBuilding = pItr->current();
        auto pNewBuilding = transformEntity(pBuilding);
        if (pNewBuilding)
        {
//            std::vector<SrcEntityPtr> oPropertySetList;
//            getPropertySetList(pSrcEntity->ref(), oPropertySetList);
            auto nBuildingRef = write(pBuilding->ref(), pNewBuilding);
            transformBuildingPropertySet(pBuilding, pNewBuilding);
            oResult.insert(std::make_pair(pBuilding->ref(), nBuildingRef));
            addRelAggregates(nProjectRef, nBuildingRef);
        }
        pItr->next();
    }
    return oResult;
}

GfcTransform::GfcEntityRefMap GfcTransform::transformFloor(const GfcEntityRefMap& oBuildingRefMap)
{
    GfcEntityRefMap oResult;
    // 转楼层
    auto pItr = m_pContainer->getEntities(L"Gfc2RelAggregates");
    pItr->first();
    while (!pItr->isDone())
    {
        auto pAggregate = pItr->current();
        auto itr = oBuildingRefMap.find(pAggregate->asEntityRef(L"RelatingObject"));
        if (itr != oBuildingRefMap.end())
        {
            auto pValue = pAggregate->valueByName(L"RelatedObjects");
            for (int i = 0; i < pAggregate->getArrayCount(pValue); i++)
            {
                if (pAggregate->isNull(pValue, i))
                    continue;
                auto pFloor = pAggregate->getEntity(pValue, i);
                if (pFloor->entityName() != L"Gfc2Floor")
                    continue;
                auto pNewFloor = transformEntity(pFloor);
                if (pNewFloor)
                {
                    auto nFloorRef = write(pFloor->ref(), pNewFloor);
                    transformFloorPropertySet(pFloor, pNewFloor);
                    oResult.insert(std::make_pair(pFloor->ref(), nFloorRef));
                    addRelAggregates(itr->second, nFloorRef);
                }
            }
        }
        pItr->next();
    }
    return oResult;
}

void GfcTransform::transformElement(const GfcEntityRefMap & oFloorRefMap)
{
    GfcEntityRefMap oElementRefMap, oElementTypeRefMap;
    // 转楼层
    auto pItr = m_pContainer->getEntities(L"Gfc2RelAggregates");
    pItr->first();
    while (!pItr->isDone())
    {
        auto pAggregate = pItr->current();
        auto itr = oFloorRefMap.find(pAggregate->asEntityRef(L"RelatingObject"));
        if (itr != oFloorRefMap.end())
        {
            auto pValue = pAggregate->valueByName(L"RelatedObjects");
            for (int i = 0; i < pAggregate->getArrayCount(pValue); i++)
            {
                if (pAggregate->isNull(pValue, i))
                    continue;
                auto pEntity = pAggregate->getEntity(pValue, i);
                if (isElement(pEntity))//pEntity->entityName() == L"Gfc2Element")
                {
                    // 构件
                    auto pNewShape = doTransformShape(pEntity);
                    if (nullptr == pNewShape)
                        continue;
                    auto pNewElement = doTransformElement(pEntity);
                    if (nullptr == pNewElement)
                        continue;
                    linkElementShape(pNewElement, pNewShape);
                    //pNewElement->setAsEntityRef(L"Shape", m_pWriter->writeEntity(pNewShape.get()));
                    auto nElementRef = write(pEntity->ref(), pNewElement);
                    oElementRefMap.insert(std::make_pair(pEntity->ref(), nElementRef));
                    addRelAggregates(itr->second, nElementRef);
                }
                else if (isElementType(pEntity))//(pEntity->entityName() == L"Gfc2ElementType")
                {
                    // 构件类型
                    auto pNewElementType = doTransformElementType(pEntity); // 暂时可以用构件的
                    if (nullptr == pNewElementType)
                        continue;
                    auto nElementTypeRef = write(pEntity->ref(), pNewElementType);
                    oElementTypeRefMap.insert(std::make_pair(pEntity->ref(), nElementTypeRef));
                    addRelAggregates(itr->second, nElementTypeRef);
                }
            }
        }
        pItr->next();
    }
    transformTypeElementRelationShip(oElementTypeRefMap, oElementRefMap, getSrcRelDefinesByTypeSchema(), getDestRelDefinesByTypeSchema());
}

void GfcTransform::transformTypeElementRelationShip(const GfcEntityRefMap & oElementTypeRefMap, const GfcEntityRefMap & oElementRefMap, 
    const GfcRelDefinesByTypeSchema& oSrcSchema, const GfcRelDefinesByTypeSchema& oDestSchema)
{
    std::map<gfc::engine::EntityRef, std::vector<gfc::engine::EntityRef>> oRelMap;
    auto pItr = m_pContainer->getEntities(oSrcSchema.sClassName);
    pItr->first();
    while (!pItr->isDone())
    {
        auto pAggregate = pItr->current();
        auto itr = oElementTypeRefMap.find(pAggregate->asEntityRef(oSrcSchema.sRelatingTypeFieldName));
        if (itr != oElementTypeRefMap.end())
        {
            auto pValue = pAggregate->valueByName(oSrcSchema.sRelatingElementFieldName);
            for (int i = 0; i < pValue->getCount(); i++)
            {
                auto pItem = pValue->getItems(i);
                if (pItem->isNull())
                    continue;
                auto itr2 = oElementRefMap.find(pItem->asEntityRef());
                if (itr2 == oElementRefMap.end())
                    continue;
                oRelMap[itr->second].push_back(itr2->second);
            }
        }
        pItr->next();
    }
    //write
    for (auto oItem : oRelMap)
    {
        auto pRelDefinesByElement = createEntity(oDestSchema.sClassName);
        pRelDefinesByElement->setAsEntityRef(oDestSchema.sRelatingTypeFieldName, oItem.first);
        auto pValue = pRelDefinesByElement->valueByName(oDestSchema.sRelatingElementFieldName);
        if (pValue)
        {
            for (auto nRef : oItem.second)
            {
                pValue->add(new gfc::engine::CEntityRefValue(nRef));
            }
        }
        write(oItem.first, pRelDefinesByElement);
    }
}

void GfcTransform::changeEntityRefConverter()
{
    for (int i = 0; i < m_pEntityUpgrader->model()->getCount(); i++)
    {
        auto pClass = m_pEntityUpgrader->model()->getItems(i);
        for (int j = 0; j < pClass->getCount(); j++)
        {
            auto pAttribte = pClass->getCompatibilityAttribute(j);
            auto pConverter = pAttribte->converter();
            if (pConverter && pConverter->next())
            {
                auto p = dynamic_cast<gfc::engine::CEntityRefConverter*>(pConverter->next());
                if (p)
                {
                    pConverter->setNext(new CNewEntityRefConverter(this));
                }
            }
        }
    }
}

void GfcTransform::addRelAggregates(gfc::engine::EntityRef nRelatingObject, gfc::engine::EntityRef nRelatedObject)
{
    m_oRelAggregates[nRelatingObject].push_back(nRelatedObject);
}

void GfcTransform::clear()
{
    m_oTransformMap.clear();
    m_oRelAggregates.clear();
}

gfc::engine::EntityRef GfcTransform::write(gfc::engine::EntityRef nSrcRef, DestEntityPtr& pDestEntity)
{
    auto nDestRef = m_pWriter->writeEntity(pDestEntity.get());
    pDestEntity->setRef(nDestRef);
    m_oTransformMap[nSrcRef] = nDestRef;
    return nDestRef;
}
