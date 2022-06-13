#include "NGfcRelConnects.h"

using namespace gfc::classes::x3;

NGfcRelConnects::NGfcRelConnects()
{
    m_pEntity = new GfcRelConnects;
    m_bOwner = true;
}

NGfcRelConnects::NGfcRelConnects(bool bNoCreate):
    NGfcRelationShip(bNoCreate)
{
}

