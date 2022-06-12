#include "NGfcPrimitiveRenderable.h"

using namespace gfc::classes::x3;

NGfcPrimitiveRenderable::NGfcPrimitiveRenderable()
{
    m_pEntity = new GfcPrimitiveRenderable;
    m_bOwner = true;
}

NGfcPrimitiveRenderable::NGfcPrimitiveRenderable(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcRepresentationItem(pEntity, bOwner)
{
}

void NGfcPrimitiveRenderable::setPrimitiveType(NGfcPrimitiveType nValue)
{
    ((GfcPrimitiveRenderable*)m_pEntity)->setPrimitiveType((GfcPrimitiveType)nValue);
}

NGfcPrimitiveType NGfcPrimitiveRenderable::getPrimitiveType()
{
    return (NGfcPrimitiveType)((GfcPrimitiveRenderable*)m_pEntity)->getPrimitiveType();
}

bool NGfcPrimitiveRenderable::hasPrimitiveType()
{
    return ((GfcPrimitiveRenderable*)m_pEntity)->hasPrimitiveType();
}

void NGfcPrimitiveRenderable::setGeometryDataType(NGfcGeometryDataType nValue)
{
    ((GfcPrimitiveRenderable*)m_pEntity)->setGeometryDataType((GfcGeometryDataType)nValue);
}

NGfcGeometryDataType NGfcPrimitiveRenderable::getGeometryDataType()
{
    return (NGfcGeometryDataType)((GfcPrimitiveRenderable*)m_pEntity)->getGeometryDataType();
}

bool NGfcPrimitiveRenderable::hasGeometryDataType()
{
    return ((GfcPrimitiveRenderable*)m_pEntity)->hasGeometryDataType();
}

void NGfcPrimitiveRenderable::setExtension(NGfcString sValue)
{
    ((GfcPrimitiveRenderable*)m_pEntity)->setExtension(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcPrimitiveRenderable::getExtension()
{
    return marshal_as<String^>(((GfcPrimitiveRenderable*)m_pEntity)->getExtension());
}

bool NGfcPrimitiveRenderable::hasExtension()
{
    return ((GfcPrimitiveRenderable*)m_pEntity)->hasExtension();
}

int NGfcPrimitiveRenderable::getVertexesCount()
{
    return ((GfcPrimitiveRenderable*)m_pEntity)->getVertexesCount();
}

void NGfcPrimitiveRenderable::clearVertexes()
{
    ((GfcPrimitiveRenderable*)m_pEntity)->clearVertexes();
}

void NGfcPrimitiveRenderable::addVertexes(gfc::engine::EntityRef nValue)
{
    ((GfcPrimitiveRenderable*)m_pEntity)->addVertexes(nValue);
}

gfc::engine::EntityRef NGfcPrimitiveRenderable::getVertexes(int nIndex)
{
    return ((GfcPrimitiveRenderable*)m_pEntity)->getVertexes(nIndex);
}

int NGfcPrimitiveRenderable::getNormalsCount()
{
    return ((GfcPrimitiveRenderable*)m_pEntity)->getNormalsCount();
}

void NGfcPrimitiveRenderable::clearNormals()
{
    ((GfcPrimitiveRenderable*)m_pEntity)->clearNormals();
}

void NGfcPrimitiveRenderable::addNormals(gfc::engine::EntityRef nValue)
{
    ((GfcPrimitiveRenderable*)m_pEntity)->addNormals(nValue);
}

gfc::engine::EntityRef NGfcPrimitiveRenderable::getNormals(int nIndex)
{
    return ((GfcPrimitiveRenderable*)m_pEntity)->getNormals(nIndex);
}

int NGfcPrimitiveRenderable::getIndexesCount()
{
    return ((GfcPrimitiveRenderable*)m_pEntity)->getIndexesCount();
}

void NGfcPrimitiveRenderable::clearIndexes()
{
    ((GfcPrimitiveRenderable*)m_pEntity)->clearIndexes();
}

void NGfcPrimitiveRenderable::addIndexes(NGfcInteger nValue)
{
    ((GfcPrimitiveRenderable*)m_pEntity)->addIndexes(nValue);
}

NGfcInteger NGfcPrimitiveRenderable::getIndexes(int nIndex)
{
    return ((GfcPrimitiveRenderable*)m_pEntity)->getIndexes(nIndex);
}

