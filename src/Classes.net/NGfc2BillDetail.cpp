#include "StdAfx.h"
#include "NGfc2BillDetail.h"
NGfc2BillDetail::NGfc2BillDetail()
{
    m_pEntity = new Gfc2BillDetail;
    m_bOwner = true;
}

NGfc2BillDetail::NGfc2BillDetail(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2BillDetail::setFloorNum(NGfc2Integer nValue)
{
    ((Gfc2BillDetail*)m_pEntity)->setFloorNum(nValue);
}

NGfc2Integer NGfc2BillDetail::getFloorNum()
{
    return ((Gfc2BillDetail*)m_pEntity)->getFloorNum();
}

bool NGfc2BillDetail::hasFloorNum()
{
    return ((Gfc2BillDetail*)m_pEntity)->hasFloorNum();
}

void NGfc2BillDetail::setEntityID(NGfc2Integer nValue)
{
    ((Gfc2BillDetail*)m_pEntity)->setEntityID(nValue);
}

NGfc2Integer NGfc2BillDetail::getEntityID()
{
    return ((Gfc2BillDetail*)m_pEntity)->getEntityID();
}

bool NGfc2BillDetail::hasEntityID()
{
    return ((Gfc2BillDetail*)m_pEntity)->hasEntityID();
}

void NGfc2BillDetail::setUnit(NGfc2String sValue)
{
    ((Gfc2BillDetail*)m_pEntity)->setUnit(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2BillDetail::getUnit()
{
    return marshal_as<String^>(((Gfc2BillDetail*)m_pEntity)->getUnit());
}

bool NGfc2BillDetail::hasUnit()
{
    return ((Gfc2BillDetail*)m_pEntity)->hasUnit();
}

void NGfc2BillDetail::setExpress(NGfc2String sValue)
{
    ((Gfc2BillDetail*)m_pEntity)->setExpress(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2BillDetail::getExpress()
{
    return marshal_as<String^>(((Gfc2BillDetail*)m_pEntity)->getExpress());
}

bool NGfc2BillDetail::hasExpress()
{
    return ((Gfc2BillDetail*)m_pEntity)->hasExpress();
}

void NGfc2BillDetail::setQuantity(NGfc2String sValue)
{
    ((Gfc2BillDetail*)m_pEntity)->setQuantity(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2BillDetail::getQuantity()
{
    return marshal_as<String^>(((Gfc2BillDetail*)m_pEntity)->getQuantity());
}

bool NGfc2BillDetail::hasQuantity()
{
    return ((Gfc2BillDetail*)m_pEntity)->hasQuantity();
}

void NGfc2BillDetail::setMemo(NGfc2String sValue)
{
    ((Gfc2BillDetail*)m_pEntity)->setMemo(marshal_as<std::string>(sValue));
}

NGfc2String NGfc2BillDetail::getMemo()
{
    return marshal_as<String^>(((Gfc2BillDetail*)m_pEntity)->getMemo());
}

bool NGfc2BillDetail::hasMemo()
{
    return ((Gfc2BillDetail*)m_pEntity)->hasMemo();
}

