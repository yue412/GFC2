#include "GfcUtils/GfcTransform30to20.h"
#include "GfcEngine\PropValue.h"
#include "GfcEngine\Writer.h"


GfcTransform30to20::GfcTransform30to20(gfc::engine::IContainer* pContainer): GfcTransform(pContainer)
{
}


GfcTransform30to20::~GfcTransform30to20()
{
}

GfcTransform::DestEntityPtr GfcTransform30to20::doTransformElement(SrcEntityPtr & pSrcEntity, std::vector<SrcEntityPtr>& oPropertySetList)
{
    return DestEntityPtr();
}

GfcTransform::DestEntityPtr GfcTransform30to20::doTransformShape(SrcEntityPtr & pSrcEntity)
{
    return DestEntityPtr();
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
        write(itr.first, pRelAggregates);
    }
}