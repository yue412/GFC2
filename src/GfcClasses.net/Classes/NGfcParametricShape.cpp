#include "NGfcParametricShape.h"

using namespace gfc::classes::x3;

NGfcParametricShape::NGfcParametricShape()
{
    m_pEntity = new GfcParametricShape;
    m_bOwner = true;
}

NGfcParametricShape::NGfcParametricShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcShape(pEntity, bOwner)
{
}

