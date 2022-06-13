#include "NGfcEdge.h"

using namespace gfc::classes::x3;

NGfcEdge::NGfcEdge()
{
    m_pEntity = new GfcEdge;
    m_bOwner = true;
}

NGfcEdge::NGfcEdge(bool bNoCreate):
    NGfcTopology(bNoCreate)
{
}

void NGfcEdge::setCurve(gfc::engine::EntityRef nValue)
{
    ((GfcEdge*)m_pEntity)->setCurve(nValue);
}

gfc::engine::EntityRef NGfcEdge::getCurve()
{
    return ((GfcEdge*)m_pEntity)->getCurve();
}

bool NGfcEdge::hasCurve()
{
    return ((GfcEdge*)m_pEntity)->hasCurve();
}

void NGfcEdge::setFaceIndex1(NGfcInteger nValue)
{
    ((GfcEdge*)m_pEntity)->setFaceIndex1(nValue);
}

NGfcInteger NGfcEdge::getFaceIndex1()
{
    return ((GfcEdge*)m_pEntity)->getFaceIndex1();
}

bool NGfcEdge::hasFaceIndex1()
{
    return ((GfcEdge*)m_pEntity)->hasFaceIndex1();
}

void NGfcEdge::setFaceIndex2(NGfcInteger nValue)
{
    ((GfcEdge*)m_pEntity)->setFaceIndex2(nValue);
}

NGfcInteger NGfcEdge::getFaceIndex2()
{
    return ((GfcEdge*)m_pEntity)->getFaceIndex2();
}

bool NGfcEdge::hasFaceIndex2()
{
    return ((GfcEdge*)m_pEntity)->hasFaceIndex2();
}

void NGfcEdge::setLoopIndex1(NGfcInteger nValue)
{
    ((GfcEdge*)m_pEntity)->setLoopIndex1(nValue);
}

NGfcInteger NGfcEdge::getLoopIndex1()
{
    return ((GfcEdge*)m_pEntity)->getLoopIndex1();
}

bool NGfcEdge::hasLoopIndex1()
{
    return ((GfcEdge*)m_pEntity)->hasLoopIndex1();
}

void NGfcEdge::setLoopIndex2(NGfcInteger nValue)
{
    ((GfcEdge*)m_pEntity)->setLoopIndex2(nValue);
}

NGfcInteger NGfcEdge::getLoopIndex2()
{
    return ((GfcEdge*)m_pEntity)->getLoopIndex2();
}

bool NGfcEdge::hasLoopIndex2()
{
    return ((GfcEdge*)m_pEntity)->hasLoopIndex2();
}

void NGfcEdge::setCoedgeIndex1(NGfcInteger nValue)
{
    ((GfcEdge*)m_pEntity)->setCoedgeIndex1(nValue);
}

NGfcInteger NGfcEdge::getCoedgeIndex1()
{
    return ((GfcEdge*)m_pEntity)->getCoedgeIndex1();
}

bool NGfcEdge::hasCoedgeIndex1()
{
    return ((GfcEdge*)m_pEntity)->hasCoedgeIndex1();
}

void NGfcEdge::setCoedgeIndex2(NGfcInteger nValue)
{
    ((GfcEdge*)m_pEntity)->setCoedgeIndex2(nValue);
}

NGfcInteger NGfcEdge::getCoedgeIndex2()
{
    return ((GfcEdge*)m_pEntity)->getCoedgeIndex2();
}

bool NGfcEdge::hasCoedgeIndex2()
{
    return ((GfcEdge*)m_pEntity)->hasCoedgeIndex2();
}

