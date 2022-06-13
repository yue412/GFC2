#include "NGfcEllipseSection.h"

using namespace gfc::classes::x3;

NGfcEllipseSection::NGfcEllipseSection()
{
    m_pEntity = new GfcEllipseSection;
    m_bOwner = true;
}

NGfcEllipseSection::NGfcEllipseSection(bool bNoCreate):
    NGfcParameterizedSection(bNoCreate)
{
}

void NGfcEllipseSection::setSemiAxis1(NGfcDouble dValue)
{
    ((GfcEllipseSection*)m_pEntity)->setSemiAxis1(dValue);
}

NGfcDouble NGfcEllipseSection::getSemiAxis1()
{
    return ((GfcEllipseSection*)m_pEntity)->getSemiAxis1();
}

bool NGfcEllipseSection::hasSemiAxis1()
{
    return ((GfcEllipseSection*)m_pEntity)->hasSemiAxis1();
}

void NGfcEllipseSection::setSemiAxis2(NGfcDouble dValue)
{
    ((GfcEllipseSection*)m_pEntity)->setSemiAxis2(dValue);
}

NGfcDouble NGfcEllipseSection::getSemiAxis2()
{
    return ((GfcEllipseSection*)m_pEntity)->getSemiAxis2();
}

bool NGfcEllipseSection::hasSemiAxis2()
{
    return ((GfcEllipseSection*)m_pEntity)->hasSemiAxis2();
}

