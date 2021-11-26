#include "NGfc2StringListProperty.h"

using namespace gfc::classes::x3;

NGfc2StringListProperty::NGfc2StringListProperty()
{
    m_pEntity = new Gfc2StringListProperty;
    m_bOwner = true;
}

NGfc2StringListProperty::NGfc2StringListProperty(void* pEntity, bool bOwner):
    NGfc2ListProperty(pEntity, bOwner)
{
}

int NGfc2StringListProperty::getValuesCount()
{
    return ((Gfc2StringListProperty*)m_pEntity)->getValuesCount();
}

void NGfc2StringListProperty::clearValues()
{
    ((Gfc2StringListProperty*)m_pEntity)->clearValues();
}

void NGfc2StringListProperty::addValues(NGfc2String sValue)
{
    ((Gfc2StringListProperty*)m_pEntity)->addValues(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2StringListProperty::getValues(int nIndex)
{
    return marshal_as<String^>(((Gfc2StringListProperty*)m_pEntity)->getValues(nIndex));
}

