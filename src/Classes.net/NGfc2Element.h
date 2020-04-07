#ifndef NGFC2ELEMENT_H
#define NGFC2ELEMENT_H

#include "NGfc2Object.h"
#include "Gfc2Element.h"
#include "NGfc2Representation.h"
#include "NGfc2ElementShape.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2Element: public NGfc2Object
{
public:
    NGfc2Element();
    NGfc2Element(void* pEntity, bool bOwner);
    void setType(NGfc2Integer nValue);
    NGfc2Integer getType();
    bool hasType();
    int getRepresentationsCount();
    void clearRepresentations();
    void addRepresentations(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getRepresentations(int nIndex);
    NGfc2Representation^ getRepresentationsPtr(int nIndex);
    int getShapesCount();
    void clearShapes();
    void addShapes(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getShapes(int nIndex);
    NGfc2ElementShape^ getShapesPtr(int nIndex);

};
#endif
