#include "StdAfx.h"
#include "NGfc2StringProperty.h"
NGfc2StringProperty::NGfc2StringProperty()
{
    m_pEntity = new Gfc2StringProperty;
    m_bOwner = true;
}

NGfc2StringProperty::NGfc2StringProperty(void* pEntity, bool bOwner):
    NGfc2SingleProperty(pEntity, bOwner)
{
}

void NGfc2StringProperty::setValue(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2StringProperty*)m_pEntity)->setValue(nValue);
}

glodon::objectbuf::EntityRef NGfc2StringProperty::getValue()
{
    return ((Gfc2StringProperty*)m_pEntity)->getValue();
}

bool NGfc2StringProperty::hasValue()
{
    return ((Gfc2StringProperty*)m_pEntity)->hasValue();
}

NGfc2String^ NGfc2StringProperty::getValuePtr()
{
    return gcnew NGfc2String(((Gfc2StringProperty*)m_pEntity)->getValuePtr(), false);
}

