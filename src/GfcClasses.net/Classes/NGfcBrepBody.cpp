#include "NGfcBrepBody.h"

using namespace gfc::classes::x3;

NGfcBrepBody::NGfcBrepBody()
{
    m_pEntity = new GfcBrepBody;
    m_bOwner = true;
}

NGfcBrepBody::NGfcBrepBody(bool bNoCreate):
    NGfcBody(bNoCreate)
{
}

int NGfcBrepBody::getFacesCount()
{
    return ((GfcBrepBody*)m_pEntity)->getFacesCount();
}

void NGfcBrepBody::clearFaces()
{
    ((GfcBrepBody*)m_pEntity)->clearFaces();
}

void NGfcBrepBody::addFaces(gfc::engine::EntityRef nValue)
{
    ((GfcBrepBody*)m_pEntity)->addFaces(nValue);
}

gfc::engine::EntityRef NGfcBrepBody::getFaces(int nIndex)
{
    return ((GfcBrepBody*)m_pEntity)->getFaces(nIndex);
}

int NGfcBrepBody::getEdgesCount()
{
    return ((GfcBrepBody*)m_pEntity)->getEdgesCount();
}

void NGfcBrepBody::clearEdges()
{
    ((GfcBrepBody*)m_pEntity)->clearEdges();
}

void NGfcBrepBody::addEdges(gfc::engine::EntityRef nValue)
{
    ((GfcBrepBody*)m_pEntity)->addEdges(nValue);
}

gfc::engine::EntityRef NGfcBrepBody::getEdges(int nIndex)
{
    return ((GfcBrepBody*)m_pEntity)->getEdges(nIndex);
}

