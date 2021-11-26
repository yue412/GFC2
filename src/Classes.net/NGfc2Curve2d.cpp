#include "NGfc2Curve2d.h"

using namespace gfc::classes::x3;

NGfc2Curve2d::NGfc2Curve2d()
{
    m_pEntity = new Gfc2Curve2d;
    m_bOwner = true;
}

NGfc2Curve2d::NGfc2Curve2d(void* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

