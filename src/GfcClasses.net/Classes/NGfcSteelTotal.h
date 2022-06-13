#ifndef NGFCSTEELTOTAL_H
#define NGFCSTEELTOTAL_H

#include "NEntity.h"
#include "GfcClasses\x3\GfcSteelTotal.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcSteelTotal: public NEntity
{
public:
    NGfcSteelTotal();
    NGfcSteelTotal(bool bNoCreate);
    void setCompType(NGfcString sValue);
    NGfcString getCompType();
    bool hasCompType();
    void setLevel(NGfcString sValue);
    NGfcString getLevel();
    bool hasLevel();
    void setDia(NGfcInteger nValue);
    NGfcInteger getDia();
    bool hasDia();
    void setWeight(NGfcDouble dValue);
    NGfcDouble getWeight();
    bool hasWeight();
    void setUnit(NGfcString sValue);
    NGfcString getUnit();
    bool hasUnit();

};
#endif
