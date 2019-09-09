#include "StdAfx.h"
#include "NGfc2CartesianAxisGrid.h"
NGfc2CartesianAxisGrid::NGfc2CartesianAxisGrid()
{
    m_pEntity = new Gfc2CartesianAxisGrid;
    m_bOwner = true;
}

NGfc2CartesianAxisGrid::NGfc2CartesianAxisGrid(void* pEntity, bool bOwner):
    NGfc2AxisGrid(pEntity, bOwner)
{
}

void NGfc2CartesianAxisGrid::setInsertPt(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CartesianAxisGrid*)m_pEntity)->setInsertPt(nValue);
}

glodon::objectbuf::EntityRef NGfc2CartesianAxisGrid::getInsertPt()
{
    return ((Gfc2CartesianAxisGrid*)m_pEntity)->getInsertPt();
}

bool NGfc2CartesianAxisGrid::hasInsertPt()
{
    return ((Gfc2CartesianAxisGrid*)m_pEntity)->hasInsertPt();
}

NGfc2Vector2d^ NGfc2CartesianAxisGrid::getInsertPtPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2CartesianAxisGrid*)m_pEntity)->getInsertPtPtr(), false);
}

void NGfc2CartesianAxisGrid::setAxisAngle(NGfc2Double dValue)
{
    ((Gfc2CartesianAxisGrid*)m_pEntity)->setAxisAngle(dValue);
}

NGfc2Double NGfc2CartesianAxisGrid::getAxisAngle()
{
    return ((Gfc2CartesianAxisGrid*)m_pEntity)->getAxisAngle();
}

bool NGfc2CartesianAxisGrid::hasAxisAngle()
{
    return ((Gfc2CartesianAxisGrid*)m_pEntity)->hasAxisAngle();
}

int NGfc2CartesianAxisGrid::getSKJCount()
{
    return ((Gfc2CartesianAxisGrid*)m_pEntity)->getSKJCount();
}

void NGfc2CartesianAxisGrid::clearSKJ()
{
    ((Gfc2CartesianAxisGrid*)m_pEntity)->clearSKJ();
}

void NGfc2CartesianAxisGrid::addSKJ(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CartesianAxisGrid*)m_pEntity)->addSKJ(nValue);
}

glodon::objectbuf::EntityRef NGfc2CartesianAxisGrid::getSKJ(int nIndex)
{
    return ((Gfc2CartesianAxisGrid*)m_pEntity)->getSKJ(nIndex);
}

NGfc2AxisDataItem^ NGfc2CartesianAxisGrid::getSKJPtr(int nIndex)
{
    return gcnew NGfc2AxisDataItem(((Gfc2CartesianAxisGrid*)m_pEntity)->getSKJPtr(nIndex), false);
}

int NGfc2CartesianAxisGrid::getZJSCount()
{
    return ((Gfc2CartesianAxisGrid*)m_pEntity)->getZJSCount();
}

void NGfc2CartesianAxisGrid::clearZJS()
{
    ((Gfc2CartesianAxisGrid*)m_pEntity)->clearZJS();
}

void NGfc2CartesianAxisGrid::addZJS(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CartesianAxisGrid*)m_pEntity)->addZJS(nValue);
}

glodon::objectbuf::EntityRef NGfc2CartesianAxisGrid::getZJS(int nIndex)
{
    return ((Gfc2CartesianAxisGrid*)m_pEntity)->getZJS(nIndex);
}

NGfc2AxisDataItem^ NGfc2CartesianAxisGrid::getZJSPtr(int nIndex)
{
    return gcnew NGfc2AxisDataItem(((Gfc2CartesianAxisGrid*)m_pEntity)->getZJSPtr(nIndex), false);
}

int NGfc2CartesianAxisGrid::getYJSCount()
{
    return ((Gfc2CartesianAxisGrid*)m_pEntity)->getYJSCount();
}

void NGfc2CartesianAxisGrid::clearYJS()
{
    ((Gfc2CartesianAxisGrid*)m_pEntity)->clearYJS();
}

void NGfc2CartesianAxisGrid::addYJS(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CartesianAxisGrid*)m_pEntity)->addYJS(nValue);
}

glodon::objectbuf::EntityRef NGfc2CartesianAxisGrid::getYJS(int nIndex)
{
    return ((Gfc2CartesianAxisGrid*)m_pEntity)->getYJS(nIndex);
}

NGfc2AxisDataItem^ NGfc2CartesianAxisGrid::getYJSPtr(int nIndex)
{
    return gcnew NGfc2AxisDataItem(((Gfc2CartesianAxisGrid*)m_pEntity)->getYJSPtr(nIndex), false);
}

int NGfc2CartesianAxisGrid::getXKJCount()
{
    return ((Gfc2CartesianAxisGrid*)m_pEntity)->getXKJCount();
}

void NGfc2CartesianAxisGrid::clearXKJ()
{
    ((Gfc2CartesianAxisGrid*)m_pEntity)->clearXKJ();
}

void NGfc2CartesianAxisGrid::addXKJ(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CartesianAxisGrid*)m_pEntity)->addXKJ(nValue);
}

glodon::objectbuf::EntityRef NGfc2CartesianAxisGrid::getXKJ(int nIndex)
{
    return ((Gfc2CartesianAxisGrid*)m_pEntity)->getXKJ(nIndex);
}

NGfc2AxisDataItem^ NGfc2CartesianAxisGrid::getXKJPtr(int nIndex)
{
    return gcnew NGfc2AxisDataItem(((Gfc2CartesianAxisGrid*)m_pEntity)->getXKJPtr(nIndex), false);
}

