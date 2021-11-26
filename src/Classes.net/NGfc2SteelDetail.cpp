#include "NGfc2SteelDetail.h"

using namespace gfc::classes::x3;

NGfc2SteelDetail::NGfc2SteelDetail()
{
    m_pEntity = new Gfc2SteelDetail;
    m_bOwner = true;
}

NGfc2SteelDetail::NGfc2SteelDetail(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2SteelDetail::setEntityID(NGfc2Integer nValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setEntityID(nValue);
}

NGfc2Integer NGfc2SteelDetail::getEntityID()
{
    return ((Gfc2SteelDetail*)m_pEntity)->getEntityID();
}

bool NGfc2SteelDetail::hasEntityID()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasEntityID();
}

void NGfc2SteelDetail::setName(NGfc2String sValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2SteelDetail::getName()
{
    return marshal_as<String^>(((Gfc2SteelDetail*)m_pEntity)->getName());
}

bool NGfc2SteelDetail::hasName()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasName();
}

void NGfc2SteelDetail::setDesc(NGfc2String sValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setDesc(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2SteelDetail::getDesc()
{
    return marshal_as<String^>(((Gfc2SteelDetail*)m_pEntity)->getDesc());
}

bool NGfc2SteelDetail::hasDesc()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasDesc();
}

void NGfc2SteelDetail::setLevel(NGfc2String sValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setLevel(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2SteelDetail::getLevel()
{
    return marshal_as<String^>(((Gfc2SteelDetail*)m_pEntity)->getLevel());
}

bool NGfc2SteelDetail::hasLevel()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasLevel();
}

void NGfc2SteelDetail::setDia(NGfc2Integer nValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setDia(nValue);
}

NGfc2Integer NGfc2SteelDetail::getDia()
{
    return ((Gfc2SteelDetail*)m_pEntity)->getDia();
}

bool NGfc2SteelDetail::hasDia()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasDia();
}

void NGfc2SteelDetail::setNum(NGfc2Integer nValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setNum(nValue);
}

NGfc2Integer NGfc2SteelDetail::getNum()
{
    return ((Gfc2SteelDetail*)m_pEntity)->getNum();
}

bool NGfc2SteelDetail::hasNum()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasNum();
}

void NGfc2SteelDetail::setBarLength(NGfc2Integer nValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setBarLength(nValue);
}

NGfc2Integer NGfc2SteelDetail::getBarLength()
{
    return ((Gfc2SteelDetail*)m_pEntity)->getBarLength();
}

bool NGfc2SteelDetail::hasBarLength()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasBarLength();
}

void NGfc2SteelDetail::setSingleWeight(NGfc2Double dValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setSingleWeight(dValue);
}

NGfc2Double NGfc2SteelDetail::getSingleWeight()
{
    return ((Gfc2SteelDetail*)m_pEntity)->getSingleWeight();
}

bool NGfc2SteelDetail::hasSingleWeight()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasSingleWeight();
}

void NGfc2SteelDetail::setTotalWeight(NGfc2Double dValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setTotalWeight(dValue);
}

NGfc2Double NGfc2SteelDetail::getTotalWeight()
{
    return ((Gfc2SteelDetail*)m_pEntity)->getTotalWeight();
}

bool NGfc2SteelDetail::hasTotalWeight()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasTotalWeight();
}

void NGfc2SteelDetail::setTieinNum(NGfc2Integer nValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setTieinNum(nValue);
}

NGfc2Integer NGfc2SteelDetail::getTieinNum()
{
    return ((Gfc2SteelDetail*)m_pEntity)->getTieinNum();
}

bool NGfc2SteelDetail::hasTieinNum()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasTieinNum();
}

void NGfc2SteelDetail::setTieinType(NGfc2String sValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setTieinType(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2SteelDetail::getTieinType()
{
    return marshal_as<String^>(((Gfc2SteelDetail*)m_pEntity)->getTieinType());
}

bool NGfc2SteelDetail::hasTieinType()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasTieinType();
}

