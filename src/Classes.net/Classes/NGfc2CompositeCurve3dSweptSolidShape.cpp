#include "NGfc2CompositeCurve3dSweptSolidShape.h"

using namespace gfc::classes::x3;

NGfc2CompositeCurve3dSweptSolidShape::NGfc2CompositeCurve3dSweptSolidShape()
{
    m_pEntity = new Gfc2CompositeCurve3dSweptSolidShape;
    m_bOwner = true;
}

NGfc2CompositeCurve3dSweptSolidShape::NGfc2CompositeCurve3dSweptSolidShape(gfc::engine::CEntity* pEntity, bool bOwner):
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

