#include "NGfcConnectionGeometry.h"

using namespace gfc::classes::x3;

NGfcConnectionGeometry::NGfcConnectionGeometry()
{
    m_pEntity = new GfcConnectionGeometry;
    m_bOwner = true;
}

NGfcConnectionGeometry::NGfcConnectionGeometry(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

