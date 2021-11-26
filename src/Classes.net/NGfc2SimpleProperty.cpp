#include "NGfc2SimpleProperty.h"

using namespace gfc::classes::x3;

NGfc2SimpleProperty::NGfc2SimpleProperty()
{
    m_pEntity = new Gfc2SimpleProperty;
    m_bOwner = true;
}

NGfc2SimpleProperty::NGfc2SimpleProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Property(pEntity, bOwner)
{
}

