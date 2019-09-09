#include "StdAfx.h"
#include "NGfc2ParallelAssitAxis.h"
NGfc2ParallelAssitAxis::NGfc2ParallelAssitAxis()
{
    m_pEntity = new Gfc2ParallelAssitAxis;
    m_bOwner = true;
}

NGfc2ParallelAssitAxis::NGfc2ParallelAssitAxis(void* pEntity, bool bOwner):
    NGfc2AssitAxis(pEntity, bOwner)
{
}

void NGfc2ParallelAssitAxis::setRefAxisNo(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2ParallelAssitAxis*)m_pEntity)->setRefAxisNo(nValue);
}

glodon::objectbuf::EntityRef NGfc2ParallelAssitAxis::getRefAxisNo()
{
    return ((Gfc2ParallelAssitAxis*)m_pEntity)->getRefAxisNo();
}

bool NGfc2ParallelAssitAxis::hasRefAxisNo()
{
    return ((Gfc2ParallelAssitAxis*)m_pEntity)->hasRefAxisNo();
}

NGfc2Label^ NGfc2ParallelAssitAxis::getRefAxisNoPtr()
{
    return gcnew NGfc2Label(((Gfc2ParallelAssitAxis*)m_pEntity)->getRefAxisNoPtr(), false);
}

void NGfc2ParallelAssitAxis::setOffset(NGfc2Double dValue)
{
    ((Gfc2ParallelAssitAxis*)m_pEntity)->setOffset(dValue);
}

NGfc2Double NGfc2ParallelAssitAxis::getOffset()
{
    return ((Gfc2ParallelAssitAxis*)m_pEntity)->getOffset();
}

bool NGfc2ParallelAssitAxis::hasOffset()
{
    return ((Gfc2ParallelAssitAxis*)m_pEntity)->hasOffset();
}

void NGfc2ParallelAssitAxis::setRefAxisIndex(NGfc2Integer nValue)
{
    ((Gfc2ParallelAssitAxis*)m_pEntity)->setRefAxisIndex(nValue);
}

NGfc2Integer NGfc2ParallelAssitAxis::getRefAxisIndex()
{
    return ((Gfc2ParallelAssitAxis*)m_pEntity)->getRefAxisIndex();
}

bool NGfc2ParallelAssitAxis::hasRefAxisIndex()
{
    return ((Gfc2ParallelAssitAxis*)m_pEntity)->hasRefAxisIndex();
}

void NGfc2ParallelAssitAxis::setRefAxisType(NGfc2AxisType nValue)
{
    ((Gfc2ParallelAssitAxis*)m_pEntity)->setRefAxisType((Gfc2AxisType)nValue);
}

NGfc2AxisType NGfc2ParallelAssitAxis::getRefAxisType()
{
    return (NGfc2AxisType)((Gfc2ParallelAssitAxis*)m_pEntity)->getRefAxisType();
}

bool NGfc2ParallelAssitAxis::hasRefAxisType()
{
    return ((Gfc2ParallelAssitAxis*)m_pEntity)->hasRefAxisType();
}

