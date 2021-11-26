#include "NGfc2Project.h"

using namespace gfc::classes::x3;

NGfc2Project::NGfc2Project()
{
    m_pEntity = new Gfc2Project;
    m_bOwner = true;
}

NGfc2Project::NGfc2Project(void* pEntity, bool bOwner):
    NGfc2Object(pEntity, bOwner)
{
}

