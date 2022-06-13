#include "NGfcPropertySet.h"

using namespace gfc::classes::x3;

NGfcPropertySet::NGfcPropertySet()
{
    m_pEntity = new GfcPropertySet;
    m_bOwner = true;
}

NGfcPropertySet::NGfcPropertySet(bool bNoCreate):
    NEntity(bNoCreate)
{
}

void NGfcPropertySet::setName(NGfcLabel sValue)
{
    ((GfcPropertySet*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
}

NGfcLabel NGfcPropertySet::getName()
{
    return marshal_as<String^>(((GfcPropertySet*)m_pEntity)->getName());
}

bool NGfcPropertySet::hasName()
{
    return ((GfcPropertySet*)m_pEntity)->hasName();
}

int NGfcPropertySet::getHasPropertiesCount()
{
    return ((GfcPropertySet*)m_pEntity)->getHasPropertiesCount();
}

void NGfcPropertySet::clearHasProperties()
{
    ((GfcPropertySet*)m_pEntity)->clearHasProperties();
}

void NGfcPropertySet::addHasProperties(gfc::engine::EntityRef nValue)
{
    ((GfcPropertySet*)m_pEntity)->addHasProperties(nValue);
}

gfc::engine::EntityRef NGfcPropertySet::getHasProperties(int nIndex)
{
    return ((GfcPropertySet*)m_pEntity)->getHasProperties(nIndex);
}

