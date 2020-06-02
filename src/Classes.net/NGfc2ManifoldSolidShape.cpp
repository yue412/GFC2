#include "StdAfx.h"
#include "NGfc2ManifoldSolidShape.h"
NGfc2ManifoldSolidShape::NGfc2ManifoldSolidShape()
{
    m_pEntity = new Gfc2ManifoldSolidShape;
    m_bOwner = true;
}

NGfc2ManifoldSolidShape::NGfc2ManifoldSolidShape(void* pEntity, bool bOwner):
    NGfc2SolidShape(pEntity, bOwner)
{
}

void NGfc2ManifoldSolidShape::setBody(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ManifoldSolidShape*)m_pEntity)->setBody(nValue);
}

gfc2::engine::EntityRef NGfc2ManifoldSolidShape::getBody()
{
    return ((Gfc2ManifoldSolidShape*)m_pEntity)->getBody();
}

bool NGfc2ManifoldSolidShape::hasBody()
{
    return ((Gfc2ManifoldSolidShape*)m_pEntity)->hasBody();
}

NGfc2Body^ NGfc2ManifoldSolidShape::getBodyPtr()
{
    return gcnew NGfc2Body(((Gfc2ManifoldSolidShape*)m_pEntity)->getBodyPtr(), false);
}

