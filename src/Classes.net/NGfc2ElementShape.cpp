#include "StdAfx.h"
#include "NGfc2ElementShape.h"
NGfc2ElementShape::NGfc2ElementShape()
{
    m_pEntity = new Gfc2ElementShape;
    m_bOwner = true;
}

NGfc2ElementShape::NGfc2ElementShape(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2ElementShape::setIdentifier(gfc::engine::EntityRef nValue)
{
    ((Gfc2ElementShape*)m_pEntity)->setIdentifier(nValue);
}

gfc::engine::EntityRef NGfc2ElementShape::getIdentifier()
{
    return ((Gfc2ElementShape*)m_pEntity)->getIdentifier();
}

bool NGfc2ElementShape::hasIdentifier()
{
    return ((Gfc2ElementShape*)m_pEntity)->hasIdentifier();
}

NGfc2String^ NGfc2ElementShape::getIdentifierPtr()
{
    return gcnew NGfc2String(((Gfc2ElementShape*)m_pEntity)->getIdentifierPtr(), false);
}

void NGfc2ElementShape::setShape(gfc::engine::EntityRef nValue)
{
    ((Gfc2ElementShape*)m_pEntity)->setShape(nValue);
}

gfc::engine::EntityRef NGfc2ElementShape::getShape()
{
    return ((Gfc2ElementShape*)m_pEntity)->getShape();
}

bool NGfc2ElementShape::hasShape()
{
    return ((Gfc2ElementShape*)m_pEntity)->hasShape();
}

NGfc2Shape^ NGfc2ElementShape::getShapePtr()
{
    return gcnew NGfc2Shape(((Gfc2ElementShape*)m_pEntity)->getShapePtr(), false);
}

