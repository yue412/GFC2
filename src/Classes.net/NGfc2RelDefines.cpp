#include "StdAfx.h"
#include "NGfc2RelDefines.h"
NGfc2RelDefines::NGfc2RelDefines()
{
    m_pEntity = new Gfc2RelDefines;
    m_bOwner = true;
}

NGfc2RelDefines::NGfc2RelDefines(void* pEntity, bool bOwner):
    NGfc2RelationShip(pEntity, bOwner)
{
}

int NGfc2RelDefines::getRelatedObjectsCount()
{
    return ((Gfc2RelDefines*)m_pEntity)->getRelatedObjectsCount();
}

void NGfc2RelDefines::clearRelatedObjects()
{
    ((Gfc2RelDefines*)m_pEntity)->clearRelatedObjects();
}

void NGfc2RelDefines::addRelatedObjects(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RelDefines*)m_pEntity)->addRelatedObjects(nValue);
}

glodon::objectbuf::EntityRef NGfc2RelDefines::getRelatedObjects(int nIndex)
{
    return ((Gfc2RelDefines*)m_pEntity)->getRelatedObjects(nIndex);
}

NGfc2Object^ NGfc2RelDefines::getRelatedObjectsPtr(int nIndex)
{
    return gcnew NGfc2Object(((Gfc2RelDefines*)m_pEntity)->getRelatedObjectsPtr(nIndex), false);
}

