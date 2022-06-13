#include "NGfcSimpleProperty.h"

using namespace gfc::classes::x3;

NGfcSimpleProperty::NGfcSimpleProperty()
{
    m_pEntity = new GfcSimpleProperty;
    m_bOwner = true;
}

NGfcSimpleProperty::NGfcSimpleProperty(bool bNoCreate):
    NGfcProperty(bNoCreate)
{
}

