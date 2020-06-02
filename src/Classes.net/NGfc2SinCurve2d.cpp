#include "StdAfx.h"
#include "NGfc2SinCurve2d.h"
NGfc2SinCurve2d::NGfc2SinCurve2d()
{
    m_pEntity = new Gfc2SinCurve2d;
    m_bOwner = true;
}

NGfc2SinCurve2d::NGfc2SinCurve2d(void* pEntity, bool bOwner):
    NGfc2Curve2d(pEntity, bOwner)
{
}

void NGfc2SinCurve2d::setPos(gfc2::engine::EntityRef nValue)
{
    ((Gfc2SinCurve2d*)m_pEntity)->setPos(nValue);
}

gfc2::engine::EntityRef NGfc2SinCurve2d::getPos()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->getPos();
}

bool NGfc2SinCurve2d::hasPos()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->hasPos();
}

NGfc2Vector2d^ NGfc2SinCurve2d::getPosPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2SinCurve2d*)m_pEntity)->getPosPtr(), false);
}

void NGfc2SinCurve2d::setDirX(gfc2::engine::EntityRef nValue)
{
    ((Gfc2SinCurve2d*)m_pEntity)->setDirX(nValue);
}

gfc2::engine::EntityRef NGfc2SinCurve2d::getDirX()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->getDirX();
}

bool NGfc2SinCurve2d::hasDirX()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->hasDirX();
}

NGfc2Vector2d^ NGfc2SinCurve2d::getDirXPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2SinCurve2d*)m_pEntity)->getDirXPtr(), false);
}

void NGfc2SinCurve2d::setA(NGfc2Double dValue)
{
    ((Gfc2SinCurve2d*)m_pEntity)->setA(dValue);
}

NGfc2Double NGfc2SinCurve2d::getA()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->getA();
}

bool NGfc2SinCurve2d::hasA()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->hasA();
}

void NGfc2SinCurve2d::setB(NGfc2Double dValue)
{
    ((Gfc2SinCurve2d*)m_pEntity)->setB(dValue);
}

NGfc2Double NGfc2SinCurve2d::getB()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->getB();
}

bool NGfc2SinCurve2d::hasB()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->hasB();
}

void NGfc2SinCurve2d::setRange(gfc2::engine::EntityRef nValue)
{
    ((Gfc2SinCurve2d*)m_pEntity)->setRange(nValue);
}

gfc2::engine::EntityRef NGfc2SinCurve2d::getRange()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->getRange();
}

bool NGfc2SinCurve2d::hasRange()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->hasRange();
}

NGfc2Intervald^ NGfc2SinCurve2d::getRangePtr()
{
    return gcnew NGfc2Intervald(((Gfc2SinCurve2d*)m_pEntity)->getRangePtr(), false);
}

void NGfc2SinCurve2d::setClockSign(NGfc2Integer nValue)
{
    ((Gfc2SinCurve2d*)m_pEntity)->setClockSign(nValue);
}

NGfc2Integer NGfc2SinCurve2d::getClockSign()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->getClockSign();
}

bool NGfc2SinCurve2d::hasClockSign()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->hasClockSign();
}

