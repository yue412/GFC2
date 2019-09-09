#ifndef NGFC2CARTESIANAXISGRID_H
#define NGFC2CARTESIANAXISGRID_H

#include "NGfc2AxisGrid.h"
#include "Gfc2CartesianAxisGrid.h"
#include "NGfc2Vector2d.h"
#include "NGfc2AxisDataItem.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2CartesianAxisGrid: public NGfc2AxisGrid
{
public:
    NGfc2CartesianAxisGrid();
    NGfc2CartesianAxisGrid(void* pEntity, bool bOwner);
    void setInsertPt(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getInsertPt();
    bool hasInsertPt();
    NGfc2Vector2d^ getInsertPtPtr();
    void setAxisAngle(NGfc2Double dValue);
    NGfc2Double getAxisAngle();
    bool hasAxisAngle();
    int getSKJCount();
    void clearSKJ();
    void addSKJ(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getSKJ(int nIndex);
    NGfc2AxisDataItem^ getSKJPtr(int nIndex);
    int getZJSCount();
    void clearZJS();
    void addZJS(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getZJS(int nIndex);
    NGfc2AxisDataItem^ getZJSPtr(int nIndex);
    int getYJSCount();
    void clearYJS();
    void addYJS(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getYJS(int nIndex);
    NGfc2AxisDataItem^ getYJSPtr(int nIndex);
    int getXKJCount();
    void clearXKJ();
    void addXKJ(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getXKJ(int nIndex);
    NGfc2AxisDataItem^ getXKJPtr(int nIndex);

};
#endif
