#include "StdAfx.h"
#include "NGfc2LineShape2d.h"
NGfc2LineShape2d::NGfc2LineShape2d()
{
    m_pEntity = new Gfc2LineShape2d;
    m_bOwner = true;
}

NGfc2LineShape2d::NGfc2LineShape2d(void* pEntity, bool bOwner):
    NGfc2Shape2d(pEntity, bOwner)
{
}

void NGfc2LineShape2d::setLine(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2LineShape2d*)m_pEntity)->setLine(nValue);
}

glodon::objectbuf::EntityRef NGfc2LineShape2d::getLine()
{
    return ((Gfc2LineShape2d*)m_pEntity)->getLine();
}

bool NGfc2LineShape2d::hasLine()
{
    return ((Gfc2LineShape2d*)m_pEntity)->hasLine();
}

NGfc2Curve2d^ NGfc2LineShape2d::getLinePtr()
{
    return gcnew NGfc2Curve2d(((Gfc2LineShape2d*)m_pEntity)->getLinePtr(), false);
}

