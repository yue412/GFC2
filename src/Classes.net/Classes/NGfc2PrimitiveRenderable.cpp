#include "NGfc2PrimitiveRenderable.h"

using namespace gfc::classes::x3;

NGfc2PrimitiveRenderable::NGfc2PrimitiveRenderable()
{
    m_pEntity = new Gfc2PrimitiveRenderable;
    m_bOwner = true;
}

NGfc2PrimitiveRenderable::NGfc2PrimitiveRenderable(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2RepresentationItem(pEntity, bOwner)
{
}

void NGfc2PrimitiveRenderable::setPrimitiveType(NGfc2PrimitiveType nValue)
{
    ((Gfc2PrimitiveRenderable*)m_pEntity)->setPrimitiveType((Gfc2PrimitiveType)nValue);
}

NGfc2PrimitiveType NGfc2PrimitiveRenderable::getPrimitiveType()
{
    return (NGfc2PrimitiveType)((Gfc2PrimitiveRenderable*)m_pEntity)->getPrimitiveType();
}

bool NGfc2PrimitiveRenderable::hasPrimitiveType()
{
    return ((Gfc2PrimitiveRenderable*)m_pEntity)->hasPrimitiveType();
}

void NGfc2PrimitiveRenderable::setGeometryDataType(NGfc2GeometryDataType nValue)
{
    ((Gfc2PrimitiveRenderable*)m_pEntity)->setGeometryDataType((Gfc2GeometryDataType)nValue);
}

NGfc2GeometryDataType NGfc2PrimitiveRenderable::getGeometryDataType()
{
    return (NGfc2GeometryDataType)((Gfc2PrimitiveRenderable*)m_pEntity)->getGeometryDataType();
}

bool NGfc2PrimitiveRenderable::hasGeometryDataType()
{
    return ((Gfc2PrimitiveRenderable*)m_pEntity)->hasGeometryDataType();
}

void NGfc2PrimitiveRenderable::setExtension(NGfc2String sValue)
{
    ((Gfc2PrimitiveRenderable*)m_pEntity)->setExtension(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2PrimitiveRenderable::getExtension()
{
    return marshal_as<String^>(((Gfc2PrimitiveRenderable*)m_pEntity)->getExtension());
}

bool NGfc2PrimitiveRenderable::hasExtension()
{
    return ((Gfc2PrimitiveRenderable*)m_pEntity)->hasExtension();
}

int NGfc2PrimitiveRenderable::getVertexesCount()
{
    return ((Gfc2PrimitiveRenderable*)m_pEntity)->getVertexesCount();
}

void NGfc2PrimitiveRenderable::clearVertexes()
{
    ((Gfc2PrimitiveRenderable*)m_pEntity)->clearVertexes();
}

void NGfc2PrimitiveRenderable::addVertexes(gfc::engine::EntityRef nValue)
{
    ((Gfc2PrimitiveRenderable*)m_pEntity)->addVertexes(nValue);
}

gfc::engine::EntityRef NGfc2PrimitiveRenderable::getVertexes(int nIndex)
{
    return ((Gfc2PrimitiveRenderable*)m_pEntity)->getVertexes(nIndex);
}

int NGfc2PrimitiveRenderable::getNormalsCount()
{
    return ((Gfc2PrimitiveRenderable*)m_pEntity)->getNormalsCount();
}

void NGfc2PrimitiveRenderable::clearNormals()
{
    ((Gfc2PrimitiveRenderable*)m_pEntity)->clearNormals();
}

void NGfc2PrimitiveRenderable::addNormals(gfc::engine::EntityRef nValue)
{
    ((Gfc2PrimitiveRenderable*)m_pEntity)->addNormals(nValue);
}

gfc::engine::EntityRef NGfc2PrimitiveRenderable::getNormals(int nIndex)
{
    return ((Gfc2PrimitiveRenderable*)m_pEntity)->getNormals(nIndex);
}

int NGfc2PrimitiveRenderable::getIndexesCount()
{
    return ((Gfc2PrimitiveRenderable*)m_pEntity)->getIndexesCount();
}

void NGfc2PrimitiveRenderable::clearIndexes()
{
    ((Gfc2PrimitiveRenderable*)m_pEntity)->clearIndexes();
}

void NGfc2PrimitiveRenderable::addIndexes(NGfc2Integer nValue)
{
    ((Gfc2PrimitiveRenderable*)m_pEntity)->addIndexes(nValue);
}

NGfc2Integer NGfc2PrimitiveRenderable::getIndexes(int nIndex)
{
    return ((Gfc2PrimitiveRenderable*)m_pEntity)->getIndexes(nIndex);
}

