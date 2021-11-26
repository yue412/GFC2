#include "NGfc2RectangleSection.h"

using namespace gfc::classes::x3;

NGfc2RectangleSection::NGfc2RectangleSection()
{
    m_pEntity = new Gfc2RectangleSection;
    m_bOwner = true;
}

NGfc2RectangleSection::NGfc2RectangleSection(void* pEntity, bool bOwner):
    NGfc2ParameterizedSection(pEntity, bOwner)
{
}

void NGfc2RectangleSection::setXLength(NGfc2Double dValue)
{
    ((Gfc2RectangleSection*)m_pEntity)->setXLength(dValue);
}

NGfc2Double NGfc2RectangleSection::getXLength()
{
    return ((Gfc2RectangleSection*)m_pEntity)->getXLength();
}

bool NGfc2RectangleSection::hasXLength()
{
    return ((Gfc2RectangleSection*)m_pEntity)->hasXLength();
}

void NGfc2RectangleSection::setYLength(NGfc2Double dValue)
{
    ((Gfc2RectangleSection*)m_pEntity)->setYLength(dValue);
}

NGfc2Double NGfc2RectangleSection::getYLength()
{
    return ((Gfc2RectangleSection*)m_pEntity)->getYLength();
}

bool NGfc2RectangleSection::hasYLength()
{
    return ((Gfc2RectangleSection*)m_pEntity)->hasYLength();
}

