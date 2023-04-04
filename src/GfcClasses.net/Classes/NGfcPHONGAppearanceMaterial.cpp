#include "NGfcPHONGAppearanceMaterial.h"

using namespace gfc::classes::x3;

NGfcPHONGAppearanceMaterial::NGfcPHONGAppearanceMaterial()
{
    m_pEntity = new GfcPHONGAppearanceMaterial;
    m_bOwner = true;
}

NGfcPHONGAppearanceMaterial::NGfcPHONGAppearanceMaterial(bool bNoCreate):
    NGfcAppearanceMaterial(bNoCreate)
{
}

void NGfcPHONGAppearanceMaterial::setAmbient(gfc::engine::EntityRef nValue)
{
    ((GfcPHONGAppearanceMaterial*)m_pEntity)->setAmbient(nValue);
}

gfc::engine::EntityRef NGfcPHONGAppearanceMaterial::getAmbient()
{
    return ((GfcPHONGAppearanceMaterial*)m_pEntity)->getAmbient();
}

bool NGfcPHONGAppearanceMaterial::hasAmbient()
{
    return ((GfcPHONGAppearanceMaterial*)m_pEntity)->hasAmbient();
}

void NGfcPHONGAppearanceMaterial::setEmissive(gfc::engine::EntityRef nValue)
{
    ((GfcPHONGAppearanceMaterial*)m_pEntity)->setEmissive(nValue);
}

gfc::engine::EntityRef NGfcPHONGAppearanceMaterial::getEmissive()
{
    return ((GfcPHONGAppearanceMaterial*)m_pEntity)->getEmissive();
}

bool NGfcPHONGAppearanceMaterial::hasEmissive()
{
    return ((GfcPHONGAppearanceMaterial*)m_pEntity)->hasEmissive();
}

void NGfcPHONGAppearanceMaterial::setSpecular(gfc::engine::EntityRef nValue)
{
    ((GfcPHONGAppearanceMaterial*)m_pEntity)->setSpecular(nValue);
}

gfc::engine::EntityRef NGfcPHONGAppearanceMaterial::getSpecular()
{
    return ((GfcPHONGAppearanceMaterial*)m_pEntity)->getSpecular();
}

bool NGfcPHONGAppearanceMaterial::hasSpecular()
{
    return ((GfcPHONGAppearanceMaterial*)m_pEntity)->hasSpecular();
}

void NGfcPHONGAppearanceMaterial::setEnvironment(gfc::engine::EntityRef nValue)
{
    ((GfcPHONGAppearanceMaterial*)m_pEntity)->setEnvironment(nValue);
}

gfc::engine::EntityRef NGfcPHONGAppearanceMaterial::getEnvironment()
{
    return ((GfcPHONGAppearanceMaterial*)m_pEntity)->getEnvironment();
}

bool NGfcPHONGAppearanceMaterial::hasEnvironment()
{
    return ((GfcPHONGAppearanceMaterial*)m_pEntity)->hasEnvironment();
}

void NGfcPHONGAppearanceMaterial::setShiniess(NGfcDouble dValue)
{
    ((GfcPHONGAppearanceMaterial*)m_pEntity)->setShiniess(dValue);
}

NGfcDouble NGfcPHONGAppearanceMaterial::getShiniess()
{
    return ((GfcPHONGAppearanceMaterial*)m_pEntity)->getShiniess();
}

bool NGfcPHONGAppearanceMaterial::hasShiniess()
{
    return ((GfcPHONGAppearanceMaterial*)m_pEntity)->hasShiniess();
}

