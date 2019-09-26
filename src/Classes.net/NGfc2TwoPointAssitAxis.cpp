#include "StdAfx.h"
#include "NGfc2TwoPointAssitAxis.h"
NGfc2TwoPointAssitAxis::NGfc2TwoPointAssitAxis()
{
    m_pEntity = new Gfc2TwoPointAssitAxis;
    m_bOwner = true;
}

NGfc2TwoPointAssitAxis::NGfc2TwoPointAssitAxis(void* pEntity, bool bOwner):
    NGfc2AssitAxis(pEntity, bOwner)
{
}

void NGfc2TwoPointAssitAxis::setStartPt(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2TwoPointAssitAxis*)m_pEntity)->setStartPt(nValue);
}

glodon::objectbuf::EntityRef NGfc2TwoPointAssitAxis::getStartPt()
{
    return ((Gfc2TwoPointAssitAxis*)m_pEntity)->getStartPt();
}

bool NGfc2TwoPointAssitAxis::hasStartPt()
{
    return ((Gfc2TwoPointAssitAxis*)m_pEntity)->hasStartPt();
}

NGfc2Vector2d^ NGfc2TwoPointAssitAxis::getStartPtPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2TwoPointAssitAxis*)m_pEntity)->getStartPtPtr(), false);
}

void NGfc2TwoPointAssitAxis::setEndPt(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2TwoPointAssitAxis*)m_pEntity)->setEndPt(nValue);
}

glodon::objectbuf::EntityRef NGfc2TwoPointAssitAxis::getEndPt()
{
    return ((Gfc2TwoPointAssitAxis*)m_pEntity)->getEndPt();
}

bool NGfc2TwoPointAssitAxis::hasEndPt()
{
    return ((Gfc2TwoPointAssitAxis*)m_pEntity)->hasEndPt();
}

NGfc2Vector2d^ NGfc2TwoPointAssitAxis::getEndPtPtr()
{
    return gcnew NGfc2Vector2d(((Gfc2TwoPointAssitAxis*)m_pEntity)->getEndPtPtr(), false);
}

