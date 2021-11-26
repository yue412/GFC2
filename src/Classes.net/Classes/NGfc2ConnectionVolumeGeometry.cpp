#include "NGfc2ConnectionVolumeGeometry.h"

using namespace gfc::classes::x3;

NGfc2ConnectionVolumeGeometry::NGfc2ConnectionVolumeGeometry()
{
    m_pEntity = new Gfc2ConnectionVolumeGeometry;
    m_bOwner = true;
}

NGfc2ConnectionVolumeGeometry::NGfc2ConnectionVolumeGeometry(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2ConnectionGeometry(pEntity, bOwner)
{
}

void NGfc2ConnectionVolumeGeometry::setVolumeOnRelatingElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2ConnectionVolumeGeometry*)m_pEntity)->setVolumeOnRelatingElement(nValue);
}

gfc::engine::EntityRef NGfc2ConnectionVolumeGeometry::getVolumeOnRelatingElement()
{
    return ((Gfc2ConnectionVolumeGeometry*)m_pEntity)->getVolumeOnRelatingElement();
}

bool NGfc2ConnectionVolumeGeometry::hasVolumeOnRelatingElement()
{
    return ((Gfc2ConnectionVolumeGeometry*)m_pEntity)->hasVolumeOnRelatingElement();
}

void NGfc2ConnectionVolumeGeometry::setVolumeOnRelatedElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2ConnectionVolumeGeometry*)m_pEntity)->setVolumeOnRelatedElement(nValue);
}

gfc::engine::EntityRef NGfc2ConnectionVolumeGeometry::getVolumeOnRelatedElement()
{
    return ((Gfc2ConnectionVolumeGeometry*)m_pEntity)->getVolumeOnRelatedElement();
}

bool NGfc2ConnectionVolumeGeometry::hasVolumeOnRelatedElement()
{
    return ((Gfc2ConnectionVolumeGeometry*)m_pEntity)->hasVolumeOnRelatedElement();
}

