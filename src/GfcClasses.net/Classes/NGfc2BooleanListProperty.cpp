#include "NGfc2BooleanListProperty.h"

using namespace gfc::classes::x3;

NGfc2BooleanListProperty::NGfc2BooleanListProperty()
{
    m_pEntity = new Gfc2BooleanListProperty;
    m_bOwner = true;
}

NGfc2BooleanListProperty::NGfc2BooleanListProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2ListProperty(pEntity, bOwner)
{
}

int NGfc2BooleanListProperty::getValuesCount()
{
    return ((Gfc2BooleanListProperty*)m_pEntity)->getValuesCount();
}

void NGfc2BooleanListProperty::clearValues()
{
    ((Gfc2BooleanListProperty*)m_pEntity)->clearValues();
}

void NGfc2BooleanListProperty::addValues(NGfc2Boolean bValue)
{
    ((Gfc2BooleanListProperty*)m_pEntity)->addValues(bValue);
}

NGfc2Boolean NGfc2BooleanListProperty::getValues(int nIndex)
{
    return ((Gfc2BooleanListProperty*)m_pEntity)->getValues(nIndex);
}

