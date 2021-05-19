#ifndef NGFC2QUOTATOTAL_H
#define NGFC2QUOTATOTAL_H

#include "NGfc2Root.h"
#include "Gfc2QuotaTotal.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2QuotaTotal: public NGfc2Root
{
public:
    NGfc2QuotaTotal();
    NGfc2QuotaTotal(void* pEntity, bool bOwner);
    void setCode(NGfc2String sValue);
    NGfc2String getCode();
    bool hasCode();
    void setSubCode(NGfc2String sValue);
    NGfc2String getSubCode();
    bool hasSubCode();
    void setName(NGfc2String sValue);
    NGfc2String getName();
    bool hasName();
    void setContent(NGfc2String sValue);
    NGfc2String getContent();
    bool hasContent();
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
