#ifndef NGFC2IMAGECURVE3D_H
#define NGFC2IMAGECURVE3D_H

#include "NGfc2Curve3d.h"
#include "Gfc2ImageCurve3d.h"
#include "NGfc2Curve2d.h"
#include "NGfc2Surface.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2ImageCurve3d: public NGfc2Curve3d
{
public:
    NGfc2ImageCurve3d();
    NGfc2ImageCurve3d(void* pEntity, bool bOwner);
    void setCurve(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getCurve();
    bool hasCurve();
    NGfc2Curve2d^ getCurvePtr();
    void setSurface(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getSurface();
    bool hasSurface();
    NGfc2Surface^ getSurfacePtr();

};
#endif
