#ifndef NGFCIMAGECURVE3D_H
#define NGFCIMAGECURVE3D_H

#include "NGfcCurve3d.h"
#include "GfcClasses\x3\GfcImageCurve3d.h"
#include "NGfcCurve2d.h"
#include "NGfcSurface.h"

public ref class NGfcImageCurve3d: public NGfcCurve3d
{
public:
    NGfcImageCurve3d();
    NGfcImageCurve3d(gfc::engine::CEntity* pEntity, bool bOwner);
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();
    void setSurface(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSurface();
    bool hasSurface();

};
#endif
