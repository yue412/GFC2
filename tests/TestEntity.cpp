#include "gtest\gtest.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\EngineException.h"
#include "GfcEngine\PropValue.h"
#include "GfcEngine\Document.h"
#include "Common.h"
#include "Model.h"
#include "EntityClass.h"
#include "EntityAttribute.h"
#include "BuildinType.h"
#include "TypeDefine.h"

TEST(TestEntity, Entity_create)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    gfc::schema::CStringType oStringType;
    gfc::schema::CAttribute* pA3 = new gfc::schema::CAttribute();
    pA3->SetName(L"name");
    pA3->SetType(&oStringType);
    oClass.addAttribute(pA3);

    gfc::schema::CBooleanType oBooleanType;
    gfc::schema::CAttribute* pA4 = new gfc::schema::CAttribute();
    pA4->SetRepeatFlag(true);
    pA4->SetType(&oBooleanType);
    pA4->SetName(L"list");
    oClass.addAttribute(pA4);

    gfc::engine::Entity oEntity;
    oEntity.setSchema(&oClass);

    oEntity.setAsString(L"name", "中华人民共和国");
    oEntity.setAsInteger(L"height", 235456);
    oEntity.setAsDouble(L"area", 12.0);
    //oEntity.asBooleanList("list").push_back(true);
    EXPECT_NEAR(12.0, oEntity.asDouble(L"area"), 1e-7);
    EXPECT_EQ(235456, oEntity.asInteger(L"height"));
    EXPECT_STREQ("中华人民共和国", oEntity.asString(L"name").c_str());
    //EXPECT_EQ(true, oEntity.asBooleanList("list")[0]);
}

TEST(TestEntity, Entity_create_typedef_class)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    gfc::schema::CStringType oStringType;
    gfc::schema::CAttribute* pA3 = new gfc::schema::CAttribute();
    pA3->SetName(L"name");
    pA3->SetType(&oStringType);
    oClass.addAttribute(pA3);

    gfc::schema::CBooleanType oBooleanType;
    gfc::schema::CAttribute* pA4 = new gfc::schema::CAttribute();
    pA4->SetRepeatFlag(true);
    pA4->SetType(&oBooleanType);
    pA4->SetName(L"list");
    oClass.addAttribute(pA4);

    gfc::schema::CTypeDef oTypeDef(L"hehe");
    oTypeDef.SetRefType(&oClass);

    gfc::engine::Entity oEntity;
    oEntity.setSchema(&oTypeDef);

    oEntity.setAsString(L"name", "中华人民共和国");
    oEntity.setAsInteger(L"height", 235456);
    oEntity.setAsDouble(L"area", 12.0);
    //oEntity.asBooleanList("list").push_back(true);
    EXPECT_NEAR(12.0, oEntity.asDouble(L"area"), 1e-7);
    EXPECT_EQ(235456, oEntity.asInteger(L"height"));
    EXPECT_STREQ("中华人民共和国", oEntity.asString(L"name").c_str());
    //EXPECT_EQ(true, oEntity.asBooleanList("list")[0]);
}

TEST(TestEntity, Entity_entityName)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;
    oEntity.setSchema(&oClass);

    EXPECT_STREQ(L"Test", oEntity.entityName().c_str());

    gfc::schema::CTypeDef oTypeDef(L"hehe");
    oTypeDef.SetRefType(&oClass);

    gfc::engine::Entity oEntity2;
    oEntity2.setSchema(&oTypeDef);

    EXPECT_STREQ(L"hehe", oEntity2.entityName().c_str());
}

TEST(TestEntity, Entity_isInitialized)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    oEntity.setAsDouble(L"area", 2.0);

    EXPECT_EQ(false, oEntity.isInitialized());
}

TEST(TestEntity, Entity_isInitialized_true)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    oEntity.setAsDouble(L"area", 2.0);
    oEntity.setAsInteger(L"height", 123);

    EXPECT_EQ(true, oEntity.isInitialized());
}

TEST(TestEntity, Entity_isInitialized_true_optional)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    gfc::schema::CStringType oStringType;
    gfc::schema::CAttribute* pA3 = new gfc::schema::CAttribute();
    pA3->SetName(L"name");
    pA3->SetType(&oStringType);
    pA3->SetOptionalFlag(true);
    oClass.addAttribute(pA3);

    oEntity.setSchema(&oClass);

    oEntity.setAsDouble(L"area", 2.0);
    oEntity.setAsInteger(L"height", 123);

    EXPECT_EQ(true, oEntity.isInitialized());
}

TEST(TestEntity, Entity_isInitialized_true_list)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    gfc::schema::CStringType oStringType;
    gfc::schema::CAttribute* pA3 = new gfc::schema::CAttribute();
    pA3->SetName(L"name");
    pA3->SetType(&oStringType);
    pA3->SetRepeatFlag(true);
    oClass.addAttribute(pA3);

    oEntity.setSchema(&oClass);

    oEntity.setAsDouble(L"area", 2.0);
    oEntity.setAsInteger(L"height", 123);

    EXPECT_EQ(true, oEntity.isInitialized());
}

TEST(TestEntity, Entity_getPropCount)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    gfc::schema::CStringType oStringType;
    gfc::schema::CAttribute* pA3 = new gfc::schema::CAttribute();
    pA3->SetName(L"name");
    pA3->SetType(&oStringType);
    pA3->SetRepeatFlag(true);
    oClass.addAttribute(pA3);

    oEntity.setSchema(&oClass);

    EXPECT_EQ(3, oEntity.getPropCount());
}

TEST(TestEntity, Entity_getProps)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    gfc::schema::CStringType oStringType;
    gfc::schema::CAttribute* pA3 = new gfc::schema::CAttribute();
    pA3->SetName(L"name");
    pA3->SetType(&oStringType);
    pA3->SetRepeatFlag(true);
    oClass.addAttribute(pA3);

    oEntity.setSchema(&oClass);

    EXPECT_STREQ(L"height", oEntity.getProps(1)->name().c_str());
}

TEST(TestEntity, Entity_getProps_null)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    oEntity.setSchema(&oClass);

    EXPECT_EQ(nullptr, oEntity.getProps(1));
}

TEST(TestEntity, Entity_propByName)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    gfc::schema::CStringType oStringType;
    gfc::schema::CAttribute* pA3 = new gfc::schema::CAttribute();
    pA3->SetName(L"name");
    pA3->SetType(&oStringType);
    pA3->SetRepeatFlag(true);
    oClass.addAttribute(pA3);

    oEntity.setSchema(&oClass);
    
    auto p = oEntity.propByName(L"name");
    EXPECT_EQ(true, p != nullptr);

    p = oEntity.propByName(L"xxx");
    EXPECT_EQ(true, p == nullptr);
}

TEST(TestEntity, Entity_valueByName)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    gfc::schema::CStringType oStringType;
    gfc::schema::CAttribute* pA3 = new gfc::schema::CAttribute();
    pA3->SetName(L"name");
    pA3->SetType(&oStringType);
    pA3->SetRepeatFlag(true);
    oClass.addAttribute(pA3);

    oEntity.setSchema(&oClass);

    auto p = oEntity.valueByName(L"name");
    EXPECT_EQ(true, p != nullptr);

    p = oEntity.valueByName(L"xxx");
    EXPECT_EQ(true, p == nullptr);
}

TEST(TestEntity, Entity_isNull)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    oEntity.setSchema(&oClass);

    auto b = oEntity.isNull(L"area");
    EXPECT_EQ(true, b);

    oEntity.setAsDouble(L"area", 0.0);
    b = oEntity.isNull(L"area");
    EXPECT_EQ(false, b);
}

TEST(TestEntity, Entity_isNull_list)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    pA1->SetRepeatFlag(true);
    oClass.addAttribute(pA1);

    oEntity.setSchema(&oClass);

    auto b = oEntity.isNull(L"area");
    EXPECT_EQ(true, b);

    oEntity.addDouble(L"area", 1.0);
    b = oEntity.isNull(L"area");
    EXPECT_EQ(false, b);
}

TEST(TestEntity, Entity_asString)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CStringType oStringType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"name");
    pA1->SetType(&oStringType);
    oClass.addAttribute(pA1);

    oEntity.setSchema(&oClass);

    auto str = oEntity.asString(L"name");
    EXPECT_STREQ("", str.c_str());

    oEntity.setAsString(L"name", "xxx");
    str = oEntity.asString(L"name");
    EXPECT_STREQ("xxx", str.c_str());

    EXPECT_THROW(oEntity.asString(L"t"), gfc::engine::EMissMatchProperty);
    EXPECT_THROW(oEntity.setAsString(L"t", "asdf"), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_asInteger)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    auto n = oEntity.asInteger(L"height");
    EXPECT_EQ(0, n);

    oEntity.setAsInteger(L"height", 234);
    n = oEntity.asInteger(L"height");
    EXPECT_EQ(234, n);

    EXPECT_THROW(oEntity.asInteger(L"t"), gfc::engine::EMissMatchProperty);
    EXPECT_THROW(oEntity.setAsInteger(L"t", -12), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_asEntityRef)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CClass oClass2;
    oClass2.SetName(L"Factory");
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"factory");
    pA2->SetType(&oClass2);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    auto n = oEntity.asEntityRef(L"factory");
    EXPECT_EQ(-1, n);

    oEntity.setAsEntityRef(L"factory", 234);
    n = oEntity.asEntityRef(L"factory");
    EXPECT_EQ(234, n);

    EXPECT_THROW(oEntity.asEntityRef(L"t"), gfc::engine::EMissMatchProperty);
    EXPECT_THROW(oEntity.setAsEntityRef(L"t", -12), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_asBoolean)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CBooleanType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    auto n = oEntity.asBoolean(L"height");
    EXPECT_EQ(false, n);

    oEntity.setAsBoolean(L"height", true);
    n = oEntity.asBoolean(L"height");
    EXPECT_EQ(true, n);

    EXPECT_THROW(oEntity.asBoolean(L"t"), gfc::engine::EMissMatchProperty);
    EXPECT_THROW(oEntity.setAsBoolean(L"t", true), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_asDouble)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    auto n = oEntity.asDouble(L"height");
    EXPECT_NEAR(0.0, n, 1e-7);

    oEntity.setAsDouble(L"height", -345.778);
    n = oEntity.asDouble(L"height");
    EXPECT_NEAR(-345.778, n, 1e-7);

    EXPECT_THROW(oEntity.asDouble(L"t"), gfc::engine::EMissMatchProperty);
    EXPECT_THROW(oEntity.setAsDouble(L"t", true), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_getArrayCount)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    pA2->SetRepeatFlag(true);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    auto n = oEntity.getArrayCount(L"height");
    EXPECT_EQ(0, n);

    oEntity.addInteger(L"height", 25);
    oEntity.addInteger(L"height", 26);
    oEntity.addInteger(L"height", 27);
    n = oEntity.getArrayCount(L"height");
    EXPECT_EQ(3, n);

    EXPECT_THROW(oEntity.getArrayCount(L"t"), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_addInteger)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    pA2->SetRepeatFlag(true);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    oEntity.addInteger(L"height", 25);
    auto pValue = oEntity.valueByName(L"height");
    EXPECT_EQ(true, pValue != nullptr);
    auto n = pValue->getCount();
    EXPECT_EQ(1, n);
    auto val = pValue->getItems(0)->asInteger();
    EXPECT_EQ(25, val);

    EXPECT_THROW(oEntity.addInteger(L"t", 123), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_getInteger)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    pA2->SetRepeatFlag(true);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    oEntity.addInteger(L"height", 25);
    auto val = oEntity.getInteger(L"height", 0);
    EXPECT_EQ(25, val);

    EXPECT_THROW(oEntity.getInteger(L"t", 0), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_addBoolean)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CBooleanType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    pA2->SetRepeatFlag(true);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    oEntity.addBoolean(L"height", true);
    auto pValue = oEntity.valueByName(L"height");
    EXPECT_EQ(true, pValue != nullptr);
    auto n = pValue->getCount();
    EXPECT_EQ(1, n);
    auto val = pValue->getItems(0)->asBoolean();
    EXPECT_EQ(true, val);

    EXPECT_THROW(oEntity.addBoolean(L"t", false), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_getBoolean)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CBooleanType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    pA2->SetRepeatFlag(true);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    oEntity.addBoolean(L"height", true);
    auto val = oEntity.getBoolean(L"height", 0);
    EXPECT_EQ(true, val);

    EXPECT_THROW(oEntity.getBoolean(L"t", 0), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_addEntityRef)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CClass oIntegerType;
    oIntegerType.SetName(L"T2");
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    pA2->SetRepeatFlag(true);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    oEntity.addEntityRef(L"height", 25);
    auto pValue = oEntity.valueByName(L"height");
    EXPECT_EQ(true, pValue != nullptr);
    auto n = pValue->getCount();
    EXPECT_EQ(1, n);
    auto val = pValue->getItems(0)->asEntityRef();
    EXPECT_EQ(25, val);

    EXPECT_THROW(oEntity.addEntityRef(L"t", 123), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_getEntityRef)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CClass oIntegerType;
    oIntegerType.SetName(L"T2");
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    pA2->SetRepeatFlag(true);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    oEntity.addEntityRef(L"height", 25);
    auto val = oEntity.getEntityRef(L"height", 0);
    EXPECT_EQ(25, val);

    EXPECT_THROW(oEntity.getEntityRef(L"t", 0), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_addDouble)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    pA2->SetRepeatFlag(true);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    oEntity.addDouble(L"height", 25);
    auto pValue = oEntity.valueByName(L"height");
    EXPECT_EQ(true, pValue != nullptr);
    auto n = pValue->getCount();
    EXPECT_EQ(1, n);
    auto val = pValue->getItems(0)->asDouble();
    EXPECT_NEAR(25, val, 1e-7);

    EXPECT_THROW(oEntity.addDouble(L"t", 123), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_getDouble)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CRealType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    pA2->SetRepeatFlag(true);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    oEntity.addDouble(L"height", 25);
    auto val = oEntity.getDouble(L"height", 0);
    EXPECT_NEAR(25, val, 1e-7);

    EXPECT_THROW(oEntity.getDouble(L"t", 0), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_addString)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CStringType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    pA2->SetRepeatFlag(true);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    oEntity.addString(L"height", "abc");
    auto pValue = oEntity.valueByName(L"height");
    EXPECT_EQ(true, pValue != nullptr);
    auto n = pValue->getCount();
    EXPECT_EQ(1, n);
    auto val = pValue->getItems(0)->asString();
    EXPECT_STREQ("abc", val.c_str());

    EXPECT_THROW(oEntity.addString(L"t", "123"), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_getString)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");
    gfc::engine::Entity oEntity;

    gfc::schema::CStringType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    pA2->SetRepeatFlag(true);
    oClass.addAttribute(pA2);

    oEntity.setSchema(&oClass);

    oEntity.addString(L"height", "25");
    auto val = oEntity.getString(L"height", 0);
    EXPECT_STREQ("25", val.c_str());

    EXPECT_THROW(oEntity.getString(L"t", 0), gfc::engine::EMissMatchProperty);
}

TEST(TestEntity, Entity_asEntity)
{
    gfc::schema::CModel oModel;
    gfc::engine::Document oDoc(&oModel);

    auto pClass = new gfc::schema::CClass;
    pClass->SetName(L"Test");
    oModel.addTypeObject(pClass);

    auto pClass2 = new gfc::schema::CClass;
    pClass2->SetName(L"Factory");
    oModel.addTypeObject(pClass2);
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"factory");
    pA2->SetType(pClass2);
    pClass->addAttribute(pA2);

    auto pEntity = new gfc::engine::Entity();
    pEntity->setSchema(pClass);
    pEntity->setAsEntityRef(L"factory", 125);
    oDoc.add(123, pEntity);
    auto pEntity2 = new gfc::engine::Entity();
    pEntity2->setSchema(pClass2);
    oDoc.add(125, pEntity2);

    auto n = pEntity->asEntity(L"factory");
    EXPECT_EQ(pEntity2, n.get());
    pEntity->setAsEntityRef(L"factory", 11);
    n = pEntity->asEntity(L"factory");
    EXPECT_EQ(nullptr, n.get());
}

TEST(TestEntity, Entity_getEntity)
{
    gfc::schema::CModel oModel;
    gfc::engine::Document oDoc(&oModel);

    auto pClass = new gfc::schema::CClass;
    pClass->SetName(L"Test");
    oModel.addTypeObject(pClass);

    auto pClass2 = new gfc::schema::CClass;
    pClass2->SetName(L"Factory");
    oModel.addTypeObject(pClass2);
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"factory");
    pA2->SetType(pClass2);
    pA2->SetRepeatFlag(true);
    pClass->addAttribute(pA2);

    auto pEntity = new gfc::engine::Entity();
    pEntity->setSchema(pClass);
    pEntity->addEntityRef(L"factory", 125);
    oDoc.add(123, pEntity);
    auto pEntity2 = new gfc::engine::Entity();
    pEntity2->setSchema(pClass2);
    oDoc.add(125, pEntity2);

    auto n = pEntity->getEntity(L"factory", 0);
    EXPECT_EQ(pEntity2, n.get());
    pEntity->addEntityRef(L"factory", 11);
    n = pEntity->getEntity(L"factory", 1);
    EXPECT_EQ(nullptr, n.get());
}

TEST(TestEntity, Entity_create_parent)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Test");

    gfc::schema::CRealType oDoubleType;
    gfc::schema::CAttribute* pA1 = new gfc::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CAttribute* pA2 = new gfc::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    gfc::schema::CClass oClass2;
    oClass2.SetName(L"Test2");
    oClass2.setParent(&oClass);

    gfc::schema::CStringType oStringType;
    gfc::schema::CAttribute* pA3 = new gfc::schema::CAttribute();
    pA3->SetName(L"name");
    pA3->SetType(&oStringType);
    oClass2.addAttribute(pA3);

    gfc::schema::CBooleanType oBooleanType;
    gfc::schema::CAttribute* pA4 = new gfc::schema::CAttribute();
    pA4->SetRepeatFlag(true);
    pA4->SetType(&oBooleanType);
    pA4->SetName(L"list");
    oClass2.addAttribute(pA4);

    gfc::engine::Entity oEntity;
    oEntity.setSchema(&oClass2);

    EXPECT_EQ(4, oEntity.getPropCount());
    oEntity.setAsString(L"name", "中华人民共和国");
    oEntity.setAsInteger(L"height", 235456);
    oEntity.setAsDouble(L"area", 12.0);
    //oEntity.asBooleanList("list").push_back(true);
    EXPECT_NEAR(12.0, oEntity.asDouble(L"area"), 1e-7);
    EXPECT_EQ(235456, oEntity.asInteger(L"height"));
    EXPECT_STREQ("中华人民共和国", oEntity.asString(L"name").c_str());
    //EXPECT_EQ(true, oEntity.asBooleanList("list")[0]);
}