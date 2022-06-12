#include "NGfcComplexProperty.h"

using namespace gfc::classes::x3;

NGfcComplexProperty::NGfcComplexProperty()
{
    m_pEntity = new GfcComplexProperty;
    m_bOwner = true;
}

NGfcComplexProperty::NGfcComplexProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcProperty(pEntity, bOwner)
{
}

int NGfcComplexProperty::getHasPropertiesCount()
{
    return ((GfcComplexProperty*)m_pEntity)->getHasPropertiesCount();
}

void NGfcComplexProperty::clearHasProperties()
{
    ((GfcComplexProperty*)m_pEntity)->clearHasProperties();
}

void NGfcComplexProperty::addHasProperties(gfc::engine::EntityRef nValue)
{
    ((GfcComplexProperty*)m_pEntity)->addHasProperties(nValue);
}

gfc::engine::EntityRef NGfcComplexProperty::getHasProperties(int nIndex)
{
    return ((GfcComplexProperty*)m_pEntity)->getHasProperties(nIndex);
}

