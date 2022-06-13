#include "NGfcExtrudedBody.h"

using namespace gfc::classes::x3;

NGfcExtrudedBody::NGfcExtrudedBody()
{
    m_pEntity = new GfcExtrudedBody;
    m_bOwner = true;
}

NGfcExtrudedBody::NGfcExtrudedBody(bool bNoCreate):
    NGfcPrimitiveBody(bNoCreate)
{
}

void NGfcExtrudedBody::setCoordinate(gfc::engine::EntityRef nValue)
{
    ((GfcExtrudedBody*)m_pEntity)->setCoordinate(nValue);
}

gfc::engine::EntityRef NGfcExtrudedBody::getCoordinate()
{
    return ((GfcExtrudedBody*)m_pEntity)->getCoordinate();
}

bool NGfcExtrudedBody::hasCoordinate()
{
    return ((GfcExtrudedBody*)m_pEntity)->hasCoordinate();
}

void NGfcExtrudedBody::setLen(NGfcDouble dValue)
{
    ((GfcExtrudedBody*)m_pEntity)->setLen(dValue);
}

NGfcDouble NGfcExtrudedBody::getLen()
{
    return ((GfcExtrudedBody*)m_pEntity)->getLen();
}

bool NGfcExtrudedBody::hasLen()
{
    return ((GfcExtrudedBody*)m_pEntity)->hasLen();
}

void NGfcExtrudedBody::setSection(gfc::engine::EntityRef nValue)
{
    ((GfcExtrudedBody*)m_pEntity)->setSection(nValue);
}

gfc::engine::EntityRef NGfcExtrudedBody::getSection()
{
    return ((GfcExtrudedBody*)m_pEntity)->getSection();
}

bool NGfcExtrudedBody::hasSection()
{
    return ((GfcExtrudedBody*)m_pEntity)->hasSection();
}

