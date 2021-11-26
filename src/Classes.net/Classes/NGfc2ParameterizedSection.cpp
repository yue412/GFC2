#include "NGfc2ParameterizedSection.h"

using namespace gfc::classes::x3;

NGfc2ParameterizedSection::NGfc2ParameterizedSection()
{
    m_pEntity = new Gfc2ParameterizedSection;
    m_bOwner = true;
}

NGfc2ParameterizedSection::NGfc2ParameterizedSection(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Section(pEntity, bOwner)
{
}

void NGfc2ParameterizedSection::setPosition(gfc::engine::EntityRef nValue)
{
    ((Gfc2ParameterizedSection*)m_pEntity)->setPosition(nValue);
}

gfc::engine::EntityRef NGfc2ParameterizedSection::getPosition()
{
    return ((Gfc2ParameterizedSection*)m_pEntity)->getPosition();
}

bool NGfc2ParameterizedSection::hasPosition()
{
    return ((Gfc2ParameterizedSection*)m_pEntity)->hasPosition();
}

