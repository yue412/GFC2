#include "NGfcRoot.h"

using namespace gfc::classes::x3;

NGfcRoot::NGfcRoot()
{
    m_pEntity = new GfcRoot;
    m_bOwner = true;
}

NGfcRoot::NGfcRoot(bool bNoCreate):
    NEntity(bNoCreate)
{
}

