#include "StdAfx.h"
#include "NGfc2RelConnectsWithRealizingElements.h"
NGfc2RelConnectsWithRealizingElements::NGfc2RelConnectsWithRealizingElements()
{
    m_pEntity = new Gfc2RelConnectsWithRealizingElements;
    m_bOwner = true;
}

NGfc2RelConnectsWithRealizingElements::NGfc2RelConnectsWithRealizingElements(void* pEntity, bool bOwner):
    NGfc2RelConnectsElements(pEntity, bOwner)
{
}

void NGfc2RelConnectsWithRealizingElements::setRealizingElements(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelConnectsWithRealizingElements*)m_pEntity)->setRealizingElements(nValue);
}

gfc::engine::EntityRef NGfc2RelConnectsWithRealizingElements::getRealizingElements()
{
    return ((Gfc2RelConnectsWithRealizingElements*)m_pEntity)->getRealizingElements();
}

bool NGfc2RelConnectsWithRealizingElements::hasRealizingElements()
{
    return ((Gfc2RelConnectsWithRealizingElements*)m_pEntity)->hasRealizingElements();
}

NGfc2Element^ NGfc2RelConnectsWithRealizingElements::getRealizingElementsPtr()
{
    return gcnew NGfc2Element(((Gfc2RelConnectsWithRealizingElements*)m_pEntity)->getRealizingElementsPtr(), false);
}

