#ifndef GFCCUBOIDBODY_H
#define GFCCUBOIDBODY_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcPrimitiveBody.h"
#include "GfcClasses/x3/GfcCoordinates3d.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCuboidBody: public GfcPrimitiveBody
{
GFCENGINE_DEC_OBJECT(GfcCuboidBody, gfc::engine::CEntity)
public:
    GfcCuboidBody();
    GfcCuboidBody(bool bSetSchema);
    void setCoordinate(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getCoordinate() const;
    bool hasCoordinate() const;
    std::shared_ptr<GfcCoordinates3d> getCoordinatePtr();
    void setDimension(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getDimension() const;
    bool hasDimension() const;
    std::shared_ptr<GfcVector3d> getDimensionPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
