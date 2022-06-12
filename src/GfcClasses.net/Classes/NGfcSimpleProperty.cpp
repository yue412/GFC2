#include "NGfcSimpleProperty.h"

using namespace gfc::classes::x3;

NGfcSimpleProperty::NGfcSimpleProperty()
{
    m_pEntity = new GfcSimpleProperty;
    m_bOwner = true;
}

NGfcSimpleProperty::NGfcSimpleProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcProperty(pEntity, bOwner)
{
}

