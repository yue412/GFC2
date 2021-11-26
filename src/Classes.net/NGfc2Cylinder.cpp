#include "NGfc2Cylinder.h"

using namespace gfc::classes::x3;

NGfc2Cylinder::NGfc2Cylinder()
{
    m_pEntity = new Gfc2Cylinder;
    m_bOwner = true;
}

NGfc2Cylinder::NGfc2Cylinder(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2Cylinder::setRangeV(gfc::engine::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfc2Cylinder::getRangeV()
{
    return ((Gfc2Cylinder*)m_pEntity)->getRangeV();
}

bool NGfc2Cylinder::hasRangeV()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasRangeV();
}

void NGfc2Cylinder::setCurve(gfc::engine::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfc2Cylinder::getCurve()
{
    return ((Gfc2Cylinder*)m_pEntity)->getCurve();
}

bool NGfc2Cylinder::hasCurve()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasCurve();
}

void NGfc2Cylinder::setDirX(gfc::engine::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setDirX(nValue);
}

gfc::engine::EntityRef NGfc2Cylinder::getDirX()
{
    return ((Gfc2Cylinder*)m_pEntity)->getDirX();
}

bool NGfc2Cylinder::hasDirX()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasDirX();
}

void NGfc2Cylinder::setDirY(gfc::engine::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setDirY(nValue);
}

gfc::engine::EntityRef NGfc2Cylinder::getDirY()
{
    return ((Gfc2Cylinder*)m_pEntity)->getDirY();
}

bool NGfc2Cylinder::hasDirY()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasDirY();
}

void NGfc2Cylinder::setDirZ(gfc::engine::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setDirZ(nValue);
}

gfc::engine::EntityRef NGfc2Cylinder::getDirZ()
{
    return ((Gfc2Cylinder*)m_pEntity)->getDirZ();
}

bool NGfc2Cylinder::hasDirZ()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasDirZ();
}

void NGfc2Cylinder::setPos(gfc::engine::EntityRef nValue)
{
    ((Gfc2Cylinder*)m_pEntity)->setPos(nValue);
}

gfc::engine::EntityRef NGfc2Cylinder::getPos()
{
    return ((Gfc2Cylinder*)m_pEntity)->getPos();
}

bool NGfc2Cylinder::hasPos()
{
    return ((Gfc2Cylinder*)m_pEntity)->hasPos();
}

