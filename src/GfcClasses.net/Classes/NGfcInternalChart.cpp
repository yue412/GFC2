#include "NGfcInternalChart.h"

using namespace gfc::classes::x3;

NGfcInternalChart::NGfcInternalChart()
{
    m_pEntity = new GfcInternalChart;
    m_bOwner = true;
}

NGfcInternalChart::NGfcInternalChart(bool bNoCreate):
    NEntity(bNoCreate)
{
}

void NGfcInternalChart::setTra1(NGfcDouble dValue)
{
    ((GfcInternalChart*)m_pEntity)->setTra1(dValue);
}

NGfcDouble NGfcInternalChart::getTra1()
{
    return ((GfcInternalChart*)m_pEntity)->getTra1();
}

bool NGfcInternalChart::hasTra1()
{
    return ((GfcInternalChart*)m_pEntity)->hasTra1();
}

void NGfcInternalChart::setTra2(NGfcDouble dValue)
{
    ((GfcInternalChart*)m_pEntity)->setTra2(dValue);
}

NGfcDouble NGfcInternalChart::getTra2()
{
    return ((GfcInternalChart*)m_pEntity)->getTra2();
}

bool NGfcInternalChart::hasTra2()
{
    return ((GfcInternalChart*)m_pEntity)->hasTra2();
}

void NGfcInternalChart::setTra3(NGfcDouble dValue)
{
    ((GfcInternalChart*)m_pEntity)->setTra3(dValue);
}

NGfcDouble NGfcInternalChart::getTra3()
{
    return ((GfcInternalChart*)m_pEntity)->getTra3();
}

bool NGfcInternalChart::hasTra3()
{
    return ((GfcInternalChart*)m_pEntity)->hasTra3();
}

int NGfcInternalChart::getIPSCount()
{
    return ((GfcInternalChart*)m_pEntity)->getIPSCount();
}

void NGfcInternalChart::clearIPS()
{
    ((GfcInternalChart*)m_pEntity)->clearIPS();
}

void NGfcInternalChart::addIPS(gfc::engine::EntityRef nValue)
{
    ((GfcInternalChart*)m_pEntity)->addIPS(nValue);
}

gfc::engine::EntityRef NGfcInternalChart::getIPS(int nIndex)
{
    return ((GfcInternalChart*)m_pEntity)->getIPS(nIndex);
}

