#include "NGfcRelDefines.h"

using namespace gfc::classes::x3;

NGfcRelDefines::NGfcRelDefines()
{
    m_pEntity = new GfcRelDefines;
    m_bOwner = true;
}

NGfcRelDefines::NGfcRelDefines(bool bNoCreate):
    NGfcRelationShip(bNoCreate)
{
}

