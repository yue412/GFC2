#include "NGfcRelConnects.h"

using namespace gfc::classes::x3;

NGfcRelConnects::NGfcRelConnects()
{
    m_pEntity = new GfcRelConnects;
    m_bOwner = true;
}

NGfcRelConnects::NGfcRelConnects(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcRelationShip(pEntity, bOwner)
{
}

