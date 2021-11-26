#include "NGfc2Intervald.h"

using namespace gfc::classes::x3;

NGfc2Intervald::NGfc2Intervald()
{
    m_pEntity = new Gfc2Intervald;
    m_bOwner = true;
}

NGfc2Intervald::NGfc2Intervald(void* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

void NGfc2Intervald::setMin(NGfc2Double dValue)
{
    ((Gfc2Intervald*)m_pEntity)->setMin(dValue);
}

NGfc2Double NGfc2Intervald::getMin()
{
    return ((Gfc2Intervald*)m_pEntity)->getMin();
}

bool NGfc2Intervald::hasMin()
{
    return ((Gfc2Intervald*)m_pEntity)->hasMin();
}

void NGfc2Intervald::setMax(NGfc2Double dValue)
{
    ((Gfc2Intervald*)m_pEntity)->setMax(dValue);
}

NGfc2Double NGfc2Intervald::getMax()
{
    return ((Gfc2Intervald*)m_pEntity)->getMax();
}

bool NGfc2Intervald::hasMax()
{
    return ((Gfc2Intervald*)m_pEntity)->hasMax();
}

