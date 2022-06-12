#include "NGfcBooleanResult.h"

using namespace gfc::classes::x3;

NGfcBooleanResult::NGfcBooleanResult()
{
    m_pEntity = new GfcBooleanResult;
    m_bOwner = true;
}

NGfcBooleanResult::NGfcBooleanResult(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSolidShape(pEntity, bOwner)
{
}

