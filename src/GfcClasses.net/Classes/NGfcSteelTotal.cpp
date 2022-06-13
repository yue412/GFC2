#include "NGfcSteelTotal.h"

using namespace gfc::classes::x3;

NGfcSteelTotal::NGfcSteelTotal()
{
    m_pEntity = new GfcSteelTotal;
    m_bOwner = true;
}

NGfcSteelTotal::NGfcSteelTotal(bool bNoCreate):
    NEntity(bNoCreate)
{
}

void NGfcSteelTotal::setCompType(NGfcString sValue)
{
    ((GfcSteelTotal*)m_pEntity)->setCompType(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcSteelTotal::getCompType()
{
    return marshal_as<String^>(((GfcSteelTotal*)m_pEntity)->getCompType());
}

bool NGfcSteelTotal::hasCompType()
{
    return ((GfcSteelTotal*)m_pEntity)->hasCompType();
}

void NGfcSteelTotal::setLevel(NGfcString sValue)
{
    ((GfcSteelTotal*)m_pEntity)->setLevel(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcSteelTotal::getLevel()
{
    return marshal_as<String^>(((GfcSteelTotal*)m_pEntity)->getLevel());
}

bool NGfcSteelTotal::hasLevel()
{
    return ((GfcSteelTotal*)m_pEntity)->hasLevel();
}

void NGfcSteelTotal::setDia(NGfcInteger nValue)
{
    ((GfcSteelTotal*)m_pEntity)->setDia(nValue);
}

NGfcInteger NGfcSteelTotal::getDia()
{
    return ((GfcSteelTotal*)m_pEntity)->getDia();
}

bool NGfcSteelTotal::hasDia()
{
    return ((GfcSteelTotal*)m_pEntity)->hasDia();
}

void NGfcSteelTotal::setWeight(NGfcDouble dValue)
{
    ((GfcSteelTotal*)m_pEntity)->setWeight(dValue);
}

NGfcDouble NGfcSteelTotal::getWeight()
{
    return ((GfcSteelTotal*)m_pEntity)->getWeight();
}

bool NGfcSteelTotal::hasWeight()
{
    return ((GfcSteelTotal*)m_pEntity)->hasWeight();
}

void NGfcSteelTotal::setUnit(NGfcString sValue)
{
    ((GfcSteelTotal*)m_pEntity)->setUnit(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcSteelTotal::getUnit()
{
    return marshal_as<String^>(((GfcSteelTotal*)m_pEntity)->getUnit());
}

bool NGfcSteelTotal::hasUnit()
{
    return ((GfcSteelTotal*)m_pEntity)->hasUnit();
}

