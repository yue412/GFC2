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

void NGfcRefString::setVal(String^ sValue)
{
    ((GfcRefString*)m_pEntity)->setVal(marshal_as<std::string>(sValue));
}

String^ NGfcRefString::getVal()
{
    return marshal_as<String^>(((GfcRefString*)m_pEntity)->getVal());
}

bool NGfcRefString::hasVal()
{
    return ((GfcRefString*)m_pEntity)->hasVal();
}

