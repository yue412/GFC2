#ifndef NGFC2BILLTOTAL_H
#define NGFC2BILLTOTAL_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2BillTotal.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2BillTotal: public NGfc2Root
{
public:
    NGfc2BillTotal();
    NGfc2BillTotal(void* pEntity, bool bOwner);
    void setCode(NGfc2String sValue);
    NGfc2String getCode();
    bool hasCode();
    void setName(NGfc2String sValue);
    NGfc2String getName();
    bool hasName();
    void setAttr(NGfc2String sValue);
    NGfc2String getAttr();
    bool hasAttr();
    void setQuantityType(NGfc2Integer nValue);
    NGfc2Integer getQuantityType();
    bool hasQuantityType();
    void setUnit(NGfc2String sValue);
    NGfc2String getUnit();
    bool hasUnit();
    void setQuantity(NGfc2String sValue);
    NGfc2String getQuantity();
    bool hasQuantity();
    void setMemo(NGfc2String sValue);
    NGfc2String getMemo();
    bool hasMemo();

};
#endif
