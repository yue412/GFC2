#include "NGfcManifoldSolidShape.h"

using namespace gfc::classes::x3;

NGfcManifoldSolidShape::NGfcManifoldSolidShape()
{
    m_pEntity = new GfcManifoldSolidShape;
    m_bOwner = true;
}

NGfcManifoldSolidShape::NGfcManifoldSolidShape(gfc::engine::CEntity* pEntity, bool bOwner):
    NGfcSolidShape(pEntity, bOwner)
{
}

void NGfcManifoldSolidShape::setBody(gfc::engine::EntityRef nValue)
{
    ((GfcManifoldSolidShape*)m_pEntity)->setBody(nValue);
}

gfc::engine::EntityRef NGfcManifoldSolidShape::getBody()
{
    return ((GfcManifoldSolidShape*)m_pEntity)->getBody();
}

bool NGfcManifoldSolidShape::hasBody()
{
    return ((GfcManifoldSolidShape*)m_pEntity)->hasBody();
}

