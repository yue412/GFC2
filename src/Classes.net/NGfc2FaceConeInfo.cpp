#include "StdAfx.h"
#include "NGfc2FaceConeInfo.h"
NGfc2FaceConeInfo::NGfc2FaceConeInfo()
{
    m_pEntity = new Gfc2FaceConeInfo;
    m_bOwner = true;
}

NGfc2FaceConeInfo::NGfc2FaceConeInfo(void* pEntity, bool bOwner):
    NGfc2FaceInfo(pEntity, bOwner)
{
}

void NGfc2FaceConeInfo::setHeight(NGfc2Double dValue)
{
    ((Gfc2FaceConeInfo*)m_pEntity)->setHeight(dValue);
}

NGfc2Double NGfc2FaceConeInfo::getHeight()
{
    return ((Gfc2FaceConeInfo*)m_pEntity)->getHeight();
}

bool NGfc2FaceConeInfo::hasHeight()
{
    return ((Gfc2FaceConeInfo*)m_pEntity)->hasHeight();
}

void NGfc2FaceConeInfo::setChord(NGfc2Double dValue)
{
    ((Gfc2FaceConeInfo*)m_pEntity)->setChord(dValue);
}

NGfc2Double NGfc2FaceConeInfo::getChord()
{
    return ((Gfc2FaceConeInfo*)m_pEntity)->getChord();
}

bool NGfc2FaceConeInfo::hasChord()
{
    return ((Gfc2FaceConeInfo*)m_pEntity)->hasChord();
}

void NGfc2FaceConeInfo::setCenterPoint(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2FaceConeInfo*)m_pEntity)->setCenterPoint(nValue);
}

glodon::objectbuf::EntityRef NGfc2FaceConeInfo::getCenterPoint()
{
    return ((Gfc2FaceConeInfo*)m_pEntity)->getCenterPoint();
}

bool NGfc2FaceConeInfo::hasCenterPoint()
{
    return ((Gfc2FaceConeInfo*)m_pEntity)->hasCenterPoint();
}

NGfc2Vector2d^ NGfc2FaceConeInfo::getCenterPointPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2FaceConeInfo*)m_pEntity)->getCenterPointPtr(), false);
}

void NGfc2FaceConeInfo::setCheckInnerChord(NGfc2Boolean bValue)
{
    ((Gfc2FaceConeInfo*)m_pEntity)->setCheckInnerChord(bValue);
}

NGfc2Boolean NGfc2FaceConeInfo::getCheckInnerChord()
{
    return ((Gfc2FaceConeInfo*)m_pEntity)->getCheckInnerChord();
}

bool NGfc2FaceConeInfo::hasCheckInnerChord()
{
    return ((Gfc2FaceConeInfo*)m_pEntity)->hasCheckInnerChord();
}

