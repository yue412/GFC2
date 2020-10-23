#ifndef GFC2EXTRUDEDAREASOLIDTAPEREDSHAPE_H
#define GFC2EXTRUDEDAREASOLIDTAPEREDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2ExtrudedAreaSolidShape.h"
#include "GfcClasses/x3/Gfc2Section.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2ExtrudedAreaSolidTaperedShape: public Gfc2ExtrudedAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2ExtrudedAreaSolidTaperedShape, gfc::engine::CEntity)
public:
    Gfc2ExtrudedAreaSolidTaperedShape();
    Gfc2ExtrudedAreaSolidTaperedShape(bool bSetSchema);
    void setEndSweptArea(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEndSweptArea() const;
    bool hasEndSweptArea() const;
    std::shared_ptr<Gfc2Section> getEndSweptAreaPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
