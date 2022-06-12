#include "NGfcGeometry.h"

using namespace gfc::classes::x3;

NGfcGeometry::NGfcGeometry()
{
    m_pEntity = new GfcGeometry;
    m_bOwner = true;
}

NGfcGeometry::NGfcGeometry(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

