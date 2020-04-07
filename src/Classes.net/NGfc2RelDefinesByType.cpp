#include "StdAfx.h"
#include "NGfc2RelDefinesByType.h"
NGfc2RelDefinesByType::NGfc2RelDefinesByType()
{
    m_pEntity = new Gfc2RelDefinesByType;
    m_bOwner = true;
}

NGfc2RelDefinesByType::NGfc2RelDefinesByType(void* pEntity, bool bOwner):
    NGfc2RelDefines(pEntity, bOwner)
{
}

void NGfc2RelDefinesByType::setRelatingType(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelDefinesByType*)m_pEntity)->setRelatingType(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelDefinesByType::getRelatingType()
{
    return ((Gfc2RelDefinesByType*)m_pEntity)->getRelatingType();
}

bool NGfc2RelDefinesByType::hasRelatingType()
{
    return ((Gfc2RelDefinesByType*)m_pEntity)->hasRelatingType();
}

NGfc2ElementType^ NGfc2RelDefinesByType::getRelatingTypePtr()
{
    return gcnew NGfc2ElementType(((Gfc2RelDefinesByType*)m_pEntity)->getRelatingTypePtr(), false);
}

int NGfc2RelDefinesByType::getRelatingElementCount()
{
    return ((Gfc2RelDefinesByType*)m_pEntity)->getRelatingElementCount();
}

void NGfc2RelDefinesByType::clearRelatingElement()
{
    ((Gfc2RelDefinesByType*)m_pEntity)->clearRelatingElement();
}

void NGfc2RelDefinesByType::addRelatingElement(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelDefinesByType*)m_pEntity)->addRelatingElement(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelDefinesByType::getRelatingElement(int nIndex)
{
    return ((Gfc2RelDefinesByType*)m_pEntity)->getRelatingElement(nIndex);
}

NGfc2Element^ NGfc2RelDefinesByType::getRelatingElementPtr(int nIndex)
{
    return gcnew NGfc2Element(((Gfc2RelDefinesByType*)m_pEntity)->getRelatingElementPtr(nIndex), false);
}

