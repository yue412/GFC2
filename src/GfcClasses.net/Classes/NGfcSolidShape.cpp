#include "NGfcSolidShape.h"

using namespace gfc::classes::x3;

NGfcSolidShape::NGfcSolidShape()
{
    m_pEntity = new GfcSolidShape;
    m_bOwner = true;
}

NGfcSolidShape::NGfcSolidShape(bool bNoCreate):
    NGfcParametricShape(bNoCreate)
{
}

