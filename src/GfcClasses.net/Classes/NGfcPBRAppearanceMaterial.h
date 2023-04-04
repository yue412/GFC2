#ifndef NGFCPBRAPPEARANCEMATERIAL_H
#define NGFCPBRAPPEARANCEMATERIAL_H

#include "NGfcAppearanceMaterial.h"
#include "GfcClasses\x3\GfcPBRAppearanceMaterial.h"
#include "NTypeDef.h"

public ref class NGfcPBRAppearanceMaterial: public NGfcAppearanceMaterial
{
public:
    NGfcPBRAppearanceMaterial();
    NGfcPBRAppearanceMaterial(bool bNoCreate);
    void setMetalness(NGfcDouble dValue);
    NGfcDouble getMetalness();
    bool hasMetalness();
    void setRoughness(NGfcDouble dValue);
    NGfcDouble getRoughness();
    bool hasRoughness();

};
#endif
