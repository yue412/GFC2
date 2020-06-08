#ifndef NGFC2ELEMENTSHAPE_H
#define NGFC2ELEMENTSHAPE_H

#include "Gfc2ElementShape.h"
#include "NGfc2String.h"
#include "NGfc2Shape.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2ElementShape: public glodon::objectbufnet::Entity
{
public:
    NGfc2ElementShape();
    NGfc2ElementShape(void* pEntity, bool bOwner);
    void setIdentifier(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getIdentifier();
    bool hasIdentifier();
    NGfc2String^ getIdentifierPtr();
    void setShape(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getShape();
    bool hasShape();
    NGfc2Shape^ getShapePtr();

};
#endif