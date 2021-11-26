#include "NGfc2Surface.h"

using namespace gfc::classes::x3;

NGfc2Surface::NGfc2Surface()
{
    m_pEntity = new Gfc2Surface;
    m_bOwner = true;
}

NGfc2Surface::NGfc2Surface(void* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

