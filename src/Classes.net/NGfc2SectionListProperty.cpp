#include "StdAfx.h"
#include "NGfc2SectionListProperty.h"
NGfc2SectionListProperty::NGfc2SectionListProperty()
{
    m_pEntity = new Gfc2SectionListProperty;
    m_bOwner = true;
}

NGfc2SectionListProperty::NGfc2SectionListProperty(void* pEntity, bool bOwner):
    NGfc2ListProperty(pEntity, bOwner)
{
}

int NGfc2SectionListProperty::getValueCount()
{
    return ((Gfc2SectionListProperty*)m_pEntity)->getValueCount();
}

void NGfc2SectionListProperty::clearValue()
{
    ((Gfc2SectionListProperty*)m_pEntity)->clearValue();
}

void NGfc2SectionListProperty::addValue(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SectionListProperty*)m_pEntity)->addValue(nValue);
}

glodon::objectbuf::EntityRef NGfc2SectionListProperty::getValue(int nIndex)
{
    return ((Gfc2SectionListProperty*)m_pEntity)->getValue(nIndex);
}

NGfc2Section^ NGfc2SectionListProperty::getValuePtr(int nIndex)
{
    return gcnew NGfc2Section(((Gfc2SectionListProperty*)m_pEntity)->getValuePtr(nIndex), false);
}

