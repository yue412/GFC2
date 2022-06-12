#include "NGfcEntityListProperty.h"

using namespace gfc::classes::x3;

NGfcEntityListProperty::NGfcEntityListProperty()
{
    m_pEntity = new GfcEntityListProperty;
    m_bOwner = true;
}

NGfcEntityListProperty::NGfcEntityListProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcListProperty(pEntity, bOwner)
{
}

int NGfcEntityListProperty::getValuesCount()
{
    return ((GfcEntityListProperty*)m_pEntity)->getValuesCount();
}

void NGfcEntityListProperty::clearValues()
{
    ((GfcEntityListProperty*)m_pEntity)->clearValues();
}

void NGfcEntityListProperty::addValues(gfc::engine::EntityRef nValue)
{
    ((GfcEntityListProperty*)m_pEntity)->addValues(nValue);
}

gfc::engine::EntityRef NGfcEntityListProperty::getValues(int nIndex)
{
    return ((GfcEntityListProperty*)m_pEntity)->getValues(nIndex);
}

