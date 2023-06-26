#include "GfcUtils\GfcTo2.h"
#include "GfcEngine\Writer.h"
#include "GfcSchema\Model.h"
#include "GfcSchema\EntityAttribute.h"
#include "GfcEngine\GfcEngineUtils.h"
#include "GfcEngine\PropValue.h"
#include "GfcEngine\ModelCompatibility.h"
#include "GfcEngine\ClassCompatibility.h"
#include "GfcEngine\AttributeCompatibility.h"
#include "GfcEngine\Converter.h"
#include "GfcUtils\GfcShapeTransformer.h"
#include "GfcUtils\GfcElementTransformer.h"
#include "GfcEngine\EntityUpgrader.h"
#include <memory>
#include <assert.h>

class CIDConverter : public gfc::engine::CConverter
{
public:
    virtual void doTransform(gfc::engine::CPropValue* pFrom, gfc::engine::CPropValue* pTo)
    {
        pTo->setAsInteger(std::stoi(pFrom->asString()));
    }
    virtual CConverter* clone()
    {
        return new CIDConverter(*this);
    }
};

// GFC3.0直接使用字符串，GFC2.0是字符串的引用
class CStringConverter32 : public gfc::engine::CConverter
{
public:
    CStringConverter32(GfcTo2* pOwner) : m_pOwner(pOwner) {}
    virtual void doTransform(gfc::engine::CPropValue* pFrom, gfc::engine::CPropValue* pTo)
    {
        auto s = pFrom->asString();
        auto nStringRef = m_pOwner->transformString(s);
        pTo->setAsEntityRef(nStringRef);
    }
    virtual CConverter* clone()
    {
        return new CStringConverter32(*this);
    }
private:
    GfcTo2* m_pOwner;
};

GfcTo2::GfcTo2(gfc::engine::IContainer * pContainer): GfcTransform(pContainer)
{
}

void GfcTo2::setSchema(gfc::schema::CModel* pSrcModel, gfc::schema::CModel* pDestModel)
{
    GfcTransform::setSchema(pSrcModel, pDestModel);
    changeIDConverter(L"Gfc2Project");
    changeIDConverter(L"Gfc2Building");
    changeIDConverter(L"Gfc2Floor");
    changeIDConverter(L"Gfc2Object");
    changeStringConverter();
}

gfc::engine::EntityRef GfcTo2::transformString(const std::wstring & sValue)
{
    auto pStr = createEntity(L"Gfc2String");
    pStr->setAsString(L"Value", sValue);
    auto nDestRef = writer()->writeEntity(pStr.get());
    return nDestRef;
}

GfcTo2::DestEntityPtr GfcTo2::doTransformShape(SrcEntityPtr & pSrcEntity)
{
    auto pShapesValue = pSrcEntity->valueByName(L"Shapes");
    if (pShapesValue->isNull())
        return nullptr;
    // 取第一个
    auto pElementShape = pSrcEntity->getEntity(pShapesValue, 0);
    if (nullptr == pElementShape)
        return nullptr;

    auto pShape = pElementShape->asEntity(L"Shape");
    if (nullptr == pShape)
        return nullptr;

    auto pShapeTransformer = getShapeTransformer(pShape->entityName());
    assert(pShapeTransformer);
    if (nullptr == pShapeTransformer)
        return nullptr;
    pShapeTransformer->setOwner(this);

    auto sTypeName = pSrcEntity->asString(L"EType");
    auto pElementTransformer = getElementTransformer(sTypeName);
    assert(pElementTransformer);
    if (nullptr == pElementTransformer)
        return nullptr;

    auto pNewShape = pElementTransformer->transformShape(pShapeTransformer.get(), pShape);
    if (nullptr == pNewShape)
        pNewShape = pShapeTransformer->toSolidShape(pShape);
    return pNewShape;
}

GfcTo2::DestEntityPtr GfcTo2::doTransformElement(SrcEntityPtr & pSrcEntity)
{
    auto sTypeName = pSrcEntity->asString(L"EType");
    auto pElementTransformer = getElementTransformer(sTypeName);
    if (pElementTransformer)
    {
        auto pNewElement = createEntity(pElementTransformer->elementName());
        upgrader()->transform(m_pObjectCompatibility, pSrcEntity.get(), pNewElement.get());
        std::vector<SrcEntityPtr> oPropertySetList;
        getPropertySetList(pSrcEntity->ref(), oPropertySetList);
        pElementTransformer->transformPropertySet(pSrcEntity, oPropertySetList, pNewElement);
        return pNewElement;
    }
    else
        return nullptr;
}

GfcTo2::DestEntityPtr GfcTo2::doTransformElementType(SrcEntityPtr & pSrcEntity)
{
    return doTransformElement(pSrcEntity);
}

void GfcTo2::transformProjectPropertySet(SrcEntityPtr & pSrcEntity, DestEntityPtr & pDestEntity)
{
    std::vector<SrcEntityPtr> oPropertySetList;
    getPropertySetList(pSrcEntity->ref(), oPropertySetList);
    //todo
}

void GfcTo2::transformBuildingPropertySet(SrcEntityPtr & pSrcEntity, DestEntityPtr & pDestEntity)
{
    std::vector<SrcEntityPtr> oPropertySetList;
    getPropertySetList(pSrcEntity->ref(), oPropertySetList);
    //todo
}

void GfcTo2::transformFloorPropertySet(SrcEntityPtr & pSrcEntity, DestEntityPtr & pDestEntity)
{
    std::vector<SrcEntityPtr> oPropertySetList;
    getPropertySetList(pSrcEntity->ref(), oPropertySetList);
    //todo
}

GfcRelDefinesByTypeSchema GfcTo2::getSrcRelDefinesByTypeSchema()
{
    return GfcRelDefinesByTypeSchema(L"Gfc2RelDefinesByType", L"RelatingType", L"RelatingElement");
}

GfcRelDefinesByTypeSchema GfcTo2::getDestRelDefinesByTypeSchema()
{
    return GfcRelDefinesByTypeSchema(L"Gfc2RelDefinesByElement", L"RelatingElement", L"RelatedObjects");
}

bool GfcTo2::isElement(SrcEntityPtr & pEntity)
{
    return pEntity->entityName() == L"Gfc2Element";
}

bool GfcTo2::isElementType(SrcEntityPtr & pEntity)
{
    return pEntity->entityName() == L"Gfc2ElementType";
}

void GfcTo2::linkElementShape(DestEntityPtr & pElement, DestEntityPtr & pShape)
{
    pElement->setAsEntityRef(L"Shape", writer()->writeEntity(pShape.get()));
}

std::shared_ptr<GfcShapeTransformer> GfcTo2::getShapeTransformer(const std::wstring & sName)
{
    auto pResult = dynamic_cast<GfcShapeTransformer*>(GfcShapeTransformer::GetFactory()->Create(sName));
    return std::shared_ptr<GfcShapeTransformer>(pResult);
}

std::shared_ptr<GfcElementTransformer> GfcTo2::getElementTransformer(const std::wstring & sTypeName)
{
    auto pResult = dynamic_cast<GfcElementTransformer*>(GfcElementTransformer::GetFactory()->Create(sTypeName));
    return std::shared_ptr<GfcElementTransformer>(pResult);
}

void GfcTo2::changeIDConverter(const std::wstring sEntityName)
{
    auto pClassCompatibility = upgrader()->model()->find(sEntityName);
    if (pClassCompatibility)
    {
        for (int i = 0; i < pClassCompatibility->getCount(); ++i)
        {
            auto pAttribteCompatibility = pClassCompatibility->getCompatibilityAttribute(i);
            if (pAttribteCompatibility->getName() == L"ID")
            {
                pAttribteCompatibility->setConverter(new CIDConverter);
            }
        }
    }
}

void GfcTo2::changeStringConverter()
{
    for (int i = 0; i < upgrader()->model()->getCount(); i++)
    {
        auto pClass = upgrader()->model()->getItems(i);
        for (int j = 0; j < pClass->getCount(); j++)
        {
            auto pAttribte = pClass->getCompatibilityAttribute(j);
            auto pFromAttrib = pAttribte->from();
            auto pToAttrib = pAttribte->to();
            if (pFromAttrib && pToAttrib && 
                (pFromAttrib->getType()->getDataType() == gfc::schema::EDT_STRING) &&
                (pToAttrib->getType()->getDataType() == gfc::schema::EDT_ENTITY))
            {
                auto pConverter = pAttribte->converter();
                if (pConverter && pConverter->next())
                {
                    auto pStringConverter = new CStringConverter32(this);
                    pConverter->setNext(pStringConverter);
                    //pStringConverter->doTransform(nullptr, nullptr);
                }
            }
        }
    }
}