#include "NGfcVector3d.h"

using namespace gfc::classes::x3;

NGfcVector3d::NGfcVector3d()
{
    m_pEntity = new GfcVector3d;
    m_bOwner = true;
}

NGfcVector3d::NGfcVector3d(bool bNoCreate):
    NGfcGeometry(bNoCreate)
{
}

void NGfcVector3d::setX(NGfcDouble dValue)
{
    ((GfcVector3d*)m_pEntity)->setX(dValue);
}

NGfcDouble NGfcVector3d::getX()
{
    return ((GfcVector3d*)m_pEntity)->getX();
}

bool NGfcVector3d::hasX()
{
    return ((GfcVector3d*)m_pEntity)->hasX();
}

void NGfcVector3d::setY(NGfcDouble dValue)
{
    ((GfcVector3d*)m_pEntity)->setY(dValue);
}

NGfcDouble NGfcVector3d::getY()
{
    return ((GfcVector3d*)m_pEntity)->getY();
}

bool NGfcVector3d::hasY()
{
    return ((GfcVector3d*)m_pEntity)->hasY();
}

void NGfcVector3d::setZ(NGfcDouble dValue)
{
    ((GfcVector3d*)m_pEntity)->setZ(dValue);
}

NGfcDouble NGfcVector3d::getZ()
{
    return ((GfcVector3d*)m_pEntity)->getZ();
}

bool NGfcVector3d::hasZ()
{
    return ((GfcVector3d*)m_pEntity)->hasZ();
}

