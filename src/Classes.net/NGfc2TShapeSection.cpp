#include "NGfc2TShapeSection.h"

using namespace gfc::classes::x3;

NGfc2TShapeSection::NGfc2TShapeSection()
{
    m_pEntity = new Gfc2TShapeSection;
    m_bOwner = true;
}

NGfc2TShapeSection::NGfc2TShapeSection(void* pEntity, bool bOwner):
    NGfc2ParameterizedSection(pEntity, bOwner)
{
}

void NGfc2TShapeSection::setWidth(NGfc2Double dValue)
{
    ((Gfc2TShapeSection*)m_pEntity)->setWidth(dValue);
}

NGfc2Double NGfc2TShapeSection::getWidth()
{
    return ((Gfc2TShapeSection*)m_pEntity)->getWidth();
}

bool NGfc2TShapeSection::hasWidth()
{
    return ((Gfc2TShapeSection*)m_pEntity)->hasWidth();
}

void NGfc2TShapeSection::setHeight(NGfc2Double dValue)
{
    ((Gfc2TShapeSection*)m_pEntity)->setHeight(dValue);
}

NGfc2Double NGfc2TShapeSection::getHeight()
{
    return ((Gfc2TShapeSection*)m_pEntity)->getHeight();
}

bool NGfc2TShapeSection::hasHeight()
{
    return ((Gfc2TShapeSection*)m_pEntity)->hasHeight();
}

void NGfc2TShapeSection::setThickness1(NGfc2Double dValue)
{
    ((Gfc2TShapeSection*)m_pEntity)->setThickness1(dValue);
}

NGfc2Double NGfc2TShapeSection::getThickness1()
{
    return ((Gfc2TShapeSection*)m_pEntity)->getThickness1();
}

bool NGfc2TShapeSection::hasThickness1()
{
    return ((Gfc2TShapeSection*)m_pEntity)->hasThickness1();
}

void NGfc2TShapeSection::setThickness2(NGfc2Double dValue)
{
    ((Gfc2TShapeSection*)m_pEntity)->setThickness2(dValue);
}

NGfc2Double NGfc2TShapeSection::getThickness2()
{
    return ((Gfc2TShapeSection*)m_pEntity)->getThickness2();
}

bool NGfc2TShapeSection::hasThickness2()
{
    return ((Gfc2TShapeSection*)m_pEntity)->hasThickness2();
}

void NGfc2TShapeSection::setLeftWidth(NGfc2Double dValue)
{
    ((Gfc2TShapeSection*)m_pEntity)->setLeftWidth(dValue);
}

NGfc2Double NGfc2TShapeSection::getLeftWidth()
{
    return ((Gfc2TShapeSection*)m_pEntity)->getLeftWidth();
}

bool NGfc2TShapeSection::hasLeftWidth()
{
    return ((Gfc2TShapeSection*)m_pEntity)->hasLeftWidth();
}

