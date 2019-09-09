#include "StdAfx.h"
#include "NGfc2RelDefinesByProperties.h"
NGfc2RelDefinesByProperties::NGfc2RelDefinesByProperties()
{
    m_pEntity = new Gfc2RelDefinesByProperties;
    m_bOwner = true;
}

NGfc2RelDefinesByProperties::NGfc2RelDefinesByProperties(void* pEntity, bool bOwner):
    NGfc2RelDefines(pEntity, bOwner)
{
}

void NGfc2RelDefinesByProperties::setRelatingPropertySet(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelDefinesByProperties*)m_pEntity)->setRelatingPropertySet(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelDefinesByProperties::getRelatingPropertySet()
{
    return ((Gfc2RelDefinesByProperties*)m_pEntity)->getRelatingPropertySet();
}

bool NGfc2RelDefinesByProperties::hasRelatingPropertySet()
{
    return ((Gfc2RelDefinesByProperties*)m_pEntity)->hasRelatingPropertySet();
}

NGfc2PropertySet^ NGfc2RelDefinesByProperties::getRelatingPropertySetPtr()
{
    return gcnew NGfc2PropertySet(((Gfc2RelDefinesByProperties*)m_pEntity)->getRelatingPropertySetPtr(), false);
}

