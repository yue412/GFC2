#include "NGfcRectangleSection.h"

using namespace gfc::classes::x3;

NGfcRectangleSection::NGfcRectangleSection()
{
    m_pEntity = new GfcRectangleSection;
    m_bOwner = true;
}

NGfcRectangleSection::NGfcRectangleSection(bool bNoCreate):
    NGfcParameterizedSection(bNoCreate)
{
}

void NGfcRectangleSection::setXLength(NGfcDouble dValue)
{
    ((GfcRectangleSection*)m_pEntity)->setXLength(dValue);
}

NGfcDouble NGfcRectangleSection::getXLength()
{
    return ((GfcRectangleSection*)m_pEntity)->getXLength();
}

bool NGfcRectangleSection::hasXLength()
{
    return ((GfcRectangleSection*)m_pEntity)->hasXLength();
}

void NGfcRectangleSection::setYLength(NGfcDouble dValue)
{
    ((GfcRectangleSection*)m_pEntity)->setYLength(dValue);
}

NGfcDouble NGfcRectangleSection::getYLength()
{
    return ((GfcRectangleSection*)m_pEntity)->getYLength();
}

bool NGfcRectangleSection::hasYLength()
{
    return ((GfcRectangleSection*)m_pEntity)->hasYLength();
}

