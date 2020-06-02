#include "StdAfx.h"
#include "NGfc2InternalChart.h"
NGfc2InternalChart::NGfc2InternalChart()
{
    m_pEntity = new Gfc2InternalChart;
    m_bOwner = true;
}

NGfc2InternalChart::NGfc2InternalChart(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2InternalChart::setTra1(NGfc2Double dValue)
{
    ((Gfc2InternalChart*)m_pEntity)->setTra1(dValue);
}

NGfc2Double NGfc2InternalChart::getTra1()
{
    return ((Gfc2InternalChart*)m_pEntity)->getTra1();
}

bool NGfc2InternalChart::hasTra1()
{
    return ((Gfc2InternalChart*)m_pEntity)->hasTra1();
}

void NGfc2InternalChart::setTra2(NGfc2Double dValue)
{
    ((Gfc2InternalChart*)m_pEntity)->setTra2(dValue);
}

NGfc2Double NGfc2InternalChart::getTra2()
{
    return ((Gfc2InternalChart*)m_pEntity)->getTra2();
}

bool NGfc2InternalChart::hasTra2()
{
    return ((Gfc2InternalChart*)m_pEntity)->hasTra2();
}

void NGfc2InternalChart::setTra3(NGfc2Double dValue)
{
    ((Gfc2InternalChart*)m_pEntity)->setTra3(dValue);
}

NGfc2Double NGfc2InternalChart::getTra3()
{
    return ((Gfc2InternalChart*)m_pEntity)->getTra3();
}

bool NGfc2InternalChart::hasTra3()
{
    return ((Gfc2InternalChart*)m_pEntity)->hasTra3();
}

int NGfc2InternalChart::getIPSCount()
{
    return ((Gfc2InternalChart*)m_pEntity)->getIPSCount();
}

void NGfc2InternalChart::clearIPS()
{
    ((Gfc2InternalChart*)m_pEntity)->clearIPS();
}

void NGfc2InternalChart::addIPS(gfc2::engine::EntityRef nValue)
{
    ((Gfc2InternalChart*)m_pEntity)->addIPS(nValue);
}

gfc2::engine::EntityRef NGfc2InternalChart::getIPS(int nIndex)
{
    return ((Gfc2InternalChart*)m_pEntity)->getIPS(nIndex);
}

NGfc2InternalPt^ NGfc2InternalChart::getIPSPtr(int nIndex)
{
    return gcnew NGfc2InternalPt(((Gfc2InternalChart*)m_pEntity)->getIPSPtr(nIndex), false);
}

