#include "NGfc2BooleanResult.h"

using namespace gfc::classes::x3;

NGfc2BooleanResult::NGfc2BooleanResult()
{
    m_pEntity = new Gfc2BooleanResult;
    m_bOwner = true;
}

NGfc2BooleanResult::NGfc2BooleanResult(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2SolidShape(pEntity, bOwner)
{
}

