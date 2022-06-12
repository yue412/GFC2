#ifndef NGFCINTERVALD_H
#define NGFCINTERVALD_H

#include "NGfcGeometry.h"
#include "GfcClasses\x3\GfcIntervald.h"
#include "NTypeDef.h"

public ref class NGfcIntervald: public NGfcGeometry
{
public:
    NGfcIntervald();
    NGfcIntervald(gfc::engine::CEntity* pEntity, bool bOwner);
    void setMin(NGfcDouble dValue);
    NGfcDouble getMin();
    bool hasMin();
    void setMax(NGfcDouble dValue);
    NGfcDouble getMax();
    bool hasMax();

};
#endif
