#ifndef GFC2REVOLVEDAREASOLIDTAPEREDSHAPE_H
#define GFC2REVOLVEDAREASOLIDTAPEREDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2RevolvedAreaSolidShape.h"
#include "GfcClasses/x3/Gfc2Section.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2RevolvedAreaSolidTaperedShape: public Gfc2RevolvedAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2RevolvedAreaSolidTaperedShape, gfc::engine::CEntity)
public:
    Gfc2RevolvedAreaSolidTaperedShape();
    Gfc2RevolvedAreaSolidTaperedShape(bool bSetSchema);
    void setEndSweptArea(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEndSweptArea() const;
    bool hasEndSweptArea() const;
    std::shared_ptr<Gfc2Section> getEndSweptAreaPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
