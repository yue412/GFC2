#include "NGfc2ConnectionCurveGeometry.h"

using namespace gfc::classes::x3;

NGfc2ConnectionCurveGeometry::NGfc2ConnectionCurveGeometry()
{
    m_pEntity = new Gfc2ConnectionCurveGeometry;
    m_bOwner = true;
}

NGfc2ConnectionCurveGeometry::NGfc2ConnectionCurveGeometry(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2ConnectionGeometry(pEntity, bOwner)
{
}

void NGfc2ConnectionCurveGeometry::setCurveOnRelatingElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2ConnectionCurveGeometry*)m_pEntity)->setCurveOnRelatingElement(nValue);
}

gfc::engine::EntityRef NGfc2ConnectionCurveGeometry::getCurveOnRelatingElement()
{
    return ((Gfc2ConnectionCurveGeometry*)m_pEntity)->getCurveOnRelatingElement();
}

bool NGfc2ConnectionCurveGeometry::hasCurveOnRelatingElement()
{
    return ((Gfc2ConnectionCurveGeometry*)m_pEntity)->hasCurveOnRelatingElement();
}

void NGfc2ConnectionCurveGeometry::setCurveOnRelatedElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2ConnectionCurveGeometry*)m_pEntity)->setCurveOnRelatedElement(nValue);
}

gfc::engine::EntityRef NGfc2ConnectionCurveGeometry::getCurveOnRelatedElement()
{
    return ((Gfc2ConnectionCurveGeometry*)m_pEntity)->getCurveOnRelatedElement();
}

bool NGfc2ConnectionCurveGeometry::hasCurveOnRelatedElement()
{
    return ((Gfc2ConnectionCurveGeometry*)m_pEntity)->hasCurveOnRelatedElement();
}

