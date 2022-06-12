#include "NGfcCompositeCurve2dSweptSolidShape.h"

using namespace gfc::classes::x3;

NGfcCompositeCurve2dSweptSolidShape::NGfcCompositeCurve2dSweptSolidShape()
{
    m_pEntity = new GfcCompositeCurve2dSweptSolidShape;
    m_bOwner = true;
}

NGfcCompositeCurve2dSweptSolidShape::NGfcCompositeCurve2dSweptSolidShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSweptAreaSolidShape(pEntity, bOwner)
{
}

int NGfcCompositeCurve2dSweptSolidShape::getSegmentsCount()
{
    return ((GfcCompositeCurve2dSweptSolidShape*)m_pEntity)->getSegmentsCount();
}

void NGfcCompositeCurve2dSweptSolidShape::clearSegments()
{
    ((GfcCompositeCurve2dSweptSolidShape*)m_pEntity)->clearSegments();
}

void NGfcCompositeCurve2dSweptSolidShape::addSegments(gfc::engine::EntityRef nValue)
{
    ((GfcCompositeCurve2dSweptSolidShape*)m_pEntity)->addSegments(nValue);
}

gfc::engine::EntityRef NGfcCompositeCurve2dSweptSolidShape::getSegments(int nIndex)
{
    return ((GfcCompositeCurve2dSweptSolidShape*)m_pEntity)->getSegments(nIndex);
}

