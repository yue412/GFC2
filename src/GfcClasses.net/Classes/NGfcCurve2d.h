#ifndef NGFCCURVE2D_H
#define NGFCCURVE2D_H

#include "NGfcGeometry.h"
#include "GfcClasses\x3\GfcCurve2d.h"

public ref class NGfcCurve2d: public NGfcGeometry
{
public:
    NGfcCurve2d();
    NGfcCurve2d(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
