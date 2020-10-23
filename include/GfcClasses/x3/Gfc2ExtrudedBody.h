#ifndef GFC2EXTRUDEDBODY_H
#define GFC2EXTRUDEDBODY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2PrimitiveBody.h"
#include "GfcClasses/x3/Gfc2Coordinates3d.h"
#include "GfcClasses/x3/Gfc2Polygon.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ExtrudedBody: public Gfc2PrimitiveBody
{
GFCENGINE_DEC_OBJECT(Gfc2ExtrudedBody, gfc::engine::CEntity)
public:
    Gfc2ExtrudedBody();
    Gfc2ExtrudedBody(bool bSetSchema);
    void setCoordinate(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoordinate() const;
    bool hasCoordinate() const;
    std::shared_ptr<Gfc2Coordinates3d> getCoordinatePtr();
    void setLen(const Gfc2Double& dValue);
    Gfc2Double getLen() const;
    bool hasLen() const;
    void setSection(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSection() const;
    bool hasSection() const;
    std::shared_ptr<Gfc2Polygon> getSectionPtr();

};

GFCCLASSES_NAMESPACE_END

#endif