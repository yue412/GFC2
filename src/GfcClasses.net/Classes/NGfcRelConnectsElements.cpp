#include "NGfcRelConnectsElements.h"

using namespace gfc::classes::x3;

NGfcRelConnectsElements::NGfcRelConnectsElements()
{
    m_pEntity = new GfcRelConnectsElements;
    m_bOwner = true;
}

NGfcRelConnectsElements::NGfcRelConnectsElements(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcRelConnects(pEntity, bOwner)
{
}

void NGfcRelConnectsElements::setRelatingElement(gfc::engine::EntityRef nValue)
{
    ((GfcRelConnectsElements*)m_pEntity)->setRelatingElement(nValue);
}

gfc::engine::EntityRef NGfcRelConnectsElements::getRelatingElement()
{
    return ((GfcRelConnectsElements*)m_pEntity)->getRelatingElement();
}

bool NGfcRelConnectsElements::hasRelatingElement()
{
    return ((GfcRelConnectsElements*)m_pEntity)->hasRelatingElement();
}

void NGfcRelConnectsElements::setRelatedElement(gfc::engine::EntityRef nValue)
{
    ((GfcRelConnectsElements*)m_pEntity)->setRelatedElement(nValue);
}

gfc::engine::EntityRef NGfcRelConnectsElements::getRelatedElement()
{
    return ((GfcRelConnectsElements*)m_pEntity)->getRelatedElement();
}

bool NGfcRelConnectsElements::hasRelatedElement()
{
    return ((GfcRelConnectsElements*)m_pEntity)->hasRelatedElement();
}

void NGfcRelConnectsElements::setConnectionGeometry(gfc::engine::EntityRef nValue)
{
    ((GfcRelConnectsElements*)m_pEntity)->setConnectionGeometry(nValue);
}

gfc::engine::EntityRef NGfcRelConnectsElements::getConnectionGeometry()
{
    return ((GfcRelConnectsElements*)m_pEntity)->getConnectionGeometry();
}

bool NGfcRelConnectsElements::hasConnectionGeometry()
{
    return ((GfcRelConnectsElements*)m_pEntity)->hasConnectionGeometry();
}

