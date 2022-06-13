#include "NGfcBlockShape.h"

using namespace gfc::classes::x3;

NGfcBlockShape::NGfcBlockShape()
{
    m_pEntity = new GfcBlockShape;
    m_bOwner = true;
}

NGfcBlockShape::NGfcBlockShape(bool bNoCreate):
    NGfcPrimitiveShape(bNoCreate)
{
}

void NGfcBlockShape::setXLength(NGfcDouble dValue)
{
    ((GfcBlockShape*)m_pEntity)->setXLength(dValue);
}

NGfcDouble NGfcBlockShape::getXLength()
{
    return ((GfcBlockShape*)m_pEntity)->getXLength();
}

bool NGfcBlockShape::hasXLength()
{
    return ((GfcBlockShape*)m_pEntity)->hasXLength();
}

void NGfcBlockShape::setYLength(NGfcDouble dValue)
{
    ((GfcBlockShape*)m_pEntity)->setYLength(dValue);
}

NGfcDouble NGfcBlockShape::getYLength()
{
    return ((GfcBlockShape*)m_pEntity)->getYLength();
}

bool NGfcBlockShape::hasYLength()
{
    return ((GfcBlockShape*)m_pEntity)->hasYLength();
}

void NGfcBlockShape::setZLength(NGfcDouble dValue)
{
    ((GfcBlockShape*)m_pEntity)->setZLength(dValue);
}

NGfcDouble NGfcBlockShape::getZLength()
{
    return ((GfcBlockShape*)m_pEntity)->getZLength();
}

bool NGfcBlockShape::hasZLength()
{
    return ((GfcBlockShape*)m_pEntity)->hasZLength();
}

