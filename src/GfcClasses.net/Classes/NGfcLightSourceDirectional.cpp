#include "NGfcLightSourceDirectional.h"

using namespace gfc::classes::x3;

NGfcLightSourceDirectional::NGfcLightSourceDirectional()
{
    m_pEntity = new GfcLightSourceDirectional;
    m_bOwner = true;
}

NGfcLightSourceDirectional::NGfcLightSourceDirectional(bool bNoCreate):
    NGfcLightSource(bNoCreate)
{
}

void NGfcLightSourceDirectional::setOrientation(gfc::engine::EntityRef nValue)
{
    ((GfcLightSourceDirectional*)m_pEntity)->setOrientation(nValue);
}

gfc::engine::EntityRef NGfcLightSourceDirectional::getOrientation()
{
    return ((GfcLightSourceDirectional*)m_pEntity)->getOrientation();
}

bool NGfcLightSourceDirectional::hasOrientation()
{
    return ((GfcLightSourceDirectional*)m_pEntity)->hasOrientation();
}

