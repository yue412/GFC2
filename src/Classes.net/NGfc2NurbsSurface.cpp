#include "StdAfx.h"
#include "NGfc2NurbsSurface.h"
NGfc2NurbsSurface::NGfc2NurbsSurface()
{
    m_pEntity = new Gfc2NurbsSurface;
    m_bOwner = true;
}

NGfc2NurbsSurface::NGfc2NurbsSurface(void* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2NurbsSurface::setDegreeU(NGfc2Integer nValue)
{
    ((Gfc2NurbsSurface*)m_pEntity)->setDegreeU(nValue);
}

NGfc2Integer NGfc2NurbsSurface::getDegreeU()
{
    return ((Gfc2NurbsSurface*)m_pEntity)->getDegreeU();
}

bool NGfc2NurbsSurface::hasDegreeU()
{
    return ((Gfc2NurbsSurface*)m_pEntity)->hasDegreeU();
}

void NGfc2NurbsSurface::setDegreeV(NGfc2Integer nValue)
{
    ((Gfc2NurbsSurface*)m_pEntity)->setDegreeV(nValue);
}

NGfc2Integer NGfc2NurbsSurface::getDegreeV()
{
    return ((Gfc2NurbsSurface*)m_pEntity)->getDegreeV();
}

bool NGfc2NurbsSurface::hasDegreeV()
{
    return ((Gfc2NurbsSurface*)m_pEntity)->hasDegreeV();
}

void NGfc2NurbsSurface::setCtrlPtCountU(NGfc2Integer nValue)
{
    ((Gfc2NurbsSurface*)m_pEntity)->setCtrlPtCountU(nValue);
}

NGfc2Integer NGfc2NurbsSurface::getCtrlPtCountU()
{
    return ((Gfc2NurbsSurface*)m_pEntity)->getCtrlPtCountU();
}

bool NGfc2NurbsSurface::hasCtrlPtCountU()
{
    return ((Gfc2NurbsSurface*)m_pEntity)->hasCtrlPtCountU();
}

void NGfc2NurbsSurface::setCtrlPtCountV(NGfc2Integer nValue)
{
    ((Gfc2NurbsSurface*)m_pEntity)->setCtrlPtCountV(nValue);
}

NGfc2Integer NGfc2NurbsSurface::getCtrlPtCountV()
{
    return ((Gfc2NurbsSurface*)m_pEntity)->getCtrlPtCountV();
}

bool NGfc2NurbsSurface::hasCtrlPtCountV()
{
    return ((Gfc2NurbsSurface*)m_pEntity)->hasCtrlPtCountV();
}

int NGfc2NurbsSurface::getCtrlPtsCount()
{
    return ((Gfc2NurbsSurface*)m_pEntity)->getCtrlPtsCount();
}

void NGfc2NurbsSurface::clearCtrlPts()
{
    ((Gfc2NurbsSurface*)m_pEntity)->clearCtrlPts();
}

void NGfc2NurbsSurface::addCtrlPts(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2NurbsSurface*)m_pEntity)->addCtrlPts(nValue);
}

glodon::objectbuf::EntityRef NGfc2NurbsSurface::getCtrlPts(int nIndex)
{
    return ((Gfc2NurbsSurface*)m_pEntity)->getCtrlPts(nIndex);
}

NGfc2NurbsCtrlPt3d^ NGfc2NurbsSurface::getCtrlPtsPtr(int nIndex)
{
    return gcnew NGfc2NurbsCtrlPt3d(((Gfc2NurbsSurface*)m_pEntity)->getCtrlPtsPtr(nIndex), false);
}

int NGfc2NurbsSurface::getKnotsUCount()
{
    return ((Gfc2NurbsSurface*)m_pEntity)->getKnotsUCount();
}

void NGfc2NurbsSurface::clearKnotsU()
{
    ((Gfc2NurbsSurface*)m_pEntity)->clearKnotsU();
}

void NGfc2NurbsSurface::addKnotsU(NGfc2Double dValue)
{
    ((Gfc2NurbsSurface*)m_pEntity)->addKnotsU(dValue);
}

NGfc2Double NGfc2NurbsSurface::getKnotsU(int nIndex)
{
    return ((Gfc2NurbsSurface*)m_pEntity)->getKnotsU(nIndex);
}

int NGfc2NurbsSurface::getKnotsVCount()
{
    return ((Gfc2NurbsSurface*)m_pEntity)->getKnotsVCount();
}

void NGfc2NurbsSurface::clearKnotsV()
{
    ((Gfc2NurbsSurface*)m_pEntity)->clearKnotsV();
}

void NGfc2NurbsSurface::addKnotsV(NGfc2Double dValue)
{
    ((Gfc2NurbsSurface*)m_pEntity)->addKnotsV(dValue);
}

NGfc2Double NGfc2NurbsSurface::getKnotsV(int nIndex)
{
    return ((Gfc2NurbsSurface*)m_pEntity)->getKnotsV(nIndex);
}

