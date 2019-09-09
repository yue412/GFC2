#include "StdAfx.h"
#include "NGfc2PointShape2d.h"
NGfc2PointShape2d::NGfc2PointShape2d()
{
    m_pEntity = new Gfc2PointShape2d;
    m_bOwner = true;
}

NGfc2PointShape2d::NGfc2PointShape2d(void* pEntity, bool bOwner):
    NGfc2Shape2d(pEntity, bOwner)
{
}

void NGfc2PointShape2d::setInsertPt(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2PointShape2d*)m_pEntity)->setInsertPt(nValue);
}

glodon::objectbuf::EntityRef NGfc2PointShape2d::getInsertPt()
{
    return ((Gfc2PointShape2d*)m_pEntity)->getInsertPt();
}

bool NGfc2PointShape2d::hasInsertPt()
{
    return ((Gfc2PointShape2d*)m_pEntity)->hasInsertPt();
}

NGfc2Vector2d^ NGfc2PointShape2d::getInsertPtPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2PointShape2d*)m_pEntity)->getInsertPtPtr(), false);
}

void NGfc2PointShape2d::setAngle(NGfc2Double dValue)
{
    ((Gfc2PointShape2d*)m_pEntity)->setAngle(dValue);
}

NGfc2Double NGfc2PointShape2d::getAngle()
{
    return ((Gfc2PointShape2d*)m_pEntity)->getAngle();
}

bool NGfc2PointShape2d::hasAngle()
{
    return ((Gfc2PointShape2d*)m_pEntity)->hasAngle();
}

void NGfc2PointShape2d::setMirrorFlag(NGfc2Boolean bValue)
{
    ((Gfc2PointShape2d*)m_pEntity)->setMirrorFlag(bValue);
}

NGfc2Boolean NGfc2PointShape2d::getMirrorFlag()
{
    return ((Gfc2PointShape2d*)m_pEntity)->getMirrorFlag();
}

bool NGfc2PointShape2d::hasMirrorFlag()
{
    return ((Gfc2PointShape2d*)m_pEntity)->hasMirrorFlag();
}

