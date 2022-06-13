#include "NGfcBody.h"

using namespace gfc::classes::x3;

NGfcBody::NGfcBody()
{
    m_pEntity = new GfcBody;
    m_bOwner = true;
}

NGfcBody::NGfcBody(bool bNoCreate):
    NGfcGeometry(bNoCreate)
{
}

