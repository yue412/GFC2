#include "StdAfx.h"
#include "NGfc2CoedgeListEx.h"
NGfc2CoedgeListEx::NGfc2CoedgeListEx()
{
    m_pEntity = new Gfc2CoedgeListEx;
    m_bOwner = true;
}

NGfc2CoedgeListEx::NGfc2CoedgeListEx(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

int NGfc2CoedgeListEx::getCoedgeExsCount()
{
    return ((Gfc2CoedgeListEx*)m_pEntity)->getCoedgeExsCount();
}

void NGfc2CoedgeListEx::clearCoedgeExs()
{
    ((Gfc2CoedgeListEx*)m_pEntity)->clearCoedgeExs();
}

void NGfc2CoedgeListEx::addCoedgeExs(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2CoedgeListEx*)m_pEntity)->addCoedgeExs(nValue);
}

glodon::objectbuf::EntityRef NGfc2CoedgeListEx::getCoedgeExs(int nIndex)
{
    return ((Gfc2CoedgeListEx*)m_pEntity)->getCoedgeExs(nIndex);
}

NGfc2Coedge^ NGfc2CoedgeListEx::getCoedgeExsPtr(int nIndex)
{
    return gcnew NGfc2Coedge(((Gfc2CoedgeListEx*)m_pEntity)->getCoedgeExsPtr(nIndex), false);
}

