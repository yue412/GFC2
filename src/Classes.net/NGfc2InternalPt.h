#ifndef NGFC2INTERNALPT_H
#define NGFC2INTERNALPT_H

#include "NGfc2Root.h"
#include "GfcClasses\x3\Gfc2InternalPt.h"
#include "NGfc2Vector3d.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"

public ref class NGfc2InternalPt: public NGfc2Root
{
public:
    NGfc2InternalPt();
    NGfc2InternalPt(gfc::engine::CEntity* pEntity, bool bOwner);
    void setP(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getP();
    bool hasP();
    void setTVec(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getTVec();
    bool hasTVec();
    void setT(NGfc2Double dValue);
    NGfc2Double getT();
    bool hasT();
    void setUV(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getUV();
    bool hasUV();
    void setST(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getST();
    bool hasST();
    void setUVDir(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getUVDir();
    bool hasUVDir();
    void setSTDir(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSTDir();
    bool hasSTDir();

};
#endif
