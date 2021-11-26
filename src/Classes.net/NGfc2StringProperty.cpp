#include "NGfc2StringProperty.h"

using namespace gfc::classes::x3;

NGfc2StringProperty::NGfc2StringProperty()
{
    m_pEntity = new Gfc2StringProperty;
    m_bOwner = true;
}

NGfc2StringProperty::NGfc2StringProperty(void* pEntity, bool bOwner):
    NGfc2SingleProperty(pEntity, bOwner)
{
}

void NGfc2StringProperty::setVal(NGfc2String sValue)
{
    ((Gfc2StringProperty*)m_pEntity)->setVal(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2StringProperty::getVal()
{
    return marshal_as<String^>(((Gfc2StringProperty*)m_pEntity)->getVal());
}

bool NGfc2StringProperty::hasVal()
{
    return ((Gfc2StringProperty*)m_pEntity)->hasVal();
}

