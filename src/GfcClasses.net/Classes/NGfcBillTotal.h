#ifndef NGFCBILLTOTAL_H
#define NGFCBILLTOTAL_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcBillTotal.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcBillTotal: public NGfcEntity
{
public:
    NGfcBillTotal();
    NGfcBillTotal(gfc::engine::CEntity* pEntity, bool bOwner);
    void setCode(NGfcString sValue);
    NGfcString getCode();
    bool hasCode();
    void setName(NGfcString sValue);
    NGfcString getName();
    bool hasName();
    void setAttr(NGfcString sValue);
    NGfcString getAttr();
    bool hasAttr();
    void setQuantityType(NGfcInteger nValue);
    NGfcInteger getQuantityType();
    bool hasQuantityType();
    void setUnit(NGfcString sValue);
    NGfcString getUnit();
    bool hasUnit();
    void setQuantity(NGfcString sValue);
    NGfcString getQuantity();
    bool hasQuantity();
    void setMemo(NGfcString sValue);
    NGfcString getMemo();
    bool hasMemo();

};
#endif
