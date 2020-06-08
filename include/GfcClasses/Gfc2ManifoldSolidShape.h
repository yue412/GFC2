#ifndef GFC2MANIFOLDSOLIDSHAPE_H
#define GFC2MANIFOLDSOLIDSHAPE_H

#include "GfcClasses.h"
#include "Gfc2SolidShape.h"
#include "Gfc2Body.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ManifoldSolidShape: public Gfc2SolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2ManifoldSolidShape, gfc::engine::CEntity)
public:
    Gfc2ManifoldSolidShape();
    Gfc2ManifoldSolidShape(bool bSetSchema);
    void setBody(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getBody() const;
    bool hasBody() const;
    std::shared_ptr<Gfc2Body> getBodyPtr();

};
#endif
