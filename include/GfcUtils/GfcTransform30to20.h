#ifndef GFCTRANSFORM30TO20_H
#define GFCTRANSFORM30TO20_H

#include "GfcUtils\GfcTransform.h"

class GfcTransform30to20 : public GfcTransform
{
public:
    GfcTransform30to20(gfc::engine::IContainer* pContainer);
    virtual  ~GfcTransform30to20();
protected:
    virtual std::shared_ptr<gfc::engine::CEntity> doTransformProject(gfc::engine::EntityPtr pEntity);
    virtual std::shared_ptr<gfc::engine::CEntity> doTransformBuilding(gfc::engine::EntityPtr pEntity);
    virtual std::shared_ptr<gfc::engine::CEntity> doTransformFloor(gfc::engine::EntityPtr pEntity);
    virtual std::shared_ptr<gfc::engine::CEntity> doTransformShape(gfc::engine::EntityPtr pElement);
    virtual std::shared_ptr<gfc::engine::CEntity> doTransformElement(gfc::engine::EntityPtr pElement);
    virtual void writeRelAggregates();
private:
    gfc::engine::EntityRef transformString(gfc::engine::EntityPtr pString);
};


#endif // !GFCTRANSFORM30TO20_H
