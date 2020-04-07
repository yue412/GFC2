#ifndef NGFC2ELEMENTSHAPE_H
#define NGFC2ELEMENTSHAPE_H

#include "Gfc2ElementShape.h"
#include "NGfc2String.h"
#include "NGfc2Shape.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ElementShape: public glodon::objectbufnet::Entity
{
public:
    NGfc2ElementShape();
    NGfc2ElementShape(void* pEntity, bool bOwner);
    void setIdentifier(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getIdentifier();
    bool hasIdentifier();
    NGfc2String^ getIdentifierPtr();
    void setShape(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getShape();
    bool hasShape();
    NGfc2Shape^ getShapePtr();

};
#endif
