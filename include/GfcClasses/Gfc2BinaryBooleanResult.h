#ifndef GFC2BINARYBOOLEANRESULT_H
#define GFC2BINARYBOOLEANRESULT_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2BooleanResult.h"
#include "Gfc2SolidShape.h"
#include "Gfc2SolidShape.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2BinaryBooleanResult: public Gfc2BooleanResult
{
GFCENGINE_DEC_OBJECT(Gfc2BinaryBooleanResult,gfc2::engine::EntityFactory)
public:
    Gfc2BinaryBooleanResult();
    Gfc2BinaryBooleanResult(bool bSetSchema);
    void setOperator(const Gfc2BooleanOperator& nValue);
    Gfc2BooleanOperator getOperator() const;
    bool hasOperator() const;
    void setFirstOperand(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getFirstOperand() const;
    bool hasFirstOperand() const;
    std::shared_ptr<Gfc2SolidShape> getFirstOperandPtr();
    void setSecondOperand(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getSecondOperand() const;
    bool hasSecondOperand() const;
    std::shared_ptr<Gfc2SolidShape> getSecondOperandPtr();

};
#endif
