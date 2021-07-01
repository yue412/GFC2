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

struct GfcRelDefinesByTypeSchema
{
    std::wstring sClassName;
    std::wstring sRelatingTypeFieldName;
    std::wstring sRelatingElementFieldName;
    GfcRelDefinesByTypeSchema() {}
    GfcRelDefinesByTypeSchema(std::wstring s_ClassName, std::wstring s_RelatingTypeFieldName, std::wstring s_RelatingElementFieldName):
        sClassName(s_ClassName), sRelatingTypeFieldName(s_RelatingTypeFieldName), sRelatingElementFieldName(s_RelatingElementFieldName) {}
};

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
    virtual void setSchema(gfc::schema::CModel* pSrcModel, gfc::schema::CModel* pDestModel);
    // 输出
    void setWriter(gfc::engine::CWriter* pWriter);
    gfc::engine::CWriter* writer() { return m_pWriter; }
    bool transform();
public:
    gfc::engine::EntityRef getEntityRef(gfc::engine::EntityRef nSrc);
    DestEntityPtr createEntity(const std::wstring& sEntityName);
    gfc::engine::CEntityUpgrader* upgrader() { return m_pEntityUpgrader; }
    gfc::engine::EntityRef write(gfc::engine::EntityRef nSrcRef, DestEntityPtr& pDestEntity);
protected:
    // 同名称才能转换
    DestEntityPtr transformEntity(SrcEntityPtr& pSrcEntity);
    gfc::engine::CClassCompatibility* m_pObjectCompatibility;
    virtual GfcRelDefinesByTypeSchema getSrcRelDefinesByTypeSchema() = 0;
    virtual GfcRelDefinesByTypeSchema getDestRelDefinesByTypeSchema() = 0;
    virtual bool isElement(SrcEntityPtr& pSrcEntity) = 0;
    virtual bool isElementType(SrcEntityPtr& pSrcEntity) = 0;
    virtual void linkElementShape(DestEntityPtr& pElement, DestEntityPtr& pShape) = 0;
    // 转换单个实体
    virtual DestEntityPtr doTransformShape(SrcEntityPtr& pSrcEntity) = 0;
    virtual DestEntityPtr doTransformElement(SrcEntityPtr& pSrcEntity) = 0;
    virtual DestEntityPtr doTransformElementType(SrcEntityPtr& pSrcEntity) = 0;
protected:
    // 处理属性集
    virtual void transformProjectPropertySet(SrcEntityPtr& pSrcEntity, DestEntityPtr& pDestEntity);
    virtual void transformBuildingPropertySet(SrcEntityPtr& pSrcEntity, DestEntityPtr& pDestEntity);
    virtual void transformFloorPropertySet(SrcEntityPtr& pSrcEntity, DestEntityPtr& pDestEntity);
    void getPropertySetList(gfc::engine::EntityRef nRef, std::vector<SrcEntityPtr>& oList);
    void writeRelDefinesByProperties(gfc::engine::EntityRef nRelatingPropertySet, gfc::engine::EntityRef nRelatedObject);
    // 转换流程和实体间关系
    gfc::engine::EntityRef transformProject();
    GfcEntityRefMap transformBuilding(gfc::engine::EntityRef nProjectRef);
    GfcEntityRefMap transformFloor(const GfcEntityRefMap& oBuildingRefMap);
    void transformElement(const GfcEntityRefMap& oFloorRefMap);
    void transformTypeElementRelationShip(const GfcEntityRefMap& oElementTypeRefMap, const GfcEntityRefMap& oElementRefMap, 
        const GfcRelDefinesByTypeSchema& oSrcSchema, const GfcRelDefinesByTypeSchema& oDestSchema);
    std::map<gfc::engine::EntityRef, std::vector<gfc::engine::EntityRef>> m_oRelAggregates;
private:
    void changeEntityRefConverter();
    void addRelAggregates(gfc::engine::EntityRef nRelatingObject, gfc::engine::EntityRef nRelatedObject);
    void clear();
    void writeRelAggregates();

    std::map<gfc::engine::EntityRef, gfc::engine::EntityRef> m_oTransformMap;
    gfc::engine::IContainer* m_pContainer;
    gfc::schema::CModel* m_pModel;
    gfc::engine::CWriter* m_pWriter;
    gfc::engine::CEntityUpgrader* m_pEntityUpgrader;
};

#endif // GFCTRANSFORM_H
