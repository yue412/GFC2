#include "StdAfx.h"
#include "NGfc2CustomLineShape.h"
NGfc2CustomLineShape::NGfc2CustomLineShape()
{
    m_pEntity = new Gfc2CustomLineShape;
    m_bOwner = true;
}

NGfc2CustomLineShape::NGfc2CustomLineShape(void* pEntity, bool bOwner):
    NGfc2SolidShape(pEntity, bOwner)
{
}

void NGfc2CustomLineShape::setWidth(NGfc2Double dValue)
{
    ((Gfc2CustomLineShape*)m_pEntity)->setWidth(dValue);
}

NGfc2Double NGfc2CustomLineShape::getWidth()
{
    return ((Gfc2CustomLineShape*)m_pEntity)->getWidth();
}

bool NGfc2CustomLineShape::hasWidth()
{
    return ((Gfc2CustomLineShape*)m_pEntity)->hasWidth();
}

void NGfc2CustomLineShape::setLeftWidth(NGfc2Double dValue)
{
    ((Gfc2CustomLineShape*)m_pEntity)->setLeftWidth(dValue);
}

NGfc2Double NGfc2CustomLineShape::getLeftWidth()
{
    return ((Gfc2CustomLineShape*)m_pEntity)->getLeftWidth();
}

bool NGfc2CustomLineShape::hasLeftWidth()
{
    return ((Gfc2CustomLineShape*)m_pEntity)->hasLeftWidth();
}

void NGfc2CustomLineShape::setLine(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CustomLineShape*)m_pEntity)->setLine(nValue);
}

glodon::objectbuf::EntityRef NGfc2CustomLineShape::getLine()
{
    return ((Gfc2CustomLineShape*)m_pEntity)->getLine();
}

bool NGfc2CustomLineShape::hasLine()
{
    return ((Gfc2CustomLineShape*)m_pEntity)->hasLine();
}

NGfc2Curve2d^ NGfc2CustomLineShape::getLinePtr()
{
    return gcnew NGfc2Curve2d(((Gfc2CustomLineShape*)m_pEntity)->getLinePtr(), false);
}

void NGfc2CustomLineShape::setE_S_Elevation(NGfc2Double dValue)
{
    ((Gfc2CustomLineShape*)m_pEntity)->setE_S_Elevation(dValue);
}

NGfc2Double NGfc2CustomLineShape::getE_S_Elevation()
{
    return ((Gfc2CustomLineShape*)m_pEntity)->getE_S_Elevation();
}

bool NGfc2CustomLineShape::hasE_S_Elevation()
{
    return ((Gfc2CustomLineShape*)m_pEntity)->hasE_S_Elevation();
}

