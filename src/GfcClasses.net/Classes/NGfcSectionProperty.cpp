#include "NGfcSectionProperty.h"

using namespace gfc::classes::x3;

NGfcSectionProperty::NGfcSectionProperty()
{
    m_pEntity = new GfcSectionProperty;
    m_bOwner = true;
}

NGfcSectionProperty::NGfcSectionProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSingleProperty(pEntity, bOwner)
{
}

void NGfcSectionProperty::setSection(gfc::engine::EntityRef nValue)
{
    ((GfcSectionProperty*)m_pEntity)->setSection(nValue);
}

gfc::engine::EntityRef NGfcSectionProperty::getSection()
{
    return ((GfcSectionProperty*)m_pEntity)->getSection();
}

bool NGfcSectionProperty::hasSection()
{
    return ((GfcSectionProperty*)m_pEntity)->hasSection();
}

