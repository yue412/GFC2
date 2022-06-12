#include "NGfcRelDefinesByType.h"

using namespace gfc::classes::x3;

NGfcRelDefinesByType::NGfcRelDefinesByType()
{
    m_pEntity = new GfcRelDefinesByType;
    m_bOwner = true;
}

NGfcRelDefinesByType::NGfcRelDefinesByType(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcRelDefines(pEntity, bOwner)
{
}

void NGfcRelDefinesByType::setRelatingType(gfc::engine::EntityRef nValue)
{
    ((GfcRelDefinesByType*)m_pEntity)->setRelatingType(nValue);
}

gfc::engine::EntityRef NGfcRelDefinesByType::getRelatingType()
{
    return ((GfcRelDefinesByType*)m_pEntity)->getRelatingType();
}

bool NGfcRelDefinesByType::hasRelatingType()
{
    return ((GfcRelDefinesByType*)m_pEntity)->hasRelatingType();
}

int NGfcRelDefinesByType::getRelatingElementCount()
{
    return ((GfcRelDefinesByType*)m_pEntity)->getRelatingElementCount();
}

void NGfcRelDefinesByType::clearRelatingElement()
{
    ((GfcRelDefinesByType*)m_pEntity)->clearRelatingElement();
}

void NGfcRelDefinesByType::addRelatingElement(gfc::engine::EntityRef nValue)
{
    ((GfcRelDefinesByType*)m_pEntity)->addRelatingElement(nValue);
}

gfc::engine::EntityRef NGfcRelDefinesByType::getRelatingElement(int nIndex)
{
    return ((GfcRelDefinesByType*)m_pEntity)->getRelatingElement(nIndex);
}

