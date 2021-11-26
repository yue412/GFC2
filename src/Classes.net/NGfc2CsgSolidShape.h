#ifndef NGFC2CSGSOLIDSHAPE_H
#define NGFC2CSGSOLIDSHAPE_H

#include "NGfc2SolidShape.h"
#include "GfcClasses\x3\Gfc2CsgSolidShape.h"
#include "NGfc2BooleanResult.h"

public ref class NGfc2CsgSolidShape: public NGfc2SolidShape
{
public:
    NGfc2CsgSolidShape();
    NGfc2CsgSolidShape(void* pEntity, bool bOwner);
    void setTreeRootExpression(gfc::engine::EntityRef nValue);
    gfc::engine::EntityRef getTreeRootExpression();
    bool hasTreeRootExpression();

};
#endif
