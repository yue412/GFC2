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

void NGfc2ElementType::setEType(NGfc2Label sValue)
{
    ((Gfc2ElementType*)m_pEntity)->setEType(marshal_as<std::string>(sValue));
}

NGfc2Label NGfc2ElementType::getEType()
{
    return marshal_as<String^>(((Gfc2ElementType*)m_pEntity)->getEType());
}

bool NGfc2ElementType::hasEType()
{
    return ((Gfc2ElementType*)m_pEntity)->hasEType();
}

