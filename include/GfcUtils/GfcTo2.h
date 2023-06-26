#ifndef GFCTO2_H
#define GFCTO2_H

#include <string>
#include <map>
#include "GfcEngine/GfcEngine.h"
#include "GfcEngine/Entity.h"
#include "GfcUtils/GfcTransform.h"

class GfcElementTransformer;
class GfcShapeTransformer;

class GfcTo2: public GfcTransform
{
public:
    GfcTo2(gfc::engine::IContainer* pContainer);
public:
    // 设置转换目标的Schema
    virtual void setSchema(gfc::schema::CModel* pSrcModel, gfc::schema::CModel* pDestModel);
public:
    gfc::engine::EntityRef transformString(const std::wstring& sValue);
protected:
    // 转换单个实体
    virtual DestEntityPtr doTransformShape(SrcEntityPtr& pSrcEntity);
    virtual DestEntityPtr doTransformElement(SrcEntityPtr& pSrcEntity);
    virtual DestEntityPtr doTransformElementType(SrcEntityPtr& pSrcEntity);
    // 处理属性集
    virtual void transformProjectPropertySet(SrcEntityPtr& pSrcEntity, DestEntityPtr& pDestEntity);
    virtual void transformBuildingPropertySet(SrcEntityPtr& pSrcEntity, DestEntityPtr& pDestEntity);
    virtual void transformFloorPropertySet(SrcEntityPtr& pSrcEntity, DestEntityPtr& pDestEntity);
    //
    virtual GfcRelDefinesByTypeSchema getSrcRelDefinesByTypeSchema();
    virtual GfcRelDefinesByTypeSchema getDestRelDefinesByTypeSchema();
    virtual bool isElement(SrcEntityPtr& pEntity);
    virtual bool isElementType(SrcEntityPtr& pEntity);
    virtual void linkElementShape(DestEntityPtr& pElement, DestEntityPtr& pShape);
private:
    void changeIDConverter(const std::wstring sEntityName);
    void changeStringConverter();
    std::shared_ptr<GfcShapeTransformer> getShapeTransformer(const std::wstring& sName);
    std::shared_ptr<GfcElementTransformer> getElementTransformer(const std::wstring& sTypeName);
};

#endif // GFCTRANSFORM_H
