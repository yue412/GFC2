#include "StdAfx.h"
#include "NGfc2LightSourcePositional.h"
NGfc2LightSourcePositional::NGfc2LightSourcePositional()
{
    m_pEntity = new Gfc2LightSourcePositional;
    m_bOwner = true;
}

NGfc2LightSourcePositional::NGfc2LightSourcePositional(void* pEntity, bool bOwner):
    NGfc2LightSource(pEntity, bOwner)
{
}

void NGfc2LightSourcePositional::setPosition(gfc2::engine::EntityRef nValue)
{
    ((Gfc2LightSourcePositional*)m_pEntity)->setPosition(nValue);
}

gfc2::engine::EntityRef NGfc2LightSourcePositional::getPosition()
{
    return ((Gfc2LightSourcePositional*)m_pEntity)->getPosition();
}

bool NGfc2LightSourcePositional::hasPosition()
{
    return ((Gfc2LightSourcePositional*)m_pEntity)->hasPosition();
}

NGfc2Vector3d^ NGfc2LightSourcePositional::getPositionPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2LightSourcePositional*)m_pEntity)->getPositionPtr(), false);
}

void NGfc2LightSourcePositional::setRadius(NGfc2Double dValue)
{
    ((Gfc2LightSourcePositional*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2LightSourcePositional::getRadius()
{
    return ((Gfc2LightSourcePositional*)m_pEntity)->getRadius();
}

bool NGfc2LightSourcePositional::hasRadius()
{
    return ((Gfc2LightSourcePositional*)m_pEntity)->hasRadius();
}

void NGfc2LightSourcePositional::setConstantAttenuation(NGfc2Double dValue)
{
    ((Gfc2LightSourcePositional*)m_pEntity)->setConstantAttenuation(dValue);
}

NGfc2Double NGfc2LightSourcePositional::getConstantAttenuation()
{
    return ((Gfc2LightSourcePositional*)m_pEntity)->getConstantAttenuation();
}

bool NGfc2LightSourcePositional::hasConstantAttenuation()
{
    return ((Gfc2LightSourcePositional*)m_pEntity)->hasConstantAttenuation();
}

void NGfc2LightSourcePositional::setDistanceAttenuation(NGfc2Double dValue)
{
    ((Gfc2LightSourcePositional*)m_pEntity)->setDistanceAttenuation(dValue);
}

NGfc2Double NGfc2LightSourcePositional::getDistanceAttenuation()
{
    return ((Gfc2LightSourcePositional*)m_pEntity)->getDistanceAttenuation();
}

bool NGfc2LightSourcePositional::hasDistanceAttenuation()
{
    return ((Gfc2LightSourcePositional*)m_pEntity)->hasDistanceAttenuation();
}

void NGfc2LightSourcePositional::setQuadricAttenuation(NGfc2Double dValue)
{
    ((Gfc2LightSourcePositional*)m_pEntity)->setQuadricAttenuation(dValue);
}

NGfc2Double NGfc2LightSourcePositional::getQuadricAttenuation()
{
    return ((Gfc2LightSourcePositional*)m_pEntity)->getQuadricAttenuation();
}

bool NGfc2LightSourcePositional::hasQuadricAttenuation()
{
    return ((Gfc2LightSourcePositional*)m_pEntity)->hasQuadricAttenuation();
}

