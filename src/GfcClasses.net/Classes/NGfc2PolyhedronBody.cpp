#include "NGfc2PolyhedronBody.h"

using namespace gfc::classes::x3;

NGfc2PolyhedronBody::NGfc2PolyhedronBody()
{
    m_pEntity = new Gfc2PolyhedronBody;
    m_bOwner = true;
}

NGfc2PolyhedronBody::NGfc2PolyhedronBody(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Body(pEntity, bOwner)
{
}

int NGfc2PolyhedronBody::getFacesCount()
{
    return ((Gfc2PolyhedronBody*)m_pEntity)->getFacesCount();
}

void NGfc2PolyhedronBody::clearFaces()
{
    ((Gfc2PolyhedronBody*)m_pEntity)->clearFaces();
}

void NGfc2PolyhedronBody::addFaces(gfc::engine::EntityRef nValue)
{
    ((Gfc2PolyhedronBody*)m_pEntity)->addFaces(nValue);
}

gfc::engine::EntityRef NGfc2PolyhedronBody::getFaces(int nIndex)
{
    return ((Gfc2PolyhedronBody*)m_pEntity)->getFaces(nIndex);
}

int NGfc2PolyhedronBody::getVertexesCount()
{
    return ((Gfc2PolyhedronBody*)m_pEntity)->getVertexesCount();
}

void NGfc2PolyhedronBody::clearVertexes()
{
    ((Gfc2PolyhedronBody*)m_pEntity)->clearVertexes();
}

void NGfc2PolyhedronBody::addVertexes(gfc::engine::EntityRef nValue)
{
    ((Gfc2PolyhedronBody*)m_pEntity)->addVertexes(nValue);
}

gfc::engine::EntityRef NGfc2PolyhedronBody::getVertexes(int nIndex)
{
    return ((Gfc2PolyhedronBody*)m_pEntity)->getVertexes(nIndex);
}

