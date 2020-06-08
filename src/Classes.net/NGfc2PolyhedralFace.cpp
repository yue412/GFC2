#include "StdAfx.h"
#include "NGfc2PolyhedralFace.h"
NGfc2PolyhedralFace::NGfc2PolyhedralFace()
{
    m_pEntity = new Gfc2PolyhedralFace;
    m_bOwner = true;
}

NGfc2PolyhedralFace::NGfc2PolyhedralFace(void* pEntity, bool bOwner):
    NGfc2Topology(pEntity, bOwner)
{
}

int NGfc2PolyhedralFace::getLoopsCount()
{
    return ((Gfc2PolyhedralFace*)m_pEntity)->getLoopsCount();
}

void NGfc2PolyhedralFace::clearLoops()
{
    ((Gfc2PolyhedralFace*)m_pEntity)->clearLoops();
}

void NGfc2PolyhedralFace::addLoops(gfc::engine::EntityRef nValue)
{
    ((Gfc2PolyhedralFace*)m_pEntity)->addLoops(nValue);
}

gfc::engine::EntityRef NGfc2PolyhedralFace::getLoops(int nIndex)
{
    return ((Gfc2PolyhedralFace*)m_pEntity)->getLoops(nIndex);
}

NGfc2PolyhedralLoop^ NGfc2PolyhedralFace::getLoopsPtr(int nIndex)
{
    return gcnew NGfc2PolyhedralLoop(((Gfc2PolyhedralFace*)m_pEntity)->getLoopsPtr(nIndex), false);
}

void NGfc2PolyhedralFace::setPlane(gfc::engine::EntityRef nValue)
{
    ((Gfc2PolyhedralFace*)m_pEntity)->setPlane(nValue);
}

gfc::engine::EntityRef NGfc2PolyhedralFace::getPlane()
{
    return ((Gfc2PolyhedralFace*)m_pEntity)->getPlane();
}

bool NGfc2PolyhedralFace::hasPlane()
{
    return ((Gfc2PolyhedralFace*)m_pEntity)->hasPlane();
}

NGfc2PlaneCoef^ NGfc2PolyhedralFace::getPlanePtr()
{
    return gcnew NGfc2PlaneCoef(((Gfc2PolyhedralFace*)m_pEntity)->getPlanePtr(), false);
}

