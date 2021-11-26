#include "NGfc2RectangleHollowSection.h"

using namespace gfc::classes::x3;

NGfc2RectangleHollowSection::NGfc2RectangleHollowSection()
{
    m_pEntity = new Gfc2RectangleHollowSection;
    m_bOwner = true;
}

NGfc2RectangleHollowSection::NGfc2RectangleHollowSection(void* pEntity, bool bOwner):
    NGfc2RectangleSection(pEntity, bOwner)
{
}

void NGfc2RectangleHollowSection::setThickness(NGfc2Double dValue)
{
    ((Gfc2RectangleHollowSection*)m_pEntity)->setThickness(dValue);
}

NGfc2Double NGfc2RectangleHollowSection::getThickness()
{
    return ((Gfc2RectangleHollowSection*)m_pEntity)->getThickness();
}

bool NGfc2RectangleHollowSection::hasThickness()
{
    return ((Gfc2RectangleHollowSection*)m_pEntity)->hasThickness();
}

