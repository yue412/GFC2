#include "NGfcCuboidBody.h"

using namespace gfc::classes::x3;

NGfcCuboidBody::NGfcCuboidBody()
{
    m_pEntity = new GfcCuboidBody;
    m_bOwner = true;
}

NGfcCuboidBody::NGfcCuboidBody(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcPrimitiveBody(pEntity, bOwner)
{
}

void NGfcCuboidBody::setCoordinate(gfc::engine::EntityRef nValue)
{
    ((GfcCuboidBody*)m_pEntity)->setCoordinate(nValue);
}

gfc::engine::EntityRef NGfcCuboidBody::getCoordinate()
{
    return ((GfcCuboidBody*)m_pEntity)->getCoordinate();
}

bool NGfcCuboidBody::hasCoordinate()
{
    return ((GfcCuboidBody*)m_pEntity)->hasCoordinate();
}

void NGfcCuboidBody::setDimension(gfc::engine::EntityRef nValue)
{
    ((GfcCuboidBody*)m_pEntity)->setDimension(nValue);
}

gfc::engine::EntityRef NGfcCuboidBody::getDimension()
{
    return ((GfcCuboidBody*)m_pEntity)->getDimension();
}

bool NGfcCuboidBody::hasDimension()
{
    return ((GfcCuboidBody*)m_pEntity)->hasDimension();
}

