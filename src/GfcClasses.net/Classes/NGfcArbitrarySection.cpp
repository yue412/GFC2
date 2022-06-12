#include "NGfcArbitrarySection.h"

using namespace gfc::classes::x3;

NGfcArbitrarySection::NGfcArbitrarySection()
{
    m_pEntity = new GfcArbitrarySection;
    m_bOwner = true;
}

NGfcArbitrarySection::NGfcArbitrarySection(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSection(pEntity, bOwner)
{
}

void NGfcArbitrarySection::setPoly(gfc::engine::EntityRef nValue)
{
    ((GfcArbitrarySection*)m_pEntity)->setPoly(nValue);
}

gfc::engine::EntityRef NGfcArbitrarySection::getPoly()
{
    return ((GfcArbitrarySection*)m_pEntity)->getPoly();
}

bool NGfcArbitrarySection::hasPoly()
{
    return ((GfcArbitrarySection*)m_pEntity)->hasPoly();
}

