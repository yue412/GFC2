#ifndef GFC2SWEPTAREASOLIDSHAPE_H
#define GFC2SWEPTAREASOLIDSHAPE_H

#include "GfcClasses.h"
#include "Gfc2SolidShape.h"
#include "Gfc2Section.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2SweptAreaSolidShape: public Gfc2SolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2SweptAreaSolidShape, gfc::engine::CEntity)
public:
    Gfc2SweptAreaSolidShape();
    Gfc2SweptAreaSolidShape(bool bSetSchema);
    void setSweptArea(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSweptArea() const;
    bool hasSweptArea() const;
    gfc::engine::CEntityWrapPtr<Gfc2Section> getSweptAreaPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
