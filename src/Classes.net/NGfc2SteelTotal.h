#ifndef NGFC2STEELTOTAL_H
#define NGFC2STEELTOTAL_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2SteelTotal.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2SteelTotal: public NGfc2Root
{
public:
    NGfc2SteelTotal();
    NGfc2SteelTotal(void* pEntity, bool bOwner);
    void setCompType(NGfc2String sValue);
    NGfc2String getCompType();
    bool hasCompType();
    void setLevel(NGfc2String sValue);
    NGfc2String getLevel();
    bool hasLevel();
    void setDia(NGfc2Integer nValue);
    NGfc2Integer getDia();
    bool hasDia();
    void setWeight(NGfc2Double dValue);
    NGfc2Double getWeight();
    bool hasWeight();
    void setUnit(NGfc2String sValue);
    NGfc2String getUnit();
    bool hasUnit();

};
#endif
