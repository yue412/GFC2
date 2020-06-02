#include "StdAfx.h"
#include "NGfc2ConnectionCurveGeometry.h"
NGfc2ConnectionCurveGeometry::NGfc2ConnectionCurveGeometry()
{
    m_pEntity = new Gfc2ConnectionCurveGeometry;
    m_bOwner = true;
}

NGfc2ConnectionCurveGeometry::NGfc2ConnectionCurveGeometry(void* pEntity, bool bOwner):
    NGfc2ConnectionGeometry(pEntity, bOwner)
{
}

void NGfc2ConnectionCurveGeometry::setCurveOnRelatingElement(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ConnectionCurveGeometry*)m_pEntity)->setCurveOnRelatingElement(nValue);
}

gfc2::engine::EntityRef NGfc2ConnectionCurveGeometry::getCurveOnRelatingElement()
{
    return ((Gfc2ConnectionCurveGeometry*)m_pEntity)->getCurveOnRelatingElement();
}

bool NGfc2ConnectionCurveGeometry::hasCurveOnRelatingElement()
{
    return ((Gfc2ConnectionCurveGeometry*)m_pEntity)->hasCurveOnRelatingElement();
}

NGfc2Curve3d^ NGfc2ConnectionCurveGeometry::getCurveOnRelatingElementPtr()
{
    return gcnew NGfc2Curve3d(((Gfc2ConnectionCurveGeometry*)m_pEntity)->getCurveOnRelatingElementPtr(), false);
}

void NGfc2ConnectionCurveGeometry::setCurveOnRelatedElement(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ConnectionCurveGeometry*)m_pEntity)->setCurveOnRelatedElement(nValue);
}

gfc2::engine::EntityRef NGfc2ConnectionCurveGeometry::getCurveOnRelatedElement()
{
    return ((Gfc2ConnectionCurveGeometry*)m_pEntity)->getCurveOnRelatedElement();
}

bool NGfc2ConnectionCurveGeometry::hasCurveOnRelatedElement()
{
    return ((Gfc2ConnectionCurveGeometry*)m_pEntity)->hasCurveOnRelatedElement();
}

NGfc2Curve3d^ NGfc2ConnectionCurveGeometry::getCurveOnRelatedElementPtr()
{
    return gcnew NGfc2Curve3d(((Gfc2ConnectionCurveGeometry*)m_pEntity)->getCurveOnRelatedElementPtr(), false);
}

