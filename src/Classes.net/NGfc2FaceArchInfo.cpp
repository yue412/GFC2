#include "StdAfx.h"
#include "NGfc2FaceArchInfo.h"
NGfc2FaceArchInfo::NGfc2FaceArchInfo()
{
    m_pEntity = new Gfc2FaceArchInfo;
    m_bOwner = true;
}

NGfc2FaceArchInfo::NGfc2FaceArchInfo(void* pEntity, bool bOwner):
    NGfc2FaceInfo(pEntity, bOwner)
{
}

void NGfc2FaceArchInfo::setAxialLine(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2FaceArchInfo*)m_pEntity)->setAxialLine(nValue);
}

glodon::objectbuf::EntityRef NGfc2FaceArchInfo::getAxialLine()
{
    return ((Gfc2FaceArchInfo*)m_pEntity)->getAxialLine();
}

bool NGfc2FaceArchInfo::hasAxialLine()
{
    return ((Gfc2FaceArchInfo*)m_pEntity)->hasAxialLine();
}

NGfc2Line2d^ NGfc2FaceArchInfo::getAxialLinePtr()
{
    return gcnew NGfc2Line2d(((Gfc2FaceArchInfo*)m_pEntity)->getAxialLinePtr(), false);
}

void NGfc2FaceArchInfo::setHeight(NGfc2Double dValue)
{
    ((Gfc2FaceArchInfo*)m_pEntity)->setHeight(dValue);
}

NGfc2Double NGfc2FaceArchInfo::getHeight()
{
    return ((Gfc2FaceArchInfo*)m_pEntity)->getHeight();
}

bool NGfc2FaceArchInfo::hasHeight()
{
    return ((Gfc2FaceArchInfo*)m_pEntity)->hasHeight();
}

void NGfc2FaceArchInfo::setChord(NGfc2Double dValue)
{
    ((Gfc2FaceArchInfo*)m_pEntity)->setChord(dValue);
}

NGfc2Double NGfc2FaceArchInfo::getChord()
{
    return ((Gfc2FaceArchInfo*)m_pEntity)->getChord();
}

bool NGfc2FaceArchInfo::hasChord()
{
    return ((Gfc2FaceArchInfo*)m_pEntity)->hasChord();
}

void NGfc2FaceArchInfo::setRadius(NGfc2Double dValue)
{
    ((Gfc2FaceArchInfo*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2FaceArchInfo::getRadius()
{
    return ((Gfc2FaceArchInfo*)m_pEntity)->getRadius();
}

bool NGfc2FaceArchInfo::hasRadius()
{
    return ((Gfc2FaceArchInfo*)m_pEntity)->hasRadius();
}

void NGfc2FaceArchInfo::setDefineByRadius(NGfc2Boolean bValue)
{
    ((Gfc2FaceArchInfo*)m_pEntity)->setDefineByRadius(bValue);
}

NGfc2Boolean NGfc2FaceArchInfo::getDefineByRadius()
{
    return ((Gfc2FaceArchInfo*)m_pEntity)->getDefineByRadius();
}

bool NGfc2FaceArchInfo::hasDefineByRadius()
{
    return ((Gfc2FaceArchInfo*)m_pEntity)->hasDefineByRadius();
}

void NGfc2FaceArchInfo::setCheckInnerChord(NGfc2Boolean bValue)
{
    ((Gfc2FaceArchInfo*)m_pEntity)->setCheckInnerChord(bValue);
}

NGfc2Boolean NGfc2FaceArchInfo::getCheckInnerChord()
{
    return ((Gfc2FaceArchInfo*)m_pEntity)->getCheckInnerChord();
}

bool NGfc2FaceArchInfo::hasCheckInnerChord()
{
    return ((Gfc2FaceArchInfo*)m_pEntity)->hasCheckInnerChord();
}

