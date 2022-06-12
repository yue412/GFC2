#include "NGfcMatrix.h"

using namespace gfc::classes::x3;

NGfcMatrix::NGfcMatrix()
{
    m_pEntity = new GfcMatrix;
    m_bOwner = true;
}

NGfcMatrix::NGfcMatrix(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcGeometry(pEntity, bOwner)
{
}

void NGfcMatrix::setDim(NGfcInteger nValue)
{
    ((GfcMatrix*)m_pEntity)->setDim(nValue);
}

NGfcInteger NGfcMatrix::getDim()
{
    return ((GfcMatrix*)m_pEntity)->getDim();
}

bool NGfcMatrix::hasDim()
{
    return ((GfcMatrix*)m_pEntity)->hasDim();
}

int NGfcMatrix::getDataCount()
{
    return ((GfcMatrix*)m_pEntity)->getDataCount();
}

void NGfcMatrix::clearData()
{
    ((GfcMatrix*)m_pEntity)->clearData();
}

void NGfcMatrix::addData(NGfcDouble dValue)
{
    ((GfcMatrix*)m_pEntity)->addData(dValue);
}

NGfcDouble NGfcMatrix::getData(int nIndex)
{
    return ((GfcMatrix*)m_pEntity)->getData(nIndex);
}

