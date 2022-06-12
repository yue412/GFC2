#include "NGfcConnectionCurveGeometry.h"

using namespace gfc::classes::x3;

NGfcConnectionCurveGeometry::NGfcConnectionCurveGeometry()
{
    m_pEntity = new GfcConnectionCurveGeometry;
    m_bOwner = true;
}

NGfcConnectionCurveGeometry::NGfcConnectionCurveGeometry(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcConnectionGeometry(pEntity, bOwner)
{
}

void NGfcConnectionCurveGeometry::setCurveOnRelatingElement(gfc::engine::EntityRef nValue)
{
    ((GfcConnectionCurveGeometry*)m_pEntity)->setCurveOnRelatingElement(nValue);
}

gfc::engine::EntityRef NGfcConnectionCurveGeometry::getCurveOnRelatingElement()
{
    return ((GfcConnectionCurveGeometry*)m_pEntity)->getCurveOnRelatingElement();
}

bool NGfcConnectionCurveGeometry::hasCurveOnRelatingElement()
{
    return ((GfcConnectionCurveGeometry*)m_pEntity)->hasCurveOnRelatingElement();
}

void NGfcConnectionCurveGeometry::setCurveOnRelatedElement(gfc::engine::EntityRef nValue)
{
    ((GfcConnectionCurveGeometry*)m_pEntity)->setCurveOnRelatedElement(nValue);
}

gfc::engine::EntityRef NGfcConnectionCurveGeometry::getCurveOnRelatedElement()
{
    return ((GfcConnectionCurveGeometry*)m_pEntity)->getCurveOnRelatedElement();
}

bool NGfcConnectionCurveGeometry::hasCurveOnRelatedElement()
{
    return ((GfcConnectionCurveGeometry*)m_pEntity)->hasCurveOnRelatedElement();
}

