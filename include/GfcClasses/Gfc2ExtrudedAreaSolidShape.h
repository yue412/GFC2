#ifndef GFC2EXTRUDEDAREASOLIDSHAPE_H
#define GFC2EXTRUDEDAREASOLIDSHAPE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2SweptAreaSolidShape.h"
#include "Gfc2Vector3d.h"
#include "TypeDef.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ExtrudedAreaSolidShape: public Gfc2SweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2ExtrudedAreaSolidShape,gfc2::engine::EntityFactory)
public:
    Gfc2ExtrudedAreaSolidShape();
    Gfc2ExtrudedAreaSolidShape(bool bSetSchema);
    void setExtrudedDirection(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getExtrudedDirection() const;
    bool hasExtrudedDirection() const;
    std::shared_ptr<Gfc2Vector3d> getExtrudedDirectionPtr();
    void setLength(const Gfc2Double& dValue);
    Gfc2Double getLength() const;
    bool hasLength() const;

};
#endif
