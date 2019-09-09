#include "StdAfx.h"
#include "NGfc2String.h"
NGfc2String::NGfc2String()
{
    m_pEntity = new Gfc2String;
    m_bOwner = true;
}

NGfc2String::NGfc2String(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2String::setValue(String^ sValue)
{
    ((Gfc2String*)m_pEntity)->setValue(marshal_as<std::string>(sValue));
}

String^ NGfc2String::getValue()
{
    return marshal_as<String^>(((Gfc2String*)m_pEntity)->getValue());
}

bool NGfc2String::hasValue()
{
    return ((Gfc2String*)m_pEntity)->hasValue();
}

