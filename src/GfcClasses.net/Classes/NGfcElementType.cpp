#include "NGfcElementType.h"

using namespace gfc::classes::x3;

NGfcElementType::NGfcElementType()
{
    m_pEntity = new GfcElementType;
    m_bOwner = true;
}

NGfcElementType::NGfcElementType(bool bNoCreate):
    NGfcObject(bNoCreate)
{
}

void NGfcElementType::setEType(NGfcLabel sValue)
{
    ((GfcElementType*)m_pEntity)->setEType(marshal_as<std::wstring>(sValue));
}

NGfcLabel NGfcElementType::getEType()
{
    return marshal_as<String^>(((GfcElementType*)m_pEntity)->getEType());
}

bool NGfcElementType::hasEType()
{
    return ((GfcElementType*)m_pEntity)->hasEType();
}

