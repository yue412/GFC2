#include "NGfc2SurfaceCurveSweptAreaSolidShape.h"

using namespace gfc::classes::x3;

NGfc2SurfaceCurveSweptAreaSolidShape::NGfc2SurfaceCurveSweptAreaSolidShape()
{
    m_pEntity = new Gfc2SurfaceCurveSweptAreaSolidShape;
    m_bOwner = true;
}

NGfc2SurfaceCurveSweptAreaSolidShape::NGfc2SurfaceCurveSweptAreaSolidShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2SweptAreaSolidShape(pEntity, bOwner)
{
}

void NGfc2SurfaceCurveSweptAreaSolidShape::setDirectrix(gfc::engine::EntityRef nValue)
{
    ((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->setDirectrix(nValue);
}

gfc::engine::EntityRef NGfc2SurfaceCurveSweptAreaSolidShape::getDirectrix()
{
    return ((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->getDirectrix();
}

bool NGfc2SurfaceCurveSweptAreaSolidShape::hasDirectrix()
{
    return ((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->hasDirectrix();
}

void NGfc2SurfaceCurveSweptAreaSolidShape::setReferenceSurface(gfc::engine::EntityRef nValue)
{
    ((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->setReferenceSurface(nValue);
}

gfc::engine::EntityRef NGfc2SurfaceCurveSweptAreaSolidShape::getReferenceSurface()
{
    return ((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->getReferenceSurface();
}

bool NGfc2SurfaceCurveSweptAreaSolidShape::hasReferenceSurface()
{
    return ((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->hasReferenceSurface();
}

