#ifndef GFCCSGSOLIDSHAPE_H
#define GFCCSGSOLIDSHAPE_H

#include "GfcClasses/x3/GfcClasses.h"
#include "GfcClasses/x3/GfcSolidShape.h"
#include "GfcClasses/x3/GfcBooleanResult.h"
#include "GfcEngine/Entity.h"

GFCCLASSES_NAMESPACE_BEGIN

class GFCCLASSES_API GfcCsgSolidShape: public GfcSolidShape
{
GFCENGINE_DEC_OBJECT(GfcCsgSolidShape, gfc::engine::CEntity)
public:
    GfcCsgSolidShape();
    GfcCsgSolidShape(bool bSetSchema);
    void setTreeRootExpression(const gfc::engine::EntityRef& nValue);
    gfc::engine::EntityRef getTreeRootExpression() const;
    bool hasTreeRootExpression() const;
    std::shared_ptr<GfcBooleanResult> getTreeRootExpressionPtr();

};

GFCCLASSES_NAMESPACE_END

#endif
