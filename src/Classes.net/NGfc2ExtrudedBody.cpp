#include "StdAfx.h"
#include "NGfc2ExtrudedBody.h"
NGfc2ExtrudedBody::NGfc2ExtrudedBody()
{
    m_pEntity = new Gfc2ExtrudedBody;
    m_bOwner = true;
}

NGfc2ExtrudedBody::NGfc2ExtrudedBody(void* pEntity, bool bOwner):
    NGfc2PrimitiveBody(pEntity, bOwner)
{
}

void NGfc2ExtrudedBody::setCoordinate(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ExtrudedBody*)m_pEntity)->setCoordinate(nValue);
}

gfc2::engine::EntityRef NGfc2ExtrudedBody::getCoordinate()
{
    return ((Gfc2ExtrudedBody*)m_pEntity)->getCoordinate();
}

bool NGfc2ExtrudedBody::hasCoordinate()
{
    return ((Gfc2ExtrudedBody*)m_pEntity)->hasCoordinate();
}

NGfc2Coordinates3d^ NGfc2ExtrudedBody::getCoordinatePtr()
{
    return gcnew NGfc2Coordinates3d(((Gfc2ExtrudedBody*)m_pEntity)->getCoordinatePtr(), false);
}

void NGfc2ExtrudedBody::setLength(NGfc2Double dValue)
{
    ((Gfc2ExtrudedBody*)m_pEntity)->setLength(dValue);
}

NGfc2Double NGfc2ExtrudedBody::getLength()
{
    return ((Gfc2ExtrudedBody*)m_pEntity)->getLength();
}

bool NGfc2ExtrudedBody::hasLength()
{
    return ((Gfc2ExtrudedBody*)m_pEntity)->hasLength();
}

void NGfc2ExtrudedBody::setSection(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ExtrudedBody*)m_pEntity)->setSection(nValue);
}

gfc2::engine::EntityRef NGfc2ExtrudedBody::getSection()
{
    return ((Gfc2ExtrudedBody*)m_pEntity)->getSection();
}

bool NGfc2ExtrudedBody::hasSection()
{
    return ((Gfc2ExtrudedBody*)m_pEntity)->hasSection();
}

NGfc2Polygon^ NGfc2ExtrudedBody::getSectionPtr()
{
    return gcnew NGfc2Polygon(((Gfc2ExtrudedBody*)m_pEntity)->getSectionPtr(), false);
}

