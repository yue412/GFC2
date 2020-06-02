#include "StdAfx.h"
#include "NGfc2CommonPolygonEx.h"
NGfc2CommonPolygonEx::NGfc2CommonPolygonEx()
{
    m_pEntity = new Gfc2CommonPolygonEx;
    m_bOwner = true;
}

NGfc2CommonPolygonEx::NGfc2CommonPolygonEx(void* pEntity, bool bOwner):
    NGfc2Polygon(pEntity, bOwner)
{
}

int NGfc2CommonPolygonEx::getLoopExsCount()
{
    return ((Gfc2CommonPolygonEx*)m_pEntity)->getLoopExsCount();
}

void NGfc2CommonPolygonEx::clearLoopExs()
{
    ((Gfc2CommonPolygonEx*)m_pEntity)->clearLoopExs();
}

void NGfc2CommonPolygonEx::addLoopExs(gfc2::engine::EntityRef nValue)
{
    ((Gfc2CommonPolygonEx*)m_pEntity)->addLoopExs(nValue);
}

gfc2::engine::EntityRef NGfc2CommonPolygonEx::getLoopExs(int nIndex)
{
    return ((Gfc2CommonPolygonEx*)m_pEntity)->getLoopExs(nIndex);
}

NGfc2CoedgeListEx^ NGfc2CommonPolygonEx::getLoopExsPtr(int nIndex)
{
    return gcnew NGfc2CoedgeListEx(((Gfc2CommonPolygonEx*)m_pEntity)->getLoopExsPtr(nIndex), false);
}

