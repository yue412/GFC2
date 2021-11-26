#include "NGfc2Representation.h"

using namespace gfc::classes::x3;

NGfc2Representation::NGfc2Representation()
{
    m_pEntity = new Gfc2Representation;
    m_bOwner = true;
}

NGfc2Representation::NGfc2Representation(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

void NGfc2Representation::setIdentifier(NGfc2String sValue)
{
    ((Gfc2Representation*)m_pEntity)->setIdentifier(marshal_as<std::wstring>(sValue));
}

NGfc2String NGfc2Representation::getIdentifier()
{
    return marshal_as<String^>(((Gfc2Representation*)m_pEntity)->getIdentifier());
}

bool NGfc2Representation::hasIdentifier()
{
    return ((Gfc2Representation*)m_pEntity)->hasIdentifier();
}

int NGfc2Representation::getitemsCount()
{
    return ((Gfc2Representation*)m_pEntity)->getitemsCount();
}

void NGfc2Representation::clearitems()
{
    ((Gfc2Representation*)m_pEntity)->clearitems();
}

void NGfc2Representation::additems(gfc::engine::EntityRef nValue)
{
    ((Gfc2Representation*)m_pEntity)->additems(nValue);
}

gfc::engine::EntityRef NGfc2Representation::getitems(int nIndex)
{
    return ((Gfc2Representation*)m_pEntity)->getitems(nIndex);
}

