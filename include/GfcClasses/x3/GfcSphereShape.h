#ifndef GFCSPHERESHAPE_H
#define GFCSPHERESHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcPrimitiveShape.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSphereShape: public GfcPrimitiveShape
{
GFCENGINE_DEC_OBJECT(GfcSphereShape, gfc::engine::CEntity)
public:
    GfcSphereShape();
    GfcSphereShape(bool bSetSchema);
    void setRadius(const GfcDouble& dValue);
    GfcDouble getRadius() const;
    bool hasRadius() const;

};

GFCCLASSES_NAMESPACE_END

#endif
