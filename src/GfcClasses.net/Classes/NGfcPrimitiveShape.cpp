#include "NGfcPrimitiveShape.h"

using namespace gfc::classes::x3;

NGfcPrimitiveShape::NGfcPrimitiveShape()
{
    m_pEntity = new GfcPrimitiveShape;
    m_bOwner = true;
}

NGfcPrimitiveShape::NGfcPrimitiveShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSolidShape(pEntity, bOwner)
{
}

