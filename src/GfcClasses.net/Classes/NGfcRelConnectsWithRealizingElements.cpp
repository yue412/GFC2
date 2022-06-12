#include "NGfcRelConnectsWithRealizingElements.h"

using namespace gfc::classes::x3;

NGfcRelConnectsWithRealizingElements::NGfcRelConnectsWithRealizingElements()
{
    m_pEntity = new GfcRelConnectsWithRealizingElements;
    m_bOwner = true;
}

NGfcRelConnectsWithRealizingElements::NGfcRelConnectsWithRealizingElements(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcRelConnectsElements(pEntity, bOwner)
{
}

void NGfcRelConnectsWithRealizingElements::setRealizingElements(gfc::engine::EntityRef nValue)
{
    ((GfcRelConnectsWithRealizingElements*)m_pEntity)->setRealizingElements(nValue);
}

gfc::engine::EntityRef NGfcRelConnectsWithRealizingElements::getRealizingElements()
{
    return ((GfcRelConnectsWithRealizingElements*)m_pEntity)->getRealizingElements();
}

bool NGfcRelConnectsWithRealizingElements::hasRealizingElements()
{
    return ((GfcRelConnectsWithRealizingElements*)m_pEntity)->hasRealizingElements();
}

