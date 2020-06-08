#ifndef GFC2CSGSOLIDSHAPE_H
#define GFC2CSGSOLIDSHAPE_H

#include "GfcClasses.h"
#include "Gfc2SolidShape.h"
#include "Gfc2BooleanResult.h"
#include "GfcEngine/Entity.h"

class GFCCLASSES_API Gfc2CsgSolidShape: public Gfc2SolidShape
{
GFCENGINE_DEC_OBJECT(Gfc2CsgSolidShape, gfc::engine::CEntity)
public:
    Gfc2CsgSolidShape();
    Gfc2CsgSolidShape(bool bSetSchema);
    void setTreeRootExpression(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getTreeRootExpression() const;
    bool hasTreeRootExpression() const;
    std::shared_ptr<Gfc2BooleanResult> getTreeRootExpressionPtr();

};
#endif
