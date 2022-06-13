#include "NGfcPolyhedronBody.h"

using namespace gfc::classes::x3;

NGfcPolyhedronBody::NGfcPolyhedronBody()
{
    m_pEntity = new GfcPolyhedronBody;
    m_bOwner = true;
}

NGfcPolyhedronBody::NGfcPolyhedronBody(bool bNoCreate):
    NGfcBody(bNoCreate)
{
}

int NGfcPolyhedronBody::getFacesCount()
{
    return ((GfcPolyhedronBody*)m_pEntity)->getFacesCount();
}

void NGfcPolyhedronBody::clearFaces()
{
    ((GfcPolyhedronBody*)m_pEntity)->clearFaces();
}

void NGfcPolyhedronBody::addFaces(gfc::engine::EntityRef nValue)
{
    ((GfcPolyhedronBody*)m_pEntity)->addFaces(nValue);
}

gfc::engine::EntityRef NGfcPolyhedronBody::getFaces(int nIndex)
{
    return ((GfcPolyhedronBody*)m_pEntity)->getFaces(nIndex);
}

int NGfcPolyhedronBody::getVertexesCount()
{
    return ((GfcPolyhedronBody*)m_pEntity)->getVertexesCount();
}

void NGfcPolyhedronBody::clearVertexes()
{
    ((GfcPolyhedronBody*)m_pEntity)->clearVertexes();
}

void NGfcPolyhedronBody::addVertexes(gfc::engine::EntityRef nValue)
{
    ((GfcPolyhedronBody*)m_pEntity)->addVertexes(nValue);
}

gfc::engine::EntityRef NGfcPolyhedronBody::getVertexes(int nIndex)
{
    return ((GfcPolyhedronBody*)m_pEntity)->getVertexes(nIndex);
}

