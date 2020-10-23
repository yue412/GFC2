#ifndef GFC2MANIFOLDSOLIDSHAPE_H
#define GFC2MANIFOLDSOLIDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SolidShape.h"
#include "GfcClasses/x3/Gfc2Body.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

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

GFCCLASSES_NAMESPACE_END

#endif
