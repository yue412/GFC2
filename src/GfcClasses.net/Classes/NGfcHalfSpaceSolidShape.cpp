#include "NGfcHalfSpaceSolidShape.h"

using namespace gfc::classes::x3;

NGfcHalfSpaceSolidShape::NGfcHalfSpaceSolidShape()
{
    m_pEntity = new GfcHalfSpaceSolidShape;
    m_bOwner = true;
}

NGfcHalfSpaceSolidShape::NGfcHalfSpaceSolidShape(bool bNoCreate):
    NGfcSolidShape(bNoCreate)
{
}

void NGfcHalfSpaceSolidShape::setBaseSurface(gfc::engine::EntityRef nValue)
{
    ((GfcHalfSpaceSolidShape*)m_pEntity)->setBaseSurface(nValue);
}

gfc::engine::EntityRef NGfcHalfSpaceSolidShape::getBaseSurface()
{
    return ((GfcHalfSpaceSolidShape*)m_pEntity)->getBaseSurface();
}

bool NGfcHalfSpaceSolidShape::hasBaseSurface()
{
    return ((GfcHalfSpaceSolidShape*)m_pEntity)->hasBaseSurface();
}

void NGfcHalfSpaceSolidShape::setAgreementFlag(NGfcBoolean bValue)
{
    ((GfcHalfSpaceSolidShape*)m_pEntity)->setAgreementFlag(bValue);
}

NGfcBoolean NGfcHalfSpaceSolidShape::getAgreementFlag()
{
    return ((GfcHalfSpaceSolidShape*)m_pEntity)->getAgreementFlag();
}

bool NGfcHalfSpaceSolidShape::hasAgreementFlag()
{
    return ((GfcHalfSpaceSolidShape*)m_pEntity)->hasAgreementFlag();
}

