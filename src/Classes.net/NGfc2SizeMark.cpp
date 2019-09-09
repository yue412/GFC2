#include "StdAfx.h"
#include "NGfc2SizeMark.h"
NGfc2SizeMark::NGfc2SizeMark()
{
    m_pEntity = new Gfc2SizeMark;
    m_bOwner = true;
}

NGfc2SizeMark::NGfc2SizeMark(void* pEntity, bool bOwner):
    NGfc2Entity(pEntity, bOwner)
{
}

void NGfc2SizeMark::setSizeMarkType(NGfc2SizeMarkType nValue)
{
    ((Gfc2SizeMark*)m_pEntity)->setSizeMarkType((Gfc2SizeMarkType)nValue);
}

NGfc2SizeMarkType NGfc2SizeMark::getSizeMarkType()
{
    return (NGfc2SizeMarkType)((Gfc2SizeMark*)m_pEntity)->getSizeMarkType();
}

bool NGfc2SizeMark::hasSizeMarkType()
{
    return ((Gfc2SizeMark*)m_pEntity)->hasSizeMarkType();
}

void NGfc2SizeMark::setStartLine(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SizeMark*)m_pEntity)->setStartLine(nValue);
}

glodon::objectbuf::EntityRef NGfc2SizeMark::getStartLine()
{
    return ((Gfc2SizeMark*)m_pEntity)->getStartLine();
}

bool NGfc2SizeMark::hasStartLine()
{
    return ((Gfc2SizeMark*)m_pEntity)->hasStartLine();
}

NGfc2CoedgeList^ NGfc2SizeMark::getStartLinePtr()
{
    return gcnew NGfc2CoedgeList(((Gfc2SizeMark*)m_pEntity)->getStartLinePtr(), false);
}

void NGfc2SizeMark::setEndLine(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SizeMark*)m_pEntity)->setEndLine(nValue);
}

glodon::objectbuf::EntityRef NGfc2SizeMark::getEndLine()
{
    return ((Gfc2SizeMark*)m_pEntity)->getEndLine();
}

bool NGfc2SizeMark::hasEndLine()
{
    return ((Gfc2SizeMark*)m_pEntity)->hasEndLine();
}

NGfc2CoedgeList^ NGfc2SizeMark::getEndLinePtr()
{
    return gcnew NGfc2CoedgeList(((Gfc2SizeMark*)m_pEntity)->getEndLinePtr(), false);
}

