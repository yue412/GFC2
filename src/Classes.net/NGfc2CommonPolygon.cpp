#include "StdAfx.h"
#include "NGfc2CommonPolygon.h"
NGfc2CommonPolygon::NGfc2CommonPolygon()
{
    m_pEntity = new Gfc2CommonPolygon;
    m_bOwner = true;
}

NGfc2CommonPolygon::NGfc2CommonPolygon(void* pEntity, bool bOwner):
    NGfc2Polygon(pEntity, bOwner)
{
}

int NGfc2CommonPolygon::getLoopsCount()
{
    return ((Gfc2CommonPolygon*)m_pEntity)->getLoopsCount();
}

void NGfc2CommonPolygon::clearLoops()
{
    ((Gfc2CommonPolygon*)m_pEntity)->clearLoops();
}

void NGfc2CommonPolygon::addLoops(gfc2::engine::EntityRef nValue)
{
    ((Gfc2CommonPolygon*)m_pEntity)->addLoops(nValue);
}

gfc2::engine::EntityRef NGfc2CommonPolygon::getLoops(int nIndex)
{
    return ((Gfc2CommonPolygon*)m_pEntity)->getLoops(nIndex);
}

NGfc2CoedgeList^ NGfc2CommonPolygon::getLoopsPtr(int nIndex)
{
    return gcnew NGfc2CoedgeList(((Gfc2CommonPolygon*)m_pEntity)->getLoopsPtr(nIndex), false);
}

