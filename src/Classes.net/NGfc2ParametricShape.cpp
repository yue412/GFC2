#include "StdAfx.h"
#include "NGfc2ParametricShape.h"
NGfc2ParametricShape::NGfc2ParametricShape()
{
    m_pEntity = new Gfc2ParametricShape;
    m_bOwner = true;
}

NGfc2ParametricShape::NGfc2ParametricShape(void* pEntity, bool bOwner):
    NGfc2Shape(pEntity, bOwner)
{
}

