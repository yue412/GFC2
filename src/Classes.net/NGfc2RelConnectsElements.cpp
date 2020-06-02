#include "StdAfx.h"
#include "NGfc2RelConnectsElements.h"
NGfc2RelConnectsElements::NGfc2RelConnectsElements()
{
    m_pEntity = new Gfc2RelConnectsElements;
    m_bOwner = true;
}

NGfc2RelConnectsElements::NGfc2RelConnectsElements(void* pEntity, bool bOwner):
    NGfc2RelConnects(pEntity, bOwner)
{
}

void NGfc2RelConnectsElements::setRelatingElement(gfc2::engine::EntityRef nValue)
{
    ((Gfc2RelConnectsElements*)m_pEntity)->setRelatingElement(nValue);
}

gfc2::engine::EntityRef NGfc2RelConnectsElements::getRelatingElement()
{
    return ((Gfc2RelConnectsElements*)m_pEntity)->getRelatingElement();
}

bool NGfc2RelConnectsElements::hasRelatingElement()
{
    return ((Gfc2RelConnectsElements*)m_pEntity)->hasRelatingElement();
}

NGfc2Element^ NGfc2RelConnectsElements::getRelatingElementPtr()
{
    return gcnew NGfc2Element(((Gfc2RelConnectsElements*)m_pEntity)->getRelatingElementPtr(), false);
}

void NGfc2RelConnectsElements::setRelatedElement(gfc2::engine::EntityRef nValue)
{
    ((Gfc2RelConnectsElements*)m_pEntity)->setRelatedElement(nValue);
}

gfc2::engine::EntityRef NGfc2RelConnectsElements::getRelatedElement()
{
    return ((Gfc2RelConnectsElements*)m_pEntity)->getRelatedElement();
}

bool NGfc2RelConnectsElements::hasRelatedElement()
{
    return ((Gfc2RelConnectsElements*)m_pEntity)->hasRelatedElement();
}

NGfc2Element^ NGfc2RelConnectsElements::getRelatedElementPtr()
{
    return gcnew NGfc2Element(((Gfc2RelConnectsElements*)m_pEntity)->getRelatedElementPtr(), false);
}

void NGfc2RelConnectsElements::setConnectionGeometry(gfc2::engine::EntityRef nValue)
{
    ((Gfc2RelConnectsElements*)m_pEntity)->setConnectionGeometry(nValue);
}

gfc2::engine::EntityRef NGfc2RelConnectsElements::getConnectionGeometry()
{
    return ((Gfc2RelConnectsElements*)m_pEntity)->getConnectionGeometry();
}

bool NGfc2RelConnectsElements::hasConnectionGeometry()
{
    return ((Gfc2RelConnectsElements*)m_pEntity)->hasConnectionGeometry();
}

NGfc2ConnectionGeometry^ NGfc2RelConnectsElements::getConnectionGeometryPtr()
{
    return gcnew NGfc2ConnectionGeometry(((Gfc2RelConnectsElements*)m_pEntity)->getConnectionGeometryPtr(), false);
}

