#include "StdAfx.h"
#include "NGfc2CompositeCurve3dSweptSolidShape.h"
NGfc2CompositeCurve3dSweptSolidShape::NGfc2CompositeCurve3dSweptSolidShape()
{
    m_pEntity = new Gfc2CompositeCurve3dSweptSolidShape;
    m_bOwner = true;
}

NGfc2CompositeCurve3dSweptSolidShape::NGfc2CompositeCurve3dSweptSolidShape(void* pEntity, bool bOwner):
    NGfc2SweptAreaSolidShape(pEntity, bOwner)
{
}

int NGfc2CompositeCurve3dSweptSolidShape::getSegmentsCount()
{
    return ((Gfc2CompositeCurve3dSweptSolidShape*)m_pEntity)->getSegmentsCount();
}

void NGfc2CompositeCurve3dSweptSolidShape::clearSegments()
{
    ((Gfc2CompositeCurve3dSweptSolidShape*)m_pEntity)->clearSegments();
}

void NGfc2CompositeCurve3dSweptSolidShape::addSegments(gfc::engine::EntityRef nValue)
{
    ((Gfc2CompositeCurve3dSweptSolidShape*)m_pEntity)->addSegments(nValue);
}

gfc::engine::EntityRef NGfc2CompositeCurve3dSweptSolidShape::getSegments(int nIndex)
{
    return ((Gfc2CompositeCurve3dSweptSolidShape*)m_pEntity)->getSegments(nIndex);
}

NGfc2Curve3d^ NGfc2CompositeCurve3dSweptSolidShape::getSegmentsPtr(int nIndex)
{
    return gcnew NGfc2Curve3d(((Gfc2CompositeCurve3dSweptSolidShape*)m_pEntity)->getSegmentsPtr(nIndex), false);
}

int NGfc2CompositeCurve3dSweptSolidShape::getReferencesCount()
{
    return ((Gfc2CompositeCurve3dSweptSolidShape*)m_pEntity)->getReferencesCount();
}

void NGfc2CompositeCurve3dSweptSolidShape::clearReferences()
{
    ((Gfc2CompositeCurve3dSweptSolidShape*)m_pEntity)->clearReferences();
}

void NGfc2CompositeCurve3dSweptSolidShape::addReferences(gfc::engine::EntityRef nValue)
{
    ((Gfc2CompositeCurve3dSweptSolidShape*)m_pEntity)->addReferences(nValue);
}

gfc::engine::EntityRef NGfc2CompositeCurve3dSweptSolidShape::getReferences(int nIndex)
{
    return ((Gfc2CompositeCurve3dSweptSolidShape*)m_pEntity)->getReferences(nIndex);
}

NGfc2Surface^ NGfc2CompositeCurve3dSweptSolidShape::getReferencesPtr(int nIndex)
{
    return gcnew NGfc2Surface(((Gfc2CompositeCurve3dSweptSolidShape*)m_pEntity)->getReferencesPtr(nIndex), false);
}

