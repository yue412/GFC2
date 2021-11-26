#include "NGfc2SinCurve2d.h"

using namespace gfc::classes::x3;

NGfc2SinCurve2d::NGfc2SinCurve2d()
{
    m_pEntity = new Gfc2SinCurve2d;
    m_bOwner = true;
}

NGfc2SinCurve2d::NGfc2SinCurve2d(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Curve2d(pEntity, bOwner)
{
}

void NGfc2SinCurve2d::setPos(gfc::engine::EntityRef nValue)
{
    ((Gfc2SinCurve2d*)m_pEntity)->setPos(nValue);
}

gfc::engine::EntityRef NGfc2SinCurve2d::getPos()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->getPos();
}

bool NGfc2SinCurve2d::hasPos()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->hasPos();
}

void NGfc2SinCurve2d::setDirX(gfc::engine::EntityRef nValue)
{
    ((Gfc2SinCurve2d*)m_pEntity)->setDirX(nValue);
}

gfc::engine::EntityRef NGfc2SinCurve2d::getDirX()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->getDirX();
}

bool NGfc2SinCurve2d::hasDirX()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->hasDirX();
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

void NGfc2SinCurve2d::setRange(gfc::engine::EntityRef nValue)
{
    ((Gfc2SinCurve2d*)m_pEntity)->setRange(nValue);
}

gfc::engine::EntityRef NGfc2SinCurve2d::getRange()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->getRange();
}

bool NGfc2SinCurve2d::hasRange()
{
    return ((Gfc2SinCurve2d*)m_pEntity)->hasRange();
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

