#include "StdAfx.h"
#include "NGfc2CsgSolidShape.h"
NGfc2CsgSolidShape::NGfc2CsgSolidShape()
{
    m_pEntity = new Gfc2CsgSolidShape;
    m_bOwner = true;
}

NGfc2CsgSolidShape::NGfc2CsgSolidShape(void* pEntity, bool bOwner):
    NGfc2SolidShape(pEntity, bOwner)
{
}

void NGfc2CsgSolidShape::setTreeRootExpression(gfc::engine::EntityRef nValue)
{
    ((Gfc2CsgSolidShape*)m_pEntity)->setTreeRootExpression(nValue);
}

gfc::engine::EntityRef NGfc2CsgSolidShape::getTreeRootExpression()
{
    return ((Gfc2CsgSolidShape*)m_pEntity)->getTreeRootExpression();
}

bool NGfc2CsgSolidShape::hasTreeRootExpression()
{
    return ((Gfc2CsgSolidShape*)m_pEntity)->hasTreeRootExpression();
}

NGfc2BooleanResult^ NGfc2CsgSolidShape::getTreeRootExpressionPtr()
{
    return gcnew NGfc2BooleanResult(((Gfc2CsgSolidShape*)m_pEntity)->getTreeRootExpressionPtr(), false);
}

