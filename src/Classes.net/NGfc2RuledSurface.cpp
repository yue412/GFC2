#include "StdAfx.h"
#include "NGfc2RuledSurface.h"
NGfc2RuledSurface::NGfc2RuledSurface()
{
    m_pEntity = new Gfc2RuledSurface;
    m_bOwner = true;
}

NGfc2RuledSurface::NGfc2RuledSurface(void* pEntity, bool bOwner):
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

void NGfc2RuledSurface::setRangeV(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RuledSurface*)m_pEntity)->setRangeV(nValue);
}

glodon::objectbuf::EntityRef NGfc2RuledSurface::getRangeV()
{
    return ((Gfc2RuledSurface*)m_pEntity)->getRangeV();
}

bool NGfc2RuledSurface::hasRangeV()
{
    return ((Gfc2RuledSurface*)m_pEntity)->hasRangeV();
}

NGfc2Intervald^ NGfc2RuledSurface::getRangeVPtr()
{
    return gcnew NGfc2Intervald(((Gfc2RuledSurface*)m_pEntity)->getRangeVPtr(), false);
}

void NGfc2RuledSurface::setRangeU(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RuledSurface*)m_pEntity)->setRangeU(nValue);
}

glodon::objectbuf::EntityRef NGfc2RuledSurface::getRangeU()
{
    return ((Gfc2RuledSurface*)m_pEntity)->getRangeU();
}

bool NGfc2RuledSurface::hasRangeU()
{
    return ((Gfc2RuledSurface*)m_pEntity)->hasRangeU();
}

NGfc2Intervald^ NGfc2RuledSurface::getRangeUPtr()
{
    return gcnew NGfc2Intervald(((Gfc2RuledSurface*)m_pEntity)->getRangeUPtr(), false);
}

void NGfc2RuledSurface::setDirectrix1(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RuledSurface*)m_pEntity)->setDirectrix1(nValue);
}

glodon::objectbuf::EntityRef NGfc2RuledSurface::getDirectrix1()
{
    return ((Gfc2RuledSurface*)m_pEntity)->getDirectrix1();
}

bool NGfc2RuledSurface::hasDirectrix1()
{
    return ((Gfc2RuledSurface*)m_pEntity)->hasDirectrix1();
}

NGfc2Curve3d^ NGfc2RuledSurface::getDirectrix1Ptr()
{
    return gcnew NGfc2Curve3d(((Gfc2RuledSurface*)m_pEntity)->getDirectrix1Ptr(), false);
}

void NGfc2RuledSurface::setDirectrix2(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RuledSurface*)m_pEntity)->setDirectrix2(nValue);
}

glodon::objectbuf::EntityRef NGfc2RuledSurface::getDirectrix2()
{
    return ((Gfc2RuledSurface*)m_pEntity)->getDirectrix2();
}

bool NGfc2RuledSurface::hasDirectrix2()
{
    return ((Gfc2RuledSurface*)m_pEntity)->hasDirectrix2();
}

NGfc2Curve3d^ NGfc2RuledSurface::getDirectrix2Ptr()
{
    return gcnew NGfc2Curve3d(((Gfc2RuledSurface*)m_pEntity)->getDirectrix2Ptr(), false);
}

