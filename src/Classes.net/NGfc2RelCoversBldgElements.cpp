#include "StdAfx.h"
#include "NGfc2RelCoversBldgElements.h"
NGfc2RelCoversBldgElements::NGfc2RelCoversBldgElements()
{
    m_pEntity = new Gfc2RelCoversBldgElements;
    m_bOwner = true;
}

NGfc2RelCoversBldgElements::NGfc2RelCoversBldgElements(void* pEntity, bool bOwner):
    NGfc2RelConnects(pEntity, bOwner)
{
}

void NGfc2RelCoversBldgElements::setRelatingBuildingElement(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelCoversBldgElements*)m_pEntity)->setRelatingBuildingElement(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelCoversBldgElements::getRelatingBuildingElement()
{
    return ((Gfc2RelCoversBldgElements*)m_pEntity)->getRelatingBuildingElement();
}

bool NGfc2RelCoversBldgElements::hasRelatingBuildingElement()
{
    return ((Gfc2RelCoversBldgElements*)m_pEntity)->hasRelatingBuildingElement();
}

NGfc2Element^ NGfc2RelCoversBldgElements::getRelatingBuildingElementPtr()
{
    return gcnew NGfc2Element(((Gfc2RelCoversBldgElements*)m_pEntity)->getRelatingBuildingElementPtr(), false);
}

int NGfc2RelCoversBldgElements::getRelatedCoveringsCount()
{
    return ((Gfc2RelCoversBldgElements*)m_pEntity)->getRelatedCoveringsCount();
}

void NGfc2RelCoversBldgElements::clearRelatedCoverings()
{
    ((Gfc2RelCoversBldgElements*)m_pEntity)->clearRelatedCoverings();
}

void NGfc2RelCoversBldgElements::addRelatedCoverings(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelCoversBldgElements*)m_pEntity)->addRelatedCoverings(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelCoversBldgElements::getRelatedCoverings(int nIndex)
{
    return ((Gfc2RelCoversBldgElements*)m_pEntity)->getRelatedCoverings(nIndex);
}

NGfc2Element^ NGfc2RelCoversBldgElements::getRelatedCoveringsPtr(int nIndex)
{
    return gcnew NGfc2Element(((Gfc2RelCoversBldgElements*)m_pEntity)->getRelatedCoveringsPtr(nIndex), false);
}

