#include "NGfcSurfaceCurveSweptAreaSolidShape.h"

using namespace gfc::classes::x3;

NGfcSurfaceCurveSweptAreaSolidShape::NGfcSurfaceCurveSweptAreaSolidShape()
{
    m_pEntity = new GfcSurfaceCurveSweptAreaSolidShape;
    m_bOwner = true;
}

NGfcSurfaceCurveSweptAreaSolidShape::NGfcSurfaceCurveSweptAreaSolidShape(bool bNoCreate):
    NGfcSweptAreaSolidShape(bNoCreate)
{
}

void NGfcSurfaceCurveSweptAreaSolidShape::setDirectrix(gfc::engine::EntityRef nValue)
{
    ((GfcSurfaceCurveSweptAreaSolidShape*)m_pEntity)->setDirectrix(nValue);
}

gfc::engine::EntityRef NGfcSurfaceCurveSweptAreaSolidShape::getDirectrix()
{
    return ((GfcSurfaceCurveSweptAreaSolidShape*)m_pEntity)->getDirectrix();
}

bool NGfcSurfaceCurveSweptAreaSolidShape::hasDirectrix()
{
    return ((GfcSurfaceCurveSweptAreaSolidShape*)m_pEntity)->hasDirectrix();
}

void NGfcSurfaceCurveSweptAreaSolidShape::setReferenceSurface(gfc::engine::EntityRef nValue)
{
    ((GfcSurfaceCurveSweptAreaSolidShape*)m_pEntity)->setReferenceSurface(nValue);
}

gfc::engine::EntityRef NGfcSurfaceCurveSweptAreaSolidShape::getReferenceSurface()
{
    return ((GfcSurfaceCurveSweptAreaSolidShape*)m_pEntity)->getReferenceSurface();
}

bool NGfcSurfaceCurveSweptAreaSolidShape::hasReferenceSurface()
{
    return ((GfcSurfaceCurveSweptAreaSolidShape*)m_pEntity)->hasReferenceSurface();
}

