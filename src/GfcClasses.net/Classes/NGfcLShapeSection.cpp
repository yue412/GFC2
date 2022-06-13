#include "NGfcLShapeSection.h"

using namespace gfc::classes::x3;

NGfcLShapeSection::NGfcLShapeSection()
{
    m_pEntity = new GfcLShapeSection;
    m_bOwner = true;
}

NGfcLShapeSection::NGfcLShapeSection(bool bNoCreate):
    NGfcParameterizedSection(bNoCreate)
{
}

void NGfcLShapeSection::setWidth(NGfcDouble dValue)
{
    ((GfcLShapeSection*)m_pEntity)->setWidth(dValue);
}

NGfcDouble NGfcLShapeSection::getWidth()
{
    return ((GfcLShapeSection*)m_pEntity)->getWidth();
}

bool NGfcLShapeSection::hasWidth()
{
    return ((GfcLShapeSection*)m_pEntity)->hasWidth();
}

void NGfcLShapeSection::setHeight(NGfcDouble dValue)
{
    ((GfcLShapeSection*)m_pEntity)->setHeight(dValue);
}

NGfcDouble NGfcLShapeSection::getHeight()
{
    return ((GfcLShapeSection*)m_pEntity)->getHeight();
}

bool NGfcLShapeSection::hasHeight()
{
    return ((GfcLShapeSection*)m_pEntity)->hasHeight();
}

void NGfcLShapeSection::setThickness1(NGfcDouble dValue)
{
    ((GfcLShapeSection*)m_pEntity)->setThickness1(dValue);
}

NGfcDouble NGfcLShapeSection::getThickness1()
{
    return ((GfcLShapeSection*)m_pEntity)->getThickness1();
}

bool NGfcLShapeSection::hasThickness1()
{
    return ((GfcLShapeSection*)m_pEntity)->hasThickness1();
}

void NGfcLShapeSection::setThickness2(NGfcDouble dValue)
{
    ((GfcLShapeSection*)m_pEntity)->setThickness2(dValue);
}

NGfcDouble NGfcLShapeSection::getThickness2()
{
    return ((GfcLShapeSection*)m_pEntity)->getThickness2();
}

bool NGfcLShapeSection::hasThickness2()
{
    return ((GfcLShapeSection*)m_pEntity)->hasThickness2();
}

