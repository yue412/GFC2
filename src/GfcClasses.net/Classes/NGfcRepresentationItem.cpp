#include "NGfcRepresentationItem.h"

using namespace gfc::classes::x3;

NGfcRepresentationItem::NGfcRepresentationItem()
{
    m_pEntity = new GfcRepresentationItem;
    m_bOwner = true;
}

NGfcRepresentationItem::NGfcRepresentationItem(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

