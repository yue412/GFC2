#include "NGfcSection.h"

using namespace gfc::classes::x3;

NGfcSection::NGfcSection()
{
    m_pEntity = new GfcSection;
    m_bOwner = true;
}

NGfcSection::NGfcSection(bool bNoCreate):
    NGfcRoot(bNoCreate)
{
}

