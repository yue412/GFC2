#include "NGfcColor.h"

using namespace gfc::classes::x3;

NGfcColor::NGfcColor()
{
    m_pEntity = new GfcColor;
    m_bOwner = true;
}

NGfcColor::NGfcColor(bool bNoCreate):
    NGfcRoot(bNoCreate)
{
}

void NGfcColor::setRed(NGfcInteger nValue)
{
    ((GfcColor*)m_pEntity)->setRed(nValue);
}

NGfcInteger NGfcColor::getRed()
{
    return ((GfcColor*)m_pEntity)->getRed();
}

bool NGfcColor::hasRed()
{
    return ((GfcColor*)m_pEntity)->hasRed();
}

void NGfcColor::setGreen(NGfcInteger nValue)
{
    ((GfcColor*)m_pEntity)->setGreen(nValue);
}

NGfcInteger NGfcColor::getGreen()
{
    return ((GfcColor*)m_pEntity)->getGreen();
}

bool NGfcColor::hasGreen()
{
    return ((GfcColor*)m_pEntity)->hasGreen();
}

void NGfcColor::setBlue(NGfcInteger nValue)
{
    ((GfcColor*)m_pEntity)->setBlue(nValue);
}

NGfcInteger NGfcColor::getBlue()
{
    return ((GfcColor*)m_pEntity)->getBlue();
}

bool NGfcColor::hasBlue()
{
    return ((GfcColor*)m_pEntity)->hasBlue();
}

