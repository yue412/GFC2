#include <assert.h>
#include "../include/GfcUtils/GfcFrom2.h"
#include "GfcEngine/EntityUpgrader.h"
#include "GfcEngine/ModelCompatibility.h"
#include "GfcEngine/ClassCompatibility.h"
#include "GfcEngine/AttributeCompatibility.h"
#include "GfcEngine/Writer.h"
#include "GfcEngine/Property.h"
#include "GfcEngine/PropValue.h"
#include "GfcEngine/Converter.h"
#include "GfcSchema/EntityClass.h"
#include "GfcSchema/EntityAttribute.h"
#include "Common.h"
#include "GfcUtils/GfcShapeFrom2.h"

// GFC2.0是字符串的引用 转为 GFC3.0直接使用字符串
class CStringConverter : public gfc::engine::CConverter
{
public:
    CStringConverter(GfcFrom2* pOwner) : m_pOwner(pOwner) {}
    virtual void doTransform(gfc::engine::CPropValue* pFrom, gfc::engine::CPropValue* pTo)
    {
        auto nStringRef = pFrom->asEntityRef();
        auto str = m_pOwner->transformString(nStringRef);
        pTo->setAsString(str);
    }
    virtual CConverter* clone()
    {
        return new CStringConverter(*this);
    }
private:
    GfcFrom2* m_pOwner;
};

GfcFrom2::GfcFrom2(gfc::engine::IContainer * pContainer): GfcTransform(pContainer)
{
}

void GfcFrom2::transformProjectPropertySet(SrcEntityPtr & pSrcEntity, DestEntityPtr & pDestEntity)
{
    // Gfc2里面的属性集，标准不认识，直接转到3
    //for each (auto oPropertySet in oPropertySetList)
    //{
    //    auto oNewPropertySet = transformEntity(oPropertySet);
    //    auto nNewPropertySetRef = writer()->writeEntity(oNewPropertySet.get());
    //    writeRelDefinesByProperties(nNewPropertySetRef, pDestEntity->ref());
    //}
    auto pNewPropertySet = entityAttributeToPropertySet(pSrcEntity);
    if (pNewPropertySet->getArrayCount(L"HasProperties") > 0)
    {
        auto nNewPropertySetRef = writer()->writeEntity(pNewPropertySet.get());
        writeRelDefinesByProperties(nNewPropertySetRef, pDestEntity->ref());
    }
}

void GfcFrom2::transformFloorPropertySet(SrcEntityPtr & pSrcEntity, DestEntityPtr & pDestEntity)
{
    auto pNewPropertySet = entityAttributeToPropertySet(pSrcEntity, {L"FirstFloorFlag", L"FloorArea", L"SlabThickness", L"EntAseismicGrade", L"EntProtectiveThickness"});
    if (pNewPropertySet->getArrayCount(L"HasProperties") > 0)
    {
        auto nNewPropertySetRef = writer()->writeEntity(pNewPropertySet.get());
        writeRelDefinesByProperties(nNewPropertySetRef, pDestEntity->ref());
    }
}

bool GfcFrom2::isElement(SrcEntityPtr & pEntity)
{
    return pEntity->entityName() == L"Gfc2Entity" && !pEntity->isNull(L"Shape");
}

bool GfcFrom2::isElementType(SrcEntityPtr & pEntity)
{
    return pEntity->entityName() == L"Gfc2Entity" && pEntity->isNull(L"Shape");
}

GfcRelDefinesByTypeSchema GfcFrom2::getSrcRelDefinesByTypeSchema()
{
    return GfcRelDefinesByTypeSchema(L"Gfc2RelDefinesByElement", L"RelatingElement", L"RelatedObjects");
}

GfcRelDefinesByTypeSchema GfcFrom2::getDestRelDefinesByTypeSchema()
{
    return GfcRelDefinesByTypeSchema(L"Gfc2RelDefinesByType", L"RelatingType", L"RelatingElement");
}

void GfcFrom2::linkElementShape(DestEntityPtr & pElement, DestEntityPtr & pShape)
{
    pElement->addEntityRef(L"Shapes", writer()->writeEntity(pShape.get()));
}

GfcFrom2::DestEntityPtr GfcFrom2::doTransformShape(SrcEntityPtr & pSrcEntity)
{
    auto pSrcShape = pSrcEntity->asEntity(L"Shape");
    auto pShapeFrom2 = dynamic_cast<GfcShapeFrom2*>(GfcShapeFrom2::GetFactory()->Create(pSrcShape->entityName()));
    assert(pShapeFrom2);
    if (pShapeFrom2)
    {
        pShapeFrom2->setOwner(this);
        auto pNewShape = pShapeFrom2->transform(pSrcShape);
        auto pElementShape = createEntity(L"Gfc2ElementShape");
        pElementShape->setAsString(L"Identifier", L"body");
        pElementShape->setAsEntityRef(L"Shape", writer()->writeEntity(pNewShape.get()));
        return pElementShape;
    }
    else
    {
        return nullptr;
    }
}

void GfcFrom2::doTransformElement(SrcEntityPtr & pSrcEntity, DestEntityPtr & pDestEntity)
{
    pSrcEntity->setAsString(L"EType", getTypeCode(pSrcEntity->entityName()));
    upgrader()->transform(m_pObjectCompatibility, pSrcEntity.get(), pDestEntity.get());
    std::vector<std::wstring> sNames;
    getEntityAttributeNames(dynamic_cast<gfc::schema::CClass*>(pSrcEntity->getSchema()), sNames);
    auto pSelfPropertySet = entityAttributeToPropertySet(pSrcEntity, sNames);
    if (pSelfPropertySet->getArrayCount(L"HasProperties") > 0)
    {
        auto nNewPropertySetRef = writer()->writeEntity(pSelfPropertySet.get());
        writeRelDefinesByProperties(nNewPropertySetRef, pDestEntity->ref());
    }
    std::vector<SrcEntityPtr> oPropertySetList;
    getPropertySetList(pSrcEntity->ref(), oPropertySetList);
    for (int i = 0; i < oPropertySetList.size(); i++)
    {
        auto pPropertySet = oPropertySetList[i];
        auto pNewPropertySet = gfc::engine::EntityPtr(upgrader()->update(pPropertySet.get()));
        auto nNewPropertySetRef = writer()->writeEntity(pNewPropertySet.get());
        writeRelDefinesByProperties(nNewPropertySetRef, pDestEntity->ref());
    }
}

GfcFrom2::DestEntityPtr GfcFrom2::doTransformElement(SrcEntityPtr & pSrcEntity)
{
    auto pNewElement = createEntity(L"Gfc2Element");
    doTransformElement(pSrcEntity, pNewElement);
    return pNewElement;
}

GfcFrom2::DestEntityPtr GfcFrom2::doTransformElementType(SrcEntityPtr & pSrcEntity)
{
    auto pNewElement = createEntity(L"Gfc2ElementType");
    doTransformElement(pSrcEntity, pNewElement);
    return pNewElement;
}

GfcFrom2::DestEntityPtr GfcFrom2::entityAttributeToPropertySet(SrcEntityPtr pSrcEntity)
{
    std::vector<std::wstring> sNameList;
    auto pSchema = (gfc::schema::CClass*)(pSrcEntity->getSchema());
    for (int i = 0; i < pSchema->getAttributeCount(); i++)
    {
        auto pAttribute = pSchema->getAttribute(i);
        auto sName = pAttribute->getName();
        sNameList.push_back(sName);
    }
    return entityAttributeToPropertySet(pSrcEntity, sNameList);
}

GfcFrom2::DestEntityPtr GfcFrom2::entityAttributeToPropertySet(SrcEntityPtr pSrcEntity, const std::vector<std::wstring>& sAttributeNames)
{
    auto pPropertySet = createEntity(L"Gfc2PropertySet");
    auto pPropList = pPropertySet->valueByName(L"HasProperties");
    for (auto itr = sAttributeNames.begin(); itr != sAttributeNames.end(); itr++)
    {
        auto sName = *itr;
        if (pSrcEntity->isNull(sName))
            continue;

        auto pProperty = attributeToProperty(pSrcEntity->propByName(sName));
        if (pProperty)
        {
            auto nRef = writer()->writeEntity(pProperty.get());
            pPropList->add(new gfc::engine::CEntityRefValue(nRef));
        }
    }
    return pPropertySet;
}

GfcFrom2::DestEntityPtr GfcFrom2::attributeToProperty(gfc::engine::CProperty * pSrc)
{
    DestEntityPtr pProperty = nullptr;
    auto pAttribute = pSrc->schema();
    auto pType = pAttribute->getType();
    if (pAttribute->getRepeatFlag())
    {
        std::wstring propertyClassNames[gfc::schema::EDT_ENTITY + 1] = { L"", L"Gfc2BooleanListProperty", L"Gfc2IntegerListProperty", L"Gfc2DoubleListProperty", L"Gfc2StringListProperty", L"Gfc2IntegerListProperty", L"" };
        auto sClassName = pType->getDataType() <= gfc::schema::EDT_ENTITY ? propertyClassNames[pType->getDataType()] : L"";
        //
        if (!sClassName.empty())
        {
            pProperty = createEntity(sClassName);
            pProperty->assignValue(L"Values", pSrc->value());
        }
        else if (pType->getDataType() == gfc::schema::EDT_ENTITY)
        {
            auto pList = pSrc->value();
            if (pType->getBaseType()->getName() == L"Gfc2String")
            {
                pProperty = createEntity(L"Gfc2StringListProperty");
                auto pStrings = pProperty->valueByName(L"Values");
                for (int i = 0; i < pList->getCount(); i++)
                {
                    auto nStringRef = pList->getItems(i)->asEntityRef();
                    auto pString = container()->getEntity(nStringRef);
                    if (pString)
                    {
                        auto sValue = pString->asString(L"Value");
                        pStrings->add(new gfc::engine::CStringValue(sValue));
                    }
                }
            }
            else
            {
                // 转对象
                pProperty = createEntity(L"Gfc2EntityListProperty");
                auto pValues = pProperty->valueByName(L"Values");
                for (int i = 0; i < pList->getCount(); i++)
                {
                    auto nRef = pList->getItems(i)->asEntityRef();
                    auto pRefEntity = container()->getEntity(nRef);
                    auto pNewEntity = this->transformEntity(pRefEntity);
                    gfc::engine::EntityRef nNewRef = -1;
                    if (pNewEntity) // 同类型对象
                    {
                        nNewRef = write(pRefEntity->ref(), pNewEntity);
                    }
                    else // 没有同类型对象，转成Object
                    {
                        nNewRef = entityToObject(pRefEntity);
                    }
                    pValues->add(new gfc::engine::CEntityRefValue(nNewRef));
                }
            }
        }
    }
    else {
        std::wstring propertyClassNames[gfc::schema::EDT_ENTITY + 1] = { L"", L"Gfc2BooleanProperty", L"Gfc2IntegerProperty", L"Gfc2DoubleProperty", L"Gfc2StringProperty", L"Gfc2IntegerProperty", L"" };
        auto sClassName = pType->getDataType() <= gfc::schema::EDT_ENTITY ? propertyClassNames[pType->getDataType()] : L"";
        //
        if (!sClassName.empty())
        {
            pProperty = createEntity(sClassName);
            pProperty->assignValue(L"Val", pSrc->value());
        }
        else if (pType->getDataType() == gfc::schema::EDT_ENTITY)
        {
            auto pRefEntity = container()->getEntity(pSrc->value()->asEntityRef());
            if (pRefEntity)
            {
                if (pType->getBaseType()->getName() == L"Gfc2String")
                {
                    auto sValue = pRefEntity->asString(L"Value");
                    pProperty = createEntity(L"Gfc2StringProperty");
                    pProperty->setAsString(L"Val", sValue);
                }
                else
                {
                    // 转对象
                    auto pNewEntity = this->transformEntity(pRefEntity);
                    gfc::engine::EntityRef nNewRef = -1;
                    if (pNewEntity) // 同类型对象
                    {
                        nNewRef = write(pRefEntity->ref(), pNewEntity);
                    }
                    else // 没有同类型对象，转成Object
                    {
                        nNewRef = entityToObject(pRefEntity);
                    }
                    pProperty = createEntity(L"Gfc2EntityProperty");
                    pProperty->setAsEntityRef(L"Val", nNewRef);
                }
            }
        }
    }
    if (pProperty)
    {
        auto sName = pSrc->name();
        pProperty->setAsString(L"Name", sName);
        pProperty->setAsString(L"Code", sName);
    }
    return pProperty;
}

gfc::engine::EntityRef GfcFrom2::entityToObject(SrcEntityPtr pSrc)
{
    // object
    auto pNewObject = createEntity(L"Gfc2Object");
    pNewObject->setAsString(L"Name", pSrc->getSchema()->getName());
    auto sGuid = generateGuid();
    pNewObject->setAsString(L"ID", sGuid);
    auto nNewObjectRef = writer()->writeEntity(pNewObject.get()); //不用另一个write方法，不记录和原始ref的关系，相当于每次都新建一个，避免语义上错误
    // propertyset
    auto pNewPropertySet = createEntity(L"Gfc2PropertySet");
    auto pValue = pNewPropertySet->valueByName(L"HasProperties");
    for (int i = 0; i < pSrc->getPropCount(); i++)
    {
        auto pProp = pSrc->getProps(i);
        if (pProp->value()->isNull())
            continue;
        auto pNewProperty = attributeToProperty(pProp);
        if (pNewProperty)
        {
            auto nRef = writer()->writeEntity(pNewProperty.get());
            pValue->add(new gfc::engine::CEntityRefValue(nRef));
        }
    }
    if (pValue->getCount() == 0) // 没有属性
        return nNewObjectRef;
    auto nNewPropertySetRef = writer()->writeEntity(pNewPropertySet.get());
    // rel
    writeRelDefinesByProperties(nNewPropertySetRef, nNewObjectRef);
    return nNewObjectRef;
}

void GfcFrom2::changeStringConverter()
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
                (pToAttrib->getType()->getDataType() == gfc::schema::EDT_STRING) &&
                (pFromAttrib->getType()->getBaseType()->getName() == L"Gfc2String"))
            {
                auto pConverter = pAttribte->converter();
                if (pConverter && pConverter->next())
                {
                    pConverter->setNext(new CStringConverter(this));
                }
            }
        }
    }
}

std::wstring GfcFrom2::getTypeCode(const std::wstring & sEntityName)
{
    if (sEntityName == L"Gfc2PointColumn" || sEntityName == L"Gfc2Column")
        return L"14-07.35.07";
    else if (sEntityName == L"Gfc2LineBeam" || sEntityName == L"Gfc2Beam")
        return L"14-07.40.07";
    else if (sEntityName == L"Gfc2FaceSlab" || sEntityName == L"Gfc2Slab")
        return L"14-07.45.10";
    else if (sEntityName == L"Gfc2ForceNormalWall" || sEntityName == L"Gfc2ForceAbnormityWall" || sEntityName == L"Gfc2ForceWall")
        return L"14-07.20.07";
    else
        return L"14-07.00.00";
}

void GfcFrom2::getEntityAttributeNames(gfc::schema::CClass * pEntityClass, std::vector<std::wstring>& sAttributeNames)
{
    if (pEntityClass == nullptr || pEntityClass->getName() == L"Gfc2Entity")
        return;
    for (int i = 0; i < pEntityClass->getAttributeCount(); i++)
    {
        sAttributeNames.push_back(pEntityClass->getAttribute(i)->getName());
    }
    getEntityAttributeNames(pEntityClass->getParent(), sAttributeNames);
}

std::wstring GfcFrom2::transformString(gfc::engine::EntityRef nStringRef)
{
    auto pString = container()->getEntity(nStringRef);
    if (pString)
    {
        if (pString->getSchema()->getBaseType()->getName() == L"Gfc2String")
        {
            return pString->asString(L"Value");
        }
    }
    return std::wstring();
}

void GfcFrom2::setSchema(gfc::schema::CModel * pSrcModel, gfc::schema::CModel * pDestModel)
{
    GfcTransform::setSchema(pSrcModel, pDestModel);
    changeStringConverter();
}
