#include "StdAfx.h"
#include "NGfc2Face.h"
NGfc2Face::NGfc2Face()
{
    m_pEntity = new Gfc2Face;
    m_bOwner = true;
}

NGfc2Face::NGfc2Face(void* pEntity, bool bOwner):
    NGfc2CommonPolygonEx(pEntity, bOwner)
{
}

void NGfc2Face::setSurface(gfc::engine::EntityRef nValue)
{
    ((Gfc2Face*)m_pEntity)->setSurface(nValue);
}

gfc::engine::EntityRef NGfc2Face::getSurface()
{
    return ((Gfc2Face*)m_pEntity)->getSurface();
}

bool NGfc2Face::hasSurface()
{
    return ((Gfc2Face*)m_pEntity)->hasSurface();
}

NGfc2Surface^ NGfc2Face::getSurfacePtr()
{
    return gcnew NGfc2Surface(((Gfc2Face*)m_pEntity)->getSurfacePtr(), false);
}

void NGfc2Face::setBox(gfc::engine::EntityRef nValue)
{
    ((Gfc2Face*)m_pEntity)->setBox(nValue);
}

gfc::engine::EntityRef NGfc2Face::getBox()
{
    return ((Gfc2Face*)m_pEntity)->getBox();
}

bool NGfc2Face::hasBox()
{
    return ((Gfc2Face*)m_pEntity)->hasBox();
}

NGfc2Box3d^ NGfc2Face::getBoxPtr()
{
    return gcnew NGfc2Box3d(((Gfc2Face*)m_pEntity)->getBoxPtr(), false);
}

void NGfc2Face::setSameDir(NGfc2Boolean bValue)
{
    ((Gfc2Face*)m_pEntity)->setSameDir(bValue);
}

NGfc2Boolean NGfc2Face::getSameDir()
{
    return ((Gfc2Face*)m_pEntity)->getSameDir();
}

bool NGfc2Face::hasSameDir()
{
    return ((Gfc2Face*)m_pEntity)->hasSameDir();
}

void NGfc2Face::setIndex(NGfc2Integer nValue)
{
    ((Gfc2Face*)m_pEntity)->setIndex(nValue);
}

NGfc2Integer NGfc2Face::getIndex()
{
    return ((Gfc2Face*)m_pEntity)->getIndex();
}

bool NGfc2Face::hasIndex()
{
    return ((Gfc2Face*)m_pEntity)->hasIndex();
}

