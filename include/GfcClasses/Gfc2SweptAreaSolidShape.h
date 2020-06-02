#ifndef GFC2SWEPTAREASOLIDSHAPE_H
#define GFC2SWEPTAREASOLIDSHAPE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2SolidShape.h"
#include "Gfc2Section.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2SweptAreaSolidShape: public Gfc2SolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2SweptAreaSolidShape,gfc2::engine::EntityFactory)
public:
    Gfc2SweptAreaSolidShape();
    Gfc2SweptAreaSolidShape(bool bSetSchema);
    void setSweptArea(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getSweptArea() const;
    bool hasSweptArea() const;
    std::shared_ptr<Gfc2Section> getSweptAreaPtr();

};
#endif
