#ifndef NGFC2INTERVALD_H
#define NGFC2INTERVALD_H

#include "NGfc2Geometry.h"
#include "GfcClasses\x3\Gfc2Intervald.h"
#include "NTypeDef.h"

public ref class NGfc2Intervald: public NGfc2Geometry
{
public:
    NGfc2Intervald();
    NGfc2Intervald(void* pEntity, bool bOwner);
    void setMin(NGfc2Double dValue);
    NGfc2Double getMin();
    bool hasMin();
    void setMax(NGfc2Double dValue);
    NGfc2Double getMax();
    bool hasMax();

};
#endif
