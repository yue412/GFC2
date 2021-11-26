#include "NGfc2RelCoversBldgElements.h"

using namespace gfc::classes::x3;

NGfc2RelCoversBldgElements::NGfc2RelCoversBldgElements()
{
    m_pEntity = new Gfc2RelCoversBldgElements;
    m_bOwner = true;
}

NGfc2RelCoversBldgElements::NGfc2RelCoversBldgElements(void* pEntity, bool bOwner):
    NGfc2RelConnects(pEntity, bOwner)
{
}

void NGfc2RelCoversBldgElements::setRelatingBuildingElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelCoversBldgElements*)m_pEntity)->setRelatingBuildingElement(nValue);
}

gfc::engine::EntityRef NGfc2RelCoversBldgElements::getRelatingBuildingElement()
{
    return ((Gfc2RelCoversBldgElements*)m_pEntity)->getRelatingBuildingElement();
}

bool NGfc2RelCoversBldgElements::hasRelatingBuildingElement()
{
    return ((Gfc2RelCoversBldgElements*)m_pEntity)->hasRelatingBuildingElement();
}

int NGfc2RelCoversBldgElements::getRelatedCoveringsCount()
{
    return ((Gfc2RelCoversBldgElements*)m_pEntity)->getRelatedCoveringsCount();
}

void NGfc2RelCoversBldgElements::clearRelatedCoverings()
{
    ((Gfc2RelCoversBldgElements*)m_pEntity)->clearRelatedCoverings();
}

void NGfc2RelCoversBldgElements::addRelatedCoverings(gfc::engine::EntityRef nValue)
{
    ((Gfc2RelCoversBldgElements*)m_pEntity)->addRelatedCoverings(nValue);
}

gfc::engine::EntityRef NGfc2RelCoversBldgElements::getRelatedCoverings(int nIndex)
{
    return ((Gfc2RelCoversBldgElements*)m_pEntity)->getRelatedCoverings(nIndex);
}

