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
        class CModelCompatibility;
        class CClassCompatibility;
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
    typedef std::map<gfc::engine::EntityRef, gfc::engine::EntityRef> GfcEntityRefMap;
    typedef gfc::engine::EntityPtr SrcEntityPtr;
    typedef std::shared_ptr<gfc::engine::CEntity> DestEntityPtr;
public:
    gfc::engine::IContainer* container() { return m_pContainer; }
    // 设置转换目标的Schema
    void setSchema(gfc::schema::CModel* pSrcModel, gfc::schema::CModel* pDestModel);
    // 输出
    void setWriter(gfc::engine::CWriter* pWriter);
    bool transform();
    gfc::engine::EntityRef transformEntity(gfc::engine::EntityRef nSrc);
protected:
    virtual void transformProjectPropertySet(SrcEntityPtr& pSrcEntity, std::vector<SrcEntityPtr>& oPropertySetList, DestEntityPtr& pDestEntity) {}
    virtual void transformBuildingPropertySet(SrcEntityPtr& pSrcEntity, std::vector<SrcEntityPtr>& oPropertySetList, DestEntityPtr& pDestEntity) {}
    virtual void transformFloorPropertySet(SrcEntityPtr& pSrcEntity, std::vector<SrcEntityPtr>& oPropertySetList, DestEntityPtr& pDestEntity) {}
    virtual DestEntityPtr doTransformElement(SrcEntityPtr& pSrcEntity, std::vector<SrcEntityPtr>& oPropertySetList) = 0;
    virtual DestEntityPtr doTransformShape(SrcEntityPtr& pSrcEntity) = 0;
    virtual void writeRelAggregates() = 0;
    DestEntityPtr createEntity(const std::wstring& sEntityName);
    gfc::engine::EntityRef write(gfc::engine::EntityRef nSrcRef, DestEntityPtr& pDestEntity);
    DestEntityPtr doTransformEntity(SrcEntityPtr& pSrcEntity);

    std::map<gfc::engine::EntityRef, std::vector<gfc::engine::EntityRef>> m_oRelAggregates;
private:
    gfc::engine::EntityRef transformProject();
    GfcEntityRefMap transformBuilding(gfc::engine::EntityRef nProjectRef);
    GfcEntityRefMap transformFloor(const GfcEntityRefMap& oBuildingRefMap);
    void transformElement(const GfcEntityRefMap& oFloorRefMap);

    void changeIDConverter(const std::wstring sEntityName);
    void changeEntityRefConverter();
    void addRelAggregates(gfc::engine::EntityRef nRelatingObject, gfc::engine::EntityRef nRelatedObject);
    void getPropertySetList(gfc::engine::EntityRef nRef, std::vector<SrcEntityPtr>& oList);
    void clear();
    void transformEntity(gfc::engine::CClassCompatibility* pClassCompatibility,
        gfc::engine::CEntity* pSrcEntity, gfc::engine::CEntity* pDestEntity);

    gfc::engine::IContainer* m_pContainer;
    gfc::schema::CModel* m_pModel;
    gfc::engine::CModelCompatibility* m_pModelCompatibility;
    std::map<gfc::engine::EntityRef, gfc::engine::EntityRef> m_oTransformMap;
    gfc::engine::CWriter* m_pWriter;
};

#endif // GFCTRANSFORM_H
