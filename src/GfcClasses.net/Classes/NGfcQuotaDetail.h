#ifndef NGFCQUOTADETAIL_H
#define NGFCQUOTADETAIL_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcQuotaDetail.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcQuotaDetail: public NGfcEntity
{
public:
    NGfcQuotaDetail();
    NGfcQuotaDetail(gfc::engine::CEntity* pEntity, bool bOwner);
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
