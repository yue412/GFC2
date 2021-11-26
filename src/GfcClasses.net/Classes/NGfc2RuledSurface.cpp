#include "NGfc2RuledSurface.h"

using namespace gfc::classes::x3;

NGfc2RuledSurface::NGfc2RuledSurface()
{
    m_pEntity = new Gfc2RuledSurface;
    m_bOwner = true;
}

NGfc2RuledSurface::NGfc2RuledSurface(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Surface(pEntity, bOwner)
{
}

void NGfc2RuledSurface::setApexIndex(NGfc2Integer nValue)
{
    ((Gfc2RuledSurface*)m_pEntity)->setApexIndex(nValue);
}

NGfc2Integer NGfc2RuledSurface::getApexIndex()
{
    return ((Gfc2RuledSurface*)m_pEntity)->getApexIndex();
}

bool NGfc2RuledSurface::hasApexIndex()
{
    return ((Gfc2RuledSurface*)m_pEntity)->hasApexIndex();
}

void NGfc2RuledSurface::setRangeV(gfc::engine::EntityRef nValue)
{
    ((Gfc2RuledSurface*)m_pEntity)->setRangeV(nValue);
}

gfc::engine::EntityRef NGfc2RuledSurface::getRangeV()
{
    return ((Gfc2RuledSurface*)m_pEntity)->getRangeV();
}

bool NGfc2RuledSurface::hasRangeV()
{
    return ((Gfc2RuledSurface*)m_pEntity)->hasRangeV();
}

void NGfc2RuledSurface::setRangeU(gfc::engine::EntityRef nValue)
{
    ((Gfc2RuledSurface*)m_pEntity)->setRangeU(nValue);
}

gfc::engine::EntityRef NGfc2RuledSurface::getRangeU()
{
    return ((Gfc2RuledSurface*)m_pEntity)->getRangeU();
}

bool NGfc2RuledSurface::hasRangeU()
{
    return ((Gfc2RuledSurface*)m_pEntity)->hasRangeU();
}

void NGfc2RuledSurface::setDirectrix1(gfc::engine::EntityRef nValue)
{
    ((Gfc2RuledSurface*)m_pEntity)->setDirectrix1(nValue);
}

gfc::engine::EntityRef NGfc2RuledSurface::getDirectrix1()
{
    return ((Gfc2RuledSurface*)m_pEntity)->getDirectrix1();
}

bool NGfc2RuledSurface::hasDirectrix1()
{
    return ((Gfc2RuledSurface*)m_pEntity)->hasDirectrix1();
}

void NGfc2RuledSurface::setDirectrix2(gfc::engine::EntityRef nValue)
{
    ((Gfc2RuledSurface*)m_pEntity)->setDirectrix2(nValue);
}

gfc::engine::EntityRef NGfc2RuledSurface::getDirectrix2()
{
    return ((Gfc2RuledSurface*)m_pEntity)->getDirectrix2();
}

bool NGfc2RuledSurface::hasDirectrix2()
{
    return ((Gfc2RuledSurface*)m_pEntity)->hasDirectrix2();
}

