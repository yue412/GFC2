#include "StdAfx.h"
#include "NGfc2SectionPointShape.h"
NGfc2SectionPointShape::NGfc2SectionPointShape()
{
    m_pEntity = new Gfc2SectionPointShape;
    m_bOwner = true;
}

NGfc2SectionPointShape::NGfc2SectionPointShape(void* pEntity, bool bOwner):
    NGfc2CustomPointShape(pEntity, bOwner)
{
}

void NGfc2SectionPointShape::setPoly(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SectionPointShape*)m_pEntity)->setPoly(nValue);
}

glodon::objectbuf::EntityRef NGfc2SectionPointShape::getPoly()
{
    return ((Gfc2SectionPointShape*)m_pEntity)->getPoly();
}

bool NGfc2SectionPointShape::hasPoly()
{
    return ((Gfc2SectionPointShape*)m_pEntity)->hasPoly();
}

NGfc2Polygon^ NGfc2SectionPointShape::getPolyPtr()
{
    return gcnew NGfc2Polygon(((Gfc2SectionPointShape*)m_pEntity)->getPolyPtr(), false);
}

