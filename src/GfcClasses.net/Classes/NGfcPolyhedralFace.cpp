#include "NGfcPolyhedralFace.h"

using namespace gfc::classes::x3;

NGfcPolyhedralFace::NGfcPolyhedralFace()
{
    m_pEntity = new GfcPolyhedralFace;
    m_bOwner = true;
}

NGfcPolyhedralFace::NGfcPolyhedralFace(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcTopology(pEntity, bOwner)
{
}

int NGfcPolyhedralFace::getLoopsCount()
{
    return ((GfcPolyhedralFace*)m_pEntity)->getLoopsCount();
}

void NGfcPolyhedralFace::clearLoops()
{
    ((GfcPolyhedralFace*)m_pEntity)->clearLoops();
}

void NGfcPolyhedralFace::addLoops(gfc::engine::EntityRef nValue)
{
    ((GfcPolyhedralFace*)m_pEntity)->addLoops(nValue);
}

gfc::engine::EntityRef NGfcPolyhedralFace::getLoops(int nIndex)
{
    return ((GfcPolyhedralFace*)m_pEntity)->getLoops(nIndex);
}

void NGfcPolyhedralFace::setPlane(gfc::engine::EntityRef nValue)
{
    ((GfcPolyhedralFace*)m_pEntity)->setPlane(nValue);
}

gfc::engine::EntityRef NGfcPolyhedralFace::getPlane()
{
    return ((GfcPolyhedralFace*)m_pEntity)->getPlane();
}

bool NGfcPolyhedralFace::hasPlane()
{
    return ((GfcPolyhedralFace*)m_pEntity)->hasPlane();
}

