#include "NGfcParameterizedSection.h"

using namespace gfc::classes::x3;

NGfcParameterizedSection::NGfcParameterizedSection()
{
    m_pEntity = new GfcParameterizedSection;
    m_bOwner = true;
}

NGfcParameterizedSection::NGfcParameterizedSection(bool bNoCreate):
    NGfcSection(bNoCreate)
{
}

void NGfcParameterizedSection::setPosition(gfc::engine::EntityRef nValue)
{
    ((GfcParameterizedSection*)m_pEntity)->setPosition(nValue);
}

gfc::engine::EntityRef NGfcParameterizedSection::getPosition()
{
    return ((GfcParameterizedSection*)m_pEntity)->getPosition();
}

bool NGfcParameterizedSection::hasPosition()
{
    return ((GfcParameterizedSection*)m_pEntity)->hasPosition();
}

