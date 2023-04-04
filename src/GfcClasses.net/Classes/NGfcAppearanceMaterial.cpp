#include "NGfcAppearanceMaterial.h"

using namespace gfc::classes::x3;

NGfcAppearanceMaterial::NGfcAppearanceMaterial()
{
    m_pEntity = new GfcAppearanceMaterial;
    m_bOwner = true;
}

NGfcAppearanceMaterial::NGfcAppearanceMaterial(bool bNoCreate):
    NGfcRoot(bNoCreate)
{
}

void NGfcAppearanceMaterial::setColor(gfc::engine::EntityRef nValue)
{
    ((GfcAppearanceMaterial*)m_pEntity)->setColor(nValue);
}

gfc::engine::EntityRef NGfcAppearanceMaterial::getColor()
{
    return ((GfcAppearanceMaterial*)m_pEntity)->getColor();
}

bool NGfcAppearanceMaterial::hasColor()
{
    return ((GfcAppearanceMaterial*)m_pEntity)->hasColor();
}

void NGfcAppearanceMaterial::setDoubleSide(NGfcBoolean bValue)
{
    ((GfcAppearanceMaterial*)m_pEntity)->setDoubleSide(bValue);
}

NGfcBoolean NGfcAppearanceMaterial::getDoubleSide()
{
    return ((GfcAppearanceMaterial*)m_pEntity)->getDoubleSide();
}

bool NGfcAppearanceMaterial::hasDoubleSide()
{
    return ((GfcAppearanceMaterial*)m_pEntity)->hasDoubleSide();
}

void NGfcAppearanceMaterial::setOpacity(NGfcDouble dValue)
{
    ((GfcAppearanceMaterial*)m_pEntity)->setOpacity(dValue);
}

NGfcDouble NGfcAppearanceMaterial::getOpacity()
{
    return ((GfcAppearanceMaterial*)m_pEntity)->getOpacity();
}

bool NGfcAppearanceMaterial::hasOpacity()
{
    return ((GfcAppearanceMaterial*)m_pEntity)->hasOpacity();
}

int NGfcAppearanceMaterial::getTexturesCount()
{
    return ((GfcAppearanceMaterial*)m_pEntity)->getTexturesCount();
}

void NGfcAppearanceMaterial::clearTextures()
{
    ((GfcAppearanceMaterial*)m_pEntity)->clearTextures();
}

void NGfcAppearanceMaterial::addTextures(gfc::engine::EntityRef nValue)
{
    ((GfcAppearanceMaterial*)m_pEntity)->addTextures(nValue);
}

gfc::engine::EntityRef NGfcAppearanceMaterial::getTextures(int nIndex)
{
    return ((GfcAppearanceMaterial*)m_pEntity)->getTextures(nIndex);
}

