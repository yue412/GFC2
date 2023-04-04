#include "NGfcElementShape.h"

using namespace gfc::classes::x3;

NGfcElementShape::NGfcElementShape()
{
    m_pEntity = new GfcElementShape;
    m_bOwner = true;
}

NGfcElementShape::NGfcElementShape(bool bNoCreate):
    NGfcRoot(bNoCreate)
{
}

void NGfcElementShape::setIdentifier(NGfcString sValue)
{
    ((GfcElementShape*)m_pEntity)->setIdentifier(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcElementShape::getIdentifier()
{
    return marshal_as<String^>(((GfcElementShape*)m_pEntity)->getIdentifier());
}

bool NGfcElementShape::hasIdentifier()
{
    return ((GfcElementShape*)m_pEntity)->hasIdentifier();
}

void NGfcElementShape::setShape(gfc::engine::EntityRef nValue)
{
    ((GfcElementShape*)m_pEntity)->setShape(nValue);
}

gfc::engine::EntityRef NGfcElementShape::getShape()
{
    return ((GfcElementShape*)m_pEntity)->getShape();
}

bool NGfcElementShape::hasShape()
{
    return ((GfcElementShape*)m_pEntity)->hasShape();
}

