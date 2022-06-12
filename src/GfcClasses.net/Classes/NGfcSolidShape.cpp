#include "NGfcSolidShape.h"

using namespace gfc::classes::x3;

NGfcSolidShape::NGfcSolidShape()
{
    m_pEntity = new GfcSolidShape;
    m_bOwner = true;
}

NGfcSolidShape::NGfcSolidShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcParametricShape(pEntity, bOwner)
{
}

