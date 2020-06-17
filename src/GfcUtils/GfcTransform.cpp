#include "GfcUtils\GfcTransform.h"
#include "GfcEngine\Writer.h"
#include "GfcSchema\Model.h"
#include "GfcEngine\GfcEngineUtils.h"
#include "GfcEngine\PropValue.h"
#include "GfcUtils\ModelCompatibility.h"
#include "GfcUtils\ClassCompatibility.h"
#include "GfcUtils\AttributeCompatibility.h"
#include "GfcUtils\Converter.h"
#include <memory>
#include <assert.h>

class CIDConverter : public gfc::engine::CConverter
{
public:
    virtual void doTransform(gfc::engine::CPropValue* pFrom, gfc::engine::CPropValue* pTo)
    {
        pTo->setAsInteger(std::stoi(pFrom->asString()));
    }
    virtual CConverter* clone()
    {
        return new CIDConverter(*this);
    }
};

class CNewEntityRefConverter : public gfc::engine::CEntityRefConverter
{
public:
    CNewEntityRefConverter(GfcTransform* pOwner): m_pOwner(pOwner){}
    virtual void doTransform(gfc::engine::CPropValue* pFrom, gfc::engine::CPropValue* pTo)
    {
        auto nNewRef = m_pOwner->transformEntity(pFrom->asEntityRef());
        pTo->setAsEntityRef(nNewRef);
    }
    virtual CConverter* clone()
    {
        return new CNewEntityRefConverter(*this);
    }
private:
    GfcTransform* m_pOwner;
};

GfcTransform::GfcTransform(gfc::engine::IContainer * pContainer): m_pContainer(pContainer), m_pWriter(nullptr), m_pModel(nullptr)
{
    m_pModelCompatibility = new gfc::engine::CModelCompatibility();
}

GfcTransform::~GfcTransform()
{
    delete m_pModelCompatibility;
    clear();
}

void GfcTransform::setSchema(gfc::schema::CModel* pSrcModel, gfc::schema::CModel* pDestModel)
{
    assert(pSrcModel);
    assert(pDestModel);
    m_pModelCompatibility->init(pSrcModel, pDestModel);
    changeIDConverter(L"Gfc2Project");
    changeIDConverter(L"Gfc2Building");
    changeIDConverter(L"Gfc2Floor");
    changeEntityRefConverter();
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
    // 转Element
    transformElement(oFloorMap);
    // 记录关系
    writeRelAggregates();
    return true;
}

gfc::engine::EntityRef GfcTransform::transformEntity(gfc::engine::EntityRef nSrc)
{
    auto itr = m_oTransformMap.find(nSrc);
    if (itr == m_oTransformMap.end())
    {
        auto pSrc = m_pContainer->getEntity(nSrc);
        auto pDest = doTransformEntity(pSrc);
        return write(pSrc.ref(), pDest);
    }
    else
        return itr->second;
}

GfcTransform::DestEntityPtr GfcTransform::doTransformProject(SrcEntityPtr & pSrcEntity)
{
    auto pNewProject = doTransformEntity(pSrcEntity);
    if (pNewProject)
    {
        std::vector<SrcEntityPtr> oPropertySetList;
        getPropertySetList(pSrcEntity.ref(), oPropertySetList);
        transformProjectPropertySet(pSrcEntity, oPropertySetList, pNewProject);
    }
    return pNewProject;
}

GfcTransform::DestEntityPtr GfcTransform::doTransformBuilding(SrcEntityPtr & pSrcEntity)
{
    auto pNewBuilding = doTransformEntity(pSrcEntity);
    if (pNewBuilding)
    {
        std::vector<SrcEntityPtr> oPropertySetList;
        getPropertySetList(pSrcEntity.ref(), oPropertySetList);
        transformBuildingPropertySet(pSrcEntity, oPropertySetList, pNewBuilding);
    }
    return pNewBuilding;
}

GfcTransform::DestEntityPtr GfcTransform::doTransformFloor(SrcEntityPtr & pSrcEntity)
{
    auto pNewFloor = doTransformEntity(pSrcEntity);
    if (pNewFloor)
    {
        std::vector<SrcEntityPtr> oPropertySetList;
        getPropertySetList(pSrcEntity.ref(), oPropertySetList);
        transformFloorPropertySet(pSrcEntity, oPropertySetList, pNewFloor);
    }
    return pNewFloor;
}

GfcTransform::DestEntityPtr GfcTransform::createEntity(const std::wstring & sEntityName)
{
    return DestEntityPtr(gfc::engine::CEngineUtils::createEntity(m_pModel, sEntityName));
}

GfcTransform::DestEntityPtr GfcTransform::doTransformEntity(SrcEntityPtr& pSrcEntity)
{
  //  pSrcEntity->getSchema()->getBaseType()->getName
    auto pClassCompatibility = m_pModelCompatibility->find(pSrcEntity->entityName());
    if (pClassCompatibility == nullptr)
    {
        // no read
        pClassCompatibility = m_pModelCompatibility->find(pSrcEntity->getSchema()->getBaseType()->getName());
        if (pClassCompatibility == nullptr)
            return nullptr;
    }
    auto pNewEntity = createEntity(pSrcEntity->entityName());
    transformEntity(pClassCompatibility, pSrcEntity.get(), pNewEntity.get());
    return pNewEntity;
}

void GfcTransform::transformEntity(gfc::engine::CClassCompatibility* pClassCompatibility,
    gfc::engine::CEntity* pSrcEntity, gfc::engine::CEntity* pDestEntity)
{
    for (int i = 0; i < pClassCompatibility->getCount(); i++)
    {
        auto pAttributeCompatibility = pClassCompatibility->getCompatibilityAttribute(i);
        int  nIndex = pAttributeCompatibility->toIndex();
        auto pConverter = pAttributeCompatibility->converter();
        if (nIndex != -1 && pConverter && i < (int)pSrcEntity->getPropCount())
        {
            auto pSrcValue = pSrcEntity->getProps(i)->value();
            auto pDestValue = pDestEntity->getProps(nIndex)->value();
            pConverter->transform(pSrcValue, pDestValue);
        }
    }
}

gfc::engine::EntityRef GfcTransform::transformProject()
{
    gfc::engine::EntityRef nProjectRef = -1;
    auto pItr = m_pContainer->getEntities(L"Gfc2Project");
    pItr->first();
    if (!pItr->isDone())
    {
        auto pProject = pItr->current();
        
        auto pNewProject = doTransformProject(pProject);
        if (pNewProject)
        {
            nProjectRef = write(pProject.ref(), pNewProject);
        }
    }
    return nProjectRef;
}

void GfcTransform::getPropertySetList(gfc::engine::EntityRef nRef, std::vector<SrcEntityPtr>& oList)
{
}

GfcTransform::GfcEntityRefMap GfcTransform::transformBuilding(gfc::engine::EntityRef nProjectRef)
{
    GfcEntityRefMap oResult;
    auto pItr = m_pContainer->getEntities(L"Gfc2Building");
    pItr->first();
    while (!pItr->isDone())
    {
        auto pBuilding = pItr->current();
        auto pNewBuilding = doTransformBuilding(pBuilding);
        if (pNewBuilding)
        {
            auto nBuildingRef = write(pBuilding.ref(), pNewBuilding);
            oResult.insert(std::make_pair(pBuilding.ref(), nBuildingRef));
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
                auto pNewFloor = doTransformFloor(pFloor);
                if (pNewFloor)
                {
                    auto nFloorRef = write(pFloor.ref(), pNewFloor);
                    oResult.insert(std::make_pair(pFloor.ref(), nFloorRef));
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
                auto pElement = pAggregate->getEntity(pValue, i);
                if (pElement->entityName() != L"Gfc2Element")
                    continue;
                auto pNewShape = doTransformShape(pElement);
                /*
                auto pNewElement = doTransformElement(pElement);
                // todo
                pNewElement->setAsEntityRef(L"Shape", m_pWriter->writeEntity(pNewShape.get()));
                auto nElementRef = m_pWriter->writeEntity(pNewElement.get());
                addRelAggregates(itr->second, nElementRef);
                */
            }
        }
        pItr->next();
    }
}

void GfcTransform::changeIDConverter(const std::wstring sEntityName)
{
    auto pClassCompatibility = m_pModelCompatibility->find(sEntityName);
    if (pClassCompatibility)
    {
        for (int i = 0; i < pClassCompatibility->getCount(); ++i)
        {
            auto pAttribteCompatibility = pClassCompatibility->getCompatibilityAttribute(i);
            if (pAttribteCompatibility->getName() == L"ID")
            {
                pAttribteCompatibility->setConverter(new CIDConverter);
            }
        }
    }
}

void GfcTransform::changeEntityRefConverter()
{
    for (int i = 0; i < m_pModelCompatibility->getCount(); i++)
    {
        auto pClass = m_pModelCompatibility->getItems(i);
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
    m_oTransformMap[nSrcRef] = nDestRef;
    return nDestRef;
}
