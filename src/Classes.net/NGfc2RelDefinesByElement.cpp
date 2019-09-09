#include "StdAfx.h"
#include "NGfc2RelDefinesByElement.h"
NGfc2RelDefinesByElement::NGfc2RelDefinesByElement()
{
    m_pEntity = new Gfc2RelDefinesByElement;
    m_bOwner = true;
}

NGfc2RelDefinesByElement::NGfc2RelDefinesByElement(void* pEntity, bool bOwner):
    NGfc2RelDefines(pEntity, bOwner)
{
}

void NGfc2RelDefinesByElement::setRelatingElement(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelDefinesByElement*)m_pEntity)->setRelatingElement(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelDefinesByElement::getRelatingElement()
{
    return ((Gfc2RelDefinesByElement*)m_pEntity)->getRelatingElement();
}

bool NGfc2RelDefinesByElement::hasRelatingElement()
{
    return ((Gfc2RelDefinesByElement*)m_pEntity)->hasRelatingElement();
}

NGfc2Entity^ NGfc2RelDefinesByElement::getRelatingElementPtr()
{
    return gcnew NGfc2Entity(((Gfc2RelDefinesByElement*)m_pEntity)->getRelatingElementPtr(), false);
}

