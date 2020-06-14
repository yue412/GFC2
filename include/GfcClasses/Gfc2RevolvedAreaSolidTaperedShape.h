#ifndef GFC2REVOLVEDAREASOLIDTAPEREDSHAPE_H
#define GFC2REVOLVEDAREASOLIDTAPEREDSHAPE_H

#include "GfcClasses.h"
#include "Gfc2RevolvedAreaSolidShape.h"
#include "Gfc2Section.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RevolvedAreaSolidTaperedShape: public Gfc2RevolvedAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2RevolvedAreaSolidTaperedShape, gfc::engine::CEntity)
public:
    Gfc2RevolvedAreaSolidTaperedShape();
    Gfc2RevolvedAreaSolidTaperedShape(bool bSetSchema);
    void setEndSweptArea(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEndSweptArea() const;
    bool hasEndSweptArea() const;
    gfc::engine::CEntityWrapPtr<Gfc2Section> getEndSweptAreaPtr();

};
#endif
