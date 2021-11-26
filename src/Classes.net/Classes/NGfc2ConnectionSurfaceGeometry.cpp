#include "NGfc2ConnectionSurfaceGeometry.h"

using namespace gfc::classes::x3;

NGfc2ConnectionSurfaceGeometry::NGfc2ConnectionSurfaceGeometry()
{
    m_pEntity = new Gfc2ConnectionSurfaceGeometry;
    m_bOwner = true;
}

NGfc2ConnectionSurfaceGeometry::NGfc2ConnectionSurfaceGeometry(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2ConnectionGeometry(pEntity, bOwner)
{
}

void NGfc2ConnectionSurfaceGeometry::setSurfaceOnRelatingElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->setSurfaceOnRelatingElement(nValue);
}

gfc::engine::EntityRef NGfc2ConnectionSurfaceGeometry::getSurfaceOnRelatingElement()
{
    return ((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->getSurfaceOnRelatingElement();
}

bool NGfc2ConnectionSurfaceGeometry::hasSurfaceOnRelatingElement()
{
    return ((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->hasSurfaceOnRelatingElement();
}

void NGfc2ConnectionSurfaceGeometry::setSurfaceOnRelatedElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->setSurfaceOnRelatedElement(nValue);
}

gfc::engine::EntityRef NGfc2ConnectionSurfaceGeometry::getSurfaceOnRelatedElement()
{
    return ((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->getSurfaceOnRelatedElement();
}

bool NGfc2ConnectionSurfaceGeometry::hasSurfaceOnRelatedElement()
{
    return ((Gfc2ConnectionSurfaceGeometry*)m_pEntity)->hasSurfaceOnRelatedElement();
}

