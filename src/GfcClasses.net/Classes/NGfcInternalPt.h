#ifndef NGFCINTERNALPT_H
#define NGFCINTERNALPT_H

#include "NEntity.h"
#include "GfcClasses\x3\GfcInternalPt.h"
#include "NGfcVector3d.h"
#include "NGfcVector2d.h"
#include "NTypeDef.h"

public ref class NGfcInternalPt: public NEntity
{
public:
    NGfcInternalPt();
    NGfcInternalPt(bool bNoCreate);
    void setP(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getP();
    bool hasP();
    void setTVec(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getTVec();
    bool hasTVec();
    void setT(NGfcDouble dValue);
    NGfcDouble getT();
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
