#ifndef GFC2CONESHAPE_H
#define GFC2CONESHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2PrimitiveShape.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ConeShape: public Gfc2PrimitiveShape
{
GFCENGINE_DEC_OBJECT(Gfc2ConeShape, gfc::engine::CEntity)
public:
    Gfc2ConeShape();
    Gfc2ConeShape(bool bSetSchema);
    void setHeight(const Gfc2Double& dValue);
    Gfc2Double getHeight() const;
    bool hasHeight() const;
    void setBottomRadius(const Gfc2Double& dValue);
    Gfc2Double getBottomRadius() const;
    bool hasBottomRadius() const;

};

GFCCLASSES_NAMESPACE_END

#endif
