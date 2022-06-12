#include "NGfcBillDetail.h"

using namespace gfc::classes::x3;

NGfcBillDetail::NGfcBillDetail()
{
    m_pEntity = new GfcBillDetail;
    m_bOwner = true;
}

NGfcBillDetail::NGfcBillDetail(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

void NGfcBillDetail::setFloorNum(NGfcInteger nValue)
{
    ((GfcBillDetail*)m_pEntity)->setFloorNum(nValue);
}

NGfcInteger NGfcBillDetail::getFloorNum()
{
    return ((GfcBillDetail*)m_pEntity)->getFloorNum();
}

bool NGfcBillDetail::hasFloorNum()
{
    return ((GfcBillDetail*)m_pEntity)->hasFloorNum();
}

void NGfcBillDetail::setEntityID(NGfcInteger nValue)
{
    ((GfcBillDetail*)m_pEntity)->setEntityID(nValue);
}

NGfcInteger NGfcBillDetail::getEntityID()
{
    return ((GfcBillDetail*)m_pEntity)->getEntityID();
}

bool NGfcBillDetail::hasEntityID()
{
    return ((GfcBillDetail*)m_pEntity)->hasEntityID();
}

void NGfcBillDetail::setUnit(NGfcString sValue)
{
    ((GfcBillDetail*)m_pEntity)->setUnit(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcBillDetail::getUnit()
{
    return marshal_as<String^>(((GfcBillDetail*)m_pEntity)->getUnit());
}

bool NGfcBillDetail::hasUnit()
{
    return ((GfcBillDetail*)m_pEntity)->hasUnit();
}

void NGfcBillDetail::setExpress(NGfcString sValue)
{
    ((GfcBillDetail*)m_pEntity)->setExpress(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcBillDetail::getExpress()
{
    return marshal_as<String^>(((GfcBillDetail*)m_pEntity)->getExpress());
}

bool NGfcBillDetail::hasExpress()
{
    return ((GfcBillDetail*)m_pEntity)->hasExpress();
}

void NGfcBillDetail::setQuantity(NGfcString sValue)
{
    ((GfcBillDetail*)m_pEntity)->setQuantity(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcBillDetail::getQuantity()
{
    return marshal_as<String^>(((GfcBillDetail*)m_pEntity)->getQuantity());
}

bool NGfcBillDetail::hasQuantity()
{
    return ((GfcBillDetail*)m_pEntity)->hasQuantity();
}

void NGfcBillDetail::setMemo(NGfcString sValue)
{
    ((GfcBillDetail*)m_pEntity)->setMemo(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcBillDetail::getMemo()
{
    return marshal_as<String^>(((GfcBillDetail*)m_pEntity)->getMemo());
}

bool NGfcBillDetail::hasMemo()
{
    return ((GfcBillDetail*)m_pEntity)->hasMemo();
}

