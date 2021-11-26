#include "NGfc2Body.h"

using namespace gfc::classes::x3;

NGfc2Body::NGfc2Body()
{
    m_pEntity = new Gfc2Body;
    m_bOwner = true;
}

NGfc2Body::NGfc2Body(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfc2Geometry(pEntity, bOwner)
{
}

