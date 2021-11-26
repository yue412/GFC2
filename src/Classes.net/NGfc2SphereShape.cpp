#include "NGfc2SphereShape.h"

using namespace gfc::classes::x3;

NGfc2SphereShape::NGfc2SphereShape()
{
    m_pEntity = new Gfc2SphereShape;
    m_bOwner = true;
}

NGfc2SphereShape::NGfc2SphereShape(void* pEntity, bool bOwner):
    NGfc2PrimitiveShape(pEntity, bOwner)
{
}

void NGfc2SphereShape::setRadius(NGfc2Double dValue)
{
    ((Gfc2SphereShape*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2SphereShape::getRadius()
{
    return ((Gfc2SphereShape*)m_pEntity)->getRadius();
}

bool NGfc2SphereShape::hasRadius()
{
    return ((Gfc2SphereShape*)m_pEntity)->hasRadius();
}

