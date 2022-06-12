#include "NGfcNurbsSurface.h"

using namespace gfc::classes::x3;

NGfcNurbsSurface::NGfcNurbsSurface()
{
    m_pEntity = new GfcNurbsSurface;
    m_bOwner = true;
}

NGfcNurbsSurface::NGfcNurbsSurface(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSurface(pEntity, bOwner)
{
}

void NGfcNurbsSurface::setDegreeU(NGfcInteger nValue)
{
    ((GfcNurbsSurface*)m_pEntity)->setDegreeU(nValue);
}

NGfcInteger NGfcNurbsSurface::getDegreeU()
{
    return ((GfcNurbsSurface*)m_pEntity)->getDegreeU();
}

bool NGfcNurbsSurface::hasDegreeU()
{
    return ((GfcNurbsSurface*)m_pEntity)->hasDegreeU();
}

void NGfcNurbsSurface::setDegreeV(NGfcInteger nValue)
{
    ((GfcNurbsSurface*)m_pEntity)->setDegreeV(nValue);
}

NGfcInteger NGfcNurbsSurface::getDegreeV()
{
    return ((GfcNurbsSurface*)m_pEntity)->getDegreeV();
}

bool NGfcNurbsSurface::hasDegreeV()
{
    return ((GfcNurbsSurface*)m_pEntity)->hasDegreeV();
}

void NGfcNurbsSurface::setCtrlPtCountU(NGfcInteger nValue)
{
    ((GfcNurbsSurface*)m_pEntity)->setCtrlPtCountU(nValue);
}

NGfcInteger NGfcNurbsSurface::getCtrlPtCountU()
{
    return ((GfcNurbsSurface*)m_pEntity)->getCtrlPtCountU();
}

bool NGfcNurbsSurface::hasCtrlPtCountU()
{
    return ((GfcNurbsSurface*)m_pEntity)->hasCtrlPtCountU();
}

void NGfcNurbsSurface::setCtrlPtCountV(NGfcInteger nValue)
{
    ((GfcNurbsSurface*)m_pEntity)->setCtrlPtCountV(nValue);
}

NGfcInteger NGfcNurbsSurface::getCtrlPtCountV()
{
    return ((GfcNurbsSurface*)m_pEntity)->getCtrlPtCountV();
}

bool NGfcNurbsSurface::hasCtrlPtCountV()
{
    return ((GfcNurbsSurface*)m_pEntity)->hasCtrlPtCountV();
}

int NGfcNurbsSurface::getCtrlPtsCount()
{
    return ((GfcNurbsSurface*)m_pEntity)->getCtrlPtsCount();
}

void NGfcNurbsSurface::clearCtrlPts()
{
    ((GfcNurbsSurface*)m_pEntity)->clearCtrlPts();
}

void NGfcNurbsSurface::addCtrlPts(gfc::engine::EntityRef nValue)
{
    ((GfcNurbsSurface*)m_pEntity)->addCtrlPts(nValue);
}

gfc::engine::EntityRef NGfcNurbsSurface::getCtrlPts(int nIndex)
{
    return ((GfcNurbsSurface*)m_pEntity)->getCtrlPts(nIndex);
}

int NGfcNurbsSurface::getKnotsUCount()
{
    return ((GfcNurbsSurface*)m_pEntity)->getKnotsUCount();
}

void NGfcNurbsSurface::clearKnotsU()
{
    ((GfcNurbsSurface*)m_pEntity)->clearKnotsU();
}

void NGfcNurbsSurface::addKnotsU(NGfcDouble dValue)
{
    ((GfcNurbsSurface*)m_pEntity)->addKnotsU(dValue);
}

NGfcDouble NGfcNurbsSurface::getKnotsU(int nIndex)
{
    return ((GfcNurbsSurface*)m_pEntity)->getKnotsU(nIndex);
}

int NGfcNurbsSurface::getKnotsVCount()
{
    return ((GfcNurbsSurface*)m_pEntity)->getKnotsVCount();
}

void NGfcNurbsSurface::clearKnotsV()
{
    ((GfcNurbsSurface*)m_pEntity)->clearKnotsV();
}

void NGfcNurbsSurface::addKnotsV(NGfcDouble dValue)
{
    ((GfcNurbsSurface*)m_pEntity)->addKnotsV(dValue);
}

NGfcDouble NGfcNurbsSurface::getKnotsV(int nIndex)
{
    return ((GfcNurbsSurface*)m_pEntity)->getKnotsV(nIndex);
}

