#include "NGfc2CylinderShape.h"

using namespace gfc::classes::x3;

NGfc2CylinderShape::NGfc2CylinderShape()
{
    m_pEntity = new Gfc2CylinderShape;
    m_bOwner = true;
}

NGfc2CylinderShape::NGfc2CylinderShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2PrimitiveShape(pEntity, bOwner)
{
}

void NGfc2CylinderShape::setHeight(NGfc2Double dValue)
{
    ((Gfc2CylinderShape*)m_pEntity)->setHeight(dValue);
}

NGfc2Double NGfc2CylinderShape::getHeight()
{
    return ((Gfc2CylinderShape*)m_pEntity)->getHeight();
}

bool NGfc2CylinderShape::hasHeight()
{
    return ((Gfc2CylinderShape*)m_pEntity)->hasHeight();
}

void NGfc2CylinderShape::setRadius(NGfc2Double dValue)
{
    ((Gfc2CylinderShape*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2CylinderShape::getRadius()
{
    return ((Gfc2CylinderShape*)m_pEntity)->getRadius();
}

bool NGfc2CylinderShape::hasRadius()
{
    return ((Gfc2CylinderShape*)m_pEntity)->hasRadius();
}

