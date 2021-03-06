#include "StdAfx.h"
#include "NGfc2Ellipse2d.h"
NGfc2Ellipse2d::NGfc2Ellipse2d()
{
    m_pEntity = new Gfc2Ellipse2d;
    m_bOwner = true;
}

NGfc2Ellipse2d::NGfc2Ellipse2d(void* pEntity, bool bOwner):
    NGfc2Curve2d(pEntity, bOwner)
{
}

void NGfc2Ellipse2d::setCenterPt(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Ellipse2d*)m_pEntity)->setCenterPt(nValue);
}

glodon::objectbuf::EntityRef NGfc2Ellipse2d::getCenterPt()
{
    return ((Gfc2Ellipse2d*)m_pEntity)->getCenterPt();
}

bool NGfc2Ellipse2d::hasCenterPt()
{
    return ((Gfc2Ellipse2d*)m_pEntity)->hasCenterPt();
}

NGfc2Vector2d^ NGfc2Ellipse2d::getCenterPtPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2Ellipse2d*)m_pEntity)->getCenterPtPtr(), false);
}

void NGfc2Ellipse2d::setMajorAxis(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Ellipse2d*)m_pEntity)->setMajorAxis(nValue);
}

glodon::objectbuf::EntityRef NGfc2Ellipse2d::getMajorAxis()
{
    return ((Gfc2Ellipse2d*)m_pEntity)->getMajorAxis();
}

bool NGfc2Ellipse2d::hasMajorAxis()
{
    return ((Gfc2Ellipse2d*)m_pEntity)->hasMajorAxis();
}

NGfc2Vector2d^ NGfc2Ellipse2d::getMajorAxisPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2Ellipse2d*)m_pEntity)->getMajorAxisPtr(), false);
}

void NGfc2Ellipse2d::setdMajorRad(NGfc2Double dValue)
{
    ((Gfc2Ellipse2d*)m_pEntity)->setdMajorRad(dValue);
}

NGfc2Double NGfc2Ellipse2d::getdMajorRad()
{
    return ((Gfc2Ellipse2d*)m_pEntity)->getdMajorRad();
}

bool NGfc2Ellipse2d::hasdMajorRad()
{
    return ((Gfc2Ellipse2d*)m_pEntity)->hasdMajorRad();
}

void NGfc2Ellipse2d::setdMinorRad(NGfc2Double dValue)
{
    ((Gfc2Ellipse2d*)m_pEntity)->setdMinorRad(dValue);
}

NGfc2Double NGfc2Ellipse2d::getdMinorRad()
{
    return ((Gfc2Ellipse2d*)m_pEntity)->getdMinorRad();
}

bool NGfc2Ellipse2d::hasdMinorRad()
{
    return ((Gfc2Ellipse2d*)m_pEntity)->hasdMinorRad();
}

void NGfc2Ellipse2d::setRange(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Ellipse2d*)m_pEntity)->setRange(nValue);
}

glodon::objectbuf::EntityRef NGfc2Ellipse2d::getRange()
{
    return ((Gfc2Ellipse2d*)m_pEntity)->getRange();
}

bool NGfc2Ellipse2d::hasRange()
{
    return ((Gfc2Ellipse2d*)m_pEntity)->hasRange();
}

NGfc2Intervald^ NGfc2Ellipse2d::getRangePtr()
{
    return gcnew NGfc2Intervald(((Gfc2Ellipse2d*)m_pEntity)->getRangePtr(), false);
}

void NGfc2Ellipse2d::setClockSign(NGfc2Integer nValue)
{
    ((Gfc2Ellipse2d*)m_pEntity)->setClockSign(nValue);
}

NGfc2Integer NGfc2Ellipse2d::getClockSign()
{
    return ((Gfc2Ellipse2d*)m_pEntity)->getClockSign();
}

bool NGfc2Ellipse2d::hasClockSign()
{
    return ((Gfc2Ellipse2d*)m_pEntity)->hasClockSign();
}

