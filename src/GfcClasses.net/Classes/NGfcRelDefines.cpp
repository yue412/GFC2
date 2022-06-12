#include "NGfcRelDefines.h"

using namespace gfc::classes::x3;

NGfcRelDefines::NGfcRelDefines()
{
    m_pEntity = new GfcRelDefines;
    m_bOwner = true;
}

NGfcRelDefines::NGfcRelDefines(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcRelationShip(pEntity, bOwner)
{
}

