#ifndef NGFC2SURFACETEXTURE_H
#define NGFC2SURFACETEXTURE_H

#include "NGfc2Root.h"
#include "Gfc2SurfaceTexture.h"
#include "NGfc2Matrix.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class NGfc2SurfaceTexture: public NGfc2Root
{
public:
    NGfc2SurfaceTexture();
    NGfc2SurfaceTexture(void* pEntity, bool bOwner);
    void setRepeatS(NGfc2Boolean bValue);
    NGfc2Boolean getRepeatS();
    bool hasRepeatS();
    void setRepeatT(NGfc2Boolean bValue);
    NGfc2Boolean getRepeatT();
    bool hasRepeatT();
    void setImageFileName(NGfc2String sValue);
    NGfc2String getImageFileName();
    bool hasImageFileName();
    void setTranfromsMatirx(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getTranfromsMatirx();
    bool hasTranfromsMatirx();
    NGfc2Matrix^ getTranfromsMatirxPtr();
    int getParameterCount();
    void clearParameter();
    void addParameter(NGfc2String sValue);
    NGfc2String getParameter(int nIndex);

};
#endif
