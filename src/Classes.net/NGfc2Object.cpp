#include "StdAfx.h"
#include "NGfc2Object.h"
NGfc2Object::NGfc2Object()
{
    m_pEntity = new Gfc2Object;
    m_bOwner = true;
}

NGfc2Object::NGfc2Object(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2Object::setID(NGfc2Identity sValue)
{
    ((Gfc2Object*)m_pEntity)->setID(marshal_as<std::string>(sValue));
}

NGfc2Identity NGfc2Object::getID()
{
    return marshal_as<String^>(((Gfc2Object*)m_pEntity)->getID());
}

bool NGfc2Object::hasID()
{
    return ((Gfc2Object*)m_pEntity)->hasID();
}

void NGfc2Object::setName(gfc::engine::EntityRef nValue)
{
    ((Gfc2Object*)m_pEntity)->setName(nValue);
}

gfc::engine::EntityRef NGfc2Object::getName()
{
    return ((Gfc2Object*)m_pEntity)->getName();
}

bool NGfc2Object::hasName()
{
    return ((Gfc2Object*)m_pEntity)->hasName();
}

NGfc2Label^ NGfc2Object::getNamePtr()
{
    return gcnew NGfc2Label(((Gfc2Object*)m_pEntity)->getNamePtr(), false);
}

