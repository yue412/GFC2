#ifndef NGFCPROPERTY_H
#define NGFCPROPERTY_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcProperty.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcProperty: public NGfcEntity
{
public:
    NGfcProperty();
    NGfcProperty(gfc::engine::CEntity* pEntity, bool bOwner);
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
