#include "NGfcBooleanProperty.h"

using namespace gfc::classes::x3;

NGfcBooleanProperty::NGfcBooleanProperty()
{
    m_pEntity = new GfcBooleanProperty;
    m_bOwner = true;
}

NGfcBooleanProperty::NGfcBooleanProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSingleProperty(pEntity, bOwner)
{
}

void NGfcBooleanProperty::setVal(NGfcBoolean bValue)
{
    ((GfcBooleanProperty*)m_pEntity)->setVal(bValue);
}

NGfcBoolean NGfcBooleanProperty::getVal()
{
    return ((GfcBooleanProperty*)m_pEntity)->getVal();
}

bool NGfcBooleanProperty::hasVal()
{
    return ((GfcBooleanProperty*)m_pEntity)->hasVal();
}

