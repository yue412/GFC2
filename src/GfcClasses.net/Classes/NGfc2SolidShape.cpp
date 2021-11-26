#include "NGfc2SolidShape.h"

using namespace gfc::classes::x3;

NGfc2SolidShape::NGfc2SolidShape()
{
    m_pEntity = new Gfc2SolidShape;
    m_bOwner = true;
}

NGfc2SolidShape::NGfc2SolidShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2ParametricShape(pEntity, bOwner)
{
}

