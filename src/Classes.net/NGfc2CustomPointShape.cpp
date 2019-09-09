#include "StdAfx.h"
#include "NGfc2CustomPointShape.h"
NGfc2CustomPointShape::NGfc2CustomPointShape()
{
    m_pEntity = new Gfc2CustomPointShape;
    m_bOwner = true;
}

NGfc2CustomPointShape::NGfc2CustomPointShape(void* pEntity, bool bOwner):
    NGfc2SolidShape(pEntity, bOwner)
{
}

void NGfc2CustomPointShape::setInsertPt(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CustomPointShape*)m_pEntity)->setInsertPt(nValue);
}

glodon::objectbuf::EntityRef NGfc2CustomPointShape::getInsertPt()
{
    return ((Gfc2CustomPointShape*)m_pEntity)->getInsertPt();
}

bool NGfc2CustomPointShape::hasInsertPt()
{
    return ((Gfc2CustomPointShape*)m_pEntity)->hasInsertPt();
}

NGfc2Vector2d^ NGfc2CustomPointShape::getInsertPtPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2CustomPointShape*)m_pEntity)->getInsertPtPtr(), false);
}

void NGfc2CustomPointShape::setBaseInsertPt(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CustomPointShape*)m_pEntity)->setBaseInsertPt(nValue);
}

glodon::objectbuf::EntityRef NGfc2CustomPointShape::getBaseInsertPt()
{
    return ((Gfc2CustomPointShape*)m_pEntity)->getBaseInsertPt();
}

bool NGfc2CustomPointShape::hasBaseInsertPt()
{
    return ((Gfc2CustomPointShape*)m_pEntity)->hasBaseInsertPt();
}

NGfc2Vector2d^ NGfc2CustomPointShape::getBaseInsertPtPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2CustomPointShape*)m_pEntity)->getBaseInsertPtPtr(), false);
}

void NGfc2CustomPointShape::setAngle(NGfc2Double dValue)
{
    ((Gfc2CustomPointShape*)m_pEntity)->setAngle(dValue);
}

NGfc2Double NGfc2CustomPointShape::getAngle()
{
    return ((Gfc2CustomPointShape*)m_pEntity)->getAngle();
}

bool NGfc2CustomPointShape::hasAngle()
{
    return ((Gfc2CustomPointShape*)m_pEntity)->hasAngle();
}

void NGfc2CustomPointShape::setMirrorFlag(NGfc2Boolean bValue)
{
    ((Gfc2CustomPointShape*)m_pEntity)->setMirrorFlag(bValue);
}

NGfc2Boolean NGfc2CustomPointShape::getMirrorFlag()
{
    return ((Gfc2CustomPointShape*)m_pEntity)->getMirrorFlag();
}

bool NGfc2CustomPointShape::hasMirrorFlag()
{
    return ((Gfc2CustomPointShape*)m_pEntity)->hasMirrorFlag();
}

