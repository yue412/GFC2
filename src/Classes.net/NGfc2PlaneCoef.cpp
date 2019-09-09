#include "StdAfx.h"
#include "NGfc2PlaneCoef.h"
NGfc2PlaneCoef::NGfc2PlaneCoef()
{
    m_pEntity = new Gfc2PlaneCoef;
    m_bOwner = true;
}

NGfc2PlaneCoef::NGfc2PlaneCoef(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2PlaneCoef::setA(NGfc2Double dValue)
{
    ((Gfc2PlaneCoef*)m_pEntity)->setA(dValue);
}

NGfc2Double NGfc2PlaneCoef::getA()
{
    return ((Gfc2PlaneCoef*)m_pEntity)->getA();
}

bool NGfc2PlaneCoef::hasA()
{
    return ((Gfc2PlaneCoef*)m_pEntity)->hasA();
}

void NGfc2PlaneCoef::setB(NGfc2Double dValue)
{
    ((Gfc2PlaneCoef*)m_pEntity)->setB(dValue);
}

NGfc2Double NGfc2PlaneCoef::getB()
{
    return ((Gfc2PlaneCoef*)m_pEntity)->getB();
}

bool NGfc2PlaneCoef::hasB()
{
    return ((Gfc2PlaneCoef*)m_pEntity)->hasB();
}

void NGfc2PlaneCoef::setC(NGfc2Double dValue)
{
    ((Gfc2PlaneCoef*)m_pEntity)->setC(dValue);
}

NGfc2Double NGfc2PlaneCoef::getC()
{
    return ((Gfc2PlaneCoef*)m_pEntity)->getC();
}

bool NGfc2PlaneCoef::hasC()
{
    return ((Gfc2PlaneCoef*)m_pEntity)->hasC();
}

void NGfc2PlaneCoef::setD(NGfc2Double dValue)
{
    ((Gfc2PlaneCoef*)m_pEntity)->setD(dValue);
}

NGfc2Double NGfc2PlaneCoef::getD()
{
    return ((Gfc2PlaneCoef*)m_pEntity)->getD();
}

bool NGfc2PlaneCoef::hasD()
{
    return ((Gfc2PlaneCoef*)m_pEntity)->hasD();
}

