#include "GfcUtils\GfcTransform.h"
#include "GfcEngine\Writer.h"
#include "GfcSchema\Model.h"
#include "GfcEngine\GfcEngineUtils.h"
#include "GfcEngine\PropValue.h"
#include <memory>
#include <assert.h>

GfcTransform::GfcTransform(gfc::engine::IContainer * pContainer): m_pContainer(pContainer), m_pWriter(nullptr), m_pModel(nullptr)
{
}

GfcTransform::~GfcTransform()
{
    clear();
}

void GfcTransform::setSchema(gfc::schema::CModel * pModel)
{
    assert(pModel);
    m_pModel = pModel;
}

bool GfcTransform::transform(const std::wstring & sFileName)
{
    if (nullptr == m_pModel)
        return false;
    clear();
    m_pWriter = new gfc::engine::CWriter(m_pModel->version());
    if (!m_pWriter->open(sFileName, L"express"))
        return false;
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
    m_pWriter->close();
    return true;
}

std::shared_ptr<gfc::engine::CEntity> GfcTransform::createEntity(const std::wstring & sEntityName)
{
    return std::shared_ptr<gfc::engine::CEntity>(gfc::engine::CEngineUtils::createEntity(m_pModel, sEntityName));
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
        nProjectRef = m_pWriter->writeEntity(pNewProject.get());
    }
    return nProjectRef;
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
        auto nBuildingRef = m_pWriter->writeEntity(pNewBuilding.get());
        oResult.insert(std::make_pair(pBuilding.ref(), nBuildingRef));
        addRelAggregates(nProjectRef, nBuildingRef);
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
                auto nFloorRef = m_pWriter->writeEntity(pNewFloor.get());
                oResult.insert(std::make_pair(pFloor.ref(), nFloorRef));
                addRelAggregates(itr->second, nFloorRef);
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
                //auto pNewPropertySet = doTransformPropertySet(pElement);
                auto pNewElement = doTransformElement(pElement);
                // todo
                pNewElement->setAsEntityRef(L"Shape", m_pWriter->writeEntity(pNewShape.get()));
                auto nElementRef = m_pWriter->writeEntity(pNewElement.get());
                addRelAggregates(itr->second, nElementRef);
            }
        }
        pItr->next();
    }
}

void GfcTransform::addRelAggregates(gfc::engine::EntityRef nRelatingObject, gfc::engine::EntityRef nRelatedObject)
{
    m_oRelAggregates[nRelatingObject].push_back(nRelatedObject);
}

void GfcTransform::clear()
{
    m_oRelAggregates.clear();
    delete m_pWriter; m_pWriter = nullptr;
}
