#ifndef NGFCOBJECT_H
#define NGFCOBJECT_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcObject.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcObject: public NGfcEntity
{
public:
    NGfcObject();
    NGfcObject(gfc::engine::CEntity* pEntity, bool bOwner);
    void setID(NGfcIdentity sValue);
    NGfcIdentity getID();
    bool hasID();
    void setName(NGfcLabel sValue);
    NGfcLabel getName();
    bool hasName();

};
#endif
