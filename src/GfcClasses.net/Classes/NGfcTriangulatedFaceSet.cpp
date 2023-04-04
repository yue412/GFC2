#include "NGfcTriangulatedFaceSet.h"

using namespace gfc::classes::x3;

NGfcTriangulatedFaceSet::NGfcTriangulatedFaceSet()
{
    m_pEntity = new GfcTriangulatedFaceSet;
    m_bOwner = true;
}

NGfcTriangulatedFaceSet::NGfcTriangulatedFaceSet(bool bNoCreate):
    NGfcRepresentationItem(bNoCreate)
{
}

void NGfcTriangulatedFaceSet::setExtension(NGfcString sValue)
{
    ((GfcTriangulatedFaceSet*)m_pEntity)->setExtension(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcTriangulatedFaceSet::getExtension()
{
    return marshal_as<String^>(((GfcTriangulatedFaceSet*)m_pEntity)->getExtension());
}

bool NGfcTriangulatedFaceSet::hasExtension()
{
    return ((GfcTriangulatedFaceSet*)m_pEntity)->hasExtension();
}

int NGfcTriangulatedFaceSet::getVertexesCount()
{
    return ((GfcTriangulatedFaceSet*)m_pEntity)->getVertexesCount();
}

void NGfcTriangulatedFaceSet::clearVertexes()
{
    ((GfcTriangulatedFaceSet*)m_pEntity)->clearVertexes();
}

void NGfcTriangulatedFaceSet::addVertexes(NGfcDouble dValue)
{
    ((GfcTriangulatedFaceSet*)m_pEntity)->addVertexes(dValue);
}

NGfcDouble NGfcTriangulatedFaceSet::getVertexes(int nIndex)
{
    return ((GfcTriangulatedFaceSet*)m_pEntity)->getVertexes(nIndex);
}

int NGfcTriangulatedFaceSet::getNormalsCount()
{
    return ((GfcTriangulatedFaceSet*)m_pEntity)->getNormalsCount();
}

void NGfcTriangulatedFaceSet::clearNormals()
{
    ((GfcTriangulatedFaceSet*)m_pEntity)->clearNormals();
}

void NGfcTriangulatedFaceSet::addNormals(NGfcDouble dValue)
{
    ((GfcTriangulatedFaceSet*)m_pEntity)->addNormals(dValue);
}

NGfcDouble NGfcTriangulatedFaceSet::getNormals(int nIndex)
{
    return ((GfcTriangulatedFaceSet*)m_pEntity)->getNormals(nIndex);
}

int NGfcTriangulatedFaceSet::getVertexIndexCount()
{
    return ((GfcTriangulatedFaceSet*)m_pEntity)->getVertexIndexCount();
}

void NGfcTriangulatedFaceSet::clearVertexIndex()
{
    ((GfcTriangulatedFaceSet*)m_pEntity)->clearVertexIndex();
}

void NGfcTriangulatedFaceSet::addVertexIndex(NGfcInteger nValue)
{
    ((GfcTriangulatedFaceSet*)m_pEntity)->addVertexIndex(nValue);
}

NGfcInteger NGfcTriangulatedFaceSet::getVertexIndex(int nIndex)
{
    return ((GfcTriangulatedFaceSet*)m_pEntity)->getVertexIndex(nIndex);
}

int NGfcTriangulatedFaceSet::getNormalIndexCount()
{
    return ((GfcTriangulatedFaceSet*)m_pEntity)->getNormalIndexCount();
}

void NGfcTriangulatedFaceSet::clearNormalIndex()
{
    ((GfcTriangulatedFaceSet*)m_pEntity)->clearNormalIndex();
}

void NGfcTriangulatedFaceSet::addNormalIndex(NGfcInteger nValue)
{
    ((GfcTriangulatedFaceSet*)m_pEntity)->addNormalIndex(nValue);
}

NGfcInteger NGfcTriangulatedFaceSet::getNormalIndex(int nIndex)
{
    return ((GfcTriangulatedFaceSet*)m_pEntity)->getNormalIndex(nIndex);
}

