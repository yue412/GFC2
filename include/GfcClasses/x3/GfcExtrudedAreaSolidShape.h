#ifndef GFCEXTRUDEDAREASOLIDSHAPE_H
#define GFCEXTRUDEDAREASOLIDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSweptAreaSolidShape.h"
#include "GfcClasses/x3/GfcVector3d.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcExtrudedAreaSolidShape: public GfcSweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(GfcExtrudedAreaSolidShape, gfc::engine::CEntity)
public:
    GfcExtrudedAreaSolidShape();
    GfcExtrudedAreaSolidShape(bool bSetSchema);
    void setExtrudedDirection(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getExtrudedDirection() const;
    bool hasExtrudedDirection() const;
    std::shared_ptr<GfcVector3d> getExtrudedDirectionPtr();
    void setLen(const GfcDouble& dValue);
    GfcDouble getLen() const;
    bool hasLen() const;

};

GFCCLASSES_NAMESPACE_END

#endif
