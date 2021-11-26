#include "NGfc2PolyhedralFace.h"

using namespace gfc::classes::x3;

NGfc2PolyhedralFace::NGfc2PolyhedralFace()
{
    m_pEntity = new Gfc2PolyhedralFace;
    m_bOwner = true;
}

NGfc2PolyhedralFace::NGfc2PolyhedralFace(gfc::engine::CEntity* pEntity, bool bOwner):
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

