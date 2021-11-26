#include "NGfc2QuotaTotal.h"

using namespace gfc::classes::x3;

NGfc2QuotaTotal::NGfc2QuotaTotal()
{
    m_pEntity = new Gfc2QuotaTotal;
    m_bOwner = true;
}

NGfc2QuotaTotal::NGfc2QuotaTotal(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2QuotaTotal::setCode(NGfc2String sValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setCode(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2QuotaTotal::getCode()
{
    return marshal_as<String^>(((Gfc2QuotaTotal*)m_pEntity)->getCode());
}

bool NGfc2QuotaTotal::hasCode()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasCode();
}

void NGfc2QuotaTotal::setSubCode(NGfc2String sValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setSubCode(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2QuotaTotal::getSubCode()
{
    return marshal_as<String^>(((Gfc2QuotaTotal*)m_pEntity)->getSubCode());
}

bool NGfc2QuotaTotal::hasSubCode()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasSubCode();
}

void NGfc2QuotaTotal::setName(NGfc2String sValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2QuotaTotal::getName()
{
    return marshal_as<String^>(((Gfc2QuotaTotal*)m_pEntity)->getName());
}

bool NGfc2QuotaTotal::hasName()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasName();
}

void NGfc2QuotaTotal::setContent(NGfc2String sValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setContent(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2QuotaTotal::getContent()
{
    return marshal_as<String^>(((Gfc2QuotaTotal*)m_pEntity)->getContent());
}

bool NGfc2QuotaTotal::hasContent()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasContent();
}

void NGfc2QuotaTotal::setUnit(NGfc2String sValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setUnit(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2QuotaTotal::getUnit()
{
    return marshal_as<String^>(((Gfc2QuotaTotal*)m_pEntity)->getUnit());
}

bool NGfc2QuotaTotal::hasUnit()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasUnit();
}

void NGfc2QuotaTotal::setQuantity(NGfc2String sValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setQuantity(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2QuotaTotal::getQuantity()
{
    return marshal_as<String^>(((Gfc2QuotaTotal*)m_pEntity)->getQuantity());
}

bool NGfc2QuotaTotal::hasQuantity()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasQuantity();
}

void NGfc2QuotaTotal::setMemo(NGfc2String sValue)
{
    ((Gfc2QuotaTotal*)m_pEntity)->setMemo(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2QuotaTotal::getMemo()
{
    return marshal_as<String^>(((Gfc2QuotaTotal*)m_pEntity)->getMemo());
}

bool NGfc2QuotaTotal::hasMemo()
{
    return ((Gfc2QuotaTotal*)m_pEntity)->hasMemo();
}

