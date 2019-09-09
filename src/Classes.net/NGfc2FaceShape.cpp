#include "StdAfx.h"
#include "NGfc2FaceShape.h"
NGfc2FaceShape::NGfc2FaceShape()
{
    m_pEntity = new Gfc2FaceShape;
    m_bOwner = true;
}

NGfc2FaceShape::NGfc2FaceShape(void* pEntity, bool bOwner):
    NGfc2SolidShape(pEntity, bOwner)
{
}

void NGfc2FaceShape::setThickness(NGfc2Double dValue)
{
    ((Gfc2FaceShape*)m_pEntity)->setThickness(dValue);
}

NGfc2Double NGfc2FaceShape::getThickness()
{
    return ((Gfc2FaceShape*)m_pEntity)->getThickness();
}

bool NGfc2FaceShape::hasThickness()
{
    return ((Gfc2FaceShape*)m_pEntity)->hasThickness();
}

void NGfc2FaceShape::setPoly(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2FaceShape*)m_pEntity)->setPoly(nValue);
}

glodon::objectbuf::EntityRef NGfc2FaceShape::getPoly()
{
    return ((Gfc2FaceShape*)m_pEntity)->getPoly();
}

bool NGfc2FaceShape::hasPoly()
{
    return ((Gfc2FaceShape*)m_pEntity)->hasPoly();
}

NGfc2Polygon^ NGfc2FaceShape::getPolyPtr()
{
    return gcnew NGfc2Polygon(((Gfc2FaceShape*)m_pEntity)->getPolyPtr(), false);
}

void NGfc2FaceShape::setMirrorFlag(NGfc2Boolean bValue)
{
    ((Gfc2FaceShape*)m_pEntity)->setMirrorFlag(bValue);
}

NGfc2Boolean NGfc2FaceShape::getMirrorFlag()
{
    return ((Gfc2FaceShape*)m_pEntity)->getMirrorFlag();
}

bool NGfc2FaceShape::hasMirrorFlag()
{
    return ((Gfc2FaceShape*)m_pEntity)->hasMirrorFlag();
}

void NGfc2FaceShape::setFaceInfo(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2FaceShape*)m_pEntity)->setFaceInfo(nValue);
}

glodon::objectbuf::EntityRef NGfc2FaceShape::getFaceInfo()
{
    return ((Gfc2FaceShape*)m_pEntity)->getFaceInfo();
}

bool NGfc2FaceShape::hasFaceInfo()
{
    return ((Gfc2FaceShape*)m_pEntity)->hasFaceInfo();
}

NGfc2FaceInfo^ NGfc2FaceShape::getFaceInfoPtr()
{
    return gcnew NGfc2FaceInfo(((Gfc2FaceShape*)m_pEntity)->getFaceInfoPtr(), false);
}

