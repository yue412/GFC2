#include "NGfc2Torus.h"

using namespace gfc::classes::x3;

NGfc2Torus::NGfc2Torus()
{
    m_pEntity = new Gfc2Torus;
    m_bOwner = true;
}

NGfc2Torus::NGfc2Torus(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2Torus::setCoord(gfc::engine::EntityRef nValue)
{
    ((Gfc2Torus*)m_pEntity)->setCoord(nValue);
}

gfc::engine::EntityRef NGfc2Torus::getCoord()
{
    return ((Gfc2Torus*)m_pEntity)->getCoord();
}

bool NGfc2Torus::hasCoord()
{
    return ((Gfc2Torus*)m_pEntity)->hasCoord();
}

void NGfc2Torus::setRadius(NGfc2Double dValue)
{
    ((Gfc2Torus*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2Torus::getRadius()
{
    return ((Gfc2Torus*)m_pEntity)->getRadius();
}

bool NGfc2Torus::hasRadius()
{
    return ((Gfc2Torus*)m_pEntity)->hasRadius();
}

void NGfc2Torus::setClockSign(NGfc2Integer nValue)
{
    ((Gfc2Torus*)m_pEntity)->setClockSign(nValue);
}

NGfc2Integer NGfc2Torus::getClockSign()
{
    return ((Gfc2Torus*)m_pEntity)->getClockSign();
}

bool NGfc2Torus::hasClockSign()
{
    return ((Gfc2Torus*)m_pEntity)->hasClockSign();
}

void NGfc2Torus::setRangeV(gfc::engine::EntityRef nValue)
{
    ((Gfc2Torus*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfc2Torus::getRangeV()
{
    return ((Gfc2Torus*)m_pEntity)->getRangeV();
}

bool NGfc2Torus::hasRangeV()
{
    return ((Gfc2Torus*)m_pEntity)->hasRangeV();
}

void NGfc2Torus::setCurve(gfc::engine::EntityRef nValue)
{
    ((Gfc2Torus*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfc2Torus::getCurve()
{
    return ((Gfc2Torus*)m_pEntity)->getCurve();
}

bool NGfc2Torus::hasCurve()
{
    return ((Gfc2Torus*)m_pEntity)->hasCurve();
}

