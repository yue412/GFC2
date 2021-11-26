#include "NGfc2ComplexProperty.h"

using namespace gfc::classes::x3;

NGfc2ComplexProperty::NGfc2ComplexProperty()
{
    m_pEntity = new Gfc2ComplexProperty;
    m_bOwner = true;
}

NGfc2ComplexProperty::NGfc2ComplexProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Property(pEntity, bOwner)
{
}

int NGfc2ComplexProperty::getHasPropertiesCount()
{
    return ((Gfc2ComplexProperty*)m_pEntity)->getHasPropertiesCount();
}

void NGfc2ComplexProperty::clearHasProperties()
{
    ((Gfc2ComplexProperty*)m_pEntity)->clearHasProperties();
}

void NGfc2ComplexProperty::addHasProperties(gfc::engine::EntityRef nValue)
{
    ((Gfc2ComplexProperty*)m_pEntity)->addHasProperties(nValue);
}

gfc::engine::EntityRef NGfc2ComplexProperty::getHasProperties(int nIndex)
{
    return ((Gfc2ComplexProperty*)m_pEntity)->getHasProperties(nIndex);
}

