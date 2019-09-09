#include "StdAfx.h"
#include "NGfc2EntityShape.h"
NGfc2EntityShape::NGfc2EntityShape()
{
    m_pEntity = new Gfc2EntityShape;
    m_bOwner = true;
}

NGfc2EntityShape::NGfc2EntityShape(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2EntityShape::setIdentifier(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2EntityShape*)m_pEntity)->setIdentifier(nValue);
}

glodon::objectbuf::EntityRef NGfc2EntityShape::getIdentifier()
{
    return ((Gfc2EntityShape*)m_pEntity)->getIdentifier();
}

bool NGfc2EntityShape::hasIdentifier()
{
    return ((Gfc2EntityShape*)m_pEntity)->hasIdentifier();
}

NGfc2String^ NGfc2EntityShape::getIdentifierPtr()
{
    return gcnew NGfc2String(((Gfc2EntityShape*)m_pEntity)->getIdentifierPtr(), false);
}

void NGfc2EntityShape::setShape(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2EntityShape*)m_pEntity)->setShape(nValue);
}

glodon::objectbuf::EntityRef NGfc2EntityShape::getShape()
{
    return ((Gfc2EntityShape*)m_pEntity)->getShape();
}

bool NGfc2EntityShape::hasShape()
{
    return ((Gfc2EntityShape*)m_pEntity)->hasShape();
}

NGfc2Shape^ NGfc2EntityShape::getShapePtr()
{
    return gcnew NGfc2Shape(((Gfc2EntityShape*)m_pEntity)->getShapePtr(), false);
}

