#ifndef NGFCREPRESENTATION_H
#define NGFCREPRESENTATION_H

#include "NEntity.h"
#include "GfcClasses\x3\GfcRepresentation.h"
#include "NGfcRepresentationItem.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcRepresentation: public NEntity
{
public:
    NGfcRepresentation();
    NGfcRepresentation(bool bNoCreate);
    void setIdentifier(NGfcString sValue);
    NGfcString getIdentifier();
    bool hasIdentifier();
    int getitemsCount();
    void clearitems();
    void additems(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getitems(int nIndex);

};
#endif
