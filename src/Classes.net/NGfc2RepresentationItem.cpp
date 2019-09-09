#include "StdAfx.h"
#include "NGfc2RepresentationItem.h"
NGfc2RepresentationItem::NGfc2RepresentationItem()
{
    m_pEntity = new Gfc2RepresentationItem;
    m_bOwner = true;
}

NGfc2RepresentationItem::NGfc2RepresentationItem(void* pEntity, bool bOwner):
    glodon::objectbufnet::Entity(pEntity, bOwner)
{
}

void NGfc2RepresentationItem::setPrimitiveType(NGfc2PrimitiveType nValue)
{
    ((Gfc2RepresentationItem*)m_pEntity)->setPrimitiveType((Gfc2PrimitiveType)nValue);
}

NGfc2PrimitiveType NGfc2RepresentationItem::getPrimitiveType()
{
    return (NGfc2PrimitiveType)((Gfc2RepresentationItem*)m_pEntity)->getPrimitiveType();
}

bool NGfc2RepresentationItem::hasPrimitiveType()
{
    return ((Gfc2RepresentationItem*)m_pEntity)->hasPrimitiveType();
}

void NGfc2RepresentationItem::setGeometryDataType(NGfc2GeometryDataType nValue)
{
    ((Gfc2RepresentationItem*)m_pEntity)->setGeometryDataType((Gfc2GeometryDataType)nValue);
}

NGfc2GeometryDataType NGfc2RepresentationItem::getGeometryDataType()
{
    return (NGfc2GeometryDataType)((Gfc2RepresentationItem*)m_pEntity)->getGeometryDataType();
}

bool NGfc2RepresentationItem::hasGeometryDataType()
{
    return ((Gfc2RepresentationItem*)m_pEntity)->hasGeometryDataType();
}

int NGfc2RepresentationItem::getVertexesCount()
{
    return ((Gfc2RepresentationItem*)m_pEntity)->getVertexesCount();
}

void NGfc2RepresentationItem::clearVertexes()
{
    ((Gfc2RepresentationItem*)m_pEntity)->clearVertexes();
}

void NGfc2RepresentationItem::addVertexes(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RepresentationItem*)m_pEntity)->addVertexes(nValue);
}

glodon::objectbuf::EntityRef NGfc2RepresentationItem::getVertexes(int nIndex)
{
    return ((Gfc2RepresentationItem*)m_pEntity)->getVertexes(nIndex);
}

NGfc2Vector3d^ NGfc2RepresentationItem::getVertexesPtr(int nIndex)
{
    return gcnew NGfc2Vector3d(((Gfc2RepresentationItem*)m_pEntity)->getVertexesPtr(nIndex), false);
}

int NGfc2RepresentationItem::getNormalsCount()
{
    return ((Gfc2RepresentationItem*)m_pEntity)->getNormalsCount();
}

void NGfc2RepresentationItem::clearNormals()
{
    ((Gfc2RepresentationItem*)m_pEntity)->clearNormals();
}

void NGfc2RepresentationItem::addNormals(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RepresentationItem*)m_pEntity)->addNormals(nValue);
}

glodon::objectbuf::EntityRef NGfc2RepresentationItem::getNormals(int nIndex)
{
    return ((Gfc2RepresentationItem*)m_pEntity)->getNormals(nIndex);
}

NGfc2Vector3d^ NGfc2RepresentationItem::getNormalsPtr(int nIndex)
{
    return gcnew NGfc2Vector3d(((Gfc2RepresentationItem*)m_pEntity)->getNormalsPtr(nIndex), false);
}

int NGfc2RepresentationItem::getIndexesCount()
{
    return ((Gfc2RepresentationItem*)m_pEntity)->getIndexesCount();
}

void NGfc2RepresentationItem::clearIndexes()
{
    ((Gfc2RepresentationItem*)m_pEntity)->clearIndexes();
}

void NGfc2RepresentationItem::addIndexes(NGfc2Integer nValue)
{
    ((Gfc2RepresentationItem*)m_pEntity)->addIndexes(nValue);
}

NGfc2Integer NGfc2RepresentationItem::getIndexes(int nIndex)
{
    return ((Gfc2RepresentationItem*)m_pEntity)->getIndexes(nIndex);
}

void NGfc2RepresentationItem::setStateSet(glodon::objectbuf::EntityRef nValue)
{
    ((Gfc2RepresentationItem*)m_pEntity)->setStateSet(nValue);
}

glodon::objectbuf::EntityRef NGfc2RepresentationItem::getStateSet()
{
    return ((Gfc2RepresentationItem*)m_pEntity)->getStateSet();
}

bool NGfc2RepresentationItem::hasStateSet()
{
    return ((Gfc2RepresentationItem*)m_pEntity)->hasStateSet();
}

NGfc2StateSet^ NGfc2RepresentationItem::getStateSetPtr()
{
    return gcnew NGfc2StateSet(((Gfc2RepresentationItem*)m_pEntity)->getStateSetPtr(), false);
}

