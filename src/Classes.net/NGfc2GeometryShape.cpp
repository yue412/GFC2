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

void NGfc2GeometryShape::setGeo(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2GeometryShape*)m_pEntity)->setGeo(nValue);
}

glodon::objectbuf::EntityRef NGfc2GeometryShape::getGeo()
{
    return ((Gfc2GeometryShape*)m_pEntity)->getGeo();
}

bool NGfc2GeometryShape::hasGeo()
{
    return ((Gfc2GeometryShape*)m_pEntity)->hasGeo();
}

NGfc2Geometry^ NGfc2GeometryShape::getGeoPtr()
{
    return gcnew NGfc2Geometry(((Gfc2GeometryShape*)m_pEntity)->getGeoPtr(), false);
}

