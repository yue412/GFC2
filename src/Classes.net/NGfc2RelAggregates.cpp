#include "StdAfx.h"
#include "NGfc2RelAggregates.h"
NGfc2RelAggregates::NGfc2RelAggregates()
{
    m_pEntity = new Gfc2RelAggregates;
    m_bOwner = true;
}

NGfc2RelAggregates::NGfc2RelAggregates(void* pEntity, bool bOwner):
    NGfc2RelDecomposes(pEntity, bOwner)
{
}

void NGfc2RelAggregates::setRelatingObject(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelAggregates*)m_pEntity)->setRelatingObject(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelAggregates::getRelatingObject()
{
    return ((Gfc2RelAggregates*)m_pEntity)->getRelatingObject();
}

bool NGfc2RelAggregates::hasRelatingObject()
{
    return ((Gfc2RelAggregates*)m_pEntity)->hasRelatingObject();
}

NGfc2Object^ NGfc2RelAggregates::getRelatingObjectPtr()
{
    return gcnew NGfc2Object(((Gfc2RelAggregates*)m_pEntity)->getRelatingObjectPtr(), false);
}

int NGfc2RelAggregates::getRelatedObjectsCount()
{
    return ((Gfc2RelAggregates*)m_pEntity)->getRelatedObjectsCount();
}

void NGfc2RelAggregates::clearRelatedObjects()
{
    ((Gfc2RelAggregates*)m_pEntity)->clearRelatedObjects();
}

void NGfc2RelAggregates::addRelatedObjects(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelAggregates*)m_pEntity)->addRelatedObjects(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelAggregates::getRelatedObjects(int nIndex)
{
    return ((Gfc2RelAggregates*)m_pEntity)->getRelatedObjects(nIndex);
}

NGfc2Object^ NGfc2RelAggregates::getRelatedObjectsPtr(int nIndex)
{
    return gcnew NGfc2Object(((Gfc2RelAggregates*)m_pEntity)->getRelatedObjectsPtr(nIndex), false);
}

