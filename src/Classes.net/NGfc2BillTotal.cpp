#include "NGfc2BillTotal.h"

using namespace gfc::classes::x3;

NGfc2BillTotal::NGfc2BillTotal()
{
    m_pEntity = new Gfc2BillTotal;
    m_bOwner = true;
}

NGfc2BillTotal::NGfc2BillTotal(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2BillTotal::setCode(NGfc2String sValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setCode(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2BillTotal::getCode()
{
    return marshal_as<String^>(((Gfc2BillTotal*)m_pEntity)->getCode());
}

bool NGfc2BillTotal::hasCode()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasCode();
}

void NGfc2BillTotal::setName(NGfc2String sValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2BillTotal::getName()
{
    return marshal_as<String^>(((Gfc2BillTotal*)m_pEntity)->getName());
}

bool NGfc2BillTotal::hasName()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasName();
}

void NGfc2BillTotal::setAttr(NGfc2String sValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setAttr(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2BillTotal::getAttr()
{
    return marshal_as<String^>(((Gfc2BillTotal*)m_pEntity)->getAttr());
}

bool NGfc2BillTotal::hasAttr()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasAttr();
}

void NGfc2BillTotal::setQuantityType(NGfc2Integer nValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setQuantityType(nValue);
}

NGfc2Integer NGfc2BillTotal::getQuantityType()
{
    return ((Gfc2BillTotal*)m_pEntity)->getQuantityType();
}

bool NGfc2BillTotal::hasQuantityType()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasQuantityType();
}

void NGfc2BillTotal::setUnit(NGfc2String sValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setUnit(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2BillTotal::getUnit()
{
    return marshal_as<String^>(((Gfc2BillTotal*)m_pEntity)->getUnit());
}

bool NGfc2BillTotal::hasUnit()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasUnit();
}

void NGfc2BillTotal::setQuantity(NGfc2String sValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setQuantity(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2BillTotal::getQuantity()
{
    return marshal_as<String^>(((Gfc2BillTotal*)m_pEntity)->getQuantity());
}

bool NGfc2BillTotal::hasQuantity()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasQuantity();
}

void NGfc2BillTotal::setMemo(NGfc2String sValue)
{
    ((Gfc2BillTotal*)m_pEntity)->setMemo(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2BillTotal::getMemo()
{
    return marshal_as<String^>(((Gfc2BillTotal*)m_pEntity)->getMemo());
}

bool NGfc2BillTotal::hasMemo()
{
    return ((Gfc2BillTotal*)m_pEntity)->hasMemo();
}

