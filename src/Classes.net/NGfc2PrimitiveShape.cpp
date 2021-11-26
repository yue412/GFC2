#include "NGfc2PrimitiveShape.h"

using namespace gfc::classes::x3;

NGfc2PrimitiveShape::NGfc2PrimitiveShape()
{
    m_pEntity = new Gfc2PrimitiveShape;
    m_bOwner = true;
}

NGfc2PrimitiveShape::NGfc2PrimitiveShape(void* pEntity, bool bOwner):
    NGfc2SolidShape(pEntity, bOwner)
{
}

