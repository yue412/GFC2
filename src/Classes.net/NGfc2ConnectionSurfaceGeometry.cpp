#include "StdAfx.h"
#include "NGfc2ConnectionSurfaceGeometry.h"
NGfc2ConnectionSurfaceGeometry::NGfc2ConnectionSurfaceGeometry()
{
    m_pEntity = new Gfc2ConnectionSurfaceGeometry;
    m_bOwner = true;
}

NGfc2ConnectionSurfaceGeometry::NGfc2ConnectionSurfaceGeometry(void* pEntity, bool bOwner):
    NGfc2ConnectionGeometry(pEntity, bOwner)
{
}

void NGfc2ConnectionSurfaceGeometry::setSurfaceOnRelatingElement(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->setSurfaceOnRelatingElement(nValue);
}

gfc2::engine::EntityRef NGfc2ConnectionSurfaceGeometry::getSurfaceOnRelatingElement()
{
    return ((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->getSurfaceOnRelatingElement();
}

bool NGfc2ConnectionSurfaceGeometry::hasSurfaceOnRelatingElement()
{
    return ((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->hasSurfaceOnRelatingElement();
}

NGfc2Surface^ NGfc2ConnectionSurfaceGeometry::getSurfaceOnRelatingElementPtr()
{
    return gcnew NGfc2Surface(((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->getSurfaceOnRelatingElementPtr(), false);
}

void NGfc2ConnectionSurfaceGeometry::setSurfaceOnRelatedElement(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->setSurfaceOnRelatedElement(nValue);
}

gfc2::engine::EntityRef NGfc2ConnectionSurfaceGeometry::getSurfaceOnRelatedElement()
{
    return ((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->getSurfaceOnRelatedElement();
}

bool NGfc2ConnectionSurfaceGeometry::hasSurfaceOnRelatedElement()
{
    return ((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->hasSurfaceOnRelatedElement();
}

NGfc2Surface^ NGfc2ConnectionSurfaceGeometry::getSurfaceOnRelatedElementPtr()
{
    return gcnew NGfc2Surface(((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->getSurfaceOnRelatedElementPtr(), false);
}

