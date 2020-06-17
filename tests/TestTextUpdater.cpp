#include "gtest\gtest.h"
#include "Upgrader.h"
#include "GfcSchema/EntityClass.h"
#include "GfcSchema/EntityAttribute.h"
#include "GfcSchema/BuildinType.h"
#include "GfcUtils\ClassCompatibility.h"
#include "GfcEngine/PropValue.h"
#include "GfcEngine\Entity.h"

TEST(TestUpdater, transform_same)
{
    gfc::engine::CUpgrader oUpdater;

    gfc::schema::CClass oFromClass, oToClass;
    gfc::schema::CAttribute* pFromAttrib1 = new gfc::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromClass.addAttribute(pFromAttrib1);

    gfc::schema::CAttribute* pToAttrib1 = new gfc::schema::CAttribute();
    pToAttrib1->SetName(L"ID");
    //gfc::schema::CIntegerType oType;
    pToAttrib1->SetType(&oType);
    oToClass.addAttribute(pToAttrib1);

    gfc::engine::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);

    gfc::engine::CEntity oFromEntity;
    oFromEntity.setSchema(&oFromClass);
    gfc::engine::CEntity oToEntity;
    oToEntity.setSchema(&oToClass);

    oFromEntity.setAsInteger(L"ID", 123);
    oUpdater.transform(&oCompatibility, &oFromEntity, &oToEntity);
    
    EXPECT_EQ(123, oToEntity.asInteger(L"ID"));
}

TEST(TestUpdater, transform_delete)
{
    gfc::engine::CUpgrader oUpdater;

    gfc::schema::CClass oFromClass, oToClass;
    gfc::schema::CAttribute* pFromAttrib1 = new gfc::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromClass.addAttribute(pFromAttrib1);

    gfc::engine::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);

    gfc::engine::CEntity oFromEntity;
    oFromEntity.setSchema(&oFromClass);
    gfc::engine::CEntity oToEntity;
    oToEntity.setSchema(&oToClass);

    oFromEntity.setAsInteger(L"ID", 123);
    oUpdater.transform(&oCompatibility, &oFromEntity, &oToEntity);

    EXPECT_EQ(0, oToEntity.getPropCount());
}

TEST(TestUpdater, transform_add)
{
    gfc::engine::CUpgrader oUpdater;

    gfc::schema::CClass oFromClass, oToClass;
    gfc::schema::CAttribute* pFromAttrib1 = new gfc::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromClass.addAttribute(pFromAttrib1);

    gfc::schema::CAttribute* pToAttrib1 = new gfc::schema::CAttribute();
    pToAttrib1->SetName(L"Name");
    //gfc::schema::CIntegerType oType;
    pToAttrib1->SetType(&oType);
    oToClass.addAttribute(pToAttrib1);

    gfc::engine::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);

    gfc::engine::CEntity oFromEntity;
    oFromEntity.setSchema(&oFromClass);
    gfc::engine::CEntity oToEntity;
    oToEntity.setSchema(&oToClass);

    oFromEntity.setAsInteger(L"ID", 123);
    oUpdater.transform(&oCompatibility, &oFromEntity, &oToEntity);

    EXPECT_EQ(true, oToEntity.isNull(L"Name"));
}

TEST(TestUpdater, transform_exchange)
{
    gfc::engine::CUpgrader oUpdater;

    gfc::schema::CClass oFromClass, oToClass;
    gfc::schema::CAttribute* pFromAttrib1 = new gfc::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromClass.addAttribute(pFromAttrib1);

    gfc::schema::CAttribute* pFromAttrib2 = new gfc::schema::CAttribute();
    pFromAttrib2->SetName(L"Name");
    gfc::schema::CStringType oType2;
    pFromAttrib2->SetType(&oType2);
    oFromClass.addAttribute(pFromAttrib2);


    gfc::schema::CAttribute* pToAttrib1 = new gfc::schema::CAttribute();
    pToAttrib1->SetName(L"ID");
    //gfc::schema::CIntegerType oType;
    pToAttrib1->SetType(&oType);

    gfc::schema::CAttribute* pToAttrib2 = new gfc::schema::CAttribute();
    pToAttrib2->SetName(L"Name");
    //gfc::schema::CBuildinType oType(L"STRING");
    pToAttrib2->SetType(&oType2);

    oToClass.addAttribute(pToAttrib2);
    oToClass.addAttribute(pToAttrib1);

    gfc::engine::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);

    gfc::engine::CEntity oFromEntity;
    oFromEntity.setSchema(&oFromClass);
    gfc::engine::CEntity oToEntity;
    oToEntity.setSchema(&oToClass);

    oFromEntity.setAsInteger(L"ID", 123);
    oFromEntity.setAsString(L"Name", L"abc");
    oUpdater.transform(&oCompatibility, &oFromEntity, &oToEntity);

    EXPECT_EQ(123, oToEntity.asInteger(L"ID"));
    EXPECT_STREQ(L"abc", oToEntity.asString(L"Name").c_str());
}
