#include "StdAfx.h"
#include "NGfc2SurfaceCurveSweptAreaSolidShape.h"
NGfc2SurfaceCurveSweptAreaSolidShape::NGfc2SurfaceCurveSweptAreaSolidShape()
{
    m_pEntity = new Gfc2SurfaceCurveSweptAreaSolidShape;
    m_bOwner = true;
}

NGfc2SurfaceCurveSweptAreaSolidShape::NGfc2SurfaceCurveSweptAreaSolidShape(void* pEntity, bool bOwner):
    NGfc2SweptAreaSolidShape(pEntity, bOwner)
{
}

void NGfc2SurfaceCurveSweptAreaSolidShape::setDirectrix(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->setDirectrix(nValue);
}

glodon::objectbuf::EntityRef NGfc2SurfaceCurveSweptAreaSolidShape::getDirectrix()
{
    return ((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->getDirectrix();
}

bool NGfc2SurfaceCurveSweptAreaSolidShape::hasDirectrix()
{
    return ((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->hasDirectrix();
}

NGfc2Curve3d^ NGfc2SurfaceCurveSweptAreaSolidShape::getDirectrixPtr()
{
    return gcnew NGfc2Curve3d(((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->getDirectrixPtr(), false);
}

void NGfc2SurfaceCurveSweptAreaSolidShape::setReferenceSurface(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->setReferenceSurface(nValue);
}

glodon::objectbuf::EntityRef NGfc2SurfaceCurveSweptAreaSolidShape::getReferenceSurface()
{
    return ((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->getReferenceSurface();
}

bool NGfc2SurfaceCurveSweptAreaSolidShape::hasReferenceSurface()
{
    return ((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->hasReferenceSurface();
}

NGfc2Surface^ NGfc2SurfaceCurveSweptAreaSolidShape::getReferenceSurfacePtr()
{
    return gcnew NGfc2Surface(((Gfc2SurfaceCurveSweptAreaSolidShape*)m_pEntity)->getReferenceSurfacePtr(), false);
}

