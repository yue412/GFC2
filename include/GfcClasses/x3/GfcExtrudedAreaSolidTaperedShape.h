#ifndef GFCEXTRUDEDAREASOLIDTAPEREDSHAPE_H
#define GFCEXTRUDEDAREASOLIDTAPEREDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcExtrudedAreaSolidShape.h"
#include "GfcClasses/x3/GfcSection.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcExtrudedAreaSolidTaperedShape: public GfcExtrudedAreaSolidShape
{
GFCENGINE_DEC_OBJECT(GfcExtrudedAreaSolidTaperedShape, gfc::engine::CEntity)
public:
    GfcExtrudedAreaSolidTaperedShape();
    GfcExtrudedAreaSolidTaperedShape(bool bSetSchema);
    void setEndSweptArea(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getEndSweptArea() const;
    bool hasEndSweptArea() const;
    std::shared_ptr<GfcSection> getEndSweptAreaPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
