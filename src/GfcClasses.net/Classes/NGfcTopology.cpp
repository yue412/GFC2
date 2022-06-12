#include "NGfcTopology.h"

using namespace gfc::classes::x3;

NGfcTopology::NGfcTopology()
{
    m_pEntity = new GfcTopology;
    m_bOwner = true;
}

NGfcTopology::NGfcTopology(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcGeometry(pEntity, bOwner)
{
}

