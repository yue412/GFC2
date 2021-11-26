#include "NGfc2Bevel.h"

using namespace gfc::classes::x3;

NGfc2Bevel::NGfc2Bevel()
{
    m_pEntity = new Gfc2Bevel;
    m_bOwner = true;
}

NGfc2Bevel::NGfc2Bevel(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2Bevel::setCoord(gfc::engine::EntityRef nValue)
{
    ((Gfc2Bevel*)m_pEntity)->setCoord(nValue);
}

gfc::engine::EntityRef NGfc2Bevel::getCoord()
{
    return ((Gfc2Bevel*)m_pEntity)->getCoord();
}

bool NGfc2Bevel::hasCoord()
{
    return ((Gfc2Bevel*)m_pEntity)->hasCoord();
}

void NGfc2Bevel::setHeight(NGfc2Double dValue)
{
    ((Gfc2Bevel*)m_pEntity)->setHeight(dValue);
}

NGfc2Double NGfc2Bevel::getHeight()
{
    return ((Gfc2Bevel*)m_pEntity)->getHeight();
}

bool NGfc2Bevel::hasHeight()
{
    return ((Gfc2Bevel*)m_pEntity)->hasHeight();
}

void NGfc2Bevel::setRangeV(gfc::engine::EntityRef nValue)
{
    ((Gfc2Bevel*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfc2Bevel::getRangeV()
{
    return ((Gfc2Bevel*)m_pEntity)->getRangeV();
}

bool NGfc2Bevel::hasRangeV()
{
    return ((Gfc2Bevel*)m_pEntity)->hasRangeV();
}

void NGfc2Bevel::setCurve(gfc::engine::EntityRef nValue)
{
    ((Gfc2Bevel*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfc2Bevel::getCurve()
{
    return ((Gfc2Bevel*)m_pEntity)->getCurve();
}

bool NGfc2Bevel::hasCurve()
{
    return ((Gfc2Bevel*)m_pEntity)->hasCurve();
}

