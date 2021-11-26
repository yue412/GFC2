#ifndef NGFC2STEELDETAIL_H
#define NGFC2STEELDETAIL_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2SteelDetail.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2SteelDetail: public NGfc2Root
{
public:
    NGfc2SteelDetail();
    NGfc2SteelDetail(gfc::engine::CEntity* pEntity, bool bOwner);
    void setEntityID(NGfc2Integer nValue);
    NGfc2Integer getEntityID();
    bool hasEntityID();
    void setName(NGfc2String sValue);
    NGfc2String getName();
    bool hasName();
    void setDesc(NGfc2String sValue);
    NGfc2String getDesc();
    bool hasDesc();
    void setLevel(NGfc2String sValue);
    NGfc2String getLevel();
    bool hasLevel();
    void setDia(NGfc2Integer nValue);
    NGfc2Integer getDia();
    bool hasDia();
    void setNum(NGfc2Integer nValue);
    NGfc2Integer getNum();
    bool hasNum();
    void setBarLength(NGfc2Integer nValue);
    NGfc2Integer getBarLength();
    bool hasBarLength();
    void setSingleWeight(NGfc2Double dValue);
    NGfc2Double getSingleWeight();
    bool hasSingleWeight();
    void setTotalWeight(NGfc2Double dValue);
    NGfc2Double getTotalWeight();
    bool hasTotalWeight();
    void setTieinNum(NGfc2Integer nValue);
    NGfc2Integer getTieinNum();
    bool hasTieinNum();
    void setTieinType(NGfc2String sValue);
    NGfc2String getTieinType();
    bool hasTieinType();

};
#endif
