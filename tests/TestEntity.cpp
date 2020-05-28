#include "gtest\gtest.h"
#include "GfcEngine\EntityFactory.h"
#include "GfcEngine\Entity.h"
#include "Common.h"
#include "EntityClass.h"
#include "EntityAttribute.h"
#include "BuildinType.h"

TEST(TestEntity, Entity_create)
{
    gfc2::engine::EntityFactory oFactory;
    gfc2::schema::CClass oClass;
    oClass.SetName(L"Test");

    gfc2::schema::CRealType oDoubleType;
    gfc2::schema::CAttribute* pA1 = new gfc2::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc2::schema::CIntegerType oIntegerType;
    gfc2::schema::CAttribute* pA2 = new gfc2::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    gfc2::schema::CStringType oStringType;
    gfc2::schema::CAttribute* pA3 = new gfc2::schema::CAttribute();
    pA3->SetName(L"name");
    pA3->SetType(&oStringType);
    oClass.addAttribute(pA3);

    gfc2::schema::CBooleanType oBooleanType;
    gfc2::schema::CAttribute* pA4 = new gfc2::schema::CAttribute();
    pA4->SetRepeatFlag(true);
    pA4->SetType(&oBooleanType);
    pA4->SetName(L"list");
    oClass.addAttribute(pA4);

    gfc2::engine::Entity oEntity;
    oEntity.setSchema(&oClass);

    oEntity.setAsString("name", "中华人民共和国");
    oEntity.setAsInteger("height", 235456);
    oEntity.setAsDouble("area", 12.0);
    //oEntity.asBooleanList("list").push_back(true);
    EXPECT_NEAR(12.0, oEntity.asDouble("area"), 1e-7);
    EXPECT_EQ(235456, oEntity.asInteger("height"));
    EXPECT_STREQ("中华人民共和国", oEntity.asString("name").c_str());
    //EXPECT_EQ(true, oEntity.asBooleanList("list")[0]);
}

TEST(TestEntity, Entity_isNull)
{
    gfc2::engine::EntityFactory oFactory;
    gfc2::schema::CClass oClass;
    oClass.SetName(L"Test");

    gfc2::schema::CRealType oDoubleType;
    gfc2::schema::CAttribute* pA1 = new gfc2::schema::CAttribute();
    pA1->SetName(L"area");
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc2::schema::CIntegerType oIntegerType;
    gfc2::schema::CAttribute* pA2 = new gfc2::schema::CAttribute();
    pA2->SetName(L"height");
    pA2->SetType(&oIntegerType);
    oClass.addAttribute(pA2);

    gfc2::schema::CStringType oStringType;
    gfc2::schema::CAttribute* pA3 = new gfc2::schema::CAttribute();
    pA3->SetName(L"name");
    pA3->SetType(&oStringType);
    oClass.addAttribute(pA3);

    gfc2::schema::CBooleanType oBooleanType;
    gfc2::schema::CAttribute* pA4 = new gfc2::schema::CAttribute();
    pA4->SetType(&oBooleanType);
    pA4->SetName(L"sex");
    oClass.addAttribute(pA4);

    gfc2::schema::CClass oClass2;
    oClass2.SetName(L"Test2");
    gfc2::schema::CAttribute* pA5 = new gfc2::schema::CAttribute();
    pA5->SetType(&oClass2);
    pA5->SetName(L"other");
    oClass.addAttribute(pA5);

    //oFactory.initClass(&oClass);

    gfc2::engine::Entity oEntity;
    oEntity.setSchema(&oClass);

    EXPECT_EQ(true, oEntity.isNull("area"));
    EXPECT_EQ(true, oEntity.isNull("height"));
    EXPECT_EQ(true, oEntity.isNull("name"));
    EXPECT_EQ(true, oEntity.isNull("sex"));
    EXPECT_EQ(true, oEntity.isNull("other"));
    oEntity.setAsString("name", "中华人民共和国");
    oEntity.setAsInteger("height", 235456);
    oEntity.setAsDouble("area", 12.0);
    oEntity.setAsBoolean("sex", true);
    oEntity.setAsEntityRef("other", 123);
    EXPECT_NEAR(12.0, oEntity.asDouble("area"), 1e-7);
    EXPECT_EQ(235456, oEntity.asInteger("height"));
    EXPECT_STREQ("中华人民共和国", oEntity.asString("name").c_str());
    EXPECT_EQ(true, oEntity.asBoolean("sex"));
    EXPECT_EQ(123, oEntity.asEntityRef("other"));
    EXPECT_EQ(false, oEntity.isNull("area"));
    EXPECT_EQ(false, oEntity.isNull("height"));
    EXPECT_EQ(false, oEntity.isNull("name"));
    EXPECT_EQ(false, oEntity.isNull("sex"));
    EXPECT_EQ(false, oEntity.isNull("other"));
}