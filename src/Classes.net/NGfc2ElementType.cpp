#include "StdAfx.h"
#include "NGfc2ElementType.h"
NGfc2ElementType::NGfc2ElementType()
{
    m_pEntity = new Gfc2ElementType;
    m_bOwner = true;
}

NGfc2ElementType::NGfc2ElementType(void* pEntity, bool bOwner):
    NGfc2Object(pEntity, bOwner)
{
}

void NGfc2ElementType::setType(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ElementType*)m_pEntity)->setType(nValue);
}

gfc2::engine::EntityRef NGfc2ElementType::getType()
{
    return ((Gfc2ElementType*)m_pEntity)->getType();
}

bool NGfc2ElementType::hasType()
{
    return ((Gfc2ElementType*)m_pEntity)->hasType();
}

NGfc2Label^ NGfc2ElementType::getTypePtr()
{
    return gcnew NGfc2Label(((Gfc2ElementType*)m_pEntity)->getTypePtr(), false);
}

