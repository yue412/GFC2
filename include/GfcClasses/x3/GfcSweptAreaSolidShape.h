#ifndef GFCSWEPTAREASOLIDSHAPE_H
#define GFCSWEPTAREASOLIDSHAPE_H

#include "GfcClasses/x3/_Gfc_Classes.h"
#include "GfcClasses/x3/GfcSolidShape.h"
#include "GfcClasses/x3/GfcSection.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcSweptAreaSolidShape: public GfcSolidShape
{
GFCENGINE_DEC_OBJECT(GfcSweptAreaSolidShape, gfc::engine::CEntity)
public:
    GfcSweptAreaSolidShape();
    GfcSweptAreaSolidShape(bool bSetSchema);
    void setSweptArea(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSweptArea() const;
    bool hasSweptArea() const;
    std::shared_ptr<GfcSection> getSweptAreaPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
