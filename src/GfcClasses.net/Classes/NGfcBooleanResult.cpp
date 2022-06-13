#include "NGfcBooleanResult.h"

using namespace gfc::classes::x3;

NGfcBooleanResult::NGfcBooleanResult()
{
    m_pEntity = new GfcBooleanResult;
    m_bOwner = true;
}

NGfcBooleanResult::NGfcBooleanResult(bool bNoCreate):
    NGfcSolidShape(bNoCreate)
{
}

