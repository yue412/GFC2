#include "GfcUtils\GfcElementTransformer.h"
#include "GfcUtils\GfcShapeTransformer.h"

GFCENGINE_IMP_FACTORY(GfcElementTransformer, 0)

GfcElementTransformer::GfcElementTransformer()
{
}


GfcElementTransformer::~GfcElementTransformer()
{
}

GFCENGINE_IMP_OBJECT(GfcColumnTransformer, L"Column", 0)

std::shared_ptr<gfc::engine::CEntity> GfcColumnTransformer::transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape)
{
    return pTransformer->toPointShape(pShape);
}

void GfcColumnTransformer::transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity)
{

}
