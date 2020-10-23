#ifndef GFC2EXTRUDEDAREASOLIDSHAPE_H
#define GFC2EXTRUDEDAREASOLIDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SweptAreaSolidShape.h"
#include "GfcClasses/x3/Gfc2Vector3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ExtrudedAreaSolidShape: public Gfc2SweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2ExtrudedAreaSolidShape, gfc::engine::CEntity)
public:
    Gfc2ExtrudedAreaSolidShape();
    Gfc2ExtrudedAreaSolidShape(bool bSetSchema);
    void setExtrudedDirection(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getExtrudedDirection() const;
    bool hasExtrudedDirection() const;
    std::shared_ptr<Gfc2Vector3d> getExtrudedDirectionPtr();
    void setLen(const Gfc2Double& dValue);
    Gfc2Double getLen() const;
    bool hasLen() const;

};

GFCCLASSES_NAMESPACE_END

#endif
