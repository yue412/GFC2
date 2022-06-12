#include "NGfcArc3d.h"

using namespace gfc::classes::x3;

NGfcArc3d::NGfcArc3d()
{
    m_pEntity = new GfcArc3d;
    m_bOwner = true;
}

NGfcArc3d::NGfcArc3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcPlaneCurve3d(pEntity, bOwner)
{
}

