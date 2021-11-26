#include "NGfc2BrepBody.h"

using namespace gfc::classes::x3;

NGfc2BrepBody::NGfc2BrepBody()
{
    m_pEntity = new Gfc2BrepBody;
    m_bOwner = true;
}

NGfc2BrepBody::NGfc2BrepBody(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Body(pEntity, bOwner)
{
}

int NGfc2BrepBody::getFacesCount()
{
    return ((Gfc2BrepBody*)m_pEntity)->getFacesCount();
}

void NGfc2BrepBody::clearFaces()
{
    ((Gfc2BrepBody*)m_pEntity)->clearFaces();
}

void NGfc2BrepBody::addFaces(gfc::engine::EntityRef nValue)
{
    ((Gfc2BrepBody*)m_pEntity)->addFaces(nValue);
}

gfc::engine::EntityRef NGfc2BrepBody::getFaces(int nIndex)
{
    return ((Gfc2BrepBody*)m_pEntity)->getFaces(nIndex);
}

int NGfc2BrepBody::getEdgesCount()
{
    return ((Gfc2BrepBody*)m_pEntity)->getEdgesCount();
}

void NGfc2BrepBody::clearEdges()
{
    ((Gfc2BrepBody*)m_pEntity)->clearEdges();
}

void NGfc2BrepBody::addEdges(gfc::engine::EntityRef nValue)
{
    ((Gfc2BrepBody*)m_pEntity)->addEdges(nValue);
}

gfc::engine::EntityRef NGfc2BrepBody::getEdges(int nIndex)
{
    return ((Gfc2BrepBody*)m_pEntity)->getEdges(nIndex);
}

