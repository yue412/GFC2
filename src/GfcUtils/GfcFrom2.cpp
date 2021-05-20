#include <assert.h>
#include "..\include\GfcUtils\GfcFrom2.h"
#include "GfcEngine\EntityUpgrader.h"
#include "GfcEngine\ModelCompatibility.h"
#include "GfcEngine\ClassCompatibility.h"
#include "GfcEngine\Writer.h"
#include "GfcEngine\Property.h"
#include "GfcEngine\PropValue.h"
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\EntityAttribute.h"

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
    auto pNewPropertySet = createEntity(L"Gfc2PropertySet");
    entityAttributeToProperty(pSrcEntity, pNewPropertySet);
    if (pNewPropertySet->getArrayCount(L"HasProperties") > 0)
    {
        auto nNewPropertySetRef = writer()->writeEntity(pNewPropertySet.get());
        writeRelDefinesByProperties(nNewPropertySetRef, pDestEntity->ref());
    }
}

void GfcFrom2::entityAttributeToProperty(SrcEntityPtr pSrcEntity, DestEntityPtr pDestPropertySet)
{
    auto pPropList = pDestPropertySet->valueByName(L"HasProperties");
    auto pSchema = (gfc::schema::CClass*)(pSrcEntity->getSchema());
    for (int i = 0; i < pSchema->getAttributeCount(); i++)
    {
        auto pAttribute = pSchema->getAttribute(i);
        auto sName = pAttribute->getName();
        if (pSrcEntity->isNull(sName))
            continue;

        auto pProperty = attributeToProperty(pSrcEntity->propByName(sName));
        if (pProperty)
        {
            pProperty->setAsString(L"Name", sName);
            pProperty->setAsString(L"Code", sName);
            auto nRef = writer()->writeEntity(pProperty.get());
            auto pPropValue = new gfc::engine::CEntityRefValue();
            pPropValue->setAsEntityRef(nRef);
            pPropList->add(pPropValue);
        }
    }
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
    return pProperty;
}

gfc::engine::EntityRef GfcFrom2::entityToObject(SrcEntityPtr pSrc)
{
    // object
    auto pNewObject = createEntity(L"Gfc2Object");
    pNewObject->setAsString(L"Name", pSrc->getSchema()->getName());
    pNewObject->setAsString(L"ID", L"guid");
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
    auto pRelDefines = createEntity(L"Gfc2RelDefinesByProperties");
    pRelDefines->setAsEntityRef(L"RelatingPropertySet", nNewPropertySetRef);
    pRelDefines->addEntityRef(L"RelatedObjects", nNewObjectRef);
    writer()->writeEntity(pRelDefines.get());
    return nNewObjectRef;
}
