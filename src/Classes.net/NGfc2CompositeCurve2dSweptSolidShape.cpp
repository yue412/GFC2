#include "StdAfx.h"
#include "NGfc2CompositeCurve2dSweptSolidShape.h"
NGfc2CompositeCurve2dSweptSolidShape::NGfc2CompositeCurve2dSweptSolidShape()
{
    m_pEntity = new Gfc2CompositeCurve2dSweptSolidShape;
    m_bOwner = true;
}

NGfc2CompositeCurve2dSweptSolidShape::NGfc2CompositeCurve2dSweptSolidShape(void* pEntity, bool bOwner):
    NGfc2SweptAreaSolidShape(pEntity, bOwner)
{
}

int NGfc2CompositeCurve2dSweptSolidShape::getSegmentsCount()
{
    return ((Gfc2CompositeCurve2dSweptSolidShape*)m_pEntity)->getSegmentsCount();
}

void NGfc2CompositeCurve2dSweptSolidShape::clearSegments()
{
    ((Gfc2CompositeCurve2dSweptSolidShape*)m_pEntity)->clearSegments();
}

void NGfc2CompositeCurve2dSweptSolidShape::addSegments(gfc2::engine::EntityRef nValue)
{
    ((Gfc2CompositeCurve2dSweptSolidShape*)m_pEntity)->addSegments(nValue);
}

gfc2::engine::EntityRef NGfc2CompositeCurve2dSweptSolidShape::getSegments(int nIndex)
{
    return ((Gfc2CompositeCurve2dSweptSolidShape*)m_pEntity)->getSegments(nIndex);
}

NGfc2Curve2d^ NGfc2CompositeCurve2dSweptSolidShape::getSegmentsPtr(int nIndex)
{
    return gcnew NGfc2Curve2d(((Gfc2CompositeCurve2dSweptSolidShape*)m_pEntity)->getSegmentsPtr(nIndex), false);
}

