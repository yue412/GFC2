#include "NGfc2ListProperty.h"

using namespace gfc::classes::x3;

NGfc2ListProperty::NGfc2ListProperty()
{
    m_pEntity = new Gfc2ListProperty;
    m_bOwner = true;
}

NGfc2ListProperty::NGfc2ListProperty(void* pEntity, bool bOwner):
    NGfc2SimpleProperty(pEntity, bOwner)
{
}

