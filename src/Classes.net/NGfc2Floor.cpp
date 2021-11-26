#include "NGfc2Floor.h"

using namespace gfc::classes::x3;

NGfc2Floor::NGfc2Floor()
{
    m_pEntity = new Gfc2Floor;
    m_bOwner = true;
}

NGfc2Floor::NGfc2Floor(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2SpatialStructureElement(pEntity, bOwner)
{
}

void NGfc2Floor::setHeight(NGfc2Double dValue)
{
    ((Gfc2Floor*)m_pEntity)->setHeight(dValue);
}

NGfc2Double NGfc2Floor::getHeight()
{
    return ((Gfc2Floor*)m_pEntity)->getHeight();
}

bool NGfc2Floor::hasHeight()
{
    return ((Gfc2Floor*)m_pEntity)->hasHeight();
}

void NGfc2Floor::setStdFloorCount(NGfc2Integer nValue)
{
    ((Gfc2Floor*)m_pEntity)->setStdFloorCount(nValue);
}

NGfc2Integer NGfc2Floor::getStdFloorCount()
{
    return ((Gfc2Floor*)m_pEntity)->getStdFloorCount();
}

bool NGfc2Floor::hasStdFloorCount()
{
    return ((Gfc2Floor*)m_pEntity)->hasStdFloorCount();
}

void NGfc2Floor::setStructuralElevation(NGfc2Double dValue)
{
    ((Gfc2Floor*)m_pEntity)->setStructuralElevation(dValue);
}

NGfc2Double NGfc2Floor::getStructuralElevation()
{
    return ((Gfc2Floor*)m_pEntity)->getStructuralElevation();
}

bool NGfc2Floor::hasStructuralElevation()
{
    return ((Gfc2Floor*)m_pEntity)->hasStructuralElevation();
}

void NGfc2Floor::setStartFloorNo(NGfc2Integer nValue)
{
    ((Gfc2Floor*)m_pEntity)->setStartFloorNo(nValue);
}

NGfc2Integer NGfc2Floor::getStartFloorNo()
{
    return ((Gfc2Floor*)m_pEntity)->getStartFloorNo();
}

bool NGfc2Floor::hasStartFloorNo()
{
    return ((Gfc2Floor*)m_pEntity)->hasStartFloorNo();
}

void NGfc2Floor::setRemark(NGfc2Text sValue)
{
    ((Gfc2Floor*)m_pEntity)->setRemark(marshal_as<std::wstring>(sValue));
}

NGfc2Text NGfc2Floor::getRemark()
{
    return marshal_as<String^>(((Gfc2Floor*)m_pEntity)->getRemark());
}

bool NGfc2Floor::hasRemark()
{
    return ((Gfc2Floor*)m_pEntity)->hasRemark();
}

