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

void NGfc2Cylinder::setRangeV(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setRangeV(nValue);
}

gfc2::engine::EntityRef NGfc2Cylinder::getRangeV()
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

void NGfc2Cylinder::setCurve(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setCurve(nValue);
}

gfc2::engine::EntityRef NGfc2Cylinder::getCurve()
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

void NGfc2Cylinder::setDirX(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setDirX(nValue);
}

gfc2::engine::EntityRef NGfc2Cylinder::getDirX()
{
    return ((Gfc2Cylinder*)m_pEntity)->getDirX();
}

bool NGfc2Cylinder::hasDirX()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasDirX();
}

NGfc2Vector3d^ NGfc2Cylinder::getDirXPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Cylinder*)m_pEntity)->getDirXPtr(), false);
}

void NGfc2Cylinder::setDirY(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setDirY(nValue);
}

gfc2::engine::EntityRef NGfc2Cylinder::getDirY()
{
    return ((Gfc2Cylinder*)m_pEntity)->getDirY();
}

bool NGfc2Cylinder::hasDirY()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasDirY();
}

NGfc2Vector3d^ NGfc2Cylinder::getDirYPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Cylinder*)m_pEntity)->getDirYPtr(), false);
}

void NGfc2Cylinder::setDirZ(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setDirZ(nValue);
}

gfc2::engine::EntityRef NGfc2Cylinder::getDirZ()
{
    return ((Gfc2Cylinder*)m_pEntity)->getDirZ();
}

bool NGfc2Cylinder::hasDirZ()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasDirZ();
}

NGfc2Vector3d^ NGfc2Cylinder::getDirZPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Cylinder*)m_pEntity)->getDirZPtr(), false);
}

void NGfc2Cylinder::setPos(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setPos(nValue);
}

gfc2::engine::EntityRef NGfc2Cylinder::getPos()
{
    return ((Gfc2Cylinder*)m_pEntity)->getPos();
}

bool NGfc2Cylinder::hasPos()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasPos();
}

NGfc2Vector3d^ NGfc2Cylinder::getPosPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2Cylinder*)m_pEntity)->getPosPtr(), false);
}

