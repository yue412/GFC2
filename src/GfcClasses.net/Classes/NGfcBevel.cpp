#include "NGfcBevel.h"

using namespace gfc::classes::x3;

NGfcBevel::NGfcBevel()
{
    m_pEntity = new GfcBevel;
    m_bOwner = true;
}

NGfcBevel::NGfcBevel(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSurface(pEntity, bOwner)
{
}

void NGfcBevel::setCoord(gfc::engine::EntityRef nValue)
{
    ((GfcBevel*)m_pEntity)->setCoord(nValue);
}

gfc::engine::EntityRef NGfcBevel::getCoord()
{
    return ((GfcBevel*)m_pEntity)->getCoord();
}

bool NGfcBevel::hasCoord()
{
    return ((GfcBevel*)m_pEntity)->hasCoord();
}

void NGfcBevel::setHeight(NGfcDouble dValue)
{
    ((GfcBevel*)m_pEntity)->setHeight(dValue);
}

NGfcDouble NGfcBevel::getHeight()
{
    return ((GfcBevel*)m_pEntity)->getHeight();
}

bool NGfcBevel::hasHeight()
{
    return ((GfcBevel*)m_pEntity)->hasHeight();
}

void NGfcBevel::setRangeV(gfc::engine::EntityRef nValue)
{
    ((GfcBevel*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfcBevel::getRangeV()
{
    return ((GfcBevel*)m_pEntity)->getRangeV();
}

bool NGfcBevel::hasRangeV()
{
    return ((GfcBevel*)m_pEntity)->hasRangeV();
}

void NGfcBevel::setCurve(gfc::engine::EntityRef nValue)
{
    ((GfcBevel*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfcBevel::getCurve()
{
    return ((GfcBevel*)m_pEntity)->getCurve();
}

bool NGfcBevel::hasCurve()
{
    return ((GfcBevel*)m_pEntity)->hasCurve();
}

