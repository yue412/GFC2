#include "NGfc2ConnectionGeometry.h"

using namespace gfc::classes::x3;

NGfc2ConnectionGeometry::NGfc2ConnectionGeometry()
{
    m_pEntity = new Gfc2ConnectionGeometry;
    m_bOwner = true;
}

NGfc2ConnectionGeometry::NGfc2ConnectionGeometry(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

