#include "NGfc2RelDefinesByType.h"

using namespace gfc::classes::x3;

NGfc2RelDefinesByType::NGfc2RelDefinesByType()
{
    m_pEntity = new Gfc2RelDefinesByType;
    m_bOwner = true;
}

NGfc2RelDefinesByType::NGfc2RelDefinesByType(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2RelDefines(pEntity, bOwner)
{
}

void NGfc2RelDefinesByType::setRelatingType(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelDefinesByType*)m_pEntity)->setRelatingType(nValue);
}

gfc::engine::EntityRef NGfc2RelDefinesByType::getRelatingType()
{
    return ((Gfc2RelDefinesByType*)m_pEntity)->getRelatingType();
}

bool NGfc2RelDefinesByType::hasRelatingType()
{
    return ((Gfc2RelDefinesByType*)m_pEntity)->hasRelatingType();
}

int NGfc2RelDefinesByType::getRelatingElementCount()
{
    return ((Gfc2RelDefinesByType*)m_pEntity)->getRelatingElementCount();
}

void NGfc2RelDefinesByType::clearRelatingElement()
{
    ((Gfc2RelDefinesByType*)m_pEntity)->clearRelatingElement();
}

void NGfc2RelDefinesByType::addRelatingElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelDefinesByType*)m_pEntity)->addRelatingElement(nValue);
}

gfc::engine::EntityRef NGfc2RelDefinesByType::getRelatingElement(int nIndex)
{
    return ((Gfc2RelDefinesByType*)m_pEntity)->getRelatingElement(nIndex);
}

