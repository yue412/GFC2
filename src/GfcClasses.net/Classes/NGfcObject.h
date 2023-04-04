#ifndef NGFCOBJECT_H
#define NGFCOBJECT_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcObject.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcObject: public NGfcRoot
{
public:
    NGfcObject();
    NGfcObject(bool bNoCreate);
    void setID(NGfcIdentity sValue);
    NGfcIdentity getID();
    bool hasID();
    void setName(NGfcLabel sValue);
    NGfcLabel getName();
    bool hasName();

};
#endif
