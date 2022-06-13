#ifndef NGFCSWEEPCURVE3D_H
#define NGFCSWEEPCURVE3D_H

#include "NGfcCurve3d.h"
#include "GfcClasses\x3\GfcSweepCurve3d.h"
#include "NGfcVector3d.h"
#include "NGfcVector2d.h"
#include "NTypeDef.h"

public ref class NGfcSweepCurve3d: public NGfcCurve3d
{
public:
    NGfcSweepCurve3d();
    NGfcSweepCurve3d(bool bNoCreate);
    void setSpine3d(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSpine3d();
    bool hasSpine3d();
    void setReferenceVector(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getReferenceVector();
    bool hasReferenceVector();
    void setPoint(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getPoint();
    bool hasPoint();
    void setSweepType(NGfcSweepType nValue);
    NGfcSweepType getSweepType();
    bool hasSweepType();

};
#endif
