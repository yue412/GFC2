#include "NGfc2GeometryShape.h"

using namespace gfc::classes::x3;

NGfc2GeometryShape::NGfc2GeometryShape()
{
    m_pEntity = new Gfc2GeometryShape;
    m_bOwner = true;
}

NGfc2GeometryShape::NGfc2GeometryShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Shape(pEntity, bOwner)
{
}

int NGfc2GeometryShape::getGeosCount()
{
    return ((Gfc2GeometryShape*)m_pEntity)->getGeosCount();
}

void NGfc2GeometryShape::clearGeos()
{
    ((Gfc2GeometryShape*)m_pEntity)->clearGeos();
}

void NGfc2GeometryShape::addGeos(gfc::engine::EntityRef nValue)
{
    ((Gfc2GeometryShape*)m_pEntity)->addGeos(nValue);
}

gfc::engine::EntityRef NGfc2GeometryShape::getGeos(int nIndex)
{
    return ((Gfc2GeometryShape*)m_pEntity)->getGeos(nIndex);
}

