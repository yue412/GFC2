#include "NGfcVector2d.h"

using namespace gfc::classes::x3;

NGfcVector2d::NGfcVector2d()
{
    m_pEntity = new GfcVector2d;
    m_bOwner = true;
}

NGfcVector2d::NGfcVector2d(bool bNoCreate):
    NGfcGeometry(bNoCreate)
{
}

void NGfcVector2d::setX(NGfcDouble dValue)
{
    ((GfcVector2d*)m_pEntity)->setX(dValue);
}

NGfcDouble NGfcVector2d::getX()
{
    return ((GfcVector2d*)m_pEntity)->getX();
}

bool NGfcVector2d::hasX()
{
    return ((GfcVector2d*)m_pEntity)->hasX();
}

void NGfcVector2d::setY(NGfcDouble dValue)
{
    ((GfcVector2d*)m_pEntity)->setY(dValue);
}

NGfcDouble NGfcVector2d::getY()
{
    return ((GfcVector2d*)m_pEntity)->getY();
}

bool NGfcVector2d::hasY()
{
    return ((GfcVector2d*)m_pEntity)->hasY();
}

