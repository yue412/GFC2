#ifndef NGFC2ELEMENT_H
#define NGFC2ELEMENT_H

#include "NGfc2Object.h"
#include "GfcClasses\x3\Gfc2Element.h"
#include "NGfc2Representation.h"
#include "NGfc2ElementShape.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2Element: public NGfc2Object
{
public:
    NGfc2Element();
    NGfc2Element(gfc::engine::CEntity* pEntity, bool bOwner);
    void setEType(NGfc2Label sValue);
    NGfc2Label getEType();
    bool hasEType();
    int getRepresentationsCount();
    void clearRepresentations();
    void addRepresentations(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getRepresentations(int nIndex);
    int getShapesCount();
    void clearShapes();
    void addShapes(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getShapes(int nIndex);

};
#endif
