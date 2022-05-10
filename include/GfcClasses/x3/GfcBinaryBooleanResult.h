#ifndef GFCBINARYBOOLEANRESULT_H
#define GFCBINARYBOOLEANRESULT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcBooleanResult.h"
#include "GfcClasses/x3/GfcSolidShape.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcBinaryBooleanResult: public GfcBooleanResult
{
GFCENGINE_DEC_OBJECT(GfcBinaryBooleanResult, gfc::engine::CEntity)
public:
    GfcBinaryBooleanResult();
    GfcBinaryBooleanResult(bool bSetSchema);
    void setOperator(const GfcBooleanOperator& nValue);
    GfcBooleanOperator getOperator() const;
    bool hasOperator() const;
    void setFirstOperand(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getFirstOperand() const;
    bool hasFirstOperand() const;
    std::shared_ptr<GfcSolidShape> getFirstOperandPtr();
    void setSecondOperand(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSecondOperand() const;
    bool hasSecondOperand() const;
    std::shared_ptr<GfcSolidShape> getSecondOperandPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
