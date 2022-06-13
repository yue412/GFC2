#include "NGfcEllipse3d.h"

using namespace gfc::classes::x3;

NGfcEllipse3d::NGfcEllipse3d()
{
    m_pEntity = new GfcEllipse3d;
    m_bOwner = true;
}

NGfcEllipse3d::NGfcEllipse3d(bool bNoCreate):
    NGfcPlaneCurve3d(bNoCreate)
{
}

