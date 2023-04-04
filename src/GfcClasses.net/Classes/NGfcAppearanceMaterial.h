#ifndef NGFCAPPEARANCEMATERIAL_H
#define NGFCAPPEARANCEMATERIAL_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcAppearanceMaterial.h"
#include "NGfcColor.h"
#include "NGfcSurfaceTexture.h"
#include "NTypeDef.h"

public ref class NGfcAppearanceMaterial: public NGfcRoot
{
public:
    NGfcAppearanceMaterial();
    NGfcAppearanceMaterial(bool bNoCreate);
    void setColor(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getColor();
    bool hasColor();
    void setDoubleSide(NGfcBoolean bValue);
    NGfcBoolean getDoubleSide();
    bool hasDoubleSide();
    void setOpacity(NGfcDouble dValue);
    NGfcDouble getOpacity();
    bool hasOpacity();
    int getTexturesCount();
    void clearTextures();
    void addTextures(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getTextures(int nIndex);

};
#endif
