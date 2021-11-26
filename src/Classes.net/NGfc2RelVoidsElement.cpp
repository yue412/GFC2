#include "NGfc2RelVoidsElement.h"

using namespace gfc::classes::x3;

NGfc2RelVoidsElement::NGfc2RelVoidsElement()
{
    m_pEntity = new Gfc2RelVoidsElement;
    m_bOwner = true;
}

NGfc2RelVoidsElement::NGfc2RelVoidsElement(void* pEntity, bool bOwner):
    NGfc2RelDecomposes(pEntity, bOwner)
{
}

void NGfc2RelVoidsElement::setRelatedOpeningElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelVoidsElement*)m_pEntity)->setRelatedOpeningElement(nValue);
}

gfc::engine::EntityRef NGfc2RelVoidsElement::getRelatedOpeningElement()
{
    return ((Gfc2RelVoidsElement*)m_pEntity)->getRelatedOpeningElement();
}

bool NGfc2RelVoidsElement::hasRelatedOpeningElement()
{
    return ((Gfc2RelVoidsElement*)m_pEntity)->hasRelatedOpeningElement();
}

int NGfc2RelVoidsElement::getRelatingBuildingElementCount()
{
    return ((Gfc2RelVoidsElement*)m_pEntity)->getRelatingBuildingElementCount();
}

void NGfc2RelVoidsElement::clearRelatingBuildingElement()
{
    ((Gfc2RelVoidsElement*)m_pEntity)->clearRelatingBuildingElement();
}

void NGfc2RelVoidsElement::addRelatingBuildingElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelVoidsElement*)m_pEntity)->addRelatingBuildingElement(nValue);
}

gfc::engine::EntityRef NGfc2RelVoidsElement::getRelatingBuildingElement(int nIndex)
{
    return ((Gfc2RelVoidsElement*)m_pEntity)->getRelatingBuildingElement(nIndex);
}

