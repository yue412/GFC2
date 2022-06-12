#ifndef NGFCSURFACETEXTURE_H
#define NGFCSURFACETEXTURE_H

#include "NGfcEntity.h"
#include "GfcClasses\x3\GfcSurfaceTexture.h"
#include "NGfcMatrix.h"
#include "NTypeDef.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfcSurfaceTexture: public NGfcEntity
{
public:
    NGfcSurfaceTexture();
    NGfcSurfaceTexture(gfc::engine::CEntity* pEntity, bool bOwner);
    void setRepeatS(NGfcBoolean bValue);
    NGfcBoolean getRepeatS();
    bool hasRepeatS();
    void setRepeatT(NGfcBoolean bValue);
    NGfcBoolean getRepeatT();
    bool hasRepeatT();
    void setImageFileName(NGfcString sValue);
    NGfcString getImageFileName();
    bool hasImageFileName();
    void setTranfromsMatirx(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getTranfromsMatirx();
    bool hasTranfromsMatirx();
    int getParameterCount();
    void clearParameter();
    void addParameter(NGfcString sValue);
    NGfcString getParameter(int nIndex);

};
#endif
