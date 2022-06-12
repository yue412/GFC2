#include "NGfcGeometryShape.h"

using namespace gfc::classes::x3;

NGfcGeometryShape::NGfcGeometryShape()
{
    m_pEntity = new GfcGeometryShape;
    m_bOwner = true;
}

NGfcGeometryShape::NGfcGeometryShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcShape(pEntity, bOwner)
{
}

int NGfcGeometryShape::getGeosCount()
{
    return ((GfcGeometryShape*)m_pEntity)->getGeosCount();
}

void NGfcGeometryShape::clearGeos()
{
    ((GfcGeometryShape*)m_pEntity)->clearGeos();
}

void NGfcGeometryShape::addGeos(gfc::engine::EntityRef nValue)
{
    ((GfcGeometryShape*)m_pEntity)->addGeos(nValue);
}

gfc::engine::EntityRef NGfcGeometryShape::getGeos(int nIndex)
{
    return ((GfcGeometryShape*)m_pEntity)->getGeos(nIndex);
}

