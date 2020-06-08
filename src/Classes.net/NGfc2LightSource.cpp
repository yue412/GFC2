#include "StdAfx.h"
#include "NGfc2LightSource.h"
NGfc2LightSource::NGfc2LightSource()
{
    m_pEntity = new Gfc2LightSource;
    m_bOwner = true;
}

NGfc2LightSource::NGfc2LightSource(void* pEntity, bool bOwner):
    NGfc2RepresentationItem(pEntity, bOwner)
{
}

void NGfc2LightSource::setName(gfc::engine::EntityRef nValue)
{
    ((Gfc2LightSource*)m_pEntity)->setName(nValue);
}

gfc::engine::EntityRef NGfc2LightSource::getName()
{
    return ((Gfc2LightSource*)m_pEntity)->getName();
}

bool NGfc2LightSource::hasName()
{
    return ((Gfc2LightSource*)m_pEntity)->hasName();
}

NGfc2Label^ NGfc2LightSource::getNamePtr()
{
    return gcnew NGfc2Label(((Gfc2LightSource*)m_pEntity)->getNamePtr(), false);
}

void NGfc2LightSource::setLightColour(gfc::engine::EntityRef nValue)
{
    ((Gfc2LightSource*)m_pEntity)->setLightColour(nValue);
}

gfc::engine::EntityRef NGfc2LightSource::getLightColour()
{
    return ((Gfc2LightSource*)m_pEntity)->getLightColour();
}

bool NGfc2LightSource::hasLightColour()
{
    return ((Gfc2LightSource*)m_pEntity)->hasLightColour();
}

NGfc2Color^ NGfc2LightSource::getLightColourPtr()
{
    return gcnew NGfc2Color(((Gfc2LightSource*)m_pEntity)->getLightColourPtr(), false);
}

void NGfc2LightSource::setAmbientIntensity(NGfc2Double dValue)
{
    ((Gfc2LightSource*)m_pEntity)->setAmbientIntensity(dValue);
}

NGfc2Double NGfc2LightSource::getAmbientIntensity()
{
    return ((Gfc2LightSource*)m_pEntity)->getAmbientIntensity();
}

bool NGfc2LightSource::hasAmbientIntensity()
{
    return ((Gfc2LightSource*)m_pEntity)->hasAmbientIntensity();
}

void NGfc2LightSource::setIntensity(NGfc2Double dValue)
{
    ((Gfc2LightSource*)m_pEntity)->setIntensity(dValue);
}

NGfc2Double NGfc2LightSource::getIntensity()
{
    return ((Gfc2LightSource*)m_pEntity)->getIntensity();
}

bool NGfc2LightSource::hasIntensity()
{
    return ((Gfc2LightSource*)m_pEntity)->hasIntensity();
}

