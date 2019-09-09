#include "StdAfx.h"
#include "NGfc2SectionLineShape.h"
NGfc2SectionLineShape::NGfc2SectionLineShape()
{
    m_pEntity = new Gfc2SectionLineShape;
    m_bOwner = true;
}

NGfc2SectionLineShape::NGfc2SectionLineShape(void* pEntity, bool bOwner):
    NGfc2CustomLineShape(pEntity, bOwner)
{
}

void NGfc2SectionLineShape::setPoly(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SectionLineShape*)m_pEntity)->setPoly(nValue);
}

glodon::objectbuf::EntityRef NGfc2SectionLineShape::getPoly()
{
    return ((Gfc2SectionLineShape*)m_pEntity)->getPoly();
}

bool NGfc2SectionLineShape::hasPoly()
{
    return ((Gfc2SectionLineShape*)m_pEntity)->hasPoly();
}

NGfc2Polygon^ NGfc2SectionLineShape::getPolyPtr()
{
    return gcnew NGfc2Polygon(((Gfc2SectionLineShape*)m_pEntity)->getPolyPtr(), false);
}

void NGfc2SectionLineShape::setBaseInsertPt(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SectionLineShape*)m_pEntity)->setBaseInsertPt(nValue);
}

glodon::objectbuf::EntityRef NGfc2SectionLineShape::getBaseInsertPt()
{
    return ((Gfc2SectionLineShape*)m_pEntity)->getBaseInsertPt();
}

bool NGfc2SectionLineShape::hasBaseInsertPt()
{
    return ((Gfc2SectionLineShape*)m_pEntity)->hasBaseInsertPt();
}

NGfc2Vector2d^ NGfc2SectionLineShape::getBaseInsertPtPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2SectionLineShape*)m_pEntity)->getBaseInsertPtPtr(), false);
}

void NGfc2SectionLineShape::setAngle(NGfc2Double dValue)
{
    ((Gfc2SectionLineShape*)m_pEntity)->setAngle(dValue);
}

NGfc2Double NGfc2SectionLineShape::getAngle()
{
    return ((Gfc2SectionLineShape*)m_pEntity)->getAngle();
}

bool NGfc2SectionLineShape::hasAngle()
{
    return ((Gfc2SectionLineShape*)m_pEntity)->hasAngle();
}

void NGfc2SectionLineShape::setMirrorFlag(NGfc2Boolean bValue)
{
    ((Gfc2SectionLineShape*)m_pEntity)->setMirrorFlag(bValue);
}

NGfc2Boolean NGfc2SectionLineShape::getMirrorFlag()
{
    return ((Gfc2SectionLineShape*)m_pEntity)->getMirrorFlag();
}

bool NGfc2SectionLineShape::hasMirrorFlag()
{
    return ((Gfc2SectionLineShape*)m_pEntity)->hasMirrorFlag();
}

void NGfc2SectionLineShape::setArcInfo(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SectionLineShape*)m_pEntity)->setArcInfo(nValue);
}

glodon::objectbuf::EntityRef NGfc2SectionLineShape::getArcInfo()
{
    return ((Gfc2SectionLineShape*)m_pEntity)->getArcInfo();
}

bool NGfc2SectionLineShape::hasArcInfo()
{
    return ((Gfc2SectionLineShape*)m_pEntity)->hasArcInfo();
}

NGfc2BaseLineArcInfo^ NGfc2SectionLineShape::getArcInfoPtr()
{
    return gcnew NGfc2BaseLineArcInfo(((Gfc2SectionLineShape*)m_pEntity)->getArcInfoPtr(), false);
}

void NGfc2SectionLineShape::setIsSpiral(NGfc2Boolean bValue)
{
    ((Gfc2SectionLineShape*)m_pEntity)->setIsSpiral(bValue);
}

NGfc2Boolean NGfc2SectionLineShape::getIsSpiral()
{
    return ((Gfc2SectionLineShape*)m_pEntity)->getIsSpiral();
}

bool NGfc2SectionLineShape::hasIsSpiral()
{
    return ((Gfc2SectionLineShape*)m_pEntity)->hasIsSpiral();
}

