#include "NGfc2SectionListProperty.h"

using namespace gfc::classes::x3;

NGfc2SectionListProperty::NGfc2SectionListProperty()
{
    m_pEntity = new Gfc2SectionListProperty;
    m_bOwner = true;
}

NGfc2SectionListProperty::NGfc2SectionListProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2ListProperty(pEntity, bOwner)
{
}

int NGfc2SectionListProperty::getValuesCount()
{
    return ((Gfc2SectionListProperty*)m_pEntity)->getValuesCount();
}

void NGfc2SectionListProperty::clearValues()
{
    ((Gfc2SectionListProperty*)m_pEntity)->clearValues();
}

void NGfc2SectionListProperty::addValues(gfc::engine::EntityRef nValue)
{
    ((Gfc2SectionListProperty*)m_pEntity)->addValues(nValue);
}

gfc::engine::EntityRef NGfc2SectionListProperty::getValues(int nIndex)
{
    return ((Gfc2SectionListProperty*)m_pEntity)->getValues(nIndex);
}

