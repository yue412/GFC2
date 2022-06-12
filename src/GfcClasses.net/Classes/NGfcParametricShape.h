#ifndef NGFCPARAMETRICSHAPE_H
#define NGFCPARAMETRICSHAPE_H

#include "NGfcShape.h"
#include "GfcClasses\x3\GfcParametricShape.h"

public ref class NGfcParametricShape: public NGfcShape
{
public:
    NGfcParametricShape();
    NGfcParametricShape(gfc::engine::CEntity* pEntity, bool bOwner);

};
#endif
