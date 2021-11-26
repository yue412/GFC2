#include "NGfc2IntegerProperty.h"

using namespace gfc::classes::x3;

NGfc2IntegerProperty::NGfc2IntegerProperty()
{
    m_pEntity = new Gfc2IntegerProperty;
    m_bOwner = true;
}

NGfc2IntegerProperty::NGfc2IntegerProperty(void* pEntity, bool bOwner):
    NGfc2SingleProperty(pEntity, bOwner)
{
}

void NGfc2IntegerProperty::setVal(NGfc2Integer nValue)
{
    ((Gfc2IntegerProperty*)m_pEntity)->setVal(nValue);
}

NGfc2Integer NGfc2IntegerProperty::getVal()
{
    return ((Gfc2IntegerProperty*)m_pEntity)->getVal();
}

bool NGfc2IntegerProperty::hasVal()
{
    return ((Gfc2IntegerProperty*)m_pEntity)->hasVal();
}

