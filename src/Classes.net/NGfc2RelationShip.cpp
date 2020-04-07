#include "StdAfx.h"
#include "NGfc2RelationShip.h"
NGfc2RelationShip::NGfc2RelationShip()
{
    m_pEntity = new Gfc2RelationShip;
    m_bOwner = true;
}

NGfc2RelationShip::NGfc2RelationShip(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2RelationShip::setName(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelationShip*)m_pEntity)->setName(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelationShip::getName()
{
    return ((Gfc2RelationShip*)m_pEntity)->getName();
}

bool NGfc2RelationShip::hasName()
{
    return ((Gfc2RelationShip*)m_pEntity)->hasName();
}

NGfc2Label^ NGfc2RelationShip::getNamePtr()
{
    return gcnew NGfc2Label(((Gfc2RelationShip*)m_pEntity)->getNamePtr(), false);
}

