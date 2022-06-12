#include "NGfcIntegerProperty.h"

using namespace gfc::classes::x3;

NGfcIntegerProperty::NGfcIntegerProperty()
{
    m_pEntity = new GfcIntegerProperty;
    m_bOwner = true;
}

NGfcIntegerProperty::NGfcIntegerProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSingleProperty(pEntity, bOwner)
{
}

void NGfcIntegerProperty::setVal(NGfcInteger nValue)
{
    ((GfcIntegerProperty*)m_pEntity)->setVal(nValue);
}

NGfcInteger NGfcIntegerProperty::getVal()
{
    return ((GfcIntegerProperty*)m_pEntity)->getVal();
}

bool NGfcIntegerProperty::hasVal()
{
    return ((GfcIntegerProperty*)m_pEntity)->hasVal();
}

