#include "NGfcCommonPolygon.h"

using namespace gfc::classes::x3;

NGfcCommonPolygon::NGfcCommonPolygon()
{
    m_pEntity = new GfcCommonPolygon;
    m_bOwner = true;
}

NGfcCommonPolygon::NGfcCommonPolygon(bool bNoCreate):
    NGfcPolygon(bNoCreate)
{
}

int NGfcCommonPolygon::getLoopsCount()
{
    return ((GfcCommonPolygon*)m_pEntity)->getLoopsCount();
}

void NGfcCommonPolygon::clearLoops()
{
    ((GfcCommonPolygon*)m_pEntity)->clearLoops();
}

void NGfcCommonPolygon::addLoops(gfc::engine::EntityRef nValue)
{
    ((GfcCommonPolygon*)m_pEntity)->addLoops(nValue);
}

gfc::engine::EntityRef NGfcCommonPolygon::getLoops(int nIndex)
{
    return ((GfcCommonPolygon*)m_pEntity)->getLoops(nIndex);
}

