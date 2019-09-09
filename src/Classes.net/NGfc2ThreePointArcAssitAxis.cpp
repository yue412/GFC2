#include "StdAfx.h"
#include "NGfc2ThreePointArcAssitAxis.h"
NGfc2ThreePointArcAssitAxis::NGfc2ThreePointArcAssitAxis()
{
    m_pEntity = new Gfc2ThreePointArcAssitAxis;
    m_bOwner = true;
}

NGfc2ThreePointArcAssitAxis::NGfc2ThreePointArcAssitAxis(void* pEntity, bool bOwner):
    NGfc2AssitAxis(pEntity, bOwner)
{
}

void NGfc2ThreePointArcAssitAxis::setRefPoint1(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2ThreePointArcAssitAxis*)m_pEntity)->setRefPoint1(nValue);
}

glodon::objectbuf::EntityRef NGfc2ThreePointArcAssitAxis::getRefPoint1()
{
    return ((Gfc2ThreePointArcAssitAxis*)m_pEntity)->getRefPoint1();
}

bool NGfc2ThreePointArcAssitAxis::hasRefPoint1()
{
    return ((Gfc2ThreePointArcAssitAxis*)m_pEntity)->hasRefPoint1();
}

NGfc2Vector2d^ NGfc2ThreePointArcAssitAxis::getRefPoint1Ptr()
{
    return gcnew NGfc2Vector2d(((Gfc2ThreePointArcAssitAxis*)m_pEntity)->getRefPoint1Ptr(), false);
}

void NGfc2ThreePointArcAssitAxis::setRefPoint2(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2ThreePointArcAssitAxis*)m_pEntity)->setRefPoint2(nValue);
}

glodon::objectbuf::EntityRef NGfc2ThreePointArcAssitAxis::getRefPoint2()
{
    return ((Gfc2ThreePointArcAssitAxis*)m_pEntity)->getRefPoint2();
}

bool NGfc2ThreePointArcAssitAxis::hasRefPoint2()
{
    return ((Gfc2ThreePointArcAssitAxis*)m_pEntity)->hasRefPoint2();
}

NGfc2Vector2d^ NGfc2ThreePointArcAssitAxis::getRefPoint2Ptr()
{
    return gcnew NGfc2Vector2d(((Gfc2ThreePointArcAssitAxis*)m_pEntity)->getRefPoint2Ptr(), false);
}

void NGfc2ThreePointArcAssitAxis::setRefPoint3(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2ThreePointArcAssitAxis*)m_pEntity)->setRefPoint3(nValue);
}

glodon::objectbuf::EntityRef NGfc2ThreePointArcAssitAxis::getRefPoint3()
{
    return ((Gfc2ThreePointArcAssitAxis*)m_pEntity)->getRefPoint3();
}

bool NGfc2ThreePointArcAssitAxis::hasRefPoint3()
{
    return ((Gfc2ThreePointArcAssitAxis*)m_pEntity)->hasRefPoint3();
}

NGfc2Vector2d^ NGfc2ThreePointArcAssitAxis::getRefPoint3Ptr()
{
    return gcnew NGfc2Vector2d(((Gfc2ThreePointArcAssitAxis*)m_pEntity)->getRefPoint3Ptr(), false);
}

