#include "NGfc2RelConnectsElements.h"

using namespace gfc::classes::x3;

NGfc2RelConnectsElements::NGfc2RelConnectsElements()
{
    m_pEntity = new Gfc2RelConnectsElements;
    m_bOwner = true;
}

NGfc2RelConnectsElements::NGfc2RelConnectsElements(void* pEntity, bool bOwner):
    NGfc2RelConnects(pEntity, bOwner)
{
}

void NGfc2RelConnectsElements::setRelatingElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelConnectsElements*)m_pEntity)->setRelatingElement(nValue);
}

gfc::engine::EntityRef NGfc2RelConnectsElements::getRelatingElement()
{
    return ((Gfc2RelConnectsElements*)m_pEntity)->getRelatingElement();
}

bool NGfc2RelConnectsElements::hasRelatingElement()
{
    return ((Gfc2RelConnectsElements*)m_pEntity)->hasRelatingElement();
}

void NGfc2RelConnectsElements::setRelatedElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelConnectsElements*)m_pEntity)->setRelatedElement(nValue);
}

gfc::engine::EntityRef NGfc2RelConnectsElements::getRelatedElement()
{
    return ((Gfc2RelConnectsElements*)m_pEntity)->getRelatedElement();
}

bool NGfc2RelConnectsElements::hasRelatedElement()
{
    return ((Gfc2RelConnectsElements*)m_pEntity)->hasRelatedElement();
}

void NGfc2RelConnectsElements::setConnectionGeometry(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelConnectsElements*)m_pEntity)->setConnectionGeometry(nValue);
}

gfc::engine::EntityRef NGfc2RelConnectsElements::getConnectionGeometry()
{
    return ((Gfc2RelConnectsElements*)m_pEntity)->getConnectionGeometry();
}

bool NGfc2RelConnectsElements::hasConnectionGeometry()
{
    return ((Gfc2RelConnectsElements*)m_pEntity)->hasConnectionGeometry();
}

