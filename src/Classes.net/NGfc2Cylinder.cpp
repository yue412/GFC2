#include "StdAfx.h"
#include "NGfc2Cylinder.h"
NGfc2Cylinder::NGfc2Cylinder()
{
    m_pEntity = new Gfc2Cylinder;
    m_bOwner = true;
}

NGfc2Cylinder::NGfc2Cylinder(void* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2Cylinder::setCoord(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setCoord(nValue);
}

glodon::objectbuf::EntityRef NGfc2Cylinder::getCoord()
{
    return ((Gfc2Cylinder*)m_pEntity)->getCoord();
}

bool NGfc2Cylinder::hasCoord()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasCoord();
}

NGfc2Coordinates3d^ NGfc2Cylinder::getCoordPtr()
{
    return gcnew NGfc2Coordinates3d(((Gfc2Cylinder*)m_pEntity)->getCoordPtr(), false);
}

void NGfc2Cylinder::setRangeV(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setRangeV(nValue);
}

glodon::objectbuf::EntityRef NGfc2Cylinder::getRangeV()
{
    return ((Gfc2Cylinder*)m_pEntity)->getRangeV();
}

bool NGfc2Cylinder::hasRangeV()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasRangeV();
}

NGfc2Intervald^ NGfc2Cylinder::getRangeVPtr()
{
    return gcnew NGfc2Intervald(((Gfc2Cylinder*)m_pEntity)->getRangeVPtr(), false);
}

void NGfc2Cylinder::setCurve(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setCurve(nValue);
}

glodon::objectbuf::EntityRef NGfc2Cylinder::getCurve()
{
    return ((Gfc2Cylinder*)m_pEntity)->getCurve();
}

bool NGfc2Cylinder::hasCurve()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasCurve();
}

NGfc2Curve2d^ NGfc2Cylinder::getCurvePtr()
{
    return gcnew NGfc2Curve2d(((Gfc2Cylinder*)m_pEntity)->getCurvePtr(), false);
}

