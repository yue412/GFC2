#ifndef NGFCPROPERTY_H
#define NGFCPROPERTY_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcProperty.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcProperty: public NGfcRoot
{
public:
    NGfcProperty();
    NGfcProperty(bool bNoCreate);
    void setName(NGfcLabel sValue);
    NGfcLabel getName();
    bool hasName();
    void setCode(NGfcString sValue);
    NGfcString getCode();
    bool hasCode();
    void setExtension(NGfcString sValue);
    NGfcString getExtension();
    bool hasExtension();

};
#endif
