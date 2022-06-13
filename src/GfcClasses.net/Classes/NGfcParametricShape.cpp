#include "NGfcParametricShape.h"

using namespace gfc::classes::x3;

NGfcParametricShape::NGfcParametricShape()
{
    m_pEntity = new GfcParametricShape;
    m_bOwner = true;
}

NGfcParametricShape::NGfcParametricShape(bool bNoCreate):
    NGfcShape(bNoCreate)
{
}

