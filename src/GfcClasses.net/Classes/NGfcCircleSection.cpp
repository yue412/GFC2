#include "NGfcCircleSection.h"

using namespace gfc::classes::x3;

NGfcCircleSection::NGfcCircleSection()
{
    m_pEntity = new GfcCircleSection;
    m_bOwner = true;
}

NGfcCircleSection::NGfcCircleSection(bool bNoCreate):
    NGfcParameterizedSection(bNoCreate)
{
}

void NGfcCircleSection::setRadius(NGfcDouble dValue)
{
    ((GfcCircleSection*)m_pEntity)->setRadius(dValue);
}

NGfcDouble NGfcCircleSection::getRadius()
{
    return ((GfcCircleSection*)m_pEntity)->getRadius();
}

bool NGfcCircleSection::hasRadius()
{
    return ((GfcCircleSection*)m_pEntity)->hasRadius();
}

