#ifndef GFCUNARYBOOLEANRESULT_H
#define GFCUNARYBOOLEANRESULT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcBooleanResult.h"
#include "GfcClasses/x3/GfcSolidShape.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcUnaryBooleanResult: public GfcBooleanResult
{
GFCENGINE_DEC_OBJECT(GfcUnaryBooleanResult, gfc::engine::CEntity)
public:
    GfcUnaryBooleanResult();
    GfcUnaryBooleanResult(bool bSetSchema);
    void setOperand(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getOperand() const;
    bool hasOperand() const;
    std::shared_ptr<GfcSolidShape> getOperandPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
