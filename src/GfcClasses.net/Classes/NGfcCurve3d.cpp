#include "NGfcCurve3d.h"

using namespace gfc::classes::x3;

NGfcCurve3d::NGfcCurve3d()
{
    m_pEntity = new GfcCurve3d;
    m_bOwner = true;
}

NGfcCurve3d::NGfcCurve3d(bool bNoCreate):
    NGfcGeometry(bNoCreate)
{
}

