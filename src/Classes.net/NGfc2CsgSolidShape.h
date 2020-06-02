#ifndef NGFC2CSGSOLIDSHAPE_H
#define NGFC2CSGSOLIDSHAPE_H

#include "NGfc2SolidShape.h"
#include "Gfc2CsgSolidShape.h"
#include "NGfc2BooleanResult.h"
#include "GfcEngine/Entity.h"

public ref class NGfc2CsgSolidShape: public NGfc2SolidShape
{
public:
    NGfc2CsgSolidShape();
    NGfc2CsgSolidShape(void* pEntity, bool bOwner);
    void setTreeRootExpression(gfc2::engine::EntityRef nValue);
    gfc2::engine::EntityRef getTreeRootExpression();
    bool hasTreeRootExpression();
    NGfc2BooleanResult^ getTreeRootExpressionPtr();

};
#endif
