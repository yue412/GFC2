#include "StdAfx.h"
#include "NGfc2PolarAxisGrid.h"
NGfc2PolarAxisGrid::NGfc2PolarAxisGrid()
{
    m_pEntity = new Gfc2PolarAxisGrid;
    m_bOwner = true;
}

NGfc2PolarAxisGrid::NGfc2PolarAxisGrid(void* pEntity, bool bOwner):
    NGfc2AxisGrid(pEntity, bOwner)
{
}

void NGfc2PolarAxisGrid::setInsertPt(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2PolarAxisGrid*)m_pEntity)->setInsertPt(nValue);
}

glodon::objectbuf::EntityRef NGfc2PolarAxisGrid::getInsertPt()
{
    return ((Gfc2PolarAxisGrid*)m_pEntity)->getInsertPt();
}

bool NGfc2PolarAxisGrid::hasInsertPt()
{
    return ((Gfc2PolarAxisGrid*)m_pEntity)->hasInsertPt();
}

NGfc2Vector2d^ NGfc2PolarAxisGrid::getInsertPtPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2PolarAxisGrid*)m_pEntity)->getInsertPtPtr(), false);
}

void NGfc2PolarAxisGrid::setStartRadius(NGfc2Double dValue)
{
    ((Gfc2PolarAxisGrid*)m_pEntity)->setStartRadius(dValue);
}

NGfc2Double NGfc2PolarAxisGrid::getStartRadius()
{
    return ((Gfc2PolarAxisGrid*)m_pEntity)->getStartRadius();
}

bool NGfc2PolarAxisGrid::hasStartRadius()
{
    return ((Gfc2PolarAxisGrid*)m_pEntity)->hasStartRadius();
}

void NGfc2PolarAxisGrid::setClockwise(NGfc2Boolean bValue)
{
    ((Gfc2PolarAxisGrid*)m_pEntity)->setClockwise(bValue);
}

NGfc2Boolean NGfc2PolarAxisGrid::getClockwise()
{
    return ((Gfc2PolarAxisGrid*)m_pEntity)->getClockwise();
}

bool NGfc2PolarAxisGrid::hasClockwise()
{
    return ((Gfc2PolarAxisGrid*)m_pEntity)->hasClockwise();
}

int NGfc2PolarAxisGrid::getXKJCount()
{
    return ((Gfc2PolarAxisGrid*)m_pEntity)->getXKJCount();
}

void NGfc2PolarAxisGrid::clearXKJ()
{
    ((Gfc2PolarAxisGrid*)m_pEntity)->clearXKJ();
}

void NGfc2PolarAxisGrid::addXKJ(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2PolarAxisGrid*)m_pEntity)->addXKJ(nValue);
}

glodon::objectbuf::EntityRef NGfc2PolarAxisGrid::getXKJ(int nIndex)
{
    return ((Gfc2PolarAxisGrid*)m_pEntity)->getXKJ(nIndex);
}

NGfc2AxisDataItem^ NGfc2PolarAxisGrid::getXKJPtr(int nIndex)
{
    return gcnew NGfc2AxisDataItem(((Gfc2PolarAxisGrid*)m_pEntity)->getXKJPtr(nIndex), false);
}

int NGfc2PolarAxisGrid::getZJSCount()
{
    return ((Gfc2PolarAxisGrid*)m_pEntity)->getZJSCount();
}

void NGfc2PolarAxisGrid::clearZJS()
{
    ((Gfc2PolarAxisGrid*)m_pEntity)->clearZJS();
}

void NGfc2PolarAxisGrid::addZJS(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2PolarAxisGrid*)m_pEntity)->addZJS(nValue);
}

glodon::objectbuf::EntityRef NGfc2PolarAxisGrid::getZJS(int nIndex)
{
    return ((Gfc2PolarAxisGrid*)m_pEntity)->getZJS(nIndex);
}

NGfc2AxisDataItem^ NGfc2PolarAxisGrid::getZJSPtr(int nIndex)
{
    return gcnew NGfc2AxisDataItem(((Gfc2PolarAxisGrid*)m_pEntity)->getZJSPtr(nIndex), false);
}

