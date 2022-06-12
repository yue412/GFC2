#ifndef NGFCRELATIONSHIP_H
#define NGFCRELATIONSHIP_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcRelationShip.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcRelationShip: public NGfcEntity
{
public:
    NGfcRelationShip();
    NGfcRelationShip(gfc::engine::CEntity* pEntity, bool bOwner);
    void setName(NGfcLabel sValue);
    NGfcLabel getName();
    bool hasName();

};
#endif
