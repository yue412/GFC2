#include "NGfcPlaneCoef.h"

using namespace gfc::classes::x3;

NGfcPlaneCoef::NGfcPlaneCoef()
{
    m_pEntity = new GfcPlaneCoef;
    m_bOwner = true;
}

NGfcPlaneCoef::NGfcPlaneCoef(bool bNoCreate):
    NGfcRoot(bNoCreate)
{
}

void NGfcPlaneCoef::setA(NGfcDouble dValue)
{
    ((GfcPlaneCoef*)m_pEntity)->setA(dValue);
}

NGfcDouble NGfcPlaneCoef::getA()
{
    return ((GfcPlaneCoef*)m_pEntity)->getA();
}

bool NGfcPlaneCoef::hasA()
{
    return ((GfcPlaneCoef*)m_pEntity)->hasA();
}

void NGfcPlaneCoef::setB(NGfcDouble dValue)
{
    ((GfcPlaneCoef*)m_pEntity)->setB(dValue);
}

NGfcDouble NGfcPlaneCoef::getB()
{
    return ((GfcPlaneCoef*)m_pEntity)->getB();
}

bool NGfcPlaneCoef::hasB()
{
    return ((GfcPlaneCoef*)m_pEntity)->hasB();
}

void NGfcPlaneCoef::setC(NGfcDouble dValue)
{
    ((GfcPlaneCoef*)m_pEntity)->setC(dValue);
}

NGfcDouble NGfcPlaneCoef::getC()
{
    return ((GfcPlaneCoef*)m_pEntity)->getC();
}

bool NGfcPlaneCoef::hasC()
{
    return ((GfcPlaneCoef*)m_pEntity)->hasC();
}

void NGfcPlaneCoef::setD(NGfcDouble dValue)
{
    ((GfcPlaneCoef*)m_pEntity)->setD(dValue);
}

NGfcDouble NGfcPlaneCoef::getD()
{
    return ((GfcPlaneCoef*)m_pEntity)->getD();
}

bool NGfcPlaneCoef::hasD()
{
    return ((GfcPlaneCoef*)m_pEntity)->hasD();
}

