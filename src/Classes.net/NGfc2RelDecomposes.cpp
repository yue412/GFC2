#include "StdAfx.h"
#include "NGfc2RelDecomposes.h"
NGfc2RelDecomposes::NGfc2RelDecomposes()
{
    m_pEntity = new Gfc2RelDecomposes;
    m_bOwner = true;
}

NGfc2RelDecomposes::NGfc2RelDecomposes(void* pEntity, bool bOwner):
    NGfc2RelationShip(pEntity, bOwner)
{
}

void NGfc2RelDecomposes::setRelatingObject(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelDecomposes*)m_pEntity)->setRelatingObject(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelDecomposes::getRelatingObject()
{
    return ((Gfc2RelDecomposes*)m_pEntity)->getRelatingObject();
}

bool NGfc2RelDecomposes::hasRelatingObject()
{
    return ((Gfc2RelDecomposes*)m_pEntity)->hasRelatingObject();
}

NGfc2Object^ NGfc2RelDecomposes::getRelatingObjectPtr()
{
    return gcnew NGfc2Object(((Gfc2RelDecomposes*)m_pEntity)->getRelatingObjectPtr(), false);
}

int NGfc2RelDecomposes::getRelatedObjectsCount()
{
    return ((Gfc2RelDecomposes*)m_pEntity)->getRelatedObjectsCount();
}

void NGfc2RelDecomposes::clearRelatedObjects()
{
    ((Gfc2RelDecomposes*)m_pEntity)->clearRelatedObjects();
}

void NGfc2RelDecomposes::addRelatedObjects(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelDecomposes*)m_pEntity)->addRelatedObjects(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelDecomposes::getRelatedObjects(int nIndex)
{
    return ((Gfc2RelDecomposes*)m_pEntity)->getRelatedObjects(nIndex);
}

NGfc2Object^ NGfc2RelDecomposes::getRelatedObjectsPtr(int nIndex)
{
    return gcnew NGfc2Object(((Gfc2RelDecomposes*)m_pEntity)->getRelatedObjectsPtr(nIndex), false);
}

