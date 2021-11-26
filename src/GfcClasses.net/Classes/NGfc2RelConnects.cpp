#include "NGfc2RelConnects.h"

using namespace gfc::classes::x3;

NGfc2RelConnects::NGfc2RelConnects()
{
    m_pEntity = new Gfc2RelConnects;
    m_bOwner = true;
}

NGfc2RelConnects::NGfc2RelConnects(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2RelationShip(pEntity, bOwner)
{
}

