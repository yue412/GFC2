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

void NGfc2Property::setName(NGfc2Label sValue)
{
    ((Gfc2Property*)m_pEntity)->setName(marshal_as<std::string>(sValue));
}

NGfc2Label NGfc2Property::getName()
{
    return marshal_as<String^>(((Gfc2Property*)m_pEntity)->getName());
}

bool NGfc2Property::hasName()
{
    return ((Gfc2Property*)m_pEntity)->hasName();
}

void NGfc2Property::setCode(NGfc2String sValue)
{
    ((Gfc2Property*)m_pEntity)->setCode(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2Property::getCode()
{
    return marshal_as<String^>(((Gfc2Property*)m_pEntity)->getCode());
}

bool NGfc2Property::hasCode()
{
    return ((Gfc2Property*)m_pEntity)->hasCode();
}

