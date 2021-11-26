#include "NGfc2RepresentationItem.h"

using namespace gfc::classes::x3;

NGfc2RepresentationItem::NGfc2RepresentationItem()
{
    m_pEntity = new Gfc2RepresentationItem;
    m_bOwner = true;
}

NGfc2RepresentationItem::NGfc2RepresentationItem(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

