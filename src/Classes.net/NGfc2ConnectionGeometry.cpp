#include "NGfc2ConnectionGeometry.h"

using namespace gfc::classes::x3;

NGfc2ConnectionGeometry::NGfc2ConnectionGeometry()
{
    m_pEntity = new Gfc2ConnectionGeometry;
    m_bOwner = true;
}

NGfc2ConnectionGeometry::NGfc2ConnectionGeometry(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

