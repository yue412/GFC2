#include "NGfcSteelDetail.h"

using namespace gfc::classes::x3;

NGfcSteelDetail::NGfcSteelDetail()
{
    m_pEntity = new GfcSteelDetail;
    m_bOwner = true;
}

NGfcSteelDetail::NGfcSteelDetail(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

void NGfcSteelDetail::setEntityID(NGfcInteger nValue)
{
    ((GfcSteelDetail*)m_pEntity)->setEntityID(nValue);
}

NGfcInteger NGfcSteelDetail::getEntityID()
{
    return ((GfcSteelDetail*)m_pEntity)->getEntityID();
}

bool NGfcSteelDetail::hasEntityID()
{
    return ((GfcSteelDetail*)m_pEntity)->hasEntityID();
}

void NGfcSteelDetail::setName(NGfcString sValue)
{
    ((GfcSteelDetail*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcSteelDetail::getName()
{
    return marshal_as<String^>(((GfcSteelDetail*)m_pEntity)->getName());
}

bool NGfcSteelDetail::hasName()
{
    return ((GfcSteelDetail*)m_pEntity)->hasName();
}

void NGfcSteelDetail::setDesc(NGfcString sValue)
{
    ((GfcSteelDetail*)m_pEntity)->setDesc(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcSteelDetail::getDesc()
{
    return marshal_as<String^>(((GfcSteelDetail*)m_pEntity)->getDesc());
}

bool NGfcSteelDetail::hasDesc()
{
    return ((GfcSteelDetail*)m_pEntity)->hasDesc();
}

void NGfcSteelDetail::setLevel(NGfcString sValue)
{
    ((GfcSteelDetail*)m_pEntity)->setLevel(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcSteelDetail::getLevel()
{
    return marshal_as<String^>(((GfcSteelDetail*)m_pEntity)->getLevel());
}

bool NGfcSteelDetail::hasLevel()
{
    return ((GfcSteelDetail*)m_pEntity)->hasLevel();
}

void NGfcSteelDetail::setDia(NGfcInteger nValue)
{
    ((GfcSteelDetail*)m_pEntity)->setDia(nValue);
}

NGfcInteger NGfcSteelDetail::getDia()
{
    return ((GfcSteelDetail*)m_pEntity)->getDia();
}

bool NGfcSteelDetail::hasDia()
{
    return ((GfcSteelDetail*)m_pEntity)->hasDia();
}

void NGfcSteelDetail::setNum(NGfcInteger nValue)
{
    ((GfcSteelDetail*)m_pEntity)->setNum(nValue);
}

NGfcInteger NGfcSteelDetail::getNum()
{
    return ((GfcSteelDetail*)m_pEntity)->getNum();
}

bool NGfcSteelDetail::hasNum()
{
    return ((GfcSteelDetail*)m_pEntity)->hasNum();
}

void NGfcSteelDetail::setBarLength(NGfcInteger nValue)
{
    ((GfcSteelDetail*)m_pEntity)->setBarLength(nValue);
}

NGfcInteger NGfcSteelDetail::getBarLength()
{
    return ((GfcSteelDetail*)m_pEntity)->getBarLength();
}

bool NGfcSteelDetail::hasBarLength()
{
    return ((GfcSteelDetail*)m_pEntity)->hasBarLength();
}

void NGfcSteelDetail::setSingleWeight(NGfcDouble dValue)
{
    ((GfcSteelDetail*)m_pEntity)->setSingleWeight(dValue);
}

NGfcDouble NGfcSteelDetail::getSingleWeight()
{
    return ((GfcSteelDetail*)m_pEntity)->getSingleWeight();
}

bool NGfcSteelDetail::hasSingleWeight()
{
    return ((GfcSteelDetail*)m_pEntity)->hasSingleWeight();
}

void NGfcSteelDetail::setTotalWeight(NGfcDouble dValue)
{
    ((GfcSteelDetail*)m_pEntity)->setTotalWeight(dValue);
}

NGfcDouble NGfcSteelDetail::getTotalWeight()
{
    return ((GfcSteelDetail*)m_pEntity)->getTotalWeight();
}

bool NGfcSteelDetail::hasTotalWeight()
{
    return ((GfcSteelDetail*)m_pEntity)->hasTotalWeight();
}

void NGfcSteelDetail::setTieinNum(NGfcInteger nValue)
{
    ((GfcSteelDetail*)m_pEntity)->setTieinNum(nValue);
}

NGfcInteger NGfcSteelDetail::getTieinNum()
{
    return ((GfcSteelDetail*)m_pEntity)->getTieinNum();
}

bool NGfcSteelDetail::hasTieinNum()
{
    return ((GfcSteelDetail*)m_pEntity)->hasTieinNum();
}

void NGfcSteelDetail::setTieinType(NGfcString sValue)
{
    ((GfcSteelDetail*)m_pEntity)->setTieinType(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcSteelDetail::getTieinType()
{
    return marshal_as<String^>(((GfcSteelDetail*)m_pEntity)->getTieinType());
}

bool NGfcSteelDetail::hasTieinType()
{
    return ((GfcSteelDetail*)m_pEntity)->hasTieinType();
}

