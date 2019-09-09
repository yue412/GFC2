#include "StdAfx.h"
#include "NGfc2StateSet.h"
NGfc2StateSet::NGfc2StateSet()
{
    m_pEntity = new Gfc2StateSet;
    m_bOwner = true;
}

NGfc2StateSet::NGfc2StateSet(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2StateSet::setAmbient(NGfc2Integer nValue)
{
    ((Gfc2StateSet*)m_pEntity)->setAmbient(nValue);
}

NGfc2Integer NGfc2StateSet::getAmbient()
{
    return ((Gfc2StateSet*)m_pEntity)->getAmbient();
}

bool NGfc2StateSet::hasAmbient()
{
    return ((Gfc2StateSet*)m_pEntity)->hasAmbient();
}

void NGfc2StateSet::setDiffuse(NGfc2Integer nValue)
{
    ((Gfc2StateSet*)m_pEntity)->setDiffuse(nValue);
}

NGfc2Integer NGfc2StateSet::getDiffuse()
{
    return ((Gfc2StateSet*)m_pEntity)->getDiffuse();
}

bool NGfc2StateSet::hasDiffuse()
{
    return ((Gfc2StateSet*)m_pEntity)->hasDiffuse();
}

void NGfc2StateSet::setSourceBlendFactor(NGfc2SceneBlendFactor nValue)
{
    ((Gfc2StateSet*)m_pEntity)->setSourceBlendFactor((Gfc2SceneBlendFactor)nValue);
}

NGfc2SceneBlendFactor NGfc2StateSet::getSourceBlendFactor()
{
    return (NGfc2SceneBlendFactor)((Gfc2StateSet*)m_pEntity)->getSourceBlendFactor();
}

bool NGfc2StateSet::hasSourceBlendFactor()
{
    return ((Gfc2StateSet*)m_pEntity)->hasSourceBlendFactor();
}

void NGfc2StateSet::setDestBlendFactor(NGfc2SceneBlendFactor nValue)
{
    ((Gfc2StateSet*)m_pEntity)->setDestBlendFactor((Gfc2SceneBlendFactor)nValue);
}

NGfc2SceneBlendFactor NGfc2StateSet::getDestBlendFactor()
{
    return (NGfc2SceneBlendFactor)((Gfc2StateSet*)m_pEntity)->getDestBlendFactor();
}

bool NGfc2StateSet::hasDestBlendFactor()
{
    return ((Gfc2StateSet*)m_pEntity)->hasDestBlendFactor();
}

void NGfc2StateSet::setDepthTestEnabled(NGfc2Boolean bValue)
{
    ((Gfc2StateSet*)m_pEntity)->setDepthTestEnabled(bValue);
}

NGfc2Boolean NGfc2StateSet::getDepthTestEnabled()
{
    return ((Gfc2StateSet*)m_pEntity)->getDepthTestEnabled();
}

bool NGfc2StateSet::hasDepthTestEnabled()
{
    return ((Gfc2StateSet*)m_pEntity)->hasDepthTestEnabled();
}

void NGfc2StateSet::setDepthWriteEnabled(NGfc2Boolean bValue)
{
    ((Gfc2StateSet*)m_pEntity)->setDepthWriteEnabled(bValue);
}

NGfc2Boolean NGfc2StateSet::getDepthWriteEnabled()
{
    return ((Gfc2StateSet*)m_pEntity)->getDepthWriteEnabled();
}

bool NGfc2StateSet::hasDepthWriteEnabled()
{
    return ((Gfc2StateSet*)m_pEntity)->hasDepthWriteEnabled();
}

void NGfc2StateSet::setDepthTestFunction(NGfc2FragTestFunc nValue)
{
    ((Gfc2StateSet*)m_pEntity)->setDepthTestFunction((Gfc2FragTestFunc)nValue);
}

NGfc2FragTestFunc NGfc2StateSet::getDepthTestFunction()
{
    return (NGfc2FragTestFunc)((Gfc2StateSet*)m_pEntity)->getDepthTestFunction();
}

bool NGfc2StateSet::hasDepthTestFunction()
{
    return ((Gfc2StateSet*)m_pEntity)->hasDepthTestFunction();
}

void NGfc2StateSet::setPolygonOffsetFactor(NGfc2Double dValue)
{
    ((Gfc2StateSet*)m_pEntity)->setPolygonOffsetFactor(dValue);
}

NGfc2Double NGfc2StateSet::getPolygonOffsetFactor()
{
    return ((Gfc2StateSet*)m_pEntity)->getPolygonOffsetFactor();
}

bool NGfc2StateSet::hasPolygonOffsetFactor()
{
    return ((Gfc2StateSet*)m_pEntity)->hasPolygonOffsetFactor();
}

void NGfc2StateSet::setPolygonOffsetUnits(NGfc2Double dValue)
{
    ((Gfc2StateSet*)m_pEntity)->setPolygonOffsetUnits(dValue);
}

NGfc2Double NGfc2StateSet::getPolygonOffsetUnits()
{
    return ((Gfc2StateSet*)m_pEntity)->getPolygonOffsetUnits();
}

bool NGfc2StateSet::hasPolygonOffsetUnits()
{
    return ((Gfc2StateSet*)m_pEntity)->hasPolygonOffsetUnits();
}

void NGfc2StateSet::setPolygonStipple(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2StateSet*)m_pEntity)->setPolygonStipple(nValue);
}

glodon::objectbuf::EntityRef NGfc2StateSet::getPolygonStipple()
{
    return ((Gfc2StateSet*)m_pEntity)->getPolygonStipple();
}

bool NGfc2StateSet::hasPolygonStipple()
{
    return ((Gfc2StateSet*)m_pEntity)->hasPolygonStipple();
}

NGfc2String^ NGfc2StateSet::getPolygonStipplePtr()
{
    return gcnew NGfc2String(((Gfc2StateSet*)m_pEntity)->getPolygonStipplePtr(), false);
}

void NGfc2StateSet::setLineStipplePattern(NGfc2Integer nValue)
{
    ((Gfc2StateSet*)m_pEntity)->setLineStipplePattern(nValue);
}

NGfc2Integer NGfc2StateSet::getLineStipplePattern()
{
    return ((Gfc2StateSet*)m_pEntity)->getLineStipplePattern();
}

bool NGfc2StateSet::hasLineStipplePattern()
{
    return ((Gfc2StateSet*)m_pEntity)->hasLineStipplePattern();
}

void NGfc2StateSet::setLineStippleFactor(NGfc2Integer nValue)
{
    ((Gfc2StateSet*)m_pEntity)->setLineStippleFactor(nValue);
}

NGfc2Integer NGfc2StateSet::getLineStippleFactor()
{
    return ((Gfc2StateSet*)m_pEntity)->getLineStippleFactor();
}

bool NGfc2StateSet::hasLineStippleFactor()
{
    return ((Gfc2StateSet*)m_pEntity)->hasLineStippleFactor();
}

void NGfc2StateSet::setFaceMode(NGfc2FaceMode nValue)
{
    ((Gfc2StateSet*)m_pEntity)->setFaceMode((Gfc2FaceMode)nValue);
}

NGfc2FaceMode NGfc2StateSet::getFaceMode()
{
    return (NGfc2FaceMode)((Gfc2StateSet*)m_pEntity)->getFaceMode();
}

bool NGfc2StateSet::hasFaceMode()
{
    return ((Gfc2StateSet*)m_pEntity)->hasFaceMode();
}

void NGfc2StateSet::setLightingEnabled(NGfc2Boolean bValue)
{
    ((Gfc2StateSet*)m_pEntity)->setLightingEnabled(bValue);
}

NGfc2Boolean NGfc2StateSet::getLightingEnabled()
{
    return ((Gfc2StateSet*)m_pEntity)->getLightingEnabled();
}

bool NGfc2StateSet::hasLightingEnabled()
{
    return ((Gfc2StateSet*)m_pEntity)->hasLightingEnabled();
}

void NGfc2StateSet::setLightModelTwoSided(NGfc2Boolean bValue)
{
    ((Gfc2StateSet*)m_pEntity)->setLightModelTwoSided(bValue);
}

NGfc2Boolean NGfc2StateSet::getLightModelTwoSided()
{
    return ((Gfc2StateSet*)m_pEntity)->getLightModelTwoSided();
}

bool NGfc2StateSet::hasLightModelTwoSided()
{
    return ((Gfc2StateSet*)m_pEntity)->hasLightModelTwoSided();
}

