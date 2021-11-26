#include "NGfc2Element.h"

using namespace gfc::classes::x3;

NGfc2Element::NGfc2Element()
{
    m_pEntity = new Gfc2Element;
    m_bOwner = true;
}

NGfc2Element::NGfc2Element(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Object(pEntity, bOwner)
{
}

void NGfc2Element::setEType(NGfc2Label sValue)
{
    ((Gfc2Element*)m_pEntity)->setEType(marshal_as<std::wstring>(sValue));
}

NGfc2Label NGfc2Element::getEType()
{
    return marshal_as<String^>(((Gfc2Element*)m_pEntity)->getEType());
}

bool NGfc2Element::hasEType()
{
    return ((Gfc2Element*)m_pEntity)->hasEType();
}

int NGfc2Element::getRepresentationsCount()
{
    return ((Gfc2Element*)m_pEntity)->getRepresentationsCount();
}

void NGfc2Element::clearRepresentations()
{
    ((Gfc2Element*)m_pEntity)->clearRepresentations();
}

void NGfc2Element::addRepresentations(gfc::engine::EntityRef nValue)
{
    ((Gfc2Element*)m_pEntity)->addRepresentations(nValue);
}

gfc::engine::EntityRef NGfc2Element::getRepresentations(int nIndex)
{
    return ((Gfc2Element*)m_pEntity)->getRepresentations(nIndex);
}

int NGfc2Element::getShapesCount()
{
    return ((Gfc2Element*)m_pEntity)->getShapesCount();
}

void NGfc2Element::clearShapes()
{
    ((Gfc2Element*)m_pEntity)->clearShapes();
}

void NGfc2Element::addShapes(gfc::engine::EntityRef nValue)
{
    ((Gfc2Element*)m_pEntity)->addShapes(nValue);
}

gfc::engine::EntityRef NGfc2Element::getShapes(int nIndex)
{
    return ((Gfc2Element*)m_pEntity)->getShapes(nIndex);
}

