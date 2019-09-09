#ifndef NGFC2POLARAXISGRID_H
#define NGFC2POLARAXISGRID_H

#include "NGfc2AxisGrid.h"
#include "Gfc2PolarAxisGrid.h"
#include "NGfc2Vector2d.h"
#include "NGfc2AxisDataItem.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2PolarAxisGrid: public NGfc2AxisGrid
{
public:
    NGfc2PolarAxisGrid();
    NGfc2PolarAxisGrid(void* pEntity, bool bOwner);
    void setInsertPt(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getInsertPt();
    bool hasInsertPt();
    NGfc2Vector2d^ getInsertPtPtr();
    void setStartRadius(NGfc2Double dValue);
    NGfc2Double getStartRadius();
    bool hasStartRadius();
    void setClockwise(NGfc2Boolean bValue);
    NGfc2Boolean getClockwise();
    bool hasClockwise();
    int getXKJCount();
    void clearXKJ();
    void addXKJ(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getXKJ(int nIndex);
    NGfc2AxisDataItem^ getXKJPtr(int nIndex);
    int getZJSCount();
    void clearZJS();
    void addZJS(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getZJS(int nIndex);
    NGfc2AxisDataItem^ getZJSPtr(int nIndex);

};
#endif
