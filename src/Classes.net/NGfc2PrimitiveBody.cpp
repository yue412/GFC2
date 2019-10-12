#include "StdAfx.h"
#include "NGfc2PrimitiveBody.h"
NGfc2PrimitiveBody::NGfc2PrimitiveBody()
{
    m_pEntity = new Gfc2PrimitiveBody;
    m_bOwner = true;
}

NGfc2PrimitiveBody::NGfc2PrimitiveBody(void* pEntity, bool bOwner):
    NGfc2Body(pEntity, bOwner)
{
}

