#ifndef GFCSHAPETRANSFORMER_H
#define GFCSHAPETRANSFORMER_H

#include "GfcEngine\SysMarco.h"
#include "GfcEngine\Entity.h"
#include <memory>

namespace gfc {
    namespace engine {
        class CEntity;
    }
}

class GfcShapeTransformer : public gfc::engine::CObject
{
    GFCENGINE_DEC_FACTORY(GfcShapeTransformer, 0, std::wstring)
public:
    GfcShapeTransformer();
    virtual ~GfcShapeTransformer();
    virtual std::shared_ptr<gfc::engine::CEntity> toLineShape(gfc::engine::EntityPtr pShape) = 0;
    virtual std::shared_ptr<gfc::engine::CEntity> toSectionLineShape(gfc::engine::EntityPtr pShape) = 0;
    virtual std::shared_ptr<gfc::engine::CEntity> toPointShape(gfc::engine::EntityPtr pShape) = 0;
    virtual std::shared_ptr<gfc::engine::CEntity> toFaceShape(gfc::engine::EntityPtr pShape) = 0;
    virtual std::shared_ptr<gfc::engine::CEntity> toSolidShape(gfc::engine::EntityPtr pShape) = 0;
};

#endif // !GFCSHAPETRANSFORMER_H
