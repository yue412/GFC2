#include "NGfcImageCurve3d.h"

using namespace gfc::classes::x3;

NGfcImageCurve3d::NGfcImageCurve3d()
{
    m_pEntity = new GfcImageCurve3d;
    m_bOwner = true;
}

NGfcImageCurve3d::NGfcImageCurve3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcCurve3d(pEntity, bOwner)
{
}

void NGfcImageCurve3d::setCurve(gfc::engine::EntityRef nValue)
{
    ((GfcImageCurve3d*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfcImageCurve3d::getCurve()
{
    return ((GfcImageCurve3d*)m_pEntity)->getCurve();
}

bool NGfcImageCurve3d::hasCurve()
{
    return ((GfcImageCurve3d*)m_pEntity)->hasCurve();
}

void NGfcImageCurve3d::setSurface(gfc::engine::EntityRef nValue)
{
    ((GfcImageCurve3d*)m_pEntity)->setSurface(nValue);
}

gfc::engine::EntityRef NGfcImageCurve3d::getSurface()
{
    return ((GfcImageCurve3d*)m_pEntity)->getSurface();
}

bool NGfcImageCurve3d::hasSurface()
{
    return ((GfcImageCurve3d*)m_pEntity)->hasSurface();
}

