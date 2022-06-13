#include "NGfcRelConnectsPathElements.h"

using namespace gfc::classes::x3;

NGfcRelConnectsPathElements::NGfcRelConnectsPathElements()
{
    m_pEntity = new GfcRelConnectsPathElements;
    m_bOwner = true;
}

NGfcRelConnectsPathElements::NGfcRelConnectsPathElements(bool bNoCreate):
    NGfcRelConnectsElements(bNoCreate)
{
}

void NGfcRelConnectsPathElements::setRelatedConnectionType(NGfcConnectionType nValue)
{
    ((GfcRelConnectsPathElements*)m_pEntity)->setRelatedConnectionType((GfcConnectionType)nValue);
}

NGfcConnectionType NGfcRelConnectsPathElements::getRelatedConnectionType()
{
    return (NGfcConnectionType)((GfcRelConnectsPathElements*)m_pEntity)->getRelatedConnectionType();
}

bool NGfcRelConnectsPathElements::hasRelatedConnectionType()
{
    return ((GfcRelConnectsPathElements*)m_pEntity)->hasRelatedConnectionType();
}

void NGfcRelConnectsPathElements::setRelatingConnectionType(NGfcConnectionType nValue)
{
    ((GfcRelConnectsPathElements*)m_pEntity)->setRelatingConnectionType((GfcConnectionType)nValue);
}

NGfcConnectionType NGfcRelConnectsPathElements::getRelatingConnectionType()
{
    return (NGfcConnectionType)((GfcRelConnectsPathElements*)m_pEntity)->getRelatingConnectionType();
}

bool NGfcRelConnectsPathElements::hasRelatingConnectionType()
{
    return ((GfcRelConnectsPathElements*)m_pEntity)->hasRelatingConnectionType();
}

