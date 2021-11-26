#include "NGfc2Property.h"

using namespace gfc::classes::x3;

NGfc2Property::NGfc2Property()
{
    m_pEntity = new Gfc2Property;
    m_bOwner = true;
}

NGfc2Property::NGfc2Property(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2Property::setName(NGfc2Label sValue)
{
    ((Gfc2Property*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
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
    ((Gfc2Property*)m_pEntity)->setCode(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2Property::getCode()
{
    return marshal_as<String^>(((Gfc2Property*)m_pEntity)->getCode());
}

bool NGfc2Property::hasCode()
{
    return ((Gfc2Property*)m_pEntity)->hasCode();
}

void NGfc2Property::setExtension(NGfc2String sValue)
{
    ((Gfc2Property*)m_pEntity)->setExtension(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2Property::getExtension()
{
    return marshal_as<String^>(((Gfc2Property*)m_pEntity)->getExtension());
}

bool NGfc2Property::hasExtension()
{
    return ((Gfc2Property*)m_pEntity)->hasExtension();
}

