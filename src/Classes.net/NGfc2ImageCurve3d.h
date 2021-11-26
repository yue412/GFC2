#ifndef NGFC2IMAGECURVE3D_H
#define NGFC2IMAGECURVE3D_H

#include "NGfc2Curve3d.h"
#include "GfcClasses\x3\Gfc2ImageCurve3d.h"
#include "NGfc2Curve2d.h"
#include "NGfc2Surface.h"

public ref class NGfc2ImageCurve3d: public NGfc2Curve3d
{
public:
    NGfc2ImageCurve3d();
    NGfc2ImageCurve3d(void* pEntity, bool bOwner);
    void setCurve(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getCurve();
    bool hasCurve();
    void setSurface(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSurface();
    bool hasSurface();

};
#endif
