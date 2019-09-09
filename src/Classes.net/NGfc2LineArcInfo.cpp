#include "StdAfx.h"
#include "NGfc2LineArcInfo.h"
NGfc2LineArcInfo::NGfc2LineArcInfo()
{
    m_pEntity = new Gfc2LineArcInfo;
    m_bOwner = true;
}

NGfc2LineArcInfo::NGfc2LineArcInfo(void* pEntity, bool bOwner):
    NGfc2BaseLineArcInfo(pEntity, bOwner)
{
}

void NGfc2LineArcInfo::setBasePoint(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2LineArcInfo*)m_pEntity)->setBasePoint(nValue);
}

glodon::objectbuf::EntityRef NGfc2LineArcInfo::getBasePoint()
{
    return ((Gfc2LineArcInfo*)m_pEntity)->getBasePoint();
}

bool NGfc2LineArcInfo::hasBasePoint()
{
    return ((Gfc2LineArcInfo*)m_pEntity)->hasBasePoint();
}

NGfc2Vector2d^ NGfc2LineArcInfo::getBasePointPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2LineArcInfo*)m_pEntity)->getBasePointPtr(), false);
}

void NGfc2LineArcInfo::setArchHeight(NGfc2Double dValue)
{
    ((Gfc2LineArcInfo*)m_pEntity)->setArchHeight(dValue);
}

NGfc2Double NGfc2LineArcInfo::getArchHeight()
{
    return ((Gfc2LineArcInfo*)m_pEntity)->getArchHeight();
}

bool NGfc2LineArcInfo::hasArchHeight()
{
    return ((Gfc2LineArcInfo*)m_pEntity)->hasArchHeight();
}

void NGfc2LineArcInfo::setHalfChordLength(NGfc2Double dValue)
{
    ((Gfc2LineArcInfo*)m_pEntity)->setHalfChordLength(dValue);
}

NGfc2Double NGfc2LineArcInfo::getHalfChordLength()
{
    return ((Gfc2LineArcInfo*)m_pEntity)->getHalfChordLength();
}

bool NGfc2LineArcInfo::hasHalfChordLength()
{
    return ((Gfc2LineArcInfo*)m_pEntity)->hasHalfChordLength();
}

void NGfc2LineArcInfo::setRadius(NGfc2Double dValue)
{
    ((Gfc2LineArcInfo*)m_pEntity)->setRadius(dValue);
}

NGfc2Double NGfc2LineArcInfo::getRadius()
{
    return ((Gfc2LineArcInfo*)m_pEntity)->getRadius();
}

bool NGfc2LineArcInfo::hasRadius()
{
    return ((Gfc2LineArcInfo*)m_pEntity)->hasRadius();
}

void NGfc2LineArcInfo::setDefineByRadius(NGfc2Boolean bValue)
{
    ((Gfc2LineArcInfo*)m_pEntity)->setDefineByRadius(bValue);
}

NGfc2Boolean NGfc2LineArcInfo::getDefineByRadius()
{
    return ((Gfc2LineArcInfo*)m_pEntity)->getDefineByRadius();
}

bool NGfc2LineArcInfo::hasDefineByRadius()
{
    return ((Gfc2LineArcInfo*)m_pEntity)->hasDefineByRadius();
}

