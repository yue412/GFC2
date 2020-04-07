#ifndef NGFC2SURFACETEXTURE_H
#define NGFC2SURFACETEXTURE_H

#include "Gfc2SurfaceTexture.h"
#include "NGfc2String.h"
#include "NGfc2Matrix.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2SurfaceTexture: public glodon::objectbufnet::Entity
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
    void setImageFileName(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getImageFileName();
    bool hasImageFileName();
    NGfc2String^ getImageFileNamePtr();
    void setTranfromsMatirx(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getTranfromsMatirx();
    bool hasTranfromsMatirx();
    NGfc2Matrix^ getTranfromsMatirxPtr();
    int getParameterCount();
    void clearParameter();
    void addParameter(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getParameter(int nIndex);
    NGfc2String^ getParameterPtr(int nIndex);

};
#endif
