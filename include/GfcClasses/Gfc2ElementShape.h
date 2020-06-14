#ifndef GFC2ELEMENTSHAPE_H
#define GFC2ELEMENTSHAPE_H

#include "GfcClasses.h"
#include "Gfc2String.h"
#include "Gfc2Shape.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ElementShape: public gfc::engine::CEntity
{
GFCENGINE_DEC_OBJECT(Gfc2ElementShape, gfc::engine::CEntity)
public:
    Gfc2ElementShape();
    Gfc2ElementShape(bool bSetSchema);
    void setIdentifier(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getIdentifier() const;
    bool hasIdentifier() const;
    gfc::engine::CEntityWrapPtr<Gfc2String> getIdentifierPtr();
    void setShape(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getShape() const;
    bool hasShape() const;
    gfc::engine::CEntityWrapPtr<Gfc2Shape> getShapePtr();

};
#endif
