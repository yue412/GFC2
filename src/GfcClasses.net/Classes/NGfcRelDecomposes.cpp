#include "NGfcRelDecomposes.h"

using namespace gfc::classes::x3;

NGfcRelDecomposes::NGfcRelDecomposes()
{
    m_pEntity = new GfcRelDecomposes;
    m_bOwner = true;
}

NGfcRelDecomposes::NGfcRelDecomposes(bool bNoCreate):
    NGfcRelationShip(bNoCreate)
{
}

