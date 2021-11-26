#include "NGfc2Section.h"

using namespace gfc::classes::x3;

NGfc2Section::NGfc2Section()
{
    m_pEntity = new Gfc2Section;
    m_bOwner = true;
}

NGfc2Section::NGfc2Section(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Root(pEntity, bOwner)
{
}

