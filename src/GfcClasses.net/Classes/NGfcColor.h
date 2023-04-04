#ifndef NGFCCOLOR_H
#define NGFCCOLOR_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcColor.h"
#include "NTypeDef.h"

public ref class NGfcColor: public NGfcRoot
{
public:
    NGfcColor();
    NGfcColor(bool bNoCreate);
    void setRed(NGfcInteger nValue);
    NGfcInteger getRed();
    bool hasRed();
    void setGreen(NGfcInteger nValue);
    NGfcInteger getGreen();
    bool hasGreen();
    void setBlue(NGfcInteger nValue);
    NGfcInteger getBlue();
    bool hasBlue();

};
#endif
