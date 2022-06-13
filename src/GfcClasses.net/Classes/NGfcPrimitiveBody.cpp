#include "NGfcPrimitiveBody.h"

using namespace gfc::classes::x3;

NGfcPrimitiveBody::NGfcPrimitiveBody()
{
    m_pEntity = new GfcPrimitiveBody;
    m_bOwner = true;
}

NGfcPrimitiveBody::NGfcPrimitiveBody(bool bNoCreate):
    NGfcBody(bNoCreate)
{
}

