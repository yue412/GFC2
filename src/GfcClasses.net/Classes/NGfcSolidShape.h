#ifndef NGFCSOLIDSHAPE_H
#define NGFCSOLIDSHAPE_H

#include "NGfcParametricShape.h"
#include "GfcClasses\x3\GfcSolidShape.h"

public ref class NGfcSolidShape: public NGfcParametricShape
{
public:
    NGfcSolidShape();
    NGfcSolidShape(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
