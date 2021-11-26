#include "NGfc2ManifoldSolidShape.h"

using namespace gfc::classes::x3;

NGfc2ManifoldSolidShape::NGfc2ManifoldSolidShape()
{
    m_pEntity = new Gfc2ManifoldSolidShape;
    m_bOwner = true;
}

NGfc2ManifoldSolidShape::NGfc2ManifoldSolidShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2SolidShape(pEntity, bOwner)
{
}

void NGfc2ManifoldSolidShape::setBody(gfc::engine::EntityRef nValue)
{
    ((Gfc2ManifoldSolidShape*)m_pEntity)->setBody(nValue);
}

gfc::engine::EntityRef NGfc2ManifoldSolidShape::getBody()
{
    return ((Gfc2ManifoldSolidShape*)m_pEntity)->getBody();
}

bool NGfc2ManifoldSolidShape::hasBody()
{
    return ((Gfc2ManifoldSolidShape*)m_pEntity)->hasBody();
}

