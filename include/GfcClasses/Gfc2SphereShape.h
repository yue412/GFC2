#ifndef GFC2SPHERESHAPE_H
#define GFC2SPHERESHAPE_H

#include "GfcClasses.h"
#include "Gfc2PrimitiveShape.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SphereShape: public Gfc2PrimitiveShape
{
GFCENGINE_DEC_OBJECT(Gfc2SphereShape, gfc::engine::CEntity)
public:
    Gfc2SphereShape();
    Gfc2SphereShape(bool bSetSchema);
    void setRadius(const Gfc2Double& dValue);
    Gfc2Double getRadius() const;
    bool hasRadius() const;

};
#endif
