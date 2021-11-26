#include "NGfc2CsgSolidShape.h"

using namespace gfc::classes::x3;

NGfc2CsgSolidShape::NGfc2CsgSolidShape()
{
    m_pEntity = new Gfc2CsgSolidShape;
    m_bOwner = true;
}

NGfc2CsgSolidShape::NGfc2CsgSolidShape(gfc::engine::CEntity* pEntity, bool bOwner):
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

