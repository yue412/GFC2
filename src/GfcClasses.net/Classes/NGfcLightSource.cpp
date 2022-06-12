#include "NGfcLightSource.h"

using namespace gfc::classes::x3;

NGfcLightSource::NGfcLightSource()
{
    m_pEntity = new GfcLightSource;
    m_bOwner = true;
}

NGfcLightSource::NGfcLightSource(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcRepresentationItem(pEntity, bOwner)
{
}

void NGfcLightSource::setName(NGfcLabel sValue)
{
    ((GfcLightSource*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
}

NGfcLabel NGfcLightSource::getName()
{
    return marshal_as<String^>(((GfcLightSource*)m_pEntity)->getName());
}

bool NGfcLightSource::hasName()
{
    return ((GfcLightSource*)m_pEntity)->hasName();
}

void NGfcLightSource::setLightColour(gfc::engine::EntityRef nValue)
{
    ((GfcLightSource*)m_pEntity)->setLightColour(nValue);
}

gfc::engine::EntityRef NGfcLightSource::getLightColour()
{
    return ((GfcLightSource*)m_pEntity)->getLightColour();
}

bool NGfcLightSource::hasLightColour()
{
    return ((GfcLightSource*)m_pEntity)->hasLightColour();
}

void NGfcLightSource::setAmbientIntensity(NGfcDouble dValue)
{
    ((GfcLightSource*)m_pEntity)->setAmbientIntensity(dValue);
}

NGfcDouble NGfcLightSource::getAmbientIntensity()
{
    return ((GfcLightSource*)m_pEntity)->getAmbientIntensity();
}

bool NGfcLightSource::hasAmbientIntensity()
{
    return ((GfcLightSource*)m_pEntity)->hasAmbientIntensity();
}

void NGfcLightSource::setIntensity(NGfcDouble dValue)
{
    ((GfcLightSource*)m_pEntity)->setIntensity(dValue);
}

NGfcDouble NGfcLightSource::getIntensity()
{
    return ((GfcLightSource*)m_pEntity)->getIntensity();
}

bool NGfcLightSource::hasIntensity()
{
    return ((GfcLightSource*)m_pEntity)->hasIntensity();
}

