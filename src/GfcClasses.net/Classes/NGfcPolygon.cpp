#include "NGfcPolygon.h"

using namespace gfc::classes::x3;

NGfcPolygon::NGfcPolygon()
{
    m_pEntity = new GfcPolygon;
    m_bOwner = true;
}

NGfcPolygon::NGfcPolygon(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcTopology(pEntity, bOwner)
{
}

