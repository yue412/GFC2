#ifndef NGFCSTEELDETAIL_H
#define NGFCSTEELDETAIL_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcSteelDetail.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcSteelDetail: public NGfcEntity
{
public:
    NGfcSteelDetail();
    NGfcSteelDetail(gfc::engine::CEntity* pEntity, bool bOwner);
    void setEntityID(NGfcInteger nValue);
    NGfcInteger getEntityID();
    bool hasEntityID();
    void setName(NGfcString sValue);
    NGfcString getName();
    bool hasName();
    void setDesc(NGfcString sValue);
    NGfcString getDesc();
    bool hasDesc();
    void setLevel(NGfcString sValue);
    NGfcString getLevel();
    bool hasLevel();
    void setDia(NGfcInteger nValue);
    NGfcInteger getDia();
    bool hasDia();
    void setNum(NGfcInteger nValue);
    NGfcInteger getNum();
    bool hasNum();
    void setBarLength(NGfcInteger nValue);
    NGfcInteger getBarLength();
    bool hasBarLength();
    void setSingleWeight(NGfcDouble dValue);
    NGfcDouble getSingleWeight();
    bool hasSingleWeight();
    void setTotalWeight(NGfcDouble dValue);
    NGfcDouble getTotalWeight();
    bool hasTotalWeight();
    void setTieinNum(NGfcInteger nValue);
    NGfcInteger getTieinNum();
    bool hasTieinNum();
    void setTieinType(NGfcString sValue);
    NGfcString getTieinType();
    bool hasTieinType();

};
#endif
