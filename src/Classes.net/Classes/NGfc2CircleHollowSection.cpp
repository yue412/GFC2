#include "NGfc2CircleHollowSection.h"

using namespace gfc::classes::x3;

NGfc2CircleHollowSection::NGfc2CircleHollowSection()
{
    m_pEntity = new Gfc2CircleHollowSection;
    m_bOwner = true;
}

NGfc2CircleHollowSection::NGfc2CircleHollowSection(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2CircleSection(pEntity, bOwner)
{
}

void NGfc2CircleHollowSection::setThickness(NGfc2Double dValue)
{
    ((Gfc2CircleHollowSection*)m_pEntity)->setThickness(dValue);
}

NGfc2Double NGfc2CircleHollowSection::getThickness()
{
    return ((Gfc2CircleHollowSection*)m_pEntity)->getThickness();
}

bool NGfc2CircleHollowSection::hasThickness()
{
    return ((Gfc2CircleHollowSection*)m_pEntity)->hasThickness();
}

