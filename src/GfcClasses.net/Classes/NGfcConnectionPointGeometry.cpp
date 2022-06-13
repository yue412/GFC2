#include "NGfcConnectionPointGeometry.h"

using namespace gfc::classes::x3;

NGfcConnectionPointGeometry::NGfcConnectionPointGeometry()
{
    m_pEntity = new GfcConnectionPointGeometry;
    m_bOwner = true;
}

NGfcConnectionPointGeometry::NGfcConnectionPointGeometry(bool bNoCreate):
    NGfcConnectionGeometry(bNoCreate)
{
}

void NGfcConnectionPointGeometry::setPointOnRelatingElement(gfc::engine::EntityRef nValue)
{
    ((GfcConnectionPointGeometry*)m_pEntity)->setPointOnRelatingElement(nValue);
}

gfc::engine::EntityRef NGfcConnectionPointGeometry::getPointOnRelatingElement()
{
    return ((GfcConnectionPointGeometry*)m_pEntity)->getPointOnRelatingElement();
}

bool NGfcConnectionPointGeometry::hasPointOnRelatingElement()
{
    return ((GfcConnectionPointGeometry*)m_pEntity)->hasPointOnRelatingElement();
}

void NGfcConnectionPointGeometry::setPointOnRelatedElement(gfc::engine::EntityRef nValue)
{
    ((GfcConnectionPointGeometry*)m_pEntity)->setPointOnRelatedElement(nValue);
}

gfc::engine::EntityRef NGfcConnectionPointGeometry::getPointOnRelatedElement()
{
    return ((GfcConnectionPointGeometry*)m_pEntity)->getPointOnRelatedElement();
}

bool NGfcConnectionPointGeometry::hasPointOnRelatedElement()
{
    return ((GfcConnectionPointGeometry*)m_pEntity)->hasPointOnRelatedElement();
}

