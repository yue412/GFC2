#include "NGfcLightSourcePositional.h"

using namespace gfc::classes::x3;

NGfcLightSourcePositional::NGfcLightSourcePositional()
{
    m_pEntity = new GfcLightSourcePositional;
    m_bOwner = true;
}

NGfcLightSourcePositional::NGfcLightSourcePositional(bool bNoCreate):
    NGfcLightSource(bNoCreate)
{
}

void NGfcLightSourcePositional::setPosition(gfc::engine::EntityRef nValue)
{
    ((GfcLightSourcePositional*)m_pEntity)->setPosition(nValue);
}

gfc::engine::EntityRef NGfcLightSourcePositional::getPosition()
{
    return ((GfcLightSourcePositional*)m_pEntity)->getPosition();
}

bool NGfcLightSourcePositional::hasPosition()
{
    return ((GfcLightSourcePositional*)m_pEntity)->hasPosition();
}

void NGfcLightSourcePositional::setRadius(NGfcDouble dValue)
{
    ((GfcLightSourcePositional*)m_pEntity)->setRadius(dValue);
}

NGfcDouble NGfcLightSourcePositional::getRadius()
{
    return ((GfcLightSourcePositional*)m_pEntity)->getRadius();
}

bool NGfcLightSourcePositional::hasRadius()
{
    return ((GfcLightSourcePositional*)m_pEntity)->hasRadius();
}

void NGfcLightSourcePositional::setConstantAttenuation(NGfcDouble dValue)
{
    ((GfcLightSourcePositional*)m_pEntity)->setConstantAttenuation(dValue);
}

NGfcDouble NGfcLightSourcePositional::getConstantAttenuation()
{
    return ((GfcLightSourcePositional*)m_pEntity)->getConstantAttenuation();
}

bool NGfcLightSourcePositional::hasConstantAttenuation()
{
    return ((GfcLightSourcePositional*)m_pEntity)->hasConstantAttenuation();
}

void NGfcLightSourcePositional::setDistanceAttenuation(NGfcDouble dValue)
{
    ((GfcLightSourcePositional*)m_pEntity)->setDistanceAttenuation(dValue);
}

NGfcDouble NGfcLightSourcePositional::getDistanceAttenuation()
{
    return ((GfcLightSourcePositional*)m_pEntity)->getDistanceAttenuation();
}

bool NGfcLightSourcePositional::hasDistanceAttenuation()
{
    return ((GfcLightSourcePositional*)m_pEntity)->hasDistanceAttenuation();
}

void NGfcLightSourcePositional::setQuadricAttenuation(NGfcDouble dValue)
{
    ((GfcLightSourcePositional*)m_pEntity)->setQuadricAttenuation(dValue);
}

NGfcDouble NGfcLightSourcePositional::getQuadricAttenuation()
{
    return ((GfcLightSourcePositional*)m_pEntity)->getQuadricAttenuation();
}

bool NGfcLightSourcePositional::hasQuadricAttenuation()
{
    return ((GfcLightSourcePositional*)m_pEntity)->hasQuadricAttenuation();
}

