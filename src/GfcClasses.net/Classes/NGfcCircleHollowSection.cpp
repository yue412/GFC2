#include "NGfcCircleHollowSection.h"

using namespace gfc::classes::x3;

NGfcCircleHollowSection::NGfcCircleHollowSection()
{
    m_pEntity = new GfcCircleHollowSection;
    m_bOwner = true;
}

NGfcCircleHollowSection::NGfcCircleHollowSection(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcCircleSection(pEntity, bOwner)
{
}

void NGfcCircleHollowSection::setThickness(NGfcDouble dValue)
{
    ((GfcCircleHollowSection*)m_pEntity)->setThickness(dValue);
}

NGfcDouble NGfcCircleHollowSection::getThickness()
{
    return ((GfcCircleHollowSection*)m_pEntity)->getThickness();
}

bool NGfcCircleHollowSection::hasThickness()
{
    return ((GfcCircleHollowSection*)m_pEntity)->hasThickness();
}

