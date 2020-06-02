#ifndef NGFC2UNARYBOOLEANRESULT_H
#define NGFC2UNARYBOOLEANRESULT_H

#include "NGfc2BooleanResult.h"
#include "Gfc2UnaryBooleanResult.h"
#include "NGfc2SolidShape.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2UnaryBooleanResult: public NGfc2BooleanResult
{
public:
    NGfc2UnaryBooleanResult();
    NGfc2UnaryBooleanResult(void* pEntity, bool bOwner);
    void setOperand(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getOperand();
    bool hasOperand();
    NGfc2SolidShape^ getOperandPtr();

};
#endif
