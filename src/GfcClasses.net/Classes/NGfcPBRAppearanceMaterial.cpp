#include "NGfcPBRAppearanceMaterial.h"

using namespace gfc::classes::x3;

NGfcPBRAppearanceMaterial::NGfcPBRAppearanceMaterial()
{
    m_pEntity = new GfcPBRAppearanceMaterial;
    m_bOwner = true;
}

NGfcPBRAppearanceMaterial::NGfcPBRAppearanceMaterial(bool bNoCreate):
    NGfcAppearanceMaterial(bNoCreate)
{
}

void NGfcPBRAppearanceMaterial::setMetalness(NGfcDouble dValue)
{
    ((GfcPBRAppearanceMaterial*)m_pEntity)->setMetalness(dValue);
}

NGfcDouble NGfcPBRAppearanceMaterial::getMetalness()
{
    return ((GfcPBRAppearanceMaterial*)m_pEntity)->getMetalness();
}

bool NGfcPBRAppearanceMaterial::hasMetalness()
{
    return ((GfcPBRAppearanceMaterial*)m_pEntity)->hasMetalness();
}

void NGfcPBRAppearanceMaterial::setRoughness(NGfcDouble dValue)
{
    ((GfcPBRAppearanceMaterial*)m_pEntity)->setRoughness(dValue);
}

NGfcDouble NGfcPBRAppearanceMaterial::getRoughness()
{
    return ((GfcPBRAppearanceMaterial*)m_pEntity)->getRoughness();
}

bool NGfcPBRAppearanceMaterial::hasRoughness()
{
    return ((GfcPBRAppearanceMaterial*)m_pEntity)->hasRoughness();
}

