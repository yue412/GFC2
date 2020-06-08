#include "StdAfx.h"
#include "NGfc2SectionProperty.h"
NGfc2SectionProperty::NGfc2SectionProperty()
{
    m_pEntity = new Gfc2SectionProperty;
    m_bOwner = true;
}

NGfc2SectionProperty::NGfc2SectionProperty(void* pEntity, bool bOwner):
    NGfc2SingleProperty(pEntity, bOwner)
{
}

void NGfc2SectionProperty::setSection(gfc::engine::EntityRef nValue)
{
    ((Gfc2SectionProperty*)m_pEntity)->setSection(nValue);
}

gfc::engine::EntityRef NGfc2SectionProperty::getSection()
{
    return ((Gfc2SectionProperty*)m_pEntity)->getSection();
}

bool NGfc2SectionProperty::hasSection()
{
    return ((Gfc2SectionProperty*)m_pEntity)->hasSection();
}

NGfc2Section^ NGfc2SectionProperty::getSectionPtr()
{
    return gcnew NGfc2Section(((Gfc2SectionProperty*)m_pEntity)->getSectionPtr(), false);
}

