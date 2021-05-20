#include "GfcUtils\GfcShapeTransformer.h"
#include "GfcUtils\GfcTransform.h"
#include "GfcEngine\EntityUpgrader.h"
#include "GfcEngine\ModelCompatibility.h"
#include "GfcEngine\PropValue.h"

GFCENGINE_IMP_FACTORY(GfcShapeTransformer, 0)

GfcShapeTransformer::GfcShapeTransformer(): m_pOwner(nullptr), m_pShapeCompatibility(nullptr)
{
}


GfcShapeTransformer::~GfcShapeTransformer()
{
}

std::shared_ptr<gfc::engine::CEntity> GfcShapeTransformer::toLineShape(gfc::engine::EntityPtr pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

std::shared_ptr<gfc::engine::CEntity> GfcShapeTransformer::toSectionLineShape(gfc::engine::EntityPtr pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

std::shared_ptr<gfc::engine::CEntity> GfcShapeTransformer::toPointShape(gfc::engine::EntityPtr pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

std::shared_ptr<gfc::engine::CEntity> GfcShapeTransformer::toFaceShape(gfc::engine::EntityPtr pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

std::shared_ptr<gfc::engine::CEntity> GfcShapeTransformer::toSolidShape(gfc::engine::EntityPtr pShape)
{
    return std::shared_ptr<gfc::engine::CEntity>();
}

void GfcShapeTransformer::setOwner(GfcTransform * pOwner)
{
    m_pOwner = pOwner;
    m_pShapeCompatibility = m_pOwner->upgrader()->model()->find(L"Gfc2Shape");
}

void GfcShapeTransformer::assignShapeData(gfc::engine::EntityPtr pSrc, std::shared_ptr<gfc::engine::CEntity> pDest)
{
    m_pOwner->upgrader()->transform(m_pShapeCompatibility, pSrc.get(), pDest.get());
}

GFCENGINE_IMP_OBJECT(Gfc2ManifoldSolidShapeTransformer, L"Gfc2ManifoldSolidShape", 0)

std::shared_ptr<gfc::engine::CEntity> Gfc2ManifoldSolidShapeTransformer::toSolidShape(gfc::engine::EntityPtr pShape)
{
    auto pSolidShape = m_pOwner->createEntity(L"Gfc2SolidShape");
    assert(pSolidShape);
    assignShapeData(pShape, pSolidShape);
    auto nBodyRef = pShape->asEntityRef(L"Body");
    auto nNewBodyRef = m_pOwner->getEntityRef(nBodyRef);
    pSolidShape->setAsEntityRef(L"Body", nNewBodyRef);
    return pSolidShape;
}

