#include "StdAfx.h"
#include "NGfc2LightSourceDirectional.h"
NGfc2LightSourceDirectional::NGfc2LightSourceDirectional()
{
    m_pEntity = new Gfc2LightSourceDirectional;
    m_bOwner = true;
}

NGfc2LightSourceDirectional::NGfc2LightSourceDirectional(void* pEntity, bool bOwner):
    NGfc2LightSource(pEntity, bOwner)
{
}

void NGfc2LightSourceDirectional::setOrientation(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2LightSourceDirectional*)m_pEntity)->setOrientation(nValue);
}

glodon::objectbuf::EntityRef NGfc2LightSourceDirectional::getOrientation()
{
    return ((Gfc2LightSourceDirectional*)m_pEntity)->getOrientation();
}

bool NGfc2LightSourceDirectional::hasOrientation()
{
    return ((Gfc2LightSourceDirectional*)m_pEntity)->hasOrientation();
}

NGfc2Vector3d^ NGfc2LightSourceDirectional::getOrientationPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2LightSourceDirectional*)m_pEntity)->getOrientationPtr(), false);
}

