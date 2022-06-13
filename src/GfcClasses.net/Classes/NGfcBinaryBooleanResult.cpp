#include "NGfcBinaryBooleanResult.h"

using namespace gfc::classes::x3;

NGfcBinaryBooleanResult::NGfcBinaryBooleanResult()
{
    m_pEntity = new GfcBinaryBooleanResult;
    m_bOwner = true;
}

NGfcBinaryBooleanResult::NGfcBinaryBooleanResult(bool bNoCreate):
    NGfcBooleanResult(bNoCreate)
{
}

void NGfcBinaryBooleanResult::setOperator(NGfcBooleanOperator nValue)
{
    ((GfcBinaryBooleanResult*)m_pEntity)->setOperator((GfcBooleanOperator)nValue);
}

NGfcBooleanOperator NGfcBinaryBooleanResult::getOperator()
{
    return (NGfcBooleanOperator)((GfcBinaryBooleanResult*)m_pEntity)->getOperator();
}

bool NGfcBinaryBooleanResult::hasOperator()
{
    return ((GfcBinaryBooleanResult*)m_pEntity)->hasOperator();
}

void NGfcBinaryBooleanResult::setFirstOperand(gfc::engine::EntityRef nValue)
{
    ((GfcBinaryBooleanResult*)m_pEntity)->setFirstOperand(nValue);
}

gfc::engine::EntityRef NGfcBinaryBooleanResult::getFirstOperand()
{
    return ((GfcBinaryBooleanResult*)m_pEntity)->getFirstOperand();
}

bool NGfcBinaryBooleanResult::hasFirstOperand()
{
    return ((GfcBinaryBooleanResult*)m_pEntity)->hasFirstOperand();
}

void NGfcBinaryBooleanResult::setSecondOperand(gfc::engine::EntityRef nValue)
{
    ((GfcBinaryBooleanResult*)m_pEntity)->setSecondOperand(nValue);
}

gfc::engine::EntityRef NGfcBinaryBooleanResult::getSecondOperand()
{
    return ((GfcBinaryBooleanResult*)m_pEntity)->getSecondOperand();
}

bool NGfcBinaryBooleanResult::hasSecondOperand()
{
    return ((GfcBinaryBooleanResult*)m_pEntity)->hasSecondOperand();
}

