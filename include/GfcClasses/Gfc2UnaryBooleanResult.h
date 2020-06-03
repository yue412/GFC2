#ifndef GFC2UNARYBOOLEANRESULT_H
#define GFC2UNARYBOOLEANRESULT_H

#include "GfcClasses.h"
#include "Gfc2BooleanResult.h"
#include "Gfc2SolidShape.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2UnaryBooleanResult: public Gfc2BooleanResult
{
GFCENGINE_DEC_OBJECT(Gfc2UnaryBooleanResult, gfc::engine::Entity)
public:
    Gfc2UnaryBooleanResult();
    Gfc2UnaryBooleanResult(bool bSetSchema);
    void setOperand(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getOperand() const;
    bool hasOperand() const;
    std::shared_ptr<Gfc2SolidShape> getOperandPtr();

};
#endif
