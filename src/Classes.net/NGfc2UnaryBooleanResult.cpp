#include "NGfc2UnaryBooleanResult.h"

using namespace gfc::classes::x3;

NGfc2UnaryBooleanResult::NGfc2UnaryBooleanResult()
{
    m_pEntity = new Gfc2UnaryBooleanResult;
    m_bOwner = true;
}

NGfc2UnaryBooleanResult::NGfc2UnaryBooleanResult(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2BooleanResult(pEntity, bOwner)
{
}

void NGfc2UnaryBooleanResult::setOperand(gfc::engine::EntityRef nValue)
{
    ((Gfc2UnaryBooleanResult*)m_pEntity)->setOperand(nValue);
}

gfc::engine::EntityRef NGfc2UnaryBooleanResult::getOperand()
{
    return ((Gfc2UnaryBooleanResult*)m_pEntity)->getOperand();
}

bool NGfc2UnaryBooleanResult::hasOperand()
{
    return ((Gfc2UnaryBooleanResult*)m_pEntity)->hasOperand();
}

