#ifndef GFC2REVOLVEDAREASOLIDSHAPE_H
#define GFC2REVOLVEDAREASOLIDSHAPE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2SweptAreaSolidShape.h"
#include "Gfc2Vector2d.h"
#include "TypeDef.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2RevolvedAreaSolidShape: public Gfc2SweptAreaSolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2RevolvedAreaSolidShape,gfc2::engine::EntityFactory)
public:
    Gfc2RevolvedAreaSolidShape();
    Gfc2RevolvedAreaSolidShape(bool bSetSchema);
    void setAxis(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getAxis() const;
    bool hasAxis() const;
    std::shared_ptr<Gfc2Vector2d> getAxisPtr();
    void setAngle(const Gfc2Double& dValue);
    Gfc2Double getAngle() const;
    bool hasAngle() const;

};
#endif
