#include "NGfcSite.h"

using namespace gfc::classes::x3;

NGfcSite::NGfcSite()
{
    m_pEntity = new GfcSite;
    m_bOwner = true;
}

NGfcSite::NGfcSite(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSpatialStructureElement(pEntity, bOwner)
{
}

