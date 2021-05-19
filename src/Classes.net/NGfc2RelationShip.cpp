#include "StdAfx.h"
#include "NGfc2RelationShip.h"
NGfc2RelationShip::NGfc2RelationShip()
{
    m_pEntity = new Gfc2RelationShip;
    m_bOwner = true;
}

NGfc2RelationShip::NGfc2RelationShip(void* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2RelationShip::setName(NGfc2Label sValue)
{
    ((Gfc2RelationShip*)m_pEntity)->setName(marshal_as<std::string>(sValue));
}

NGfc2Label NGfc2RelationShip::getName()
{
    return marshal_as<String^>(((Gfc2RelationShip*)m_pEntity)->getName());
}

bool NGfc2RelationShip::hasName()
{
    return ((Gfc2RelationShip*)m_pEntity)->hasName();
}

