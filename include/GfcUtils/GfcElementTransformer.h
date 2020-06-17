#ifndef GFCELEMENTTRANSFORMER_H
#define GFCELEMENTTRANSFORMER_H

#include "GfcEngine\SysMarco.h"
#include "GfcEngine\Entity.h"
#include <memory>

namespace gfc {
    namespace engine {
        class CEntity;
    }
}

class GfcShapeTransformer;

class GfcElementTransformer : public gfc::engine::CObject
{
    GFCENGINE_DEC_FACTORY(GfcElementTransformer, 0, std::wstring)
public:
    GfcElementTransformer();
    virtual ~GfcElementTransformer();
    virtual std::shared_ptr<gfc::engine::CEntity> transformShape(GfcShapeTransformer* pTransformer, gfc::engine::EntityPtr& pShape) = 0;
    virtual std::wstring elementName() = 0;
    virtual void transformPropertySet(gfc::engine::EntityPtr& pSrcEntity, std::vector<gfc::engine::EntityPtr>& oPropertySetList, std::shared_ptr<gfc::engine::CEntity>& pDestEntity) = 0;
};

#endif // !GFCSHAPETRANSFORMER_H
