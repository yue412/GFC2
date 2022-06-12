#ifndef NGFCQUOTATOTAL_H
#define NGFCQUOTATOTAL_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcQuotaTotal.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcQuotaTotal: public NGfcEntity
{
public:
    NGfcQuotaTotal();
    NGfcQuotaTotal(gfc::engine::CEntity* pEntity, bool bOwner);
    void setCode(NGfcString sValue);
    NGfcString getCode();
    bool hasCode();
    void setSubCode(NGfcString sValue);
    NGfcString getSubCode();
    bool hasSubCode();
    void setName(NGfcString sValue);
    NGfcString getName();
    bool hasName();
    void setContent(NGfcString sValue);
    NGfcString getContent();
    bool hasContent();
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
