#include "NGfcCircleSection.h"

using namespace gfc::classes::x3;

NGfcCircleSection::NGfcCircleSection()
{
    m_pEntity = new GfcCircleSection;
    m_bOwner = true;
}

NGfcCircleSection::NGfcCircleSection(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcParameterizedSection(pEntity, bOwner)
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

