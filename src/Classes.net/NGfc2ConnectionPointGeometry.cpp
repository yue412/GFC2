#include "NGfc2ConnectionPointGeometry.h"

using namespace gfc::classes::x3;

NGfc2ConnectionPointGeometry::NGfc2ConnectionPointGeometry()
{
    m_pEntity = new Gfc2ConnectionPointGeometry;
    m_bOwner = true;
}

NGfc2ConnectionPointGeometry::NGfc2ConnectionPointGeometry(void* pEntity, bool bOwner):
    NGfc2ConnectionGeometry(pEntity, bOwner)
{
}

void NGfc2ConnectionPointGeometry::setPointOnRelatingElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2ConnectionPointGeometry*)m_pEntity)->setPointOnRelatingElement(nValue);
}

gfc::engine::EntityRef NGfc2ConnectionPointGeometry::getPointOnRelatingElement()
{
    return ((Gfc2ConnectionPointGeometry*)m_pEntity)->getPointOnRelatingElement();
}

bool NGfc2ConnectionPointGeometry::hasPointOnRelatingElement()
{
    return ((Gfc2ConnectionPointGeometry*)m_pEntity)->hasPointOnRelatingElement();
}

void NGfc2ConnectionPointGeometry::setPointOnRelatedElement(gfc::engine::EntityRef nValue)
{
    ((Gfc2ConnectionPointGeometry*)m_pEntity)->setPointOnRelatedElement(nValue);
}

gfc::engine::EntityRef NGfc2ConnectionPointGeometry::getPointOnRelatedElement()
{
    return ((Gfc2ConnectionPointGeometry*)m_pEntity)->getPointOnRelatedElement();
}

bool NGfc2ConnectionPointGeometry::hasPointOnRelatedElement()
{
    return ((Gfc2ConnectionPointGeometry*)m_pEntity)->hasPointOnRelatedElement();
}

