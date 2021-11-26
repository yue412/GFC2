#ifndef NGFC2BINARYBOOLEANRESULT_H
#define NGFC2BINARYBOOLEANRESULT_H

#include "NGfc2BooleanResult.h"
#include "GfcClasses\x3\Gfc2BinaryBooleanResult.h"
#include "NGfc2SolidShape.h"
#include "NTypeDef.h"

public ref class NGfc2BinaryBooleanResult: public NGfc2BooleanResult
{
public:
    NGfc2BinaryBooleanResult();
    NGfc2BinaryBooleanResult(void* pEntity, bool bOwner);
    void setOperator(NGfc2BooleanOperator nValue);
    NGfc2BooleanOperator getOperator();
    bool hasOperator();
    void setFirstOperand(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getFirstOperand();
    bool hasFirstOperand();
    void setSecondOperand(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSecondOperand();
    bool hasSecondOperand();

};
#endif
