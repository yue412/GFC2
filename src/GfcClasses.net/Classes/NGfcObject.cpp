#include "NGfcObject.h"

using namespace gfc::classes::x3;

NGfcObject::NGfcObject()
{
    m_pEntity = new GfcObject;
    m_bOwner = true;
}

NGfcObject::NGfcObject(bool bNoCreate):
    NEntity(bNoCreate)
{
}

void NGfcObject::setID(NGfcIdentity sValue)
{
    ((GfcObject*)m_pEntity)->setID(marshal_as<std::wstring>(sValue));
}

NGfcIdentity NGfcObject::getID()
{
    return marshal_as<String^>(((GfcObject*)m_pEntity)->getID());
}

bool NGfcObject::hasID()
{
    return ((GfcObject*)m_pEntity)->hasID();
}

void NGfcObject::setName(NGfcLabel sValue)
{
    ((GfcObject*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
}

NGfcLabel NGfcObject::getName()
{
    return marshal_as<String^>(((GfcObject*)m_pEntity)->getName());
}

bool NGfcObject::hasName()
{
    return ((GfcObject*)m_pEntity)->hasName();
}

