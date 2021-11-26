#include "NGfc2RelDefines.h"

using namespace gfc::classes::x3;

NGfc2RelDefines::NGfc2RelDefines()
{
    m_pEntity = new Gfc2RelDefines;
    m_bOwner = true;
}

NGfc2RelDefines::NGfc2RelDefines(void* pEntity, bool bOwner):
    NGfc2RelationShip(pEntity, bOwner)
{
}

