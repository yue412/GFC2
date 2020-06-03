#ifndef GFC2CONESHAPE_H
#define GFC2CONESHAPE_H

#include "GfcClasses.h"
#include "Gfc2PrimitiveShape.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ConeShape: public Gfc2PrimitiveShape
{
GFCENGINE_DEC_OBJECT(Gfc2ConeShape, gfc2::engine::Entity)
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
#endif
