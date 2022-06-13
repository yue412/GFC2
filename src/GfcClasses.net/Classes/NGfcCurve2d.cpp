#include "NGfcCurve2d.h"

using namespace gfc::classes::x3;

NGfcCurve2d::NGfcCurve2d()
{
    m_pEntity = new GfcCurve2d;
    m_bOwner = true;
}

NGfcCurve2d::NGfcCurve2d(bool bNoCreate):
    NGfcGeometry(bNoCreate)
{
}

