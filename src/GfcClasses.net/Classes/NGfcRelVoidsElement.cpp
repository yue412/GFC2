#include "NGfcRelVoidsElement.h"

using namespace gfc::classes::x3;

NGfcRelVoidsElement::NGfcRelVoidsElement()
{
    m_pEntity = new GfcRelVoidsElement;
    m_bOwner = true;
}

NGfcRelVoidsElement::NGfcRelVoidsElement(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcRelDecomposes(pEntity, bOwner)
{
}

void NGfcRelVoidsElement::setRelatedOpeningElement(gfc::engine::EntityRef nValue)
{
    ((GfcRelVoidsElement*)m_pEntity)->setRelatedOpeningElement(nValue);
}

gfc::engine::EntityRef NGfcRelVoidsElement::getRelatedOpeningElement()
{
    return ((GfcRelVoidsElement*)m_pEntity)->getRelatedOpeningElement();
}

bool NGfcRelVoidsElement::hasRelatedOpeningElement()
{
    return ((GfcRelVoidsElement*)m_pEntity)->hasRelatedOpeningElement();
}

int NGfcRelVoidsElement::getRelatingBuildingElementCount()
{
    return ((GfcRelVoidsElement*)m_pEntity)->getRelatingBuildingElementCount();
}

void NGfcRelVoidsElement::clearRelatingBuildingElement()
{
    ((GfcRelVoidsElement*)m_pEntity)->clearRelatingBuildingElement();
}

void NGfcRelVoidsElement::addRelatingBuildingElement(gfc::engine::EntityRef nValue)
{
    ((GfcRelVoidsElement*)m_pEntity)->addRelatingBuildingElement(nValue);
}

gfc::engine::EntityRef NGfcRelVoidsElement::getRelatingBuildingElement(int nIndex)
{
    return ((GfcRelVoidsElement*)m_pEntity)->getRelatingBuildingElement(nIndex);
}

