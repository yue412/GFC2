#include "StdAfx.h"
#include "NGfc2Line3d.h"
NGfc2Line3d::NGfc2Line3d()
{
    m_pEntity = new Gfc2Line3d;
    m_bOwner = true;
}

NGfc2Line3d::NGfc2Line3d(void* pEntity, bool bOwner):
    NGfc2Curve3d(pEntity, bOwner)
{
}

void NGfc2Line3d::setStartPt(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Line3d*)m_pEntity)->setStartPt(nValue);
}

glodon::objectbuf::EntityRef NGfc2Line3d::getStartPt()
{
    return ((Gfc2Line3d*)m_pEntity)->getStartPt();
}

bool NGfc2Line3d::hasStartPt()
{
    return ((Gfc2Line3d*)m_pEntity)->hasStartPt();
}

NGfc2Vector3d^ NGfc2Line3d::getStartPtPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Line3d*)m_pEntity)->getStartPtPtr(), false);
}

void NGfc2Line3d::setEndPt(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Line3d*)m_pEntity)->setEndPt(nValue);
}

glodon::objectbuf::EntityRef NGfc2Line3d::getEndPt()
{
    return ((Gfc2Line3d*)m_pEntity)->getEndPt();
}

bool NGfc2Line3d::hasEndPt()
{
    return ((Gfc2Line3d*)m_pEntity)->hasEndPt();
}

NGfc2Vector3d^ NGfc2Line3d::getEndPtPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Line3d*)m_pEntity)->getEndPtPtr(), false);
}

