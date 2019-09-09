#include "StdAfx.h"
#include "NGfc2PointShape.h"
NGfc2PointShape::NGfc2PointShape()
{
    m_pEntity = new Gfc2PointShape;
    m_bOwner = true;
}

NGfc2PointShape::NGfc2PointShape(void* pEntity, bool bOwner):
    NGfc2SectionPointShape(pEntity, bOwner)
{
}

void NGfc2PointShape::setHeight(NGfc2Double dValue)
{
    ((Gfc2PointShape*)m_pEntity)->setHeight(dValue);
}

NGfc2Double NGfc2PointShape::getHeight()
{
    return ((Gfc2PointShape*)m_pEntity)->getHeight();
}

bool NGfc2PointShape::hasHeight()
{
    return ((Gfc2PointShape*)m_pEntity)->hasHeight();
}

void NGfc2PointShape::setObliqueDir(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2PointShape*)m_pEntity)->setObliqueDir(nValue);
}

glodon::objectbuf::EntityRef NGfc2PointShape::getObliqueDir()
{
    return ((Gfc2PointShape*)m_pEntity)->getObliqueDir();
}

bool NGfc2PointShape::hasObliqueDir()
{
    return ((Gfc2PointShape*)m_pEntity)->hasObliqueDir();
}

NGfc2Vector3d^ NGfc2PointShape::getObliqueDirPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2PointShape*)m_pEntity)->getObliqueDirPtr(), false);
}

void NGfc2PointShape::setTopPoly(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2PointShape*)m_pEntity)->setTopPoly(nValue);
}

glodon::objectbuf::EntityRef NGfc2PointShape::getTopPoly()
{
    return ((Gfc2PointShape*)m_pEntity)->getTopPoly();
}

bool NGfc2PointShape::hasTopPoly()
{
    return ((Gfc2PointShape*)m_pEntity)->hasTopPoly();
}

NGfc2Polygon^ NGfc2PointShape::getTopPolyPtr()
{
    return gcnew NGfc2Polygon(((Gfc2PointShape*)m_pEntity)->getTopPolyPtr(), false);
}

