#include "NGfc2Matrix.h"

using namespace gfc::classes::x3;

NGfc2Matrix::NGfc2Matrix()
{
    m_pEntity = new Gfc2Matrix;
    m_bOwner = true;
}

NGfc2Matrix::NGfc2Matrix(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

void NGfc2Matrix::setDim(NGfc2Integer nValue)
{
    ((Gfc2Matrix*)m_pEntity)->setDim(nValue);
}

NGfc2Integer NGfc2Matrix::getDim()
{
    return ((Gfc2Matrix*)m_pEntity)->getDim();
}

bool NGfc2Matrix::hasDim()
{
    return ((Gfc2Matrix*)m_pEntity)->hasDim();
}

int NGfc2Matrix::getDataCount()
{
    return ((Gfc2Matrix*)m_pEntity)->getDataCount();
}

void NGfc2Matrix::clearData()
{
    ((Gfc2Matrix*)m_pEntity)->clearData();
}

void NGfc2Matrix::addData(NGfc2Double dValue)
{
    ((Gfc2Matrix*)m_pEntity)->addData(dValue);
}

NGfc2Double NGfc2Matrix::getData(int nIndex)
{
    return ((Gfc2Matrix*)m_pEntity)->getData(nIndex);
}

