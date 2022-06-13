#include "NGfcRectangleHollowSection.h"

using namespace gfc::classes::x3;

NGfcRectangleHollowSection::NGfcRectangleHollowSection()
{
    m_pEntity = new GfcRectangleHollowSection;
    m_bOwner = true;
}

NGfcRectangleHollowSection::NGfcRectangleHollowSection(bool bNoCreate):
    NGfcRectangleSection(bNoCreate)
{
}

void NGfcRectangleHollowSection::setThickness(NGfcDouble dValue)
{
    ((GfcRectangleHollowSection*)m_pEntity)->setThickness(dValue);
}

NGfcDouble NGfcRectangleHollowSection::getThickness()
{
    return ((GfcRectangleHollowSection*)m_pEntity)->getThickness();
}

bool NGfcRectangleHollowSection::hasThickness()
{
    return ((GfcRectangleHollowSection*)m_pEntity)->hasThickness();
}

