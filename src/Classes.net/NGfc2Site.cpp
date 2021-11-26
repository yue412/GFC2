#include "NGfc2Site.h"

using namespace gfc::classes::x3;

NGfc2Site::NGfc2Site()
{
    m_pEntity = new Gfc2Site;
    m_bOwner = true;
}

NGfc2Site::NGfc2Site(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2SpatialStructureElement(pEntity, bOwner)
{
}

