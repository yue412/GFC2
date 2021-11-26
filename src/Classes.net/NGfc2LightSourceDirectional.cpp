#include "NGfc2LightSourceDirectional.h"

using namespace gfc::classes::x3;

NGfc2LightSourceDirectional::NGfc2LightSourceDirectional()
{
    m_pEntity = new Gfc2LightSourceDirectional;
    m_bOwner = true;
}

NGfc2LightSourceDirectional::NGfc2LightSourceDirectional(void* pEntity, bool bOwner):
    NGfc2LightSource(pEntity, bOwner)
{
}

void NGfc2LightSourceDirectional::setOrientation(gfc::engine::EntityRef nValue)
{
    ((Gfc2LightSourceDirectional*)m_pEntity)->setOrientation(nValue);
}

gfc::engine::EntityRef NGfc2LightSourceDirectional::getOrientation()
{
    return ((Gfc2LightSourceDirectional*)m_pEntity)->getOrientation();
}

bool NGfc2LightSourceDirectional::hasOrientation()
{
    return ((Gfc2LightSourceDirectional*)m_pEntity)->hasOrientation();
}

