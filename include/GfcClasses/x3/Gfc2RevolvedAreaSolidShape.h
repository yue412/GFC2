#ifndef GFC2REVOLVEDAREASOLIDSHAPE_H
#define GFC2REVOLVEDAREASOLIDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2SweptAreaSolidShape.h"
#include "GfcClasses/x3/Gfc2Vector2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RevolvedAreaSolidShape: public Gfc2SweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2RevolvedAreaSolidShape, gfc::engine::CEntity)
public:
    Gfc2RevolvedAreaSolidShape();
    Gfc2RevolvedAreaSolidShape(bool bSetSchema);
    void setLocation(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLocation() const;
    bool hasLocation() const;
    std::shared_ptr<Gfc2Vector2d> getLocationPtr();
    void setAxis(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getAxis() const;
    bool hasAxis() const;
    std::shared_ptr<Gfc2Vector2d> getAxisPtr();
    void setAngle(const Gfc2Double& dValue);
    Gfc2Double getAngle() const;
    bool hasAngle() const;

};

GFCCLASSES_NAMESPACE_END

#endif
