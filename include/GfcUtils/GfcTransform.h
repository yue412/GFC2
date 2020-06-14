#ifndef GFCTRANSFORM_H
#define GFCTRANSFORM_H

#include <string>
#include <map>
#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\Entity.h"

namespace gfc {
    namespace engine {
        class IContainer;
        class CWriter;
        class CEntity;
    }
    namespace schema {
        class CModel;
    }
}

class GfcTransform
{
public:
    GfcTransform(gfc::engine::IContainer* pContainer);
    virtual ~GfcTransform();
public:
    // 设置转换目标的Schema
    void setSchema(gfc::schema::CModel* pModel);
    bool transform(const std::wstring& sFileName);
    typedef std::map<gfc::engine::EntityRef, gfc::engine::EntityRef> GfcEntityRefMap;
protected:
    virtual std::shared_ptr<gfc::engine::CEntity> doTransformProject(gfc::engine::EntityPtr pEntity) = 0;
    virtual std::shared_ptr<gfc::engine::CEntity> doTransformBuilding(gfc::engine::EntityPtr pEntity) = 0;
    virtual std::shared_ptr<gfc::engine::CEntity> doTransformFloor(gfc::engine::EntityPtr pEntity) = 0;
    virtual std::shared_ptr<gfc::engine::CEntity> doTransformShape(gfc::engine::EntityPtr pElement) = 0;
    virtual std::shared_ptr<gfc::engine::CEntity> doTransformElement(gfc::engine::EntityPtr pElement) = 0;
    virtual void writeRelAggregates() = 0;

    std::shared_ptr<gfc::engine::CEntity> createEntity(const std::wstring& sEntityName);

    std::map<gfc::engine::EntityRef, std::vector<gfc::engine::EntityRef>> m_oRelAggregates;
    gfc::engine::CWriter* m_pWriter;
private:
    gfc::engine::EntityRef transformProject();
    GfcEntityRefMap transformBuilding(gfc::engine::EntityRef nProjectRef);
    GfcEntityRefMap transformFloor(const GfcEntityRefMap& oBuildingRefMap);
    void transformElement(const GfcEntityRefMap& oFloorRefMap);
    void addRelAggregates(gfc::engine::EntityRef nRelatingObject, gfc::engine::EntityRef nRelatedObject);
    void clear();

    gfc::engine::IContainer* m_pContainer;
    gfc::schema::CModel* m_pModel;
};

#endif // GFCTRANSFORM_H
