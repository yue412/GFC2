#include "StdAfx.h"
#include "NGfc2ParameterizedSection.h"
NGfc2ParameterizedSection::NGfc2ParameterizedSection()
{
    m_pEntity = new Gfc2ParameterizedSection;
    m_bOwner = true;
}

NGfc2ParameterizedSection::NGfc2ParameterizedSection(void* pEntity, bool bOwner):
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

NGfc2Coordinates3d^ NGfc2ParameterizedSection::getPositionPtr()
{
    return gcnew NGfc2Coordinates3d(((Gfc2ParameterizedSection*)m_pEntity)->getPositionPtr(), false);
}

