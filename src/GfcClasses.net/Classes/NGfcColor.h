#ifndef NGFCCOLOR_H
#define NGFCCOLOR_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcColor.h"
#include "NTypeDef.h"

public ref class NGfcColor: public NGfcEntity
{
public:
    NGfcColor();
    NGfcColor(gfc::engine::CEntity* pEntity, bool bOwner);
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
