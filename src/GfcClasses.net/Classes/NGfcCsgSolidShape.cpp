#include "NGfcCsgSolidShape.h"

using namespace gfc::classes::x3;

NGfcCsgSolidShape::NGfcCsgSolidShape()
{
    m_pEntity = new GfcCsgSolidShape;
    m_bOwner = true;
}

NGfcCsgSolidShape::NGfcCsgSolidShape(bool bNoCreate):
    NGfcSolidShape(bNoCreate)
{
}

void NGfcCsgSolidShape::setTreeRootExpression(gfc::engine::EntityRef nValue)
{
    ((GfcCsgSolidShape*)m_pEntity)->setTreeRootExpression(nValue);
}

gfc::engine::EntityRef NGfcCsgSolidShape::getTreeRootExpression()
{
    return ((GfcCsgSolidShape*)m_pEntity)->getTreeRootExpression();
}

bool NGfcCsgSolidShape::hasTreeRootExpression()
{
    return ((GfcCsgSolidShape*)m_pEntity)->hasTreeRootExpression();
}

