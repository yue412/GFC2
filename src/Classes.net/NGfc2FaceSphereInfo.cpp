#include "StdAfx.h"
#include "NGfc2FaceSphereInfo.h"
NGfc2FaceSphereInfo::NGfc2FaceSphereInfo()
{
    m_pEntity = new Gfc2FaceSphereInfo;
    m_bOwner = true;
}

NGfc2FaceSphereInfo::NGfc2FaceSphereInfo(void* pEntity, bool bOwner):
    NGfc2FaceInfo(pEntity, bOwner)
{
}

void NGfc2FaceSphereInfo::setCenterPoint(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2FaceSphereInfo*)m_pEntity)->setCenterPoint(nValue);
}

glodon::objectbuf::EntityRef NGfc2FaceSphereInfo::getCenterPoint()
{
    return ((Gfc2FaceSphereInfo*)m_pEntity)->getCenterPoint();
}

bool NGfc2FaceSphereInfo::hasCenterPoint()
{
    return ((Gfc2FaceSphereInfo*)m_pEntity)->hasCenterPoint();
}

NGfc2Vector2d^ NGfc2FaceSphereInfo::getCenterPointPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2FaceSphereInfo*)m_pEntity)->getCenterPointPtr(), false);
}

void NGfc2FaceSphereInfo::setHeight(NGfc2Double dValue)
{
    ((Gfc2FaceSphereInfo*)m_pEntity)->setHeight(dValue);
}

NGfc2Double NGfc2FaceSphereInfo::getHeight()
{
    return ((Gfc2FaceSphereInfo*)m_pEntity)->getHeight();
}

bool NGfc2FaceSphereInfo::hasHeight()
{
    return ((Gfc2FaceSphereInfo*)m_pEntity)->hasHeight();
}

void NGfc2FaceSphereInfo::setChord(NGfc2Double dValue)
{
    ((Gfc2FaceSphereInfo*)m_pEntity)->setChord(dValue);
}

NGfc2Double NGfc2FaceSphereInfo::getChord()
{
    return ((Gfc2FaceSphereInfo*)m_pEntity)->getChord();
}

bool NGfc2FaceSphereInfo::hasChord()
{
    return ((Gfc2FaceSphereInfo*)m_pEntity)->hasChord();
}

void NGfc2FaceSphereInfo::setRadius(NGfc2Double dValue)
{
    ((Gfc2FaceSphereInfo*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2FaceSphereInfo::getRadius()
{
    return ((Gfc2FaceSphereInfo*)m_pEntity)->getRadius();
}

bool NGfc2FaceSphereInfo::hasRadius()
{
    return ((Gfc2FaceSphereInfo*)m_pEntity)->hasRadius();
}

void NGfc2FaceSphereInfo::setDefineByRadius(NGfc2Boolean bValue)
{
    ((Gfc2FaceSphereInfo*)m_pEntity)->setDefineByRadius(bValue);
}

NGfc2Boolean NGfc2FaceSphereInfo::getDefineByRadius()
{
    return ((Gfc2FaceSphereInfo*)m_pEntity)->getDefineByRadius();
}

bool NGfc2FaceSphereInfo::hasDefineByRadius()
{
    return ((Gfc2FaceSphereInfo*)m_pEntity)->hasDefineByRadius();
}

void NGfc2FaceSphereInfo::setCheckInnerChord(NGfc2Boolean bValue)
{
    ((Gfc2FaceSphereInfo*)m_pEntity)->setCheckInnerChord(bValue);
}

NGfc2Boolean NGfc2FaceSphereInfo::getCheckInnerChord()
{
    return ((Gfc2FaceSphereInfo*)m_pEntity)->getCheckInnerChord();
}

bool NGfc2FaceSphereInfo::hasCheckInnerChord()
{
    return ((Gfc2FaceSphereInfo*)m_pEntity)->hasCheckInnerChord();
}

