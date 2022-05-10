#ifndef GFCCYLINDERSHAPE_H
#define GFCCYLINDERSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcPrimitiveShape.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCylinderShape: public GfcPrimitiveShape
{
GFCENGINE_DEC_OBJECT(GfcCylinderShape, gfc::engine::CEntity)
public:
    GfcCylinderShape();
    GfcCylinderShape(bool bSetSchema);
    void setHeight(const GfcDouble& dValue);
    GfcDouble getHeight() const;
    bool hasHeight() const;
    void setRadius(const GfcDouble& dValue);
    GfcDouble getRadius() const;
    bool hasRadius() const;

};

GFCCLASSES_NAMESPACE_END

#endif
