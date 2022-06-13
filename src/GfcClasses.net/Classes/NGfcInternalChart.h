#ifndef NGFCINTERNALCHART_H
#define NGFCINTERNALCHART_H

#include "NEntity.h"
#include "GfcClasses\x3\GfcInternalChart.h"
#include "NGfcInternalPt.h"
#include "NTypeDef.h"

public ref class NGfcInternalChart: public NEntity
{
public:
    NGfcInternalChart();
    NGfcInternalChart(bool bNoCreate);
    void setTra1(NGfcDouble dValue);
    NGfcDouble getTra1();
    bool hasTra1();
    void setTra2(NGfcDouble dValue);
    NGfcDouble getTra2();
    bool hasTra2();
    void setTra3(NGfcDouble dValue);
    NGfcDouble getTra3();
    bool hasTra3();
    int getIPSCount();
    void clearIPS();
    void addIPS(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getIPS(int nIndex);

};
#endif
