#ifndef GFCREVOLVEDAREASOLIDSHAPE_H
#define GFCREVOLVEDAREASOLIDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSweptAreaSolidShape.h"
#include "GfcClasses/x3/GfcVector2d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRevolvedAreaSolidShape: public GfcSweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(GfcRevolvedAreaSolidShape, gfc::engine::CEntity)
public:
    GfcRevolvedAreaSolidShape();
    GfcRevolvedAreaSolidShape(bool bSetSchema);
    void setLocation(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getLocation() const;
    bool hasLocation() const;
    std::shared_ptr<GfcVector2d> getLocationPtr();
    void setAxis(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getAxis() const;
    bool hasAxis() const;
    std::shared_ptr<GfcVector2d> getAxisPtr();
    void setAngle(const GfcDouble& dValue);
    GfcDouble getAngle() const;
    bool hasAngle() const;

};

GFCCLASSES_NAMESPACE_END

#endif
