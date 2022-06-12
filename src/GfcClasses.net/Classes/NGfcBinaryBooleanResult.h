#ifndef NGFCBINARYBOOLEANRESULT_H
#define NGFCBINARYBOOLEANRESULT_H

#include "NGfcBooleanResult.h"
#include "GfcClasses\x3\GfcBinaryBooleanResult.h"
#include "NGfcSolidShape.h"
#include "NTypeDef.h"

public ref class NGfcBinaryBooleanResult: public NGfcBooleanResult
{
public:
    NGfcBinaryBooleanResult();
    NGfcBinaryBooleanResult(gfc::engine::CEntity* pEntity, bool bOwner);
    void setOperator(NGfcBooleanOperator nValue);
    NGfcBooleanOperator getOperator();
    bool hasOperator();
    void setFirstOperand(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getFirstOperand();
    bool hasFirstOperand();
    void setSecondOperand(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getSecondOperand();
    bool hasSecondOperand();

};
#endif
