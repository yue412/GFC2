#include "StdAfx.h"
#include "NGfc2ObjectProperty.h"
NGfc2ObjectProperty::NGfc2ObjectProperty()
{
    m_pEntity = new Gfc2ObjectProperty;
    m_bOwner = true;
}

NGfc2ObjectProperty::NGfc2ObjectProperty(void* pEntity, bool bOwner):
    NGfc2Property(pEntity, bOwner)
{
}

void NGfc2ObjectProperty::setValue(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2ObjectProperty*)m_pEntity)->setValue(nValue);
}

glodon::objectbuf::EntityRef NGfc2ObjectProperty::getValue()
{
    return ((Gfc2ObjectProperty*)m_pEntity)->getValue();
}

bool NGfc2ObjectProperty::hasValue()
{
    return ((Gfc2ObjectProperty*)m_pEntity)->hasValue();
}

NGfc2Object^ NGfc2ObjectProperty::getValuePtr()
{
    return gcnew NGfc2Object(((Gfc2ObjectProperty*)m_pEntity)->getValuePtr(), false);
}

