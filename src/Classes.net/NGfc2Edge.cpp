#include "StdAfx.h"
#include "NGfc2Edge.h"
NGfc2Edge::NGfc2Edge()
{
    m_pEntity = new Gfc2Edge;
    m_bOwner = true;
}

NGfc2Edge::NGfc2Edge(void* pEntity, bool bOwner):
    NGfc2Topology(pEntity, bOwner)
{
}

void NGfc2Edge::setCurve(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2Edge*)m_pEntity)->setCurve(nValue);
}

glodon::objectbuf::EntityRef NGfc2Edge::getCurve()
{
    return ((Gfc2Edge*)m_pEntity)->getCurve();
}

bool NGfc2Edge::hasCurve()
{
    return ((Gfc2Edge*)m_pEntity)->hasCurve();
}

NGfc2Curve3d^ NGfc2Edge::getCurvePtr()
{
    return gcnew NGfc2Curve3d(((Gfc2Edge*)m_pEntity)->getCurvePtr(), false);
}

void NGfc2Edge::setFaceIndex1(NGfc2Integer nValue)
{
    ((Gfc2Edge*)m_pEntity)->setFaceIndex1(nValue);
}

NGfc2Integer NGfc2Edge::getFaceIndex1()
{
    return ((Gfc2Edge*)m_pEntity)->getFaceIndex1();
}

bool NGfc2Edge::hasFaceIndex1()
{
    return ((Gfc2Edge*)m_pEntity)->hasFaceIndex1();
}

void NGfc2Edge::setFaceIndex2(NGfc2Integer nValue)
{
    ((Gfc2Edge*)m_pEntity)->setFaceIndex2(nValue);
}

NGfc2Integer NGfc2Edge::getFaceIndex2()
{
    return ((Gfc2Edge*)m_pEntity)->getFaceIndex2();
}

bool NGfc2Edge::hasFaceIndex2()
{
    return ((Gfc2Edge*)m_pEntity)->hasFaceIndex2();
}

void NGfc2Edge::setLoopIndex1(NGfc2Integer nValue)
{
    ((Gfc2Edge*)m_pEntity)->setLoopIndex1(nValue);
}

NGfc2Integer NGfc2Edge::getLoopIndex1()
{
    return ((Gfc2Edge*)m_pEntity)->getLoopIndex1();
}

bool NGfc2Edge::hasLoopIndex1()
{
    return ((Gfc2Edge*)m_pEntity)->hasLoopIndex1();
}

void NGfc2Edge::setLoopIndex2(NGfc2Integer nValue)
{
    ((Gfc2Edge*)m_pEntity)->setLoopIndex2(nValue);
}

NGfc2Integer NGfc2Edge::getLoopIndex2()
{
    return ((Gfc2Edge*)m_pEntity)->getLoopIndex2();
}

bool NGfc2Edge::hasLoopIndex2()
{
    return ((Gfc2Edge*)m_pEntity)->hasLoopIndex2();
}

void NGfc2Edge::setCoedgeIndex1(NGfc2Integer nValue)
{
    ((Gfc2Edge*)m_pEntity)->setCoedgeIndex1(nValue);
}

NGfc2Integer NGfc2Edge::getCoedgeIndex1()
{
    return ((Gfc2Edge*)m_pEntity)->getCoedgeIndex1();
}

bool NGfc2Edge::hasCoedgeIndex1()
{
    return ((Gfc2Edge*)m_pEntity)->hasCoedgeIndex1();
}

void NGfc2Edge::setCoedgeIndex2(NGfc2Integer nValue)
{
    ((Gfc2Edge*)m_pEntity)->setCoedgeIndex2(nValue);
}

NGfc2Integer NGfc2Edge::getCoedgeIndex2()
{
    return ((Gfc2Edge*)m_pEntity)->getCoedgeIndex2();
}

bool NGfc2Edge::hasCoedgeIndex2()
{
    return ((Gfc2Edge*)m_pEntity)->hasCoedgeIndex2();
}

