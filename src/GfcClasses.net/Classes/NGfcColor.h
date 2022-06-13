#ifndef NGFCCOLOR_H
#define NGFCCOLOR_H

#include "NEntity.h"
#include "GfcClasses\x3\GfcColor.h"
#include "NTypeDef.h"

public ref class NGfcColor: public NEntity
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
    void setAlpha(NGfcInteger nValue);
    NGfcInteger getAlpha();
    bool hasAlpha();

};
#endif
