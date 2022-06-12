#include "NGfcSection.h"

using namespace gfc::classes::x3;

NGfcSection::NGfcSection()
{
    m_pEntity = new GfcSection;
    m_bOwner = true;
}

NGfcSection::NGfcSection(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

