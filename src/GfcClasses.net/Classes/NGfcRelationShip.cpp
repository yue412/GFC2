#include "NGfcRelationShip.h"

using namespace gfc::classes::x3;

NGfcRelationShip::NGfcRelationShip()
{
    m_pEntity = new GfcRelationShip;
    m_bOwner = true;
}

NGfcRelationShip::NGfcRelationShip(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

void NGfcRelationShip::setName(NGfcLabel sValue)
{
    ((GfcRelationShip*)m_pEntity)->setName(marshal_as<std::wstring>(sValue));
}

NGfcLabel NGfcRelationShip::getName()
{
    return marshal_as<String^>(((GfcRelationShip*)m_pEntity)->getName());
}

bool NGfcRelationShip::hasName()
{
    return ((GfcRelationShip*)m_pEntity)->hasName();
}

