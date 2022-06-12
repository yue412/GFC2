#include "NGfcElement.h"

using namespace gfc::classes::x3;

NGfcElement::NGfcElement()
{
    m_pEntity = new GfcElement;
    m_bOwner = true;
}

NGfcElement::NGfcElement(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcObject(pEntity, bOwner)
{
}

void NGfcElement::setEType(NGfcLabel sValue)
{
    ((GfcElement*)m_pEntity)->setEType(marshal_as<std::wstring>(sValue));
}

NGfcLabel NGfcElement::getEType()
{
    return marshal_as<String^>(((GfcElement*)m_pEntity)->getEType());
}

bool NGfcElement::hasEType()
{
    return ((GfcElement*)m_pEntity)->hasEType();
}

int NGfcElement::getRepresentationsCount()
{
    return ((GfcElement*)m_pEntity)->getRepresentationsCount();
}

void NGfcElement::clearRepresentations()
{
    ((GfcElement*)m_pEntity)->clearRepresentations();
}

void NGfcElement::addRepresentations(gfc::engine::EntityRef nValue)
{
    ((GfcElement*)m_pEntity)->addRepresentations(nValue);
}

gfc::engine::EntityRef NGfcElement::getRepresentations(int nIndex)
{
    return ((GfcElement*)m_pEntity)->getRepresentations(nIndex);
}

int NGfcElement::getShapesCount()
{
    return ((GfcElement*)m_pEntity)->getShapesCount();
}

void NGfcElement::clearShapes()
{
    ((GfcElement*)m_pEntity)->clearShapes();
}

void NGfcElement::addShapes(gfc::engine::EntityRef nValue)
{
    ((GfcElement*)m_pEntity)->addShapes(nValue);
}

gfc::engine::EntityRef NGfcElement::getShapes(int nIndex)
{
    return ((GfcElement*)m_pEntity)->getShapes(nIndex);
}

