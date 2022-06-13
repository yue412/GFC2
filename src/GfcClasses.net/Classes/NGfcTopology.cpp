#include "NGfcTopology.h"

using namespace gfc::classes::x3;

NGfcTopology::NGfcTopology()
{
    m_pEntity = new GfcTopology;
    m_bOwner = true;
}

NGfcTopology::NGfcTopology(bool bNoCreate):
    NGfcGeometry(bNoCreate)
{
}

