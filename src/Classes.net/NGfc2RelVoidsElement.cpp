#include "StdAfx.h"
#include "NGfc2RelVoidsElement.h"
NGfc2RelVoidsElement::NGfc2RelVoidsElement()
{
    m_pEntity = new Gfc2RelVoidsElement;
    m_bOwner = true;
}

NGfc2RelVoidsElement::NGfc2RelVoidsElement(void* pEntity, bool bOwner):
    NGfc2RelDecomposes(pEntity, bOwner)
{
}

void NGfc2RelVoidsElement::setRelatedOpeningElement(gfc2::engine::EntityRef nValue)
{
    ((Gfc2RelVoidsElement*)m_pEntity)->setRelatedOpeningElement(nValue);
}

gfc2::engine::EntityRef NGfc2RelVoidsElement::getRelatedOpeningElement()
{
    return ((Gfc2RelVoidsElement*)m_pEntity)->getRelatedOpeningElement();
}

bool NGfc2RelVoidsElement::hasRelatedOpeningElement()
{
    return ((Gfc2RelVoidsElement*)m_pEntity)->hasRelatedOpeningElement();
}

NGfc2Element^ NGfc2RelVoidsElement::getRelatedOpeningElementPtr()
{
    return gcnew NGfc2Element(((Gfc2RelVoidsElement*)m_pEntity)->getRelatedOpeningElementPtr(), false);
}

int NGfc2RelVoidsElement::getRelatingBuildingElementCount()
{
    return ((Gfc2RelVoidsElement*)m_pEntity)->getRelatingBuildingElementCount();
}

void NGfc2RelVoidsElement::clearRelatingBuildingElement()
{
    ((Gfc2RelVoidsElement*)m_pEntity)->clearRelatingBuildingElement();
}

void NGfc2RelVoidsElement::addRelatingBuildingElement(gfc2::engine::EntityRef nValue)
{
    ((Gfc2RelVoidsElement*)m_pEntity)->addRelatingBuildingElement(nValue);
}

gfc2::engine::EntityRef NGfc2RelVoidsElement::getRelatingBuildingElement(int nIndex)
{
    return ((Gfc2RelVoidsElement*)m_pEntity)->getRelatingBuildingElement(nIndex);
}

NGfc2Element^ NGfc2RelVoidsElement::getRelatingBuildingElementPtr(int nIndex)
{
    return gcnew NGfc2Element(((Gfc2RelVoidsElement*)m_pEntity)->getRelatingBuildingElementPtr(nIndex), false);
}

