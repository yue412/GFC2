#ifndef NGFCPHONGAPPEARANCEMATERIAL_H
#define NGFCPHONGAPPEARANCEMATERIAL_H

#include "NGfcAppearanceMaterial.h"
#include "GfcClasses\x3\GfcPHONGAppearanceMaterial.h"
#include "NGfcColor.h"
#include "NTypeDef.h"

public ref class NGfcPHONGAppearanceMaterial: public NGfcAppearanceMaterial
{
public:
    NGfcPHONGAppearanceMaterial();
    NGfcPHONGAppearanceMaterial(bool bNoCreate);
    void setAmbient(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getAmbient();
    bool hasAmbient();
    void setEmissive(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getEmissive();
    bool hasEmissive();
    void setSpecular(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSpecular();
    bool hasSpecular();
    void setEnvironment(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getEnvironment();
    bool hasEnvironment();
    void setShiniess(NGfcDouble dValue);
    NGfcDouble getShiniess();
    bool hasShiniess();

};
#endif
