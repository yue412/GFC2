#include "NGfcConeShape.h"

using namespace gfc::classes::x3;

NGfcConeShape::NGfcConeShape()
{
    m_pEntity = new GfcConeShape;
    m_bOwner = true;
}

NGfcConeShape::NGfcConeShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcPrimitiveShape(pEntity, bOwner)
{
}

void NGfcConeShape::setHeight(NGfcDouble dValue)
{
    ((GfcConeShape*)m_pEntity)->setHeight(dValue);
}

NGfcDouble NGfcConeShape::getHeight()
{
    return ((GfcConeShape*)m_pEntity)->getHeight();
}

bool NGfcConeShape::hasHeight()
{
    return ((GfcConeShape*)m_pEntity)->hasHeight();
}

void NGfcConeShape::setBottomRadius(NGfcDouble dValue)
{
    ((GfcConeShape*)m_pEntity)->setBottomRadius(dValue);
}

NGfcDouble NGfcConeShape::getBottomRadius()
{
    return ((GfcConeShape*)m_pEntity)->getBottomRadius();
}

bool NGfcConeShape::hasBottomRadius()
{
    return ((GfcConeShape*)m_pEntity)->hasBottomRadius();
}

