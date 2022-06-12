#include "NGfcCylinderShape.h"

using namespace gfc::classes::x3;

NGfcCylinderShape::NGfcCylinderShape()
{
    m_pEntity = new GfcCylinderShape;
    m_bOwner = true;
}

NGfcCylinderShape::NGfcCylinderShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcPrimitiveShape(pEntity, bOwner)
{
}

void NGfcCylinderShape::setHeight(NGfcDouble dValue)
{
    ((GfcCylinderShape*)m_pEntity)->setHeight(dValue);
}

NGfcDouble NGfcCylinderShape::getHeight()
{
    return ((GfcCylinderShape*)m_pEntity)->getHeight();
}

bool NGfcCylinderShape::hasHeight()
{
    return ((GfcCylinderShape*)m_pEntity)->hasHeight();
}

void NGfcCylinderShape::setRadius(NGfcDouble dValue)
{
    ((GfcCylinderShape*)m_pEntity)->setRadius(dValue);
}

NGfcDouble NGfcCylinderShape::getRadius()
{
    return ((GfcCylinderShape*)m_pEntity)->getRadius();
}

bool NGfcCylinderShape::hasRadius()
{
    return ((GfcCylinderShape*)m_pEntity)->hasRadius();
}

