#include "NGfcLine2d.h"

using namespace gfc::classes::x3;

NGfcLine2d::NGfcLine2d()
{
    m_pEntity = new GfcLine2d;
    m_bOwner = true;
}

NGfcLine2d::NGfcLine2d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcCurve2d(pEntity, bOwner)
{
}

void NGfcLine2d::setStartPt(gfc::engine::EntityRef nValue)
{
    ((GfcLine2d*)m_pEntity)->setStartPt(nValue);
}

gfc::engine::EntityRef NGfcLine2d::getStartPt()
{
    return ((GfcLine2d*)m_pEntity)->getStartPt();
}

bool NGfcLine2d::hasStartPt()
{
    return ((GfcLine2d*)m_pEntity)->hasStartPt();
}

void NGfcLine2d::setEndPt(gfc::engine::EntityRef nValue)
{
    ((GfcLine2d*)m_pEntity)->setEndPt(nValue);
}

gfc::engine::EntityRef NGfcLine2d::getEndPt()
{
    return ((GfcLine2d*)m_pEntity)->getEndPt();
}

bool NGfcLine2d::hasEndPt()
{
    return ((GfcLine2d*)m_pEntity)->hasEndPt();
}

