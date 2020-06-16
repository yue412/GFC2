#ifndef GFCTRANSFORM30TO20_H
#define GFCTRANSFORM30TO20_H

#include "GfcUtils\GfcTransform.h"

class GfcTransform30to20 : public GfcTransform
{
public:
    GfcTransform30to20(gfc::engine::IContainer* pContainer);
    virtual  ~GfcTransform30to20();
protected:
    virtual DestEntityPtr doTransformElement(SrcEntityPtr& pSrcEntity, std::vector<SrcEntityPtr>& oPropertySetList);
    virtual DestEntityPtr doTransformShape(SrcEntityPtr& pSrcEntity);
    virtual void writeRelAggregates();
};


#endif // !GFCTRANSFORM30TO20_H
