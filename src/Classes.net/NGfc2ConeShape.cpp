#include "NGfc2ConeShape.h"

using namespace gfc::classes::x3;

NGfc2ConeShape::NGfc2ConeShape()
{
    m_pEntity = new Gfc2ConeShape;
    m_bOwner = true;
}

NGfc2ConeShape::NGfc2ConeShape(void* pEntity, bool bOwner):
    NGfc2PrimitiveShape(pEntity, bOwner)
{
}

void NGfc2ConeShape::setHeight(NGfc2Double dValue)
{
    ((Gfc2ConeShape*)m_pEntity)->setHeight(dValue);
}

NGfc2Double NGfc2ConeShape::getHeight()
{
    return ((Gfc2ConeShape*)m_pEntity)->getHeight();
}

bool NGfc2ConeShape::hasHeight()
{
    return ((Gfc2ConeShape*)m_pEntity)->hasHeight();
}

void NGfc2ConeShape::setBottomRadius(NGfc2Double dValue)
{
    ((Gfc2ConeShape*)m_pEntity)->setBottomRadius(dValue);
}

NGfc2Double NGfc2ConeShape::getBottomRadius()
{
    return ((Gfc2ConeShape*)m_pEntity)->getBottomRadius();
}

bool NGfc2ConeShape::hasBottomRadius()
{
    return ((Gfc2ConeShape*)m_pEntity)->hasBottomRadius();
}

