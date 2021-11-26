#include "NGfc2LightSource.h"

using namespace gfc::classes::x3;

NGfc2LightSource::NGfc2LightSource()
{
    m_pEntity = new Gfc2LightSource;
    m_bOwner = true;
}

NGfc2LightSource::NGfc2LightSource(void* pEntity, bool bOwner):
    NGfc2RepresentationItem(pEntity, bOwner)
{
}

void NGfc2LightSource::setName(NGfc2Label sValue)
{
    ((Gfc2LightSource*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
}

NGfc2Label NGfc2LightSource::getName()
{
    return marshal_as<String^>(((Gfc2LightSource*)m_pEntity)->getName());
}

bool NGfc2LightSource::hasName()
{
    return ((Gfc2LightSource*)m_pEntity)->hasName();
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

