#ifndef GFC2EXTRUDEDAREASOLIDTAPEREDSHAPE_H
#define GFC2EXTRUDEDAREASOLIDTAPEREDSHAPE_H

#include "GfcClasses.h"
#include "Gfc2ExtrudedAreaSolidShape.h"
#include "Gfc2Section.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ExtrudedAreaSolidTaperedShape: public Gfc2ExtrudedAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2ExtrudedAreaSolidTaperedShape, gfc::engine::Entity)
public:
    Gfc2ExtrudedAreaSolidTaperedShape();
    Gfc2ExtrudedAreaSolidTaperedShape(bool bSetSchema);
    void setEndSweptArea(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEndSweptArea() const;
    bool hasEndSweptArea() const;
    std::shared_ptr<Gfc2Section> getEndSweptAreaPtr();

};
#endif
