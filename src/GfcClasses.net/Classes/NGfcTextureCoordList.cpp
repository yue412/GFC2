#include "NGfcTextureCoordList.h"

using namespace gfc::classes::x3;

NGfcTextureCoordList::NGfcTextureCoordList()
{
    m_pEntity = new GfcTextureCoordList;
    m_bOwner = true;
}

NGfcTextureCoordList::NGfcTextureCoordList(bool bNoCreate):
    NGfcRoot(bNoCreate)
{
}

int NGfcTextureCoordList::getTexCoordsCount()
{
    return ((GfcTextureCoordList*)m_pEntity)->getTexCoordsCount();
}

void NGfcTextureCoordList::clearTexCoords()
{
    ((GfcTextureCoordList*)m_pEntity)->clearTexCoords();
}

void NGfcTextureCoordList::addTexCoords(NGfcDouble dValue)
{
    ((GfcTextureCoordList*)m_pEntity)->addTexCoords(dValue);
}

NGfcDouble NGfcTextureCoordList::getTexCoords(int nIndex)
{
    return ((GfcTextureCoordList*)m_pEntity)->getTexCoords(nIndex);
}

int NGfcTextureCoordList::getTexCoordIndexCount()
{
    return ((GfcTextureCoordList*)m_pEntity)->getTexCoordIndexCount();
}

void NGfcTextureCoordList::clearTexCoordIndex()
{
    ((GfcTextureCoordList*)m_pEntity)->clearTexCoordIndex();
}

void NGfcTextureCoordList::addTexCoordIndex(NGfcInteger nValue)
{
    ((GfcTextureCoordList*)m_pEntity)->addTexCoordIndex(nValue);
}

NGfcInteger NGfcTextureCoordList::getTexCoordIndex(int nIndex)
{
    return ((GfcTextureCoordList*)m_pEntity)->getTexCoordIndex(nIndex);
}

