#ifndef GFCEXTRUDEDBODY_H
#define GFCEXTRUDEDBODY_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcPrimitiveBody.h"
#include "GfcClasses/x3/GfcCoordinates3d.h"
#include "GfcClasses/x3/GfcPolygon.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcExtrudedBody: public GfcPrimitiveBody
{
GFCENGINE_DEC_OBJECT(GfcExtrudedBody, gfc::engine::CEntity)
public:
    GfcExtrudedBody();
    GfcExtrudedBody(bool bSetSchema);
    void setCoordinate(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoordinate() const;
    bool hasCoordinate() const;
    std::shared_ptr<GfcCoordinates3d> getCoordinatePtr();
    void setLen(const GfcDouble& dValue);
    GfcDouble getLen() const;
    bool hasLen() const;
    void setSection(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSection() const;
    bool hasSection() const;
    std::shared_ptr<GfcPolygon> getSectionPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
