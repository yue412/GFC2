#include "StdAfx.h"
#include "NGfc2Coedge.h"
NGfc2Coedge::NGfc2Coedge()
{
    m_pEntity = new Gfc2Coedge;
    m_bOwner = true;
}

NGfc2Coedge::NGfc2Coedge(void* pEntity, bool bOwner):
    NGfc2Topology(pEntity, bOwner)
{
}

void NGfc2Coedge::setCurve(gfc2::engine::EntityRef nValue)
{
    ((Gfc2Coedge*)m_pEntity)->setCurve(nValue);
}

gfc2::engine::EntityRef NGfc2Coedge::getCurve()
{
    return ((Gfc2Coedge*)m_pEntity)->getCurve();
}

bool NGfc2Coedge::hasCurve()
{
    return ((Gfc2Coedge*)m_pEntity)->hasCurve();
}

NGfc2Curve2d^ NGfc2Coedge::getCurvePtr()
{
    return gcnew NGfc2Curve2d(((Gfc2Coedge*)m_pEntity)->getCurvePtr(), false);
}

void NGfc2Coedge::setEdgeIndex(NGfc2Integer nValue)
{
    ((Gfc2Coedge*)m_pEntity)->setEdgeIndex(nValue);
}

NGfc2Integer NGfc2Coedge::getEdgeIndex()
{
    return ((Gfc2Coedge*)m_pEntity)->getEdgeIndex();
}

bool NGfc2Coedge::hasEdgeIndex()
{
    return ((Gfc2Coedge*)m_pEntity)->hasEdgeIndex();
}

void NGfc2Coedge::setEdgeSameDir(NGfc2Boolean bValue)
{
    ((Gfc2Coedge*)m_pEntity)->setEdgeSameDir(bValue);
}

NGfc2Boolean NGfc2Coedge::getEdgeSameDir()
{
    return ((Gfc2Coedge*)m_pEntity)->getEdgeSameDir();
}

bool NGfc2Coedge::hasEdgeSameDir()
{
    return ((Gfc2Coedge*)m_pEntity)->hasEdgeSameDir();
}

