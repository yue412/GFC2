#include "StdAfx.h"
#include "NGfc2HalfSpaceSolidShape.h"
NGfc2HalfSpaceSolidShape::NGfc2HalfSpaceSolidShape()
{
    m_pEntity = new Gfc2HalfSpaceSolidShape;
    m_bOwner = true;
}

NGfc2HalfSpaceSolidShape::NGfc2HalfSpaceSolidShape(void* pEntity, bool bOwner):
    NGfc2SolidShape(pEntity, bOwner)
{
}

void NGfc2HalfSpaceSolidShape::setBaseSurface(gfc::engine::EntityRef nValue)
{
    ((Gfc2HalfSpaceSolidShape*)m_pEntity)->setBaseSurface(nValue);
}

gfc::engine::EntityRef NGfc2HalfSpaceSolidShape::getBaseSurface()
{
    return ((Gfc2HalfSpaceSolidShape*)m_pEntity)->getBaseSurface();
}

bool NGfc2HalfSpaceSolidShape::hasBaseSurface()
{
    return ((Gfc2HalfSpaceSolidShape*)m_pEntity)->hasBaseSurface();
}

NGfc2Surface^ NGfc2HalfSpaceSolidShape::getBaseSurfacePtr()
{
    return gcnew NGfc2Surface(((Gfc2HalfSpaceSolidShape*)m_pEntity)->getBaseSurfacePtr(), false);
}

void NGfc2HalfSpaceSolidShape::setAgreementFlag(NGfc2Boolean bValue)
{
    ((Gfc2HalfSpaceSolidShape*)m_pEntity)->setAgreementFlag(bValue);
}

NGfc2Boolean NGfc2HalfSpaceSolidShape::getAgreementFlag()
{
    return ((Gfc2HalfSpaceSolidShape*)m_pEntity)->getAgreementFlag();
}

bool NGfc2HalfSpaceSolidShape::hasAgreementFlag()
{
    return ((Gfc2HalfSpaceSolidShape*)m_pEntity)->hasAgreementFlag();
}

