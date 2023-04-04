#ifndef NGFCSURFACETEXTURE_H
#define NGFCSURFACETEXTURE_H

#include "NGfcRoot.h"
#include "GfcClasses\x3\GfcSurfaceTexture.h"
#include "NGfcMatrix.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcSurfaceTexture: public NGfcRoot
{
public:
    NGfcSurfaceTexture();
    NGfcSurfaceTexture(bool bNoCreate);
    void setRepeatS(NGfcBoolean bValue);
    NGfcBoolean getRepeatS();
    bool hasRepeatS();
    void setRepeatT(NGfcBoolean bValue);
    NGfcBoolean getRepeatT();
    bool hasRepeatT();
    void setImageURL(NGfcString sValue);
    NGfcString getImageURL();
    bool hasImageURL();
    void setTranfromsMatirx(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getTranfromsMatirx();
    bool hasTranfromsMatirx();
    void setTextureType(NGfcTextureType nValue);
    NGfcTextureType getTextureType();
    bool hasTextureType();

};
#endif
