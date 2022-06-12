#include "NGfcSurface.h"

using namespace gfc::classes::x3;

NGfcSurface::NGfcSurface()
{
    m_pEntity = new GfcSurface;
    m_bOwner = true;
}

NGfcSurface::NGfcSurface(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcGeometry(pEntity, bOwner)
{
}

