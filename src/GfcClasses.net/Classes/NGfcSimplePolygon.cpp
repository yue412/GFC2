#include "NGfcSimplePolygon.h"

using namespace gfc::classes::x3;

NGfcSimplePolygon::NGfcSimplePolygon()
{
    m_pEntity = new GfcSimplePolygon;
    m_bOwner = true;
}

NGfcSimplePolygon::NGfcSimplePolygon(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcPolygon(pEntity, bOwner)
{
}

int NGfcSimplePolygon::getLoopsCount()
{
    return ((GfcSimplePolygon*)m_pEntity)->getLoopsCount();
}

void NGfcSimplePolygon::clearLoops()
{
    ((GfcSimplePolygon*)m_pEntity)->clearLoops();
}

void NGfcSimplePolygon::addLoops(gfc::engine::EntityRef nValue)
{
    ((GfcSimplePolygon*)m_pEntity)->addLoops(nValue);
}

gfc::engine::EntityRef NGfcSimplePolygon::getLoops(int nIndex)
{
    return ((GfcSimplePolygon*)m_pEntity)->getLoops(nIndex);
}

