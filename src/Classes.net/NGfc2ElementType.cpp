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

void NGfc2ElementType::setType(NGfc2Integer nValue)
{
    ((Gfc2ElementType*)m_pEntity)->setType(nValue);
}

NGfc2Integer NGfc2ElementType::getType()
{
    return ((Gfc2ElementType*)m_pEntity)->getType();
}

bool NGfc2ElementType::hasType()
{
    return ((Gfc2ElementType*)m_pEntity)->hasType();
}

