#ifndef GFC2UNARYBOOLEANRESULT_H
#define GFC2UNARYBOOLEANRESULT_H

#include "GfcClasses.h"
#include "GfcEngine/EntityFactory.h"
#include "Gfc2BooleanResult.h"
#include "Gfc2SolidShape.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2UnaryBooleanResult: public Gfc2BooleanResult
{
GFCENGINE_DEC_OBJECT(Gfc2UnaryBooleanResult,gfc2::engine::EntityFactory)
public:
    Gfc2UnaryBooleanResult();
    Gfc2UnaryBooleanResult(bool bSetSchema);
    void setOperand(const gfc2::engine::EntityRef& nValue);
    gfc2::engine::EntityRef getOperand() const;
    bool hasOperand() const;
    std::shared_ptr<Gfc2SolidShape> getOperandPtr();

};
#endif
