#include "NGfcCompositeCurve3dSweptSolidShape.h"

using namespace gfc::classes::x3;

NGfcCompositeCurve3dSweptSolidShape::NGfcCompositeCurve3dSweptSolidShape()
{
    m_pEntity = new GfcCompositeCurve3dSweptSolidShape;
    m_bOwner = true;
}

NGfcCompositeCurve3dSweptSolidShape::NGfcCompositeCurve3dSweptSolidShape(bool bNoCreate):
    NGfcSweptAreaSolidShape(bNoCreate)
{
}

int NGfcCompositeCurve3dSweptSolidShape::getSegmentsCount()
{
    return ((GfcCompositeCurve3dSweptSolidShape*)m_pEntity)->getSegmentsCount();
}

void NGfcCompositeCurve3dSweptSolidShape::clearSegments()
{
    ((GfcCompositeCurve3dSweptSolidShape*)m_pEntity)->clearSegments();
}

void NGfcCompositeCurve3dSweptSolidShape::addSegments(gfc::engine::EntityRef nValue)
{
    ((GfcCompositeCurve3dSweptSolidShape*)m_pEntity)->addSegments(nValue);
}

gfc::engine::EntityRef NGfcCompositeCurve3dSweptSolidShape::getSegments(int nIndex)
{
    return ((GfcCompositeCurve3dSweptSolidShape*)m_pEntity)->getSegments(nIndex);
}

int NGfcCompositeCurve3dSweptSolidShape::getReferencesCount()
{
    return ((GfcCompositeCurve3dSweptSolidShape*)m_pEntity)->getReferencesCount();
}

void NGfcCompositeCurve3dSweptSolidShape::clearReferences()
{
    ((GfcCompositeCurve3dSweptSolidShape*)m_pEntity)->clearReferences();
}

void NGfcCompositeCurve3dSweptSolidShape::addReferences(gfc::engine::EntityRef nValue)
{
    ((GfcCompositeCurve3dSweptSolidShape*)m_pEntity)->addReferences(nValue);
}

gfc::engine::EntityRef NGfcCompositeCurve3dSweptSolidShape::getReferences(int nIndex)
{
    return ((GfcCompositeCurve3dSweptSolidShape*)m_pEntity)->getReferences(nIndex);
}

