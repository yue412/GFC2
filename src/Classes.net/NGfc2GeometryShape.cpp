#include "StdAfx.h"
#include "NGfc2GeometryShape.h"
NGfc2GeometryShape::NGfc2GeometryShape()
{
    m_pEntity = new Gfc2GeometryShape;
    m_bOwner = true;
}

NGfc2GeometryShape::NGfc2GeometryShape(void* pEntity, bool bOwner):
    NGfc2Shape(pEntity, bOwner)
{
}

int NGfc2GeometryShape::getGeosCount()
{
    return ((Gfc2GeometryShape*)m_pEntity)->getGeosCount();
}

void NGfc2GeometryShape::clearGeos()
{
    ((Gfc2GeometryShape*)m_pEntity)->clearGeos();
}

void NGfc2GeometryShape::addGeos(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2GeometryShape*)m_pEntity)->addGeos(nValue);
}

glodon::objectbuf::EntityRef NGfc2GeometryShape::getGeos(int nIndex)
{
    return ((Gfc2GeometryShape*)m_pEntity)->getGeos(nIndex);
}

NGfc2Geometry^ NGfc2GeometryShape::getGeosPtr(int nIndex)
{
    return gcnew NGfc2Geometry(((Gfc2GeometryShape*)m_pEntity)->getGeosPtr(nIndex), false);
}

