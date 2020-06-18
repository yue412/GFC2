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
        class CEntityUpgrader;
    }
    namespace schema {
        class CModel;
    }
}

class GfcElementTransformer;
class GfcShapeTransformer;

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
    DestEntityPtr createEntity(const std::wstring& sEntityName);
    gfc::engine::CEntityUpgrader* upgrader() { return m_pEntityUpgrader; }
protected:
    // 转换单个实体
    DestEntityPtr doTransformProject(SrcEntityPtr& pSrcEntity);
    DestEntityPtr doTransformBuilding(SrcEntityPtr& pSrcEntity);
    DestEntityPtr doTransformFloor(SrcEntityPtr& pSrcEntity);
    DestEntityPtr doTransformShape(SrcEntityPtr& pSrcEntity);
    DestEntityPtr doTransformElement(SrcEntityPtr& pSrcEntity);
protected:
    // 转换流程和实体间关系
    gfc::engine::EntityRef transformProject();
    GfcEntityRefMap transformBuilding(gfc::engine::EntityRef nProjectRef);
    GfcEntityRefMap transformFloor(const GfcEntityRefMap& oBuildingRefMap);
    void transformElement(const GfcEntityRefMap& oFloorRefMap);
protected:
    DestEntityPtr doTransformEntity(SrcEntityPtr& pSrcEntity);
    std::map<gfc::engine::EntityRef, std::vector<gfc::engine::EntityRef>> m_oRelAggregates;
private:
    // 处理属性集
    void transformProjectPropertySet(SrcEntityPtr& pSrcEntity, std::vector<SrcEntityPtr>& oPropertySetList, DestEntityPtr& pDestEntity);
    void transformBuildingPropertySet(SrcEntityPtr& pSrcEntity, std::vector<SrcEntityPtr>& oPropertySetList, DestEntityPtr& pDestEntity);
    void transformFloorPropertySet(SrcEntityPtr& pSrcEntity, std::vector<SrcEntityPtr>& oPropertySetList, DestEntityPtr& pDestEntity);
private:
    void changeIDConverter(const std::wstring sEntityName);
    void changeEntityRefConverter();
    void addRelAggregates(gfc::engine::EntityRef nRelatingObject, gfc::engine::EntityRef nRelatedObject);
    void getPropertySetList(gfc::engine::EntityRef nRef, std::vector<SrcEntityPtr>& oList);
    std::shared_ptr<GfcShapeTransformer> getShapeTransformer(const std::wstring& sName);
    std::shared_ptr<GfcElementTransformer> getElementTransformer(const std::wstring& sTypeName);
    void clear();
    void writeRelAggregates();
    gfc::engine::EntityRef write(gfc::engine::EntityRef nSrcRef, DestEntityPtr& pDestEntity);

    std::map<gfc::engine::EntityRef, gfc::engine::EntityRef> m_oTransformMap;
    gfc::engine::IContainer* m_pContainer;
    gfc::schema::CModel* m_pModel;
    gfc::engine::CClassCompatibility* m_pObjectCompatibility;
    gfc::engine::CWriter* m_pWriter;
    gfc::engine::CEntityUpgrader* m_pEntityUpgrader;
};

#endif // GFCTRANSFORM_H
