#include "NGfcConnectionVolumeGeometry.h"

using namespace gfc::classes::x3;

NGfcConnectionVolumeGeometry::NGfcConnectionVolumeGeometry()
{
    m_pEntity = new GfcConnectionVolumeGeometry;
    m_bOwner = true;
}

NGfcConnectionVolumeGeometry::NGfcConnectionVolumeGeometry(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcConnectionGeometry(pEntity, bOwner)
{
}

void NGfcConnectionVolumeGeometry::setVolumeOnRelatingElement(gfc::engine::EntityRef nValue)
{
    ((GfcConnectionVolumeGeometry*)m_pEntity)->setVolumeOnRelatingElement(nValue);
}

gfc::engine::EntityRef NGfcConnectionVolumeGeometry::getVolumeOnRelatingElement()
{
    return ((GfcConnectionVolumeGeometry*)m_pEntity)->getVolumeOnRelatingElement();
}

bool NGfcConnectionVolumeGeometry::hasVolumeOnRelatingElement()
{
    return ((GfcConnectionVolumeGeometry*)m_pEntity)->hasVolumeOnRelatingElement();
}

void NGfcConnectionVolumeGeometry::setVolumeOnRelatedElement(gfc::engine::EntityRef nValue)
{
    ((GfcConnectionVolumeGeometry*)m_pEntity)->setVolumeOnRelatedElement(nValue);
}

gfc::engine::EntityRef NGfcConnectionVolumeGeometry::getVolumeOnRelatedElement()
{
    return ((GfcConnectionVolumeGeometry*)m_pEntity)->getVolumeOnRelatedElement();
}

bool NGfcConnectionVolumeGeometry::hasVolumeOnRelatedElement()
{
    return ((GfcConnectionVolumeGeometry*)m_pEntity)->hasVolumeOnRelatedElement();
}

