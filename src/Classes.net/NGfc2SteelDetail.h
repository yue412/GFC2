#ifndef NGFC2STEELDETAIL_H
#define NGFC2STEELDETAIL_H

#include "Gfc2SteelDetail.h"
#include "NGfc2String.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SteelDetail: public glodon::objectbufnet::Entity
{
public:
    NGfc2SteelDetail();
    NGfc2SteelDetail(void* pEntity, bool bOwner);
    void setEntityID(NGfc2Integer nValue);
    NGfc2Integer getEntityID();
    bool hasEntityID();
    void setName(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getName();
    bool hasName();
    NGfc2String^ getNamePtr();
    void setDesc(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getDesc();
    bool hasDesc();
    NGfc2String^ getDescPtr();
    void setLevel(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getLevel();
    bool hasLevel();
    NGfc2String^ getLevelPtr();
    void setDia(NGfc2Integer nValue);
    NGfc2Integer getDia();
    bool hasDia();
    void setNum(NGfc2Integer nValue);
    NGfc2Integer getNum();
    bool hasNum();
    void setLength(NGfc2Integer nValue);
    NGfc2Integer getLength();
    bool hasLength();
    void setSingleWeight(NGfc2Double dValue);
    NGfc2Double getSingleWeight();
    bool hasSingleWeight();
    void setTotalWeight(NGfc2Double dValue);
    NGfc2Double getTotalWeight();
    bool hasTotalWeight();
    void setTieinNum(NGfc2Integer nValue);
    NGfc2Integer getTieinNum();
    bool hasTieinNum();
    void setTieinType(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getTieinType();
    bool hasTieinType();
    NGfc2String^ getTieinTypePtr();

};
#endif
