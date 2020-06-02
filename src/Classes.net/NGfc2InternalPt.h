#ifndef NGFC2INTERNALPT_H
#define NGFC2INTERNALPT_H

#include "Gfc2InternalPt.h"
#include "NGfc2Vector3d.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2InternalPt: public glodon::objectbufnet::Entity
{
public:
    NGfc2InternalPt();
    NGfc2InternalPt(void* pEntity, bool bOwner);
    void setP(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getP();
    bool hasP();
    NGfc2Vector3d^ getPPtr();
    void setTVec(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getTVec();
    bool hasTVec();
    NGfc2Vector3d^ getTVecPtr();
    void setT(NGfc2Double dValue);
    NGfc2Double getT();
    bool hasT();
    void setUV(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getUV();
    bool hasUV();
    NGfc2Vector2d^ getUVPtr();
    void setST(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getST();
    bool hasST();
    NGfc2Vector2d^ getSTPtr();
    void setUVDir(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getUVDir();
    bool hasUVDir();
    NGfc2Vector2d^ getUVDirPtr();
    void setSTDir(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getSTDir();
    bool hasSTDir();
    NGfc2Vector2d^ getSTDirPtr();

};
#endif
