#include "StdAfx.h"
#include "NGfc2SolidShape.h"
NGfc2SolidShape::NGfc2SolidShape()
{
    m_pEntity = new Gfc2SolidShape;
    m_bOwner = true;
}

NGfc2SolidShape::NGfc2SolidShape(void* pEntity, bool bOwner):
    NGfc2ParametricShape(pEntity, bOwner)
{
}

