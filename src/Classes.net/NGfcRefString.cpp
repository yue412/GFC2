#include "StdAfx.h"
#include "NGfcRefString.h"
NGfcRefString::NGfcRefString()
{
    m_pEntity = new GfcRefString;
    m_bOwner = true;
}

NGfcRefString::NGfcRefString(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfcRefString::setSValue(String^ sValue)
{
    ((GfcRefString*)m_pEntity)->setSValue(marshal_as<std::string>(sValue));
}

String^ NGfcRefString::getSValue()
{
    return marshal_as<String^>(((GfcRefString*)m_pEntity)->getSValue());
}

bool NGfcRefString::hasSValue()
{
    return ((GfcRefString*)m_pEntity)->hasSValue();
}

