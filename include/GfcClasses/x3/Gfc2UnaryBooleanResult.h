#ifndef GFC2UNARYBOOLEANRESULT_H
#define GFC2UNARYBOOLEANRESULT_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/Gfc2BooleanResult.h"
#include "GfcClasses/x3/Gfc2SolidShape.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API Gfc2UnaryBooleanResult: public Gfc2BooleanResult
{
GFCENGINE_DEC_OBJECT(Gfc2UnaryBooleanResult, gfc::engine::CEntity)
public:
    Gfc2UnaryBooleanResult();
    Gfc2UnaryBooleanResult(bool bSetSchema);
    void setOperand(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getOperand() const;
    bool hasOperand() const;
    std::shared_ptr<Gfc2SolidShape> getOperandPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
