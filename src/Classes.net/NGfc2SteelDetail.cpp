#include "StdAfx.h"
#include "NGfc2SteelDetail.h"
NGfc2SteelDetail::NGfc2SteelDetail()
{
    m_pEntity = new Gfc2SteelDetail;
    m_bOwner = true;
}

NGfc2SteelDetail::NGfc2SteelDetail(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
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

void NGfc2SteelDetail::setName(gfc2::engine::EntityRef nValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setName(nValue);
}

gfc2::engine::EntityRef NGfc2SteelDetail::getName()
{
    return ((Gfc2SteelDetail*)m_pEntity)->getName();
}

bool NGfc2SteelDetail::hasName()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasName();
}

NGfc2String^ NGfc2SteelDetail::getNamePtr()
{
    return gcnew NGfc2String(((Gfc2SteelDetail*)m_pEntity)->getNamePtr(), false);
}

void NGfc2SteelDetail::setDesc(gfc2::engine::EntityRef nValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setDesc(nValue);
}

gfc2::engine::EntityRef NGfc2SteelDetail::getDesc()
{
    return ((Gfc2SteelDetail*)m_pEntity)->getDesc();
}

bool NGfc2SteelDetail::hasDesc()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasDesc();
}

NGfc2String^ NGfc2SteelDetail::getDescPtr()
{
    return gcnew NGfc2String(((Gfc2SteelDetail*)m_pEntity)->getDescPtr(), false);
}

void NGfc2SteelDetail::setLevel(gfc2::engine::EntityRef nValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setLevel(nValue);
}

gfc2::engine::EntityRef NGfc2SteelDetail::getLevel()
{
    return ((Gfc2SteelDetail*)m_pEntity)->getLevel();
}

bool NGfc2SteelDetail::hasLevel()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasLevel();
}

NGfc2String^ NGfc2SteelDetail::getLevelPtr()
{
    return gcnew NGfc2String(((Gfc2SteelDetail*)m_pEntity)->getLevelPtr(), false);
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

void NGfc2SteelDetail::setLength(NGfc2Integer nValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setLength(nValue);
}

NGfc2Integer NGfc2SteelDetail::getLength()
{
    return ((Gfc2SteelDetail*)m_pEntity)->getLength();
}

bool NGfc2SteelDetail::hasLength()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasLength();
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

void NGfc2SteelDetail::setTieinType(gfc2::engine::EntityRef nValue)
{
    ((Gfc2SteelDetail*)m_pEntity)->setTieinType(nValue);
}

gfc2::engine::EntityRef NGfc2SteelDetail::getTieinType()
{
    return ((Gfc2SteelDetail*)m_pEntity)->getTieinType();
}

bool NGfc2SteelDetail::hasTieinType()
{
    return ((Gfc2SteelDetail*)m_pEntity)->hasTieinType();
}

NGfc2String^ NGfc2SteelDetail::getTieinTypePtr()
{
    return gcnew NGfc2String(((Gfc2SteelDetail*)m_pEntity)->getTieinTypePtr(), false);
}

