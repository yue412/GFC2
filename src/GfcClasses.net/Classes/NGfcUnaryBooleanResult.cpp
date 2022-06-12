#include "NGfcUnaryBooleanResult.h"

using namespace gfc::classes::x3;

NGfcUnaryBooleanResult::NGfcUnaryBooleanResult()
{
    m_pEntity = new GfcUnaryBooleanResult;
    m_bOwner = true;
}

NGfcUnaryBooleanResult::NGfcUnaryBooleanResult(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcBooleanResult(pEntity, bOwner)
{
}

void NGfcUnaryBooleanResult::setOperand(gfc::engine::EntityRef nValue)
{
    ((GfcUnaryBooleanResult*)m_pEntity)->setOperand(nValue);
}

gfc::engine::EntityRef NGfcUnaryBooleanResult::getOperand()
{
    return ((GfcUnaryBooleanResult*)m_pEntity)->getOperand();
}

bool NGfcUnaryBooleanResult::hasOperand()
{
    return ((GfcUnaryBooleanResult*)m_pEntity)->hasOperand();
}

