#include "NGfcQuotaDetail.h"

using namespace gfc::classes::x3;

NGfcQuotaDetail::NGfcQuotaDetail()
{
    m_pEntity = new GfcQuotaDetail;
    m_bOwner = true;
}

NGfcQuotaDetail::NGfcQuotaDetail(bool bNoCreate):
    NGfcRoot(bNoCreate)
{
}

void NGfcQuotaDetail::setFloorNum(NGfcInteger nValue)
{
    ((GfcQuotaDetail*)m_pEntity)->setFloorNum(nValue);
}

NGfcInteger NGfcQuotaDetail::getFloorNum()
{
    return ((GfcQuotaDetail*)m_pEntity)->getFloorNum();
}

bool NGfcQuotaDetail::hasFloorNum()
{
    return ((GfcQuotaDetail*)m_pEntity)->hasFloorNum();
}

void NGfcQuotaDetail::setEntityID(NGfcInteger nValue)
{
    ((GfcQuotaDetail*)m_pEntity)->setEntityID(nValue);
}

NGfcInteger NGfcQuotaDetail::getEntityID()
{
    return ((GfcQuotaDetail*)m_pEntity)->getEntityID();
}

bool NGfcQuotaDetail::hasEntityID()
{
    return ((GfcQuotaDetail*)m_pEntity)->hasEntityID();
}

void NGfcQuotaDetail::setUnit(NGfcString sValue)
{
    ((GfcQuotaDetail*)m_pEntity)->setUnit(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcQuotaDetail::getUnit()
{
    return marshal_as<String^>(((GfcQuotaDetail*)m_pEntity)->getUnit());
}

bool NGfcQuotaDetail::hasUnit()
{
    return ((GfcQuotaDetail*)m_pEntity)->hasUnit();
}

void NGfcQuotaDetail::setExpress(NGfcString sValue)
{
    ((GfcQuotaDetail*)m_pEntity)->setExpress(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcQuotaDetail::getExpress()
{
    return marshal_as<String^>(((GfcQuotaDetail*)m_pEntity)->getExpress());
}

bool NGfcQuotaDetail::hasExpress()
{
    return ((GfcQuotaDetail*)m_pEntity)->hasExpress();
}

void NGfcQuotaDetail::setQuantity(NGfcString sValue)
{
    ((GfcQuotaDetail*)m_pEntity)->setQuantity(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcQuotaDetail::getQuantity()
{
    return marshal_as<String^>(((GfcQuotaDetail*)m_pEntity)->getQuantity());
}

bool NGfcQuotaDetail::hasQuantity()
{
    return ((GfcQuotaDetail*)m_pEntity)->hasQuantity();
}

void NGfcQuotaDetail::setMemo(NGfcString sValue)
{
    ((GfcQuotaDetail*)m_pEntity)->setMemo(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcQuotaDetail::getMemo()
{
    return marshal_as<String^>(((GfcQuotaDetail*)m_pEntity)->getMemo());
}

bool NGfcQuotaDetail::hasMemo()
{
    return ((GfcQuotaDetail*)m_pEntity)->hasMemo();
}

