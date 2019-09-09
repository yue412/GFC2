#include "StdAfx.h"
#include "NGfc2VariableSectionLineShape.h"
NGfc2VariableSectionLineShape::NGfc2VariableSectionLineShape()
{
    m_pEntity = new Gfc2VariableSectionLineShape;
    m_bOwner = true;
}

NGfc2VariableSectionLineShape::NGfc2VariableSectionLineShape(void* pEntity, bool bOwner):
    NGfc2SectionLineShape(pEntity, bOwner)
{
}

void NGfc2VariableSectionLineShape::setEndPoly(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2VariableSectionLineShape*)m_pEntity)->setEndPoly(nValue);
}

glodon::objectbuf::EntityRef NGfc2VariableSectionLineShape::getEndPoly()
{
    return ((Gfc2VariableSectionLineShape*)m_pEntity)->getEndPoly();
}

bool NGfc2VariableSectionLineShape::hasEndPoly()
{
    return ((Gfc2VariableSectionLineShape*)m_pEntity)->hasEndPoly();
}

NGfc2Polygon^ NGfc2VariableSectionLineShape::getEndPolyPtr()
{
    return gcnew NGfc2Polygon(((Gfc2VariableSectionLineShape*)m_pEntity)->getEndPolyPtr(), false);
}

