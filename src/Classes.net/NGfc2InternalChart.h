#ifndef NGFC2INTERNALCHART_H
#define NGFC2INTERNALCHART_H

#include "Gfc2InternalChart.h"
#include "NGfc2InternalPt.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2InternalChart: public glodon::objectbufnet::Entity
{
public:
    NGfc2InternalChart();
    NGfc2InternalChart(void* pEntity, bool bOwner);
    void setTra1(NGfc2Double dValue);
    NGfc2Double getTra1();
    bool hasTra1();
    void setTra2(NGfc2Double dValue);
    NGfc2Double getTra2();
    bool hasTra2();
    void setTra3(NGfc2Double dValue);
    NGfc2Double getTra3();
    bool hasTra3();
    int getIPSCount();
    void clearIPS();
    void addIPS(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getIPS(int nIndex);
    NGfc2InternalPt^ getIPSPtr(int nIndex);

};
#endif
