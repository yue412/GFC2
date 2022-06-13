#include "NGfcBox3d.h"

using namespace gfc::classes::x3;

NGfcBox3d::NGfcBox3d()
{
    m_pEntity = new GfcBox3d;
    m_bOwner = true;
}

NGfcBox3d::NGfcBox3d(bool bNoCreate):
    NGfcGeometry(bNoCreate)
{
}

void NGfcBox3d::setMin(gfc::engine::EntityRef nValue)
{
    ((GfcBox3d*)m_pEntity)->setMin(nValue);
}

gfc::engine::EntityRef NGfcBox3d::getMin()
{
    return ((GfcBox3d*)m_pEntity)->getMin();
}

bool NGfcBox3d::hasMin()
{
    return ((GfcBox3d*)m_pEntity)->hasMin();
}

void NGfcBox3d::setMax(gfc::engine::EntityRef nValue)
{
    ((GfcBox3d*)m_pEntity)->setMax(nValue);
}

gfc::engine::EntityRef NGfcBox3d::getMax()
{
    return ((GfcBox3d*)m_pEntity)->getMax();
}

bool NGfcBox3d::hasMax()
{
    return ((GfcBox3d*)m_pEntity)->hasMax();
}

