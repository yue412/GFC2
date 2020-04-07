#include "StdAfx.h"
#include "NGfc2ConnectionVolumeGeometry.h"
NGfc2ConnectionVolumeGeometry::NGfc2ConnectionVolumeGeometry()
{
    m_pEntity = new Gfc2ConnectionVolumeGeometry;
    m_bOwner = true;
}

NGfc2ConnectionVolumeGeometry::NGfc2ConnectionVolumeGeometry(void* pEntity, bool bOwner):
    NGfc2ConnectionGeometry(pEntity, bOwner)
{
}

void NGfc2ConnectionVolumeGeometry::setVolumeOnRelatingElement(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2ConnectionVolumeGeometry*)m_pEntity)->setVolumeOnRelatingElement(nValue);
}

glodon::objectbuf::EntityRef NGfc2ConnectionVolumeGeometry::getVolumeOnRelatingElement()
{
    return ((Gfc2ConnectionVolumeGeometry*)m_pEntity)->getVolumeOnRelatingElement();
}

bool NGfc2ConnectionVolumeGeometry::hasVolumeOnRelatingElement()
{
    return ((Gfc2ConnectionVolumeGeometry*)m_pEntity)->hasVolumeOnRelatingElement();
}

NGfc2Body^ NGfc2ConnectionVolumeGeometry::getVolumeOnRelatingElementPtr()
{
    return gcnew NGfc2Body(((Gfc2ConnectionVolumeGeometry*)m_pEntity)->getVolumeOnRelatingElementPtr(), false);
}

void NGfc2ConnectionVolumeGeometry::setVolumeOnRelatedElement(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2ConnectionVolumeGeometry*)m_pEntity)->setVolumeOnRelatedElement(nValue);
}

glodon::objectbuf::EntityRef NGfc2ConnectionVolumeGeometry::getVolumeOnRelatedElement()
{
    return ((Gfc2ConnectionVolumeGeometry*)m_pEntity)->getVolumeOnRelatedElement();
}

bool NGfc2ConnectionVolumeGeometry::hasVolumeOnRelatedElement()
{
    return ((Gfc2ConnectionVolumeGeometry*)m_pEntity)->hasVolumeOnRelatedElement();
}

NGfc2Body^ NGfc2ConnectionVolumeGeometry::getVolumeOnRelatedElementPtr()
{
    return gcnew NGfc2Body(((Gfc2ConnectionVolumeGeometry*)m_pEntity)->getVolumeOnRelatedElementPtr(), false);
}

