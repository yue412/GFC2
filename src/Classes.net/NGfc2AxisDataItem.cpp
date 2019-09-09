#include "StdAfx.h"
#include "NGfc2AxisDataItem.h"
NGfc2AxisDataItem::NGfc2AxisDataItem()
{
    m_pEntity = new Gfc2AxisDataItem;
    m_bOwner = true;
}

NGfc2AxisDataItem::NGfc2AxisDataItem(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2AxisDataItem::setAxisNo(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2AxisDataItem*)m_pEntity)->setAxisNo(nValue);
}

glodon::objectbuf::EntityRef NGfc2AxisDataItem::getAxisNo()
{
    return ((Gfc2AxisDataItem*)m_pEntity)->getAxisNo();
}

bool NGfc2AxisDataItem::hasAxisNo()
{
    return ((Gfc2AxisDataItem*)m_pEntity)->hasAxisNo();
}

NGfc2Label^ NGfc2AxisDataItem::getAxisNoPtr()
{
    return gcnew NGfc2Label(((Gfc2AxisDataItem*)m_pEntity)->getAxisNoPtr(), false);
}

void NGfc2AxisDataItem::setDistance(NGfc2Double dValue)
{
    ((Gfc2AxisDataItem*)m_pEntity)->setDistance(dValue);
}

NGfc2Double NGfc2AxisDataItem::getDistance()
{
    return ((Gfc2AxisDataItem*)m_pEntity)->getDistance();
}

bool NGfc2AxisDataItem::hasDistance()
{
    return ((Gfc2AxisDataItem*)m_pEntity)->hasDistance();
}

void NGfc2AxisDataItem::setLevel(NGfc2Integer nValue)
{
    ((Gfc2AxisDataItem*)m_pEntity)->setLevel(nValue);
}

NGfc2Integer NGfc2AxisDataItem::getLevel()
{
    return ((Gfc2AxisDataItem*)m_pEntity)->getLevel();
}

bool NGfc2AxisDataItem::hasLevel()
{
    return ((Gfc2AxisDataItem*)m_pEntity)->hasLevel();
}

void NGfc2AxisDataItem::setAxisNoPos(NGfc2AxisNoPosEnum nValue)
{
    ((Gfc2AxisDataItem*)m_pEntity)->setAxisNoPos((Gfc2AxisNoPosEnum)nValue);
}

NGfc2AxisNoPosEnum NGfc2AxisDataItem::getAxisNoPos()
{
    return (NGfc2AxisNoPosEnum)((Gfc2AxisDataItem*)m_pEntity)->getAxisNoPos();
}

bool NGfc2AxisDataItem::hasAxisNoPos()
{
    return ((Gfc2AxisDataItem*)m_pEntity)->hasAxisNoPos();
}

int NGfc2AxisDataItem::getTrimPointsCount()
{
    return ((Gfc2AxisDataItem*)m_pEntity)->getTrimPointsCount();
}

void NGfc2AxisDataItem::clearTrimPoints()
{
    ((Gfc2AxisDataItem*)m_pEntity)->clearTrimPoints();
}

void NGfc2AxisDataItem::addTrimPoints(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2AxisDataItem*)m_pEntity)->addTrimPoints(nValue);
}

glodon::objectbuf::EntityRef NGfc2AxisDataItem::getTrimPoints(int nIndex)
{
    return ((Gfc2AxisDataItem*)m_pEntity)->getTrimPoints(nIndex);
}

NGfc2Vector2d^ NGfc2AxisDataItem::getTrimPointsPtr(int nIndex)
{
    return gcnew NGfc2Vector2d(((Gfc2AxisDataItem*)m_pEntity)->getTrimPointsPtr(nIndex), false);
}

