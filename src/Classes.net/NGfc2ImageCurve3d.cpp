#include "NGfc2ImageCurve3d.h"

using namespace gfc::classes::x3;

NGfc2ImageCurve3d::NGfc2ImageCurve3d()
{
    m_pEntity = new Gfc2ImageCurve3d;
    m_bOwner = true;
}

NGfc2ImageCurve3d::NGfc2ImageCurve3d(void* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

void NGfc2ImageCurve3d::setCurve(gfc::engine::EntityRef nValue)
{
    ((Gfc2ImageCurve3d*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfc2ImageCurve3d::getCurve()
{
    return ((Gfc2ImageCurve3d*)m_pEntity)->getCurve();
}

bool NGfc2ImageCurve3d::hasCurve()
{
    return ((Gfc2ImageCurve3d*)m_pEntity)->hasCurve();
}

void NGfc2ImageCurve3d::setSurface(gfc::engine::EntityRef nValue)
{
    ((Gfc2ImageCurve3d*)m_pEntity)->setSurface(nValue);
}

gfc::engine::EntityRef NGfc2ImageCurve3d::getSurface()
{
    return ((Gfc2ImageCurve3d*)m_pEntity)->getSurface();
}

bool NGfc2ImageCurve3d::hasSurface()
{
    return ((Gfc2ImageCurve3d*)m_pEntity)->hasSurface();
}

