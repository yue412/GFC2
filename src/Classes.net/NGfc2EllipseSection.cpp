#include "NGfc2EllipseSection.h"

using namespace gfc::classes::x3;

NGfc2EllipseSection::NGfc2EllipseSection()
{
    m_pEntity = new Gfc2EllipseSection;
    m_bOwner = true;
}

NGfc2EllipseSection::NGfc2EllipseSection(void* pEntity, bool bOwner):
    NGfc2ParameterizedSection(pEntity, bOwner)
{
}

void NGfc2EllipseSection::setSemiAxis1(NGfc2Double dValue)
{
    ((Gfc2EllipseSection*)m_pEntity)->setSemiAxis1(dValue);
}

NGfc2Double NGfc2EllipseSection::getSemiAxis1()
{
    return ((Gfc2EllipseSection*)m_pEntity)->getSemiAxis1();
}

bool NGfc2EllipseSection::hasSemiAxis1()
{
    return ((Gfc2EllipseSection*)m_pEntity)->hasSemiAxis1();
}

void NGfc2EllipseSection::setSemiAxis2(NGfc2Double dValue)
{
    ((Gfc2EllipseSection*)m_pEntity)->setSemiAxis2(dValue);
}

NGfc2Double NGfc2EllipseSection::getSemiAxis2()
{
    return ((Gfc2EllipseSection*)m_pEntity)->getSemiAxis2();
}

bool NGfc2EllipseSection::hasSemiAxis2()
{
    return ((Gfc2EllipseSection*)m_pEntity)->hasSemiAxis2();
}

