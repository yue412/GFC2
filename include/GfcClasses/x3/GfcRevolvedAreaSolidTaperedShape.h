#ifndef GFCREVOLVEDAREASOLIDTAPEREDSHAPE_H
#define GFCREVOLVEDAREASOLIDTAPEREDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcRevolvedAreaSolidShape.h"
#include "GfcClasses/x3/GfcSection.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcRevolvedAreaSolidTaperedShape: public GfcRevolvedAreaSolidShape
{
GFCENGINE_DEC_OBJECT(GfcRevolvedAreaSolidTaperedShape, gfc::engine::CEntity)
public:
    GfcRevolvedAreaSolidTaperedShape();
    GfcRevolvedAreaSolidTaperedShape(bool bSetSchema);
    void setEndSweptArea(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEndSweptArea() const;
    bool hasEndSweptArea() const;
    std::shared_ptr<GfcSection> getEndSweptAreaPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
