#include "NGfc2ArbitrarySection.h"

using namespace gfc::classes::x3;

NGfc2ArbitrarySection::NGfc2ArbitrarySection()
{
    m_pEntity = new Gfc2ArbitrarySection;
    m_bOwner = true;
}

NGfc2ArbitrarySection::NGfc2ArbitrarySection(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Section(pEntity, bOwner)
{
}

void NGfc2ArbitrarySection::setPoly(gfc::engine::EntityRef nValue)
{
    ((Gfc2ArbitrarySection*)m_pEntity)->setPoly(nValue);
}

gfc::engine::EntityRef NGfc2ArbitrarySection::getPoly()
{
    return ((Gfc2ArbitrarySection*)m_pEntity)->getPoly();
}

bool NGfc2ArbitrarySection::hasPoly()
{
    return ((Gfc2ArbitrarySection*)m_pEntity)->hasPoly();
}

