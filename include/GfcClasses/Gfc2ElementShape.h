#ifndef GFC2ELEMENTSHAPE_H
#define GFC2ELEMENTSHAPE_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2String.h"
#include "Gfc2Shape.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2ElementShape: public gfc2::engine::Entity
{
GFCENGINE_DEC_OBJECT(Gfc2ElementShape,gfc2::engine::EntityFactory)
public:
    Gfc2ElementShape();
    Gfc2ElementShape(bool bSetSchema);
    void setIdentifier(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getIdentifier() const;
    bool hasIdentifier() const;
    std::shared_ptr<Gfc2String> getIdentifierPtr();
    void setShape(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getShape() const;
    bool hasShape() const;
    std::shared_ptr<Gfc2Shape> getShapePtr();

};
#endif
