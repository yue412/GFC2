#ifndef NGFCBILLDETAIL_H
#define NGFCBILLDETAIL_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcBillDetail.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcBillDetail: public NGfcRoot
{
public:
    NGfcBillDetail();
    NGfcBillDetail(bool bNoCreate);
    void setFloorNum(NGfcInteger nValue);
    NGfcInteger getFloorNum();
    bool hasFloorNum();
    void setEntityID(NGfcInteger nValue);
    NGfcInteger getEntityID();
    bool hasEntityID();
    void setUnit(NGfcString sValue);
    NGfcString getUnit();
    bool hasUnit();
    void setExpress(NGfcString sValue);
    NGfcString getExpress();
    bool hasExpress();
    void setQuantity(NGfcString sValue);
    NGfcString getQuantity();
    bool hasQuantity();
    void setMemo(NGfcString sValue);
    NGfcString getMemo();
    bool hasMemo();

};
#endif
