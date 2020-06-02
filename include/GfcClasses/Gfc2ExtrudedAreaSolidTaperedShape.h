#ifndef GFC2EXTRUDEDAREASOLIDTAPEREDSHAPE_H
#define GFC2EXTRUDEDAREASOLIDTAPEREDSHAPE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2ExtrudedAreaSolidShape.h"
#include "Gfc2Section.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ExtrudedAreaSolidTaperedShape: public Gfc2ExtrudedAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2ExtrudedAreaSolidTaperedShape,gfc2::engine::EntityFactory)
public:
    Gfc2ExtrudedAreaSolidTaperedShape();
    Gfc2ExtrudedAreaSolidTaperedShape(bool bSetSchema);
    void setEndSweptArea(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getEndSweptArea() const;
    bool hasEndSweptArea() const;
    std::shared_ptr<Gfc2Section> getEndSweptAreaPtr();

};
#endif
