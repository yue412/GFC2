#include "StdAfx.h"
#include "NGfc2FaceShape2d.h"
NGfc2FaceShape2d::NGfc2FaceShape2d()
{
    m_pEntity = new Gfc2FaceShape2d;
    m_bOwner = true;
}

NGfc2FaceShape2d::NGfc2FaceShape2d(void* pEntity, bool bOwner):
    NGfc2Shape2d(pEntity, bOwner)
{
}

void NGfc2FaceShape2d::setPoly(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2FaceShape2d*)m_pEntity)->setPoly(nValue);
}

glodon::objectbuf::EntityRef NGfc2FaceShape2d::getPoly()
{
    return ((Gfc2FaceShape2d*)m_pEntity)->getPoly();
}

bool NGfc2FaceShape2d::hasPoly()
{
    return ((Gfc2FaceShape2d*)m_pEntity)->hasPoly();
}

NGfc2Polygon^ NGfc2FaceShape2d::getPolyPtr()
{
    return gcnew NGfc2Polygon(((Gfc2FaceShape2d*)m_pEntity)->getPolyPtr(), false);
}

