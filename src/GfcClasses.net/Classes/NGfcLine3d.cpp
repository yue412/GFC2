#include "NGfcLine3d.h"

using namespace gfc::classes::x3;

NGfcLine3d::NGfcLine3d()
{
    m_pEntity = new GfcLine3d;
    m_bOwner = true;
}

NGfcLine3d::NGfcLine3d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcCurve3d(pEntity, bOwner)
{
}

void NGfcLine3d::setStartPt(gfc::engine::EntityRef nValue)
{
    ((GfcLine3d*)m_pEntity)->setStartPt(nValue);
}

gfc::engine::EntityRef NGfcLine3d::getStartPt()
{
    return ((GfcLine3d*)m_pEntity)->getStartPt();
}

bool NGfcLine3d::hasStartPt()
{
    return ((GfcLine3d*)m_pEntity)->hasStartPt();
}

void NGfcLine3d::setEndPt(gfc::engine::EntityRef nValue)
{
    ((GfcLine3d*)m_pEntity)->setEndPt(nValue);
}

gfc::engine::EntityRef NGfcLine3d::getEndPt()
{
    return ((GfcLine3d*)m_pEntity)->getEndPt();
}

bool NGfcLine3d::hasEndPt()
{
    return ((GfcLine3d*)m_pEntity)->hasEndPt();
}

