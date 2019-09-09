#include "StdAfx.h"
#include "NGfc2Property.h"
NGfc2Property::NGfc2Property()
{
    m_pEntity = new Gfc2Property;
    m_bOwner = true;
}

NGfc2Property::NGfc2Property(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2Property::setName(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Property*)m_pEntity)->setName(nValue);
}

glodon::objectbuf::EntityRef NGfc2Property::getName()
{
    return ((Gfc2Property*)m_pEntity)->getName();
}

bool NGfc2Property::hasName()
{
    return ((Gfc2Property*)m_pEntity)->hasName();
}

NGfc2Label^ NGfc2Property::getNamePtr()
{
    return gcnew NGfc2Label(((Gfc2Property*)m_pEntity)->getNamePtr(), false);
}

