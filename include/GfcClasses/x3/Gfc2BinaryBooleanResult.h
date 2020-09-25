#ifndef GFC2BINARYBOOLEANRESULT_H
#define GFC2BINARYBOOLEANRESULT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2BooleanResult.h"
#include "GfcClasses/x3/Gfc2SolidShape.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

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
    gfc::engine::CEntityWrapPtr<Gfc2SolidShape> getFirstOperandPtr();
    void setSecondOperand(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getSecondOperand() const;
    bool hasSecondOperand() const;
    gfc::engine::CEntityWrapPtr<Gfc2SolidShape> getSecondOperandPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
