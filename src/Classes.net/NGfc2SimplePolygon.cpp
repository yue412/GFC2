#include "StdAfx.h"
#include "NGfc2SimplePolygon.h"
NGfc2SimplePolygon::NGfc2SimplePolygon()
{
    m_pEntity = new Gfc2SimplePolygon;
    m_bOwner = true;
}

NGfc2SimplePolygon::NGfc2SimplePolygon(void* pEntity, bool bOwner):
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

void NGfc2SimplePolygon::addLoops(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SimplePolygon*)m_pEntity)->addLoops(nValue);
}

glodon::objectbuf::EntityRef NGfc2SimplePolygon::getLoops(int nIndex)
{
    return ((Gfc2SimplePolygon*)m_pEntity)->getLoops(nIndex);
}

NGfc2SimpleLoop^ NGfc2SimplePolygon::getLoopsPtr(int nIndex)
{
    return gcnew NGfc2SimpleLoop(((Gfc2SimplePolygon*)m_pEntity)->getLoopsPtr(nIndex), false);
}

