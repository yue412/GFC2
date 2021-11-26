#include "NGfc2SimplePolygon.h"

using namespace gfc::classes::x3;

NGfc2SimplePolygon::NGfc2SimplePolygon()
{
    m_pEntity = new Gfc2SimplePolygon;
    m_bOwner = true;
}

NGfc2SimplePolygon::NGfc2SimplePolygon(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Polygon(pEntity, bOwner)
{
}

int NGfc2SimplePolygon::getLoopsCount()
{
    return ((Gfc2SimplePolygon*)m_pEntity)->getLoopsCount();
}

void NGfc2SimplePolygon::clearLoops()
{
    ((Gfc2SimplePolygon*)m_pEntity)->clearLoops();
}

void NGfc2SimplePolygon::addLoops(gfc::engine::EntityRef nValue)
{
    ((Gfc2SimplePolygon*)m_pEntity)->addLoops(nValue);
}

gfc::engine::EntityRef NGfc2SimplePolygon::getLoops(int nIndex)
{
    return ((Gfc2SimplePolygon*)m_pEntity)->getLoops(nIndex);
}

