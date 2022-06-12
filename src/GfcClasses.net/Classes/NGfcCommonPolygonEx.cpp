#include "NGfcCommonPolygonEx.h"

using namespace gfc::classes::x3;

NGfcCommonPolygonEx::NGfcCommonPolygonEx()
{
    m_pEntity = new GfcCommonPolygonEx;
    m_bOwner = true;
}

NGfcCommonPolygonEx::NGfcCommonPolygonEx(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcPolygon(pEntity, bOwner)
{
}

int NGfcCommonPolygonEx::getLoopExsCount()
{
    return ((GfcCommonPolygonEx*)m_pEntity)->getLoopExsCount();
}

void NGfcCommonPolygonEx::clearLoopExs()
{
    ((GfcCommonPolygonEx*)m_pEntity)->clearLoopExs();
}

void NGfcCommonPolygonEx::addLoopExs(gfc::engine::EntityRef nValue)
{
    ((GfcCommonPolygonEx*)m_pEntity)->addLoopExs(nValue);
}

gfc::engine::EntityRef NGfcCommonPolygonEx::getLoopExs(int nIndex)
{
    return ((GfcCommonPolygonEx*)m_pEntity)->getLoopExs(nIndex);
}

