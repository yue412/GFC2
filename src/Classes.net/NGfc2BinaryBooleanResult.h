#ifndef NGFC2BINARYBOOLEANRESULT_H
#define NGFC2BINARYBOOLEANRESULT_H

#include "NGfc2BooleanResult.h"
#include "Gfc2BinaryBooleanResult.h"
#include "NGfc2SolidShape.h"
#include "NTypeDef.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2BinaryBooleanResult: public NGfc2BooleanResult
{
public:
    NGfc2BinaryBooleanResult();
    NGfc2BinaryBooleanResult(void* pEntity, bool bOwner);
    void setOperator(NGfc2BooleanOperator nValue);
    NGfc2BooleanOperator getOperator();
    bool hasOperator();
    void setFirstOperand(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getFirstOperand();
    bool hasFirstOperand();
    NGfc2SolidShape^ getFirstOperandPtr();
    void setSecondOperand(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getSecondOperand();
    bool hasSecondOperand();
    NGfc2SolidShape^ getSecondOperandPtr();

};
#endif
