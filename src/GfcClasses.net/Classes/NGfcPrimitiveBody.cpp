#include "NGfcPrimitiveBody.h"

using namespace gfc::classes::x3;

NGfcPrimitiveBody::NGfcPrimitiveBody()
{
    m_pEntity = new GfcPrimitiveBody;
    m_bOwner = true;
}

NGfcPrimitiveBody::NGfcPrimitiveBody(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcBody(pEntity, bOwner)
{
}

