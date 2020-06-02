#ifndef NGFC2ELEMENT_H
#define NGFC2ELEMENT_H

#include "NGfc2Object.h"
#include "Gfc2Element.h"
#include "NGfc2Representation.h"
#include "NGfc2ElementShape.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2Element: public NGfc2Object
{
public:
    NGfc2Element();
    NGfc2Element(void* pEntity, bool bOwner);
    void setType(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getType();
    bool hasType();
    NGfc2Label^ getTypePtr();
    int getRepresentationsCount();
    void clearRepresentations();
    void addRepresentations(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getRepresentations(int nIndex);
    NGfc2Representation^ getRepresentationsPtr(int nIndex);
    int getShapesCount();
    void clearShapes();
    void addShapes(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getShapes(int nIndex);
    NGfc2ElementShape^ getShapesPtr(int nIndex);

};
#endif
