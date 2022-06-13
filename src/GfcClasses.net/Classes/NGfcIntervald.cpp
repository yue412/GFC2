#include "NGfcIntervald.h"

using namespace gfc::classes::x3;

NGfcIntervald::NGfcIntervald()
{
    m_pEntity = new GfcIntervald;
    m_bOwner = true;
}

NGfcIntervald::NGfcIntervald(bool bNoCreate):
    NGfcGeometry(bNoCreate)
{
}

void NGfcIntervald::setMin(NGfcDouble dValue)
{
    ((GfcIntervald*)m_pEntity)->setMin(dValue);
}

NGfcDouble NGfcIntervald::getMin()
{
    return ((GfcIntervald*)m_pEntity)->getMin();
}

bool NGfcIntervald::hasMin()
{
    return ((GfcIntervald*)m_pEntity)->hasMin();
}

void NGfcIntervald::setMax(NGfcDouble dValue)
{
    ((GfcIntervald*)m_pEntity)->setMax(dValue);
}

NGfcDouble NGfcIntervald::getMax()
{
    return ((GfcIntervald*)m_pEntity)->getMax();
}

bool NGfcIntervald::hasMax()
{
    return ((GfcIntervald*)m_pEntity)->hasMax();
}

