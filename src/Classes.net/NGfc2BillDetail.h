#ifndef NGFC2BILLDETAIL_H
#define NGFC2BILLDETAIL_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2BillDetail.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2BillDetail: public NGfc2Root
{
public:
    NGfc2BillDetail();
    NGfc2BillDetail(gfc::engine::CEntity* pEntity, bool bOwner);
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
