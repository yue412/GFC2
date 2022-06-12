#ifndef NGFCREPRESENTATION_H
#define NGFCREPRESENTATION_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcRepresentation.h"
#include "NGfcRepresentationItem.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcRepresentation: public NGfcEntity
{
public:
    NGfcRepresentation();
    NGfcRepresentation(gfc::engine::CEntity* pEntity, bool bOwner);
    void setIdentifier(NGfcString sValue);
    NGfcString getIdentifier();
    bool hasIdentifier();
    int getitemsCount();
    void clearitems();
    void additems(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getitems(int nIndex);

};
#endif
