#ifndef NGFC2UNARYBOOLEANRESULT_H
#define NGFC2UNARYBOOLEANRESULT_H

#include "NGfc2BooleanResult.h"
#include "GfcClasses\x3\Gfc2UnaryBooleanResult.h"
#include "NGfc2SolidShape.h"

public ref class NGfc2UnaryBooleanResult: public NGfc2BooleanResult
{
public:
    NGfc2UnaryBooleanResult();
    NGfc2UnaryBooleanResult(void* pEntity, bool bOwner);
    void setOperand(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getOperand();
    bool hasOperand();

};
#endif
