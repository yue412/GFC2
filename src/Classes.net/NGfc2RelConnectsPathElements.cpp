#include "NGfc2RelConnectsPathElements.h"

using namespace gfc::classes::x3;

NGfc2RelConnectsPathElements::NGfc2RelConnectsPathElements()
{
    m_pEntity = new Gfc2RelConnectsPathElements;
    m_bOwner = true;
}

NGfc2RelConnectsPathElements::NGfc2RelConnectsPathElements(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2RelConnectsElements(pEntity, bOwner)
{
}

void NGfc2RelConnectsPathElements::setRelatedConnectionType(NGfc2ConnectionType nValue)
{
    ((Gfc2RelConnectsPathElements*)m_pEntity)->setRelatedConnectionType((Gfc2ConnectionType)nValue);
}

NGfc2ConnectionType NGfc2RelConnectsPathElements::getRelatedConnectionType()
{
    return (NGfc2ConnectionType)((Gfc2RelConnectsPathElements*)m_pEntity)->getRelatedConnectionType();
}

bool NGfc2RelConnectsPathElements::hasRelatedConnectionType()
{
    return ((Gfc2RelConnectsPathElements*)m_pEntity)->hasRelatedConnectionType();
}

void NGfc2RelConnectsPathElements::setRelatingConnectionType(NGfc2ConnectionType nValue)
{
    ((Gfc2RelConnectsPathElements*)m_pEntity)->setRelatingConnectionType((Gfc2ConnectionType)nValue);
}

NGfc2ConnectionType NGfc2RelConnectsPathElements::getRelatingConnectionType()
{
    return (NGfc2ConnectionType)((Gfc2RelConnectsPathElements*)m_pEntity)->getRelatingConnectionType();
}

bool NGfc2RelConnectsPathElements::hasRelatingConnectionType()
{
    return ((Gfc2RelConnectsPathElements*)m_pEntity)->hasRelatingConnectionType();
}

