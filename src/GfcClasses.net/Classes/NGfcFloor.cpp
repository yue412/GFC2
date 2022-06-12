#include "NGfcFloor.h"

using namespace gfc::classes::x3;

NGfcFloor::NGfcFloor()
{
    m_pEntity = new GfcFloor;
    m_bOwner = true;
}

NGfcFloor::NGfcFloor(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSpatialStructureElement(pEntity, bOwner)
{
}

void NGfcFloor::setHeight(NGfcDouble dValue)
{
    ((GfcFloor*)m_pEntity)->setHeight(dValue);
}

NGfcDouble NGfcFloor::getHeight()
{
    return ((GfcFloor*)m_pEntity)->getHeight();
}

bool NGfcFloor::hasHeight()
{
    return ((GfcFloor*)m_pEntity)->hasHeight();
}

void NGfcFloor::setStdFloorCount(NGfcInteger nValue)
{
    ((GfcFloor*)m_pEntity)->setStdFloorCount(nValue);
}

NGfcInteger NGfcFloor::getStdFloorCount()
{
    return ((GfcFloor*)m_pEntity)->getStdFloorCount();
}

bool NGfcFloor::hasStdFloorCount()
{
    return ((GfcFloor*)m_pEntity)->hasStdFloorCount();
}

void NGfcFloor::setStructuralElevation(NGfcDouble dValue)
{
    ((GfcFloor*)m_pEntity)->setStructuralElevation(dValue);
}

NGfcDouble NGfcFloor::getStructuralElevation()
{
    return ((GfcFloor*)m_pEntity)->getStructuralElevation();
}

bool NGfcFloor::hasStructuralElevation()
{
    return ((GfcFloor*)m_pEntity)->hasStructuralElevation();
}

void NGfcFloor::setStartFloorNo(NGfcInteger nValue)
{
    ((GfcFloor*)m_pEntity)->setStartFloorNo(nValue);
}

NGfcInteger NGfcFloor::getStartFloorNo()
{
    return ((GfcFloor*)m_pEntity)->getStartFloorNo();
}

bool NGfcFloor::hasStartFloorNo()
{
    return ((GfcFloor*)m_pEntity)->hasStartFloorNo();
}

void NGfcFloor::setRemark(NGfcText sValue)
{
    ((GfcFloor*)m_pEntity)->setRemark(marshal_as<std::wstring>(sValue));
}

NGfcText NGfcFloor::getRemark()
{
    return marshal_as<String^>(((GfcFloor*)m_pEntity)->getRemark());
}

bool NGfcFloor::hasRemark()
{
    return ((GfcFloor*)m_pEntity)->hasRemark();
}

