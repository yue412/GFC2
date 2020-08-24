#ifndef GFC2EXTRUDEDBODY_H
#define GFC2EXTRUDEDBODY_H

#include "GfcClasses.h"
#include "Gfc2PrimitiveBody.h"
#include "Gfc2Coordinates3d.h"
#include "Gfc2Polygon.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ExtrudedBody: public Gfc2PrimitiveBody
{
GFCENGINE_DEC_OBJECT(Gfc2ExtrudedBody, gfc::engine::CEntity)
public:
    Gfc2ExtrudedBody();
    Gfc2ExtrudedBody(bool bSetSchema);
    void setCoordinate(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoordinate() const;
    bool hasCoordinate() const;
    gfc::engine::CEntityWrapPtr<Gfc2Coordinates3d> getCoordinatePtr();
    void setLen(const Gfc2Double& dValue);
    Gfc2Double getLen() const;
    bool hasLen() const;
    void setSection(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSection() const;
    bool hasSection() const;
    gfc::engine::CEntityWrapPtr<Gfc2Polygon> getSectionPtr();

};
#endif
