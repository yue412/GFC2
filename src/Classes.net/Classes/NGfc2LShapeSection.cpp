#include "NGfc2LShapeSection.h"

using namespace gfc::classes::x3;

NGfc2LShapeSection::NGfc2LShapeSection()
{
    m_pEntity = new Gfc2LShapeSection;
    m_bOwner = true;
}

NGfc2LShapeSection::NGfc2LShapeSection(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2ParameterizedSection(pEntity, bOwner)
{
}

void NGfc2LShapeSection::setWidth(NGfc2Double dValue)
{
    ((Gfc2LShapeSection*)m_pEntity)->setWidth(dValue);
}

NGfc2Double NGfc2LShapeSection::getWidth()
{
    return ((Gfc2LShapeSection*)m_pEntity)->getWidth();
}

bool NGfc2LShapeSection::hasWidth()
{
    return ((Gfc2LShapeSection*)m_pEntity)->hasWidth();
}

void NGfc2LShapeSection::setHeight(NGfc2Double dValue)
{
    ((Gfc2LShapeSection*)m_pEntity)->setHeight(dValue);
}

NGfc2Double NGfc2LShapeSection::getHeight()
{
    return ((Gfc2LShapeSection*)m_pEntity)->getHeight();
}

bool NGfc2LShapeSection::hasHeight()
{
    return ((Gfc2LShapeSection*)m_pEntity)->hasHeight();
}

void NGfc2LShapeSection::setThickness1(NGfc2Double dValue)
{
    ((Gfc2LShapeSection*)m_pEntity)->setThickness1(dValue);
}

NGfc2Double NGfc2LShapeSection::getThickness1()
{
    return ((Gfc2LShapeSection*)m_pEntity)->getThickness1();
}

bool NGfc2LShapeSection::hasThickness1()
{
    return ((Gfc2LShapeSection*)m_pEntity)->hasThickness1();
}

void NGfc2LShapeSection::setThickness2(NGfc2Double dValue)
{
    ((Gfc2LShapeSection*)m_pEntity)->setThickness2(dValue);
}

NGfc2Double NGfc2LShapeSection::getThickness2()
{
    return ((Gfc2LShapeSection*)m_pEntity)->getThickness2();
}

bool NGfc2LShapeSection::hasThickness2()
{
    return ((Gfc2LShapeSection*)m_pEntity)->hasThickness2();
}

