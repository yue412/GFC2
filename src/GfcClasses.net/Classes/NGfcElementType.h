#ifndef NGFCELEMENTTYPE_H
#define NGFCELEMENTTYPE_H

#include "NGfcObject.h"
#include "GfcClasses\x3\GfcElementType.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcElementType: public NGfcObject
{
public:
    NGfcElementType();
    NGfcElementType(bool bNoCreate);
    void setEType(NGfcLabel sValue);
    NGfcLabel getEType();
    bool hasEType();

};
#endif
