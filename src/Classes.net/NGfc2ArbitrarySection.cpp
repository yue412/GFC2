#include "StdAfx.h"
#include "NGfc2ArbitrarySection.h"
NGfc2ArbitrarySection::NGfc2ArbitrarySection()
{
    m_pEntity = new Gfc2ArbitrarySection;
    m_bOwner = true;
}

NGfc2ArbitrarySection::NGfc2ArbitrarySection(void* pEntity, bool bOwner):
    NGfc2Section(pEntity, bOwner)
{
}

void NGfc2ArbitrarySection::setPoly(gfc2::engine::EntityRef nValue)
{
    ((Gfc2ArbitrarySection*)m_pEntity)->setPoly(nValue);
}

gfc2::engine::EntityRef NGfc2ArbitrarySection::getPoly()
{
    return ((Gfc2ArbitrarySection*)m_pEntity)->getPoly();
}

bool NGfc2ArbitrarySection::hasPoly()
{
    return ((Gfc2ArbitrarySection*)m_pEntity)->hasPoly();
}

NGfc2Polygon^ NGfc2ArbitrarySection::getPolyPtr()
{
    return gcnew NGfc2Polygon(((Gfc2ArbitrarySection*)m_pEntity)->getPolyPtr(), false);
}

