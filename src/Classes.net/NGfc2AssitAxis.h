#ifndef NGFC2ASSITAXIS_H
#define NGFC2ASSITAXIS_H

#include "NGfc2Entity.h"
#include "Gfc2AssitAxis.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2AssitAxis: public NGfc2Entity
{
public:
    NGfc2AssitAxis();
    NGfc2AssitAxis(void* pEntity, bool bOwner);
    void setAxisNo(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getAxisNo();
    bool hasAxisNo();
    NGfc2Label^ getAxisNoPtr();
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
