#include "NGfc2Color.h"

using namespace gfc::classes::x3;

NGfc2Color::NGfc2Color()
{
    m_pEntity = new Gfc2Color;
    m_bOwner = true;
}

NGfc2Color::NGfc2Color(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2Color::setRed(NGfc2Integer nValue)
{
    ((Gfc2Color*)m_pEntity)->setRed(nValue);
}

NGfc2Integer NGfc2Color::getRed()
{
    return ((Gfc2Color*)m_pEntity)->getRed();
}

bool NGfc2Color::hasRed()
{
    return ((Gfc2Color*)m_pEntity)->hasRed();
}

void NGfc2Color::setGreen(NGfc2Integer nValue)
{
    ((Gfc2Color*)m_pEntity)->setGreen(nValue);
}

NGfc2Integer NGfc2Color::getGreen()
{
    return ((Gfc2Color*)m_pEntity)->getGreen();
}

bool NGfc2Color::hasGreen()
{
    return ((Gfc2Color*)m_pEntity)->hasGreen();
}

void NGfc2Color::setBlue(NGfc2Integer nValue)
{
    ((Gfc2Color*)m_pEntity)->setBlue(nValue);
}

NGfc2Integer NGfc2Color::getBlue()
{
    return ((Gfc2Color*)m_pEntity)->getBlue();
}

bool NGfc2Color::hasBlue()
{
    return ((Gfc2Color*)m_pEntity)->hasBlue();
}

void NGfc2Color::setAlpha(NGfc2Integer nValue)
{
    ((Gfc2Color*)m_pEntity)->setAlpha(nValue);
}

NGfc2Integer NGfc2Color::getAlpha()
{
    return ((Gfc2Color*)m_pEntity)->getAlpha();
}

bool NGfc2Color::hasAlpha()
{
    return ((Gfc2Color*)m_pEntity)->hasAlpha();
}

