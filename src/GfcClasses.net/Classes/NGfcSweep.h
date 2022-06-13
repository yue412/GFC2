#ifndef NGFCSWEEP_H
#define NGFCSWEEP_H

#include "NGfcSurface.h"
#include "GfcClasses\x3\GfcSweep.h"
#include "NGfcCurve2d.h"
#include "NGfcCurve3d.h"
#include "NGfcVector3d.h"
#include "NTypeDef.h"

public ref class NGfcSweep: public NGfcSurface
{
public:
    NGfcSweep();
    NGfcSweep(bool bNoCreate);
    void setProfile(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getProfile();
    bool hasProfile();
    void setSpine3d(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSpine3d();
    bool hasSpine3d();
    void setReferenceVector(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getReferenceVector();
    bool hasReferenceVector();
    void setSweepType(NGfcSweepType nValue);
    NGfcSweepType getSweepType();
    bool hasSweepType();

};
#endif
