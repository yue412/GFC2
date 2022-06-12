#include "NGfcSingleProperty.h"

using namespace gfc::classes::x3;

NGfcSingleProperty::NGfcSingleProperty()
{
    m_pEntity = new GfcSingleProperty;
    m_bOwner = true;
}

NGfcSingleProperty::NGfcSingleProperty(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSimpleProperty(pEntity, bOwner)
{
}

