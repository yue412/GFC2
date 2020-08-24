#ifndef NGFC2QUOTADETAIL_H
#define NGFC2QUOTADETAIL_H

#include "Gfc2QuotaDetail.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2QuotaDetail: public glodon::objectbufnet::Entity
{
public:
    NGfc2QuotaDetail();
    NGfc2QuotaDetail(void* pEntity, bool bOwner);
    void setFloorNum(NGfc2Integer nValue);
    NGfc2Integer getFloorNum();
    bool hasFloorNum();
    void setEntityID(NGfc2Integer nValue);
    NGfc2Integer getEntityID();
    bool hasEntityID();
    void setUnit(NGfc2String sValue);
    NGfc2String getUnit();
    bool hasUnit();
    void setExpress(NGfc2String sValue);
    NGfc2String getExpress();
    bool hasExpress();
    void setQuantity(NGfc2String sValue);
    NGfc2String getQuantity();
    bool hasQuantity();
    void setMemo(NGfc2String sValue);
    NGfc2String getMemo();
    bool hasMemo();

};
#endif
