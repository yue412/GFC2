#ifndef NGFC2INTERNALPT_H
#define NGFC2INTERNALPT_H

#include "Gfc2InternalPt.h"
#include "NGfc2Vector3d.h"
#include "NGfc2Vector2d.h"
#include "NTypeDef.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2InternalPt: public glodon::objectbufnet::Entity
{
public:
    NGfc2InternalPt();
    NGfc2InternalPt(void* pEntity, bool bOwner);
    void setP(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getP();
    bool hasP();
    NGfc2Vector3d^ getPPtr();
    void setTVec(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getTVec();
    bool hasTVec();
    NGfc2Vector3d^ getTVecPtr();
    void setT(NGfc2Double dValue);
    NGfc2Double getT();
    bool hasT();
    void setUV(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getUV();
    bool hasUV();
    NGfc2Vector2d^ getUVPtr();
    void setST(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getST();
    bool hasST();
    NGfc2Vector2d^ getSTPtr();
    void setUVDir(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getUVDir();
    bool hasUVDir();
    NGfc2Vector2d^ getUVDirPtr();
    void setSTDir(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getSTDir();
    bool hasSTDir();
    NGfc2Vector2d^ getSTDirPtr();

};
#endif
