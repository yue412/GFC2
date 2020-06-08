#include "StdAfx.h"
#include "NGfc2UnaryBooleanResult.h"
NGfc2UnaryBooleanResult::NGfc2UnaryBooleanResult()
{
    m_pEntity = new Gfc2UnaryBooleanResult;
    m_bOwner = true;
}

NGfc2UnaryBooleanResult::NGfc2UnaryBooleanResult(void* pEntity, bool bOwner):
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

NGfc2SolidShape^ NGfc2UnaryBooleanResult::getOperandPtr()
{
    return gcnew NGfc2SolidShape(((Gfc2UnaryBooleanResult*)m_pEntity)->getOperandPtr(), false);
}

