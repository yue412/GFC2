#include "NGfcProperty.h"

using namespace gfc::classes::x3;

NGfcProperty::NGfcProperty()
{
    m_pEntity = new GfcProperty;
    m_bOwner = true;
}

NGfcProperty::NGfcProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

void NGfcProperty::setName(NGfcLabel sValue)
{
    ((GfcProperty*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
}

NGfcLabel NGfcProperty::getName()
{
    return marshal_as<String^>(((GfcProperty*)m_pEntity)->getName());
}

bool NGfcProperty::hasName()
{
    return ((GfcProperty*)m_pEntity)->hasName();
}

void NGfcProperty::setCode(NGfcString sValue)
{
    ((GfcProperty*)m_pEntity)->setCode(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcProperty::getCode()
{
    return marshal_as<String^>(((GfcProperty*)m_pEntity)->getCode());
}

bool NGfcProperty::hasCode()
{
    return ((GfcProperty*)m_pEntity)->hasCode();
}

void NGfcProperty::setExtension(NGfcString sValue)
{
    ((GfcProperty*)m_pEntity)->setExtension(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcProperty::getExtension()
{
    return marshal_as<String^>(((GfcProperty*)m_pEntity)->getExtension());
}

bool NGfcProperty::hasExtension()
{
    return ((GfcProperty*)m_pEntity)->hasExtension();
}

