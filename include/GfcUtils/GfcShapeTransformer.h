#ifndef GFCSHAPETRANSFORMER_H
#define GFCSHAPETRANSFORMER_H

#include "GfcEngine\SysMarco.h"
#include "GfcEngine\Entity.h"
#include <memory>

namespace gfc {
    namespace engine {
        class CEntity;
        class CClassCompatibility;
    }
}

class GfcTransform;

class GfcShapeTransformer : public gfc::engine::CObject
{
    GFCENGINE_DEC_FACTORY(GfcShapeTransformer, 0, std::wstring)
public:
    GfcShapeTransformer();
    virtual ~GfcShapeTransformer();
    virtual std::shared_ptr<gfc::engine::CEntity> toLineShape(gfc::engine::EntityPtr pShape);
    virtual std::shared_ptr<gfc::engine::CEntity> toSectionLineShape(gfc::engine::EntityPtr pShape);
    virtual std::shared_ptr<gfc::engine::CEntity> toPointShape(gfc::engine::EntityPtr pShape);
    virtual std::shared_ptr<gfc::engine::CEntity> toFaceShape(gfc::engine::EntityPtr pShape);
    virtual std::shared_ptr<gfc::engine::CEntity> toSolidShape(gfc::engine::EntityPtr pShape);
    void setOwner(GfcTransform* pOwner);
protected:
    void assignShapeData(gfc::engine::EntityPtr pSrc, std::shared_ptr<gfc::engine::CEntity> pDest);
    GfcTransform* m_pOwner;
private:
    gfc::engine::CClassCompatibility* m_pShapeCompatibility;
};

class Gfc2ManifoldSolidShapeTransformer: public GfcShapeTransformer
{
    GFCENGINE_DEC_OBJECT(Gfc2ManifoldSolidShapeTransformer, GfcShapeTransformer)
public:
    virtual std::shared_ptr<gfc::engine::CEntity> toSolidShape(gfc::engine::EntityPtr pShape);
};

#endif // !GFCSHAPETRANSFORMER_H
