#ifndef NGFCUNARYBOOLEANRESULT_H
#define NGFCUNARYBOOLEANRESULT_H

#include "NGfcBooleanResult.h"
#include "GfcClasses\x3\GfcUnaryBooleanResult.h"
#include "NGfcSolidShape.h"

public ref class NGfcUnaryBooleanResult: public NGfcBooleanResult
{
public:
    NGfcUnaryBooleanResult();
    NGfcUnaryBooleanResult(bool bNoCreate);
    void setOperand(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getOperand();
    bool hasOperand();

};
#endif
