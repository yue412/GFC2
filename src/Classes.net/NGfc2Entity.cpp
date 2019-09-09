#include "StdAfx.h"
#include "NGfc2Entity.h"
NGfc2Entity::NGfc2Entity()
{
    m_pEntity = new Gfc2Entity;
    m_bOwner = true;
}

NGfc2Entity::NGfc2Entity(void* pEntity, bool bOwner):
    NGfc2Object(pEntity, bOwner)
{
}

void NGfc2Entity::setType(NGfc2Integer nValue)
{
    ((Gfc2Entity*)m_pEntity)->setType(nValue);
}

NGfc2Integer NGfc2Entity::getType()
{
    return ((Gfc2Entity*)m_pEntity)->getType();
}

bool NGfc2Entity::hasType()
{
    return ((Gfc2Entity*)m_pEntity)->hasType();
}

int NGfc2Entity::getRepresentationsCount()
{
    return ((Gfc2Entity*)m_pEntity)->getRepresentationsCount();
}

void NGfc2Entity::clearRepresentations()
{
    ((Gfc2Entity*)m_pEntity)->clearRepresentations();
}

void NGfc2Entity::addRepresentations(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Entity*)m_pEntity)->addRepresentations(nValue);
}

glodon::objectbuf::EntityRef NGfc2Entity::getRepresentations(int nIndex)
{
    return ((Gfc2Entity*)m_pEntity)->getRepresentations(nIndex);
}

NGfc2Representation^ NGfc2Entity::getRepresentationsPtr(int nIndex)
{
    return gcnew NGfc2Representation(((Gfc2Entity*)m_pEntity)->getRepresentationsPtr(nIndex), false);
}

int NGfc2Entity::getShapesCount()
{
    return ((Gfc2Entity*)m_pEntity)->getShapesCount();
}

void NGfc2Entity::clearShapes()
{
    ((Gfc2Entity*)m_pEntity)->clearShapes();
}

void NGfc2Entity::addShapes(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Entity*)m_pEntity)->addShapes(nValue);
}

glodon::objectbuf::EntityRef NGfc2Entity::getShapes(int nIndex)
{
    return ((Gfc2Entity*)m_pEntity)->getShapes(nIndex);
}

NGfc2EntityShape^ NGfc2Entity::getShapesPtr(int nIndex)
{
    return gcnew NGfc2EntityShape(((Gfc2Entity*)m_pEntity)->getShapesPtr(nIndex), false);
}

