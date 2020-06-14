#include "GfcUtils/GfcTransform30to20.h"
#include "GfcEngine\PropValue.h"
#include "GfcEngine\Writer.h"


GfcTransform30to20::GfcTransform30to20(gfc::engine::IContainer* pContainer): GfcTransform(pContainer)
{
}


GfcTransform30to20::~GfcTransform30to20()
{
}

std::shared_ptr<gfc::engine::CEntity> GfcTransform30to20::doTransformProject(gfc::engine::EntityPtr pEntity)
{
    auto pProject = createEntity(L"Gfc2Project");
    pProject->setAsInteger(L"ID", std::stoi(pEntity->asString(L"ID")));
    if (!pEntity->isNull(L"Name"))
        pProject->setAsEntityRef(L"Name", transformString(pEntity->asEntity(L"Name")));
    return pProject;
}

std::shared_ptr<gfc::engine::CEntity> GfcTransform30to20::doTransformBuilding(gfc::engine::EntityPtr pEntity)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

std::shared_ptr<gfc::engine::CEntity> GfcTransform30to20::doTransformFloor(gfc::engine::EntityPtr pEntity)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

std::shared_ptr<gfc::engine::CEntity> GfcTransform30to20::doTransformShape(gfc::engine::EntityPtr pElement)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

std::shared_ptr<gfc::engine::CEntity> GfcTransform30to20::doTransformElement(gfc::engine::EntityPtr pElement)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcTransform30to20::writeRelAggregates()
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
        m_pWriter->writeEntity(pRelAggregates.get());
    }
}

gfc::engine::EntityRef GfcTransform30to20::transformString(gfc::engine::EntityPtr pString)
{
    auto pStr = createEntity(L"Gfc2String");
    pStr->setAsString(L"Value", pString->asString(L"Value"));
    return m_pWriter->writeEntity(pStr.get());
}
