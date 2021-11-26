#include "NGfc2RelDecomposes.h"

using namespace gfc::classes::x3;

NGfc2RelDecomposes::NGfc2RelDecomposes()
{
    m_pEntity = new Gfc2RelDecomposes;
    m_bOwner = true;
}

NGfc2RelDecomposes::NGfc2RelDecomposes(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2RelationShip(pEntity, bOwner)
{
}

