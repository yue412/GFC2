#include "NGfcRelCoversBldgElements.h"

using namespace gfc::classes::x3;

NGfcRelCoversBldgElements::NGfcRelCoversBldgElements()
{
    m_pEntity = new GfcRelCoversBldgElements;
    m_bOwner = true;
}

NGfcRelCoversBldgElements::NGfcRelCoversBldgElements(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcRelConnects(pEntity, bOwner)
{
}

void NGfcRelCoversBldgElements::setRelatingBuildingElement(gfc::engine::EntityRef nValue)
{
    ((GfcRelCoversBldgElements*)m_pEntity)->setRelatingBuildingElement(nValue);
}

gfc::engine::EntityRef NGfcRelCoversBldgElements::getRelatingBuildingElement()
{
    return ((GfcRelCoversBldgElements*)m_pEntity)->getRelatingBuildingElement();
}

bool NGfcRelCoversBldgElements::hasRelatingBuildingElement()
{
    return ((GfcRelCoversBldgElements*)m_pEntity)->hasRelatingBuildingElement();
}

int NGfcRelCoversBldgElements::getRelatedCoveringsCount()
{
    return ((GfcRelCoversBldgElements*)m_pEntity)->getRelatedCoveringsCount();
}

void NGfcRelCoversBldgElements::clearRelatedCoverings()
{
    ((GfcRelCoversBldgElements*)m_pEntity)->clearRelatedCoverings();
}

void NGfcRelCoversBldgElements::addRelatedCoverings(gfc::engine::EntityRef nValue)
{
    ((GfcRelCoversBldgElements*)m_pEntity)->addRelatedCoverings(nValue);
}

gfc::engine::EntityRef NGfcRelCoversBldgElements::getRelatedCoverings(int nIndex)
{
    return ((GfcRelCoversBldgElements*)m_pEntity)->getRelatedCoverings(nIndex);
}

