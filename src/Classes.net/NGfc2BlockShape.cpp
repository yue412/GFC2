#include "StdAfx.h"
#include "NGfc2BlockShape.h"
NGfc2BlockShape::NGfc2BlockShape()
{
    m_pEntity = new Gfc2BlockShape;
    m_bOwner = true;
}

NGfc2BlockShape::NGfc2BlockShape(void* pEntity, bool bOwner):
    NGfc2PrimitiveShape(pEntity, bOwner)
{
}

void NGfc2BlockShape::setXLength(NGfc2Double dValue)
{
    ((Gfc2BlockShape*)m_pEntity)->setXLength(dValue);
}

NGfc2Double NGfc2BlockShape::getXLength()
{
    return ((Gfc2BlockShape*)m_pEntity)->getXLength();
}

bool NGfc2BlockShape::hasXLength()
{
    return ((Gfc2BlockShape*)m_pEntity)->hasXLength();
}

void NGfc2BlockShape::setYLength(NGfc2Double dValue)
{
    ((Gfc2BlockShape*)m_pEntity)->setYLength(dValue);
}

NGfc2Double NGfc2BlockShape::getYLength()
{
    return ((Gfc2BlockShape*)m_pEntity)->getYLength();
}

bool NGfc2BlockShape::hasYLength()
{
    return ((Gfc2BlockShape*)m_pEntity)->hasYLength();
}

void NGfc2BlockShape::setZLength(NGfc2Double dValue)
{
    ((Gfc2BlockShape*)m_pEntity)->setZLength(dValue);
}

NGfc2Double NGfc2BlockShape::getZLength()
{
    return ((Gfc2BlockShape*)m_pEntity)->getZLength();
}

bool NGfc2BlockShape::hasZLength()
{
    return ((Gfc2BlockShape*)m_pEntity)->hasZLength();
}

