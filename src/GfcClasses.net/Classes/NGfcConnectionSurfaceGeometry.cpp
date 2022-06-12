#include "NGfcConnectionSurfaceGeometry.h"

using namespace gfc::classes::x3;

NGfcConnectionSurfaceGeometry::NGfcConnectionSurfaceGeometry()
{
    m_pEntity = new GfcConnectionSurfaceGeometry;
    m_bOwner = true;
}

NGfcConnectionSurfaceGeometry::NGfcConnectionSurfaceGeometry(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcConnectionGeometry(pEntity, bOwner)
{
}

void NGfcConnectionSurfaceGeometry::setSurfaceOnRelatingElement(gfc::engine::EntityRef nValue)
{
    ((GfcConnectionSurfaceGeometry*)m_pEntity)->setSurfaceOnRelatingElement(nValue);
}

gfc::engine::EntityRef NGfcConnectionSurfaceGeometry::getSurfaceOnRelatingElement()
{
    return ((GfcConnectionSurfaceGeometry*)m_pEntity)->getSurfaceOnRelatingElement();
}

bool NGfcConnectionSurfaceGeometry::hasSurfaceOnRelatingElement()
{
    return ((GfcConnectionSurfaceGeometry*)m_pEntity)->hasSurfaceOnRelatingElement();
}

void NGfcConnectionSurfaceGeometry::setSurfaceOnRelatedElement(gfc::engine::EntityRef nValue)
{
    ((GfcConnectionSurfaceGeometry*)m_pEntity)->setSurfaceOnRelatedElement(nValue);
}

gfc::engine::EntityRef NGfcConnectionSurfaceGeometry::getSurfaceOnRelatedElement()
{
    return ((GfcConnectionSurfaceGeometry*)m_pEntity)->getSurfaceOnRelatedElement();
}

bool NGfcConnectionSurfaceGeometry::hasSurfaceOnRelatedElement()
{
    return ((GfcConnectionSurfaceGeometry*)m_pEntity)->hasSurfaceOnRelatedElement();
}

