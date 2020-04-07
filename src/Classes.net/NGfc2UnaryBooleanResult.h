#ifndef NGFC2UNARYBOOLEANRESULT_H
#define NGFC2UNARYBOOLEANRESULT_H

#include "NGfc2BooleanResult.h"
#include "Gfc2UnaryBooleanResult.h"
#include "NGfc2SolidShape.h"
#include "glodon/objectbuf/Entity.h"

public ref class NGfc2UnaryBooleanResult: public NGfc2BooleanResult
{
public:
    NGfc2UnaryBooleanResult();
    NGfc2UnaryBooleanResult(void* pEntity, bool bOwner);
    void setOperand(glodon::objectbuf::EntityRef nValue);
    glodon::objectbuf::EntityRef getOperand();
    bool hasOperand();
    NGfc2SolidShape^ getOperandPtr();

};
#endif
