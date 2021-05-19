#include "StdAfx.h"
#include "NGfc2QuotaDetail.h"
NGfc2QuotaDetail::NGfc2QuotaDetail()
{
    m_pEntity = new Gfc2QuotaDetail;
    m_bOwner = true;
}

NGfc2QuotaDetail::NGfc2QuotaDetail(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2QuotaDetail::setFloorNum(NGfc2Integer nValue)
{
    ((Gfc2QuotaDetail*)m_pEntity)->setFloorNum(nValue);
}

NGfc2Integer NGfc2QuotaDetail::getFloorNum()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->getFloorNum();
}

bool NGfc2QuotaDetail::hasFloorNum()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->hasFloorNum();
}

void NGfc2QuotaDetail::setEntityID(NGfc2Integer nValue)
{
    ((Gfc2QuotaDetail*)m_pEntity)->setEntityID(nValue);
}

NGfc2Integer NGfc2QuotaDetail::getEntityID()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->getEntityID();
}

bool NGfc2QuotaDetail::hasEntityID()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->hasEntityID();
}

void NGfc2QuotaDetail::setUnit(NGfc2String sValue)
{
    ((Gfc2QuotaDetail*)m_pEntity)->setUnit(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2QuotaDetail::getUnit()
{
    return marshal_as<String^>(((Gfc2QuotaDetail*)m_pEntity)->getUnit());
}

bool NGfc2QuotaDetail::hasUnit()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->hasUnit();
}

void NGfc2QuotaDetail::setExpress(NGfc2String sValue)
{
    ((Gfc2QuotaDetail*)m_pEntity)->setExpress(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2QuotaDetail::getExpress()
{
    return marshal_as<String^>(((Gfc2QuotaDetail*)m_pEntity)->getExpress());
}

bool NGfc2QuotaDetail::hasExpress()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->hasExpress();
}

void NGfc2QuotaDetail::setQuantity(NGfc2String sValue)
{
    ((Gfc2QuotaDetail*)m_pEntity)->setQuantity(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2QuotaDetail::getQuantity()
{
    return marshal_as<String^>(((Gfc2QuotaDetail*)m_pEntity)->getQuantity());
}

bool NGfc2QuotaDetail::hasQuantity()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->hasQuantity();
}

void NGfc2QuotaDetail::setMemo(NGfc2String sValue)
{
    ((Gfc2QuotaDetail*)m_pEntity)->setMemo(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2QuotaDetail::getMemo()
{
    return marshal_as<String^>(((Gfc2QuotaDetail*)m_pEntity)->getMemo());
}

bool NGfc2QuotaDetail::hasMemo()
{
    return ((Gfc2QuotaDetail*)m_pEntity)->hasMemo();
}

