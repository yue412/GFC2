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
    void setType(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getType();
    bool hasType();
    NGfc2Label^ getTypePtr();
    int getRepresentationsCount();
    void clearRepresentations();
    void addRepresentations(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRepresentations(int nIndex);
    NGfc2Representation^ getRepresentationsPtr(int nIndex);
    int getShapesCount();
    void clearShapes();
    void addShapes(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getShapes(int nIndex);
    NGfc2ElementShape^ getShapesPtr(int nIndex);

};
#endif
