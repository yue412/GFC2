#include "StdAfx.h"
#include "NGfc2SolidShape.h"
NGfc2SolidShape::NGfc2SolidShape()
{
    m_pEntity = new Gfc2SolidShape;
    m_bOwner = true;
}

NGfc2SolidShape::NGfc2SolidShape(void* pEntity, bool bOwner):
    NGfc2Shape3d(pEntity, bOwner)
{
}

void NGfc2SolidShape::setBody(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SolidShape*)m_pEntity)->setBody(nValue);
}

glodon::objectbuf::EntityRef NGfc2SolidShape::getBody()
{
    return ((Gfc2SolidShape*)m_pEntity)->getBody();
}

bool NGfc2SolidShape::hasBody()
{
    return ((Gfc2SolidShape*)m_pEntity)->hasBody();
}

NGfc2Body^ NGfc2SolidShape::getBodyPtr()
{
    return gcnew NGfc2Body(((Gfc2SolidShape*)m_pEntity)->getBodyPtr(), false);
}

int NGfc2SolidShape::getEdgeDatasCount()
{
    return ((Gfc2SolidShape*)m_pEntity)->getEdgeDatasCount();
}

void NGfc2SolidShape::clearEdgeDatas()
{
    ((Gfc2SolidShape*)m_pEntity)->clearEdgeDatas();
}

void NGfc2SolidShape::addEdgeDatas(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2SolidShape*)m_pEntity)->addEdgeDatas(nValue);
}

glodon::objectbuf::EntityRef NGfc2SolidShape::getEdgeDatas(int nIndex)
{
    return ((Gfc2SolidShape*)m_pEntity)->getEdgeDatas(nIndex);
}

NGfc2EdgeData^ NGfc2SolidShape::getEdgeDatasPtr(int nIndex)
{
    return gcnew NGfc2EdgeData(((Gfc2SolidShape*)m_pEntity)->getEdgeDatasPtr(nIndex), false);
}

