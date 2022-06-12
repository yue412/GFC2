#include "NGfcRepresentation.h"

using namespace gfc::classes::x3;

NGfcRepresentation::NGfcRepresentation()
{
    m_pEntity = new GfcRepresentation;
    m_bOwner = true;
}

NGfcRepresentation::NGfcRepresentation(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcEntity(pEntity, bOwner)
{
}

void NGfcRepresentation::setIdentifier(NGfcString sValue)
{
    ((GfcRepresentation*)m_pEntity)->setIdentifier(marshal_as<std::wstring>(sValue));
}

NGfcString NGfcRepresentation::getIdentifier()
{
    return marshal_as<String^>(((GfcRepresentation*)m_pEntity)->getIdentifier());
}

bool NGfcRepresentation::hasIdentifier()
{
    return ((GfcRepresentation*)m_pEntity)->hasIdentifier();
}

int NGfcRepresentation::getitemsCount()
{
    return ((GfcRepresentation*)m_pEntity)->getitemsCount();
}

void NGfcRepresentation::clearitems()
{
    ((GfcRepresentation*)m_pEntity)->clearitems();
}

void NGfcRepresentation::additems(gfc::engine::EntityRef nValue)
{
    ((GfcRepresentation*)m_pEntity)->additems(nValue);
}

gfc::engine::EntityRef NGfcRepresentation::getitems(int nIndex)
{
    return ((GfcRepresentation*)m_pEntity)->getitems(nIndex);
}

