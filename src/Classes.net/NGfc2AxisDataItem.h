#ifndef NGFC2AXISDATAITEM_H
#define NGFC2AXISDATAITEM_H

#include "Gfc2AxisDataItem.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2AxisDataItem: public glodon::objectbufnet::Entity
{
public:
    NGfc2AxisDataItem();
    NGfc2AxisDataItem(void* pEntity, bool bOwner);
    void setAxisNo(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getAxisNo();
    bool hasAxisNo();
    NGfc2Label^ getAxisNoPtr();
    void setDistance(NGfc2Double dValue);
    NGfc2Double getDistance();
    bool hasDistance();
    void setLevel(NGfc2Integer nValue);
    NGfc2Integer getLevel();
    bool hasLevel();
    void setAxisNoPos(NGfc2AxisNoPosEnum nValue);
    NGfc2AxisNoPosEnum getAxisNoPos();
    bool hasAxisNoPos();
    int getTrimPointsCount();
    void clearTrimPoints();
    void addTrimPoints(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getTrimPoints(int nIndex);
    NGfc2Vector2d^ getTrimPointsPtr(int nIndex);

};
#endif
