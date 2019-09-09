#include "StdAfx.h"
#include "NGfc2AssitAxis.h"
NGfc2AssitAxis::NGfc2AssitAxis()
{
    m_pEntity = new Gfc2AssitAxis;
    m_bOwner = true;
}

NGfc2AssitAxis::NGfc2AssitAxis(void* pEntity, bool bOwner):
    NGfc2Entity(pEntity, bOwner)
{
}

void NGfc2AssitAxis::setAxisNo(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2AssitAxis*)m_pEntity)->setAxisNo(nValue);
}

glodon::objectbuf::EntityRef NGfc2AssitAxis::getAxisNo()
{
    return ((Gfc2AssitAxis*)m_pEntity)->getAxisNo();
}

bool NGfc2AssitAxis::hasAxisNo()
{
    return ((Gfc2AssitAxis*)m_pEntity)->hasAxisNo();
}

NGfc2Label^ NGfc2AssitAxis::getAxisNoPtr()
{
    return gcnew NGfc2Label(((Gfc2AssitAxis*)m_pEntity)->getAxisNoPtr(), false);
}

void NGfc2AssitAxis::setAxisNoPos(NGfc2AxisNoPosEnum nValue)
{
    ((Gfc2AssitAxis*)m_pEntity)->setAxisNoPos((Gfc2AxisNoPosEnum)nValue);
}

NGfc2AxisNoPosEnum NGfc2AssitAxis::getAxisNoPos()
{
    return (NGfc2AxisNoPosEnum)((Gfc2AssitAxis*)m_pEntity)->getAxisNoPos();
}

bool NGfc2AssitAxis::hasAxisNoPos()
{
    return ((Gfc2AssitAxis*)m_pEntity)->hasAxisNoPos();
}

int NGfc2AssitAxis::getTrimPointsCount()
{
    return ((Gfc2AssitAxis*)m_pEntity)->getTrimPointsCount();
}

void NGfc2AssitAxis::clearTrimPoints()
{
    ((Gfc2AssitAxis*)m_pEntity)->clearTrimPoints();
}

void NGfc2AssitAxis::addTrimPoints(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2AssitAxis*)m_pEntity)->addTrimPoints(nValue);
}

glodon::objectbuf::EntityRef NGfc2AssitAxis::getTrimPoints(int nIndex)
{
    return ((Gfc2AssitAxis*)m_pEntity)->getTrimPoints(nIndex);
}

NGfc2Vector2d^ NGfc2AssitAxis::getTrimPointsPtr(int nIndex)
{
    return gcnew NGfc2Vector2d(((Gfc2AssitAxis*)m_pEntity)->getTrimPointsPtr(nIndex), false);
}

