#include "StdAfx.h"
#include "NGfc2ImageCurve3d.h"
NGfc2ImageCurve3d::NGfc2ImageCurve3d()
{
    m_pEntity = new Gfc2ImageCurve3d;
    m_bOwner = true;
}

NGfc2ImageCurve3d::NGfc2ImageCurve3d(void* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

void NGfc2ImageCurve3d::setCurve(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ImageCurve3d*)m_pEntity)->setCurve(nValue);
}

gfc2::engine::EntityRef NGfc2ImageCurve3d::getCurve()
{
    return ((Gfc2ImageCurve3d*)m_pEntity)->getCurve();
}

bool NGfc2ImageCurve3d::hasCurve()
{
    return ((Gfc2ImageCurve3d*)m_pEntity)->hasCurve();
}

NGfc2Curve2d^ NGfc2ImageCurve3d::getCurvePtr()
{
    return gcnew NGfc2Curve2d(((Gfc2ImageCurve3d*)m_pEntity)->getCurvePtr(), false);
}

void NGfc2ImageCurve3d::setSurface(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ImageCurve3d*)m_pEntity)->setSurface(nValue);
}

gfc2::engine::EntityRef NGfc2ImageCurve3d::getSurface()
{
    return ((Gfc2ImageCurve3d*)m_pEntity)->getSurface();
}

bool NGfc2ImageCurve3d::hasSurface()
{
    return ((Gfc2ImageCurve3d*)m_pEntity)->hasSurface();
}

NGfc2Surface^ NGfc2ImageCurve3d::getSurfacePtr()
{
    return gcnew NGfc2Surface(((Gfc2ImageCurve3d*)m_pEntity)->getSurfacePtr(), false);
}

