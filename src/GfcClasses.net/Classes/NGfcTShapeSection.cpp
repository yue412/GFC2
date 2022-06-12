#include "NGfcTShapeSection.h"

using namespace gfc::classes::x3;

NGfcTShapeSection::NGfcTShapeSection()
{
    m_pEntity = new GfcTShapeSection;
    m_bOwner = true;
}

NGfcTShapeSection::NGfcTShapeSection(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcParameterizedSection(pEntity, bOwner)
{
}

void NGfcTShapeSection::setWidth(NGfcDouble dValue)
{
    ((GfcTShapeSection*)m_pEntity)->setWidth(dValue);
}

NGfcDouble NGfcTShapeSection::getWidth()
{
    return ((GfcTShapeSection*)m_pEntity)->getWidth();
}

bool NGfcTShapeSection::hasWidth()
{
    return ((GfcTShapeSection*)m_pEntity)->hasWidth();
}

void NGfcTShapeSection::setHeight(NGfcDouble dValue)
{
    ((GfcTShapeSection*)m_pEntity)->setHeight(dValue);
}

NGfcDouble NGfcTShapeSection::getHeight()
{
    return ((GfcTShapeSection*)m_pEntity)->getHeight();
}

bool NGfcTShapeSection::hasHeight()
{
    return ((GfcTShapeSection*)m_pEntity)->hasHeight();
}

void NGfcTShapeSection::setThickness1(NGfcDouble dValue)
{
    ((GfcTShapeSection*)m_pEntity)->setThickness1(dValue);
}

NGfcDouble NGfcTShapeSection::getThickness1()
{
    return ((GfcTShapeSection*)m_pEntity)->getThickness1();
}

bool NGfcTShapeSection::hasThickness1()
{
    return ((GfcTShapeSection*)m_pEntity)->hasThickness1();
}

void NGfcTShapeSection::setThickness2(NGfcDouble dValue)
{
    ((GfcTShapeSection*)m_pEntity)->setThickness2(dValue);
}

NGfcDouble NGfcTShapeSection::getThickness2()
{
    return ((GfcTShapeSection*)m_pEntity)->getThickness2();
}

bool NGfcTShapeSection::hasThickness2()
{
    return ((GfcTShapeSection*)m_pEntity)->hasThickness2();
}

void NGfcTShapeSection::setLeftWidth(NGfcDouble dValue)
{
    ((GfcTShapeSection*)m_pEntity)->setLeftWidth(dValue);
}

NGfcDouble NGfcTShapeSection::getLeftWidth()
{
    return ((GfcTShapeSection*)m_pEntity)->getLeftWidth();
}

bool NGfcTShapeSection::hasLeftWidth()
{
    return ((GfcTShapeSection*)m_pEntity)->hasLeftWidth();
}

