#include "StdAfx.h"
#include "NGfc2BinaryBooleanResult.h"
NGfc2BinaryBooleanResult::NGfc2BinaryBooleanResult()
{
    m_pEntity = new Gfc2BinaryBooleanResult;
    m_bOwner = true;
}

NGfc2BinaryBooleanResult::NGfc2BinaryBooleanResult(void* pEntity, bool bOwner):
    NGfc2BooleanResult(pEntity, bOwner)
{
}

void NGfc2BinaryBooleanResult::setOperator(NGfc2BooleanOperator nValue)
{
    ((Gfc2BinaryBooleanResult*)m_pEntity)->setOperator((Gfc2BooleanOperator)nValue);
}

NGfc2BooleanOperator NGfc2BinaryBooleanResult::getOperator()
{
    return (NGfc2BooleanOperator)((Gfc2BinaryBooleanResult*)m_pEntity)->getOperator();
}

bool NGfc2BinaryBooleanResult::hasOperator()
{
    return ((Gfc2BinaryBooleanResult*)m_pEntity)->hasOperator();
}

void NGfc2BinaryBooleanResult::setFirstOperand(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2BinaryBooleanResult*)m_pEntity)->setFirstOperand(nValue);
}

glodon::objectbuf::EntityRef NGfc2BinaryBooleanResult::getFirstOperand()
{
    return ((Gfc2BinaryBooleanResult*)m_pEntity)->getFirstOperand();
}

bool NGfc2BinaryBooleanResult::hasFirstOperand()
{
    return ((Gfc2BinaryBooleanResult*)m_pEntity)->hasFirstOperand();
}

NGfc2SolidShape^ NGfc2BinaryBooleanResult::getFirstOperandPtr()
{
    return gcnew NGfc2SolidShape(((Gfc2BinaryBooleanResult*)m_pEntity)->getFirstOperandPtr(), false);
}

void NGfc2BinaryBooleanResult::setSecondOperand(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2BinaryBooleanResult*)m_pEntity)->setSecondOperand(nValue);
}

glodon::objectbuf::EntityRef NGfc2BinaryBooleanResult::getSecondOperand()
{
    return ((Gfc2BinaryBooleanResult*)m_pEntity)->getSecondOperand();
}

bool NGfc2BinaryBooleanResult::hasSecondOperand()
{
    return ((Gfc2BinaryBooleanResult*)m_pEntity)->hasSecondOperand();
}

NGfc2SolidShape^ NGfc2BinaryBooleanResult::getSecondOperandPtr()
{
    return gcnew NGfc2SolidShape(((Gfc2BinaryBooleanResult*)m_pEntity)->getSecondOperandPtr(), false);
}

