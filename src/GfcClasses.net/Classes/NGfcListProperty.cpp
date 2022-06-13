#include "NGfcListProperty.h"

using namespace gfc::classes::x3;

NGfcListProperty::NGfcListProperty()
{
    m_pEntity = new GfcListProperty;
    m_bOwner = true;
}

NGfcListProperty::NGfcListProperty(bool bNoCreate):
    NGfcSimpleProperty(bNoCreate)
{
}

