#ifndef GFCELEMENTSHAPE_H
#define GFCELEMENTSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcShape.h"
#include "GfcClasses/x3/TypeDef.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcElementShape: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(GfcElementShape, gfc::engine::CEntity)
public:
    GfcElementShape();
    GfcElementShape(bool bSetSchema);
    void setIdentifier(const GfcString& sValue);
    GfcString getIdentifier() const;
    bool hasIdentifier() const;
    void setShape(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getShape() const;
    bool hasShape() const;
    std::shared_ptr<GfcShape> getShapePtr();

};

GFCCLASSES_NAMESPACE_END

#endif
