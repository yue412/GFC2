#include "StdAfx.h"
#include "NGfc2ConnectionPointGeometry.h"
NGfc2ConnectionPointGeometry::NGfc2ConnectionPointGeometry()
{
    m_pEntity = new Gfc2ConnectionPointGeometry;
    m_bOwner = true;
}

NGfc2ConnectionPointGeometry::NGfc2ConnectionPointGeometry(void* pEntity, bool bOwner):
    NGfc2ConnectionGeometry(pEntity, bOwner)
{
}

void NGfc2ConnectionPointGeometry::setPointOnRelatingElement(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ConnectionPointGeometry*)m_pEntity)->setPointOnRelatingElement(nValue);
}

gfc2::engine::EntityRef NGfc2ConnectionPointGeometry::getPointOnRelatingElement()
{
    return ((Gfc2ConnectionPointGeometry*)m_pEntity)->getPointOnRelatingElement();
}

bool NGfc2ConnectionPointGeometry::hasPointOnRelatingElement()
{
    return ((Gfc2ConnectionPointGeometry*)m_pEntity)->hasPointOnRelatingElement();
}

NGfc2Vector3d^ NGfc2ConnectionPointGeometry::getPointOnRelatingElementPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2ConnectionPointGeometry*)m_pEntity)->getPointOnRelatingElementPtr(), false);
}

void NGfc2ConnectionPointGeometry::setPointOnRelatedElement(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ConnectionPointGeometry*)m_pEntity)->setPointOnRelatedElement(nValue);
}

gfc2::engine::EntityRef NGfc2ConnectionPointGeometry::getPointOnRelatedElement()
{
    return ((Gfc2ConnectionPointGeometry*)m_pEntity)->getPointOnRelatedElement();
}

bool NGfc2ConnectionPointGeometry::hasPointOnRelatedElement()
{
    return ((Gfc2ConnectionPointGeometry*)m_pEntity)->hasPointOnRelatedElement();
}

NGfc2Vector3d^ NGfc2ConnectionPointGeometry::getPointOnRelatedElementPtr()
{
    return gcnew NGfc2Vector3d(((Gfc2ConnectionPointGeometry*)m_pEntity)->getPointOnRelatedElementPtr(), false);
}

