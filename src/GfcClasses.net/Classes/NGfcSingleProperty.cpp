#include "NGfcSingleProperty.h"

using namespace gfc::classes::x3;

NGfcSingleProperty::NGfcSingleProperty()
{
    m_pEntity = new GfcSingleProperty;
    m_bOwner = true;
}

NGfcSingleProperty::NGfcSingleProperty(bool bNoCreate):
    NGfcSimpleProperty(bNoCreate)
{
}

