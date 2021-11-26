#include "NGfc2EntityProperty.h"

using namespace gfc::classes::x3;

NGfc2EntityProperty::NGfc2EntityProperty()
{
    m_pEntity = new Gfc2EntityProperty;
    m_bOwner = true;
}

NGfc2EntityProperty::NGfc2EntityProperty(void* pEntity, bool bOwner):
    NGfc2SingleProperty(pEntity, bOwner)
{
}

void NGfc2EntityProperty::setVal(gfc::engine::EntityRef nValue)
{
    ((Gfc2EntityProperty*)m_pEntity)->setVal(nValue);
}

gfc::engine::EntityRef NGfc2EntityProperty::getVal()
{
    return ((Gfc2EntityProperty*)m_pEntity)->getVal();
}

bool NGfc2EntityProperty::hasVal()
{
    return ((Gfc2EntityProperty*)m_pEntity)->hasVal();
}

