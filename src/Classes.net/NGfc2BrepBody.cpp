#include "StdAfx.h"
#include "NGfc2BrepBody.h"
NGfc2BrepBody::NGfc2BrepBody()
{
    m_pEntity = new Gfc2BrepBody;
    m_bOwner = true;
}

NGfc2BrepBody::NGfc2BrepBody(void* pEntity, bool bOwner):
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

void NGfc2BrepBody::addFaces(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2BrepBody*)m_pEntity)->addFaces(nValue);
}

glodon::objectbuf::EntityRef NGfc2BrepBody::getFaces(int nIndex)
{
    return ((Gfc2BrepBody*)m_pEntity)->getFaces(nIndex);
}

NGfc2Face^ NGfc2BrepBody::getFacesPtr(int nIndex)
{
    return gcnew NGfc2Face(((Gfc2BrepBody*)m_pEntity)->getFacesPtr(nIndex), false);
}

int NGfc2BrepBody::getEdgesCount()
{
    return ((Gfc2BrepBody*)m_pEntity)->getEdgesCount();
}

void NGfc2BrepBody::clearEdges()
{
    ((Gfc2BrepBody*)m_pEntity)->clearEdges();
}

void NGfc2BrepBody::addEdges(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2BrepBody*)m_pEntity)->addEdges(nValue);
}

glodon::objectbuf::EntityRef NGfc2BrepBody::getEdges(int nIndex)
{
    return ((Gfc2BrepBody*)m_pEntity)->getEdges(nIndex);
}

NGfc2Edge^ NGfc2BrepBody::getEdgesPtr(int nIndex)
{
    return gcnew NGfc2Edge(((Gfc2BrepBody*)m_pEntity)->getEdgesPtr(nIndex), false);
}

