#include "NGfc2CuboidBody.h"

using namespace gfc::classes::x3;

NGfc2CuboidBody::NGfc2CuboidBody()
{
    m_pEntity = new Gfc2CuboidBody;
    m_bOwner = true;
}

NGfc2CuboidBody::NGfc2CuboidBody(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2PrimitiveBody(pEntity, bOwner)
{
}

void NGfc2CuboidBody::setCoordinate(gfc::engine::EntityRef nValue)
{
    ((Gfc2CuboidBody*)m_pEntity)->setCoordinate(nValue);
}

gfc::engine::EntityRef NGfc2CuboidBody::getCoordinate()
{
    return ((Gfc2CuboidBody*)m_pEntity)->getCoordinate();
}

bool NGfc2CuboidBody::hasCoordinate()
{
    return ((Gfc2CuboidBody*)m_pEntity)->hasCoordinate();
}

void NGfc2CuboidBody::setDimension(gfc::engine::EntityRef nValue)
{
    ((Gfc2CuboidBody*)m_pEntity)->setDimension(nValue);
}

gfc::engine::EntityRef NGfc2CuboidBody::getDimension()
{
    return ((Gfc2CuboidBody*)m_pEntity)->getDimension();
}

bool NGfc2CuboidBody::hasDimension()
{
    return ((Gfc2CuboidBody*)m_pEntity)->hasDimension();
}

