#ifndef GFC2CYLINDERSHAPE_H
#define GFC2CYLINDERSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2PrimitiveShape.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2CylinderShape: public Gfc2PrimitiveShape
{
GFCENGINE_DEC_OBJECT(Gfc2CylinderShape, gfc::engine::CEntity)
public:
    Gfc2CylinderShape();
    Gfc2CylinderShape(bool bSetSchema);
    void setHeight(const Gfc2Double& dValue);
    Gfc2Double getHeight() const;
    bool hasHeight() const;
    void setRadius(const Gfc2Double& dValue);
    Gfc2Double getRadius() const;
    bool hasRadius() const;

};

GFCCLASSES_NAMESPACE_END

#endif
