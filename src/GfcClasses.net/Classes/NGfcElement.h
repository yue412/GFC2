#ifndef NGFCELEMENT_H
#define NGFCELEMENT_H

#include "NGfcObject.h"
#include "GfcClasses\x3\GfcElement.h"
#include "NGfcRepresentation.h"
#include "NGfcElementShape.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcElement: public NGfcObject
{
public:
    NGfcElement();
    NGfcElement(gfc::engine::CEntity* pEntity, bool bOwner);
    void setEType(NGfcLabel sValue);
    NGfcLabel getEType();
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
