#ifndef GFC2BINARYBOOLEANRESULT_H
#define GFC2BINARYBOOLEANRESULT_H

#include "GfcClasses.h"
#include "Gfc2BooleanResult.h"
#include "Gfc2SolidShape.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2BinaryBooleanResult: public Gfc2BooleanResult
{
GFCENGINE_DEC_OBJECT(Gfc2BinaryBooleanResult, gfc::engine::CEntity)
public:
    Gfc2BinaryBooleanResult();
    Gfc2BinaryBooleanResult(bool bSetSchema);
    void setOperator(const Gfc2BooleanOperator& nValue);
    Gfc2BooleanOperator getOperator() const;
    bool hasOperator() const;
    void setFirstOperand(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getFirstOperand() const;
    bool hasFirstOperand() const;
    std::shared_ptr<Gfc2SolidShape> getFirstOperandPtr();
    void setSecondOperand(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSecondOperand() const;
    bool hasSecondOperand() const;
    std::shared_ptr<Gfc2SolidShape> getSecondOperandPtr();

};
#endif