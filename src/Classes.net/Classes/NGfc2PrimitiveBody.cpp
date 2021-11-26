#include "NGfc2PrimitiveBody.h"

using namespace gfc::classes::x3;

NGfc2PrimitiveBody::NGfc2PrimitiveBody()
{
    m_pEntity = new Gfc2PrimitiveBody;
    m_bOwner = true;
}

NGfc2PrimitiveBody::NGfc2PrimitiveBody(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Body(pEntity, bOwner)
{
}

