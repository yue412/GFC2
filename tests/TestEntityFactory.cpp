#include "gtest/gtest.h"
#include "GfcEngine/Entity.h"
#include "GfcEngine/GfcEngineUtils.h"
#include "Common.h"
#include "GfcSchema/EntityClass.h"
#include "GfcSchema/EntityAttribute.h"
#include "GfcSchema/BuildinType.h"
#include "GfcSchema/Model.h"
#include "GfcSchema/EnumType.h"
#include "GfcSchema/TypeDefine.h"

TEST(TestEntityFactory, EntityFactory_create)
{
    gfc::schema::CModel oModel;
    oModel.addTypeObject(new gfc::schema::CClass(L"Test"));
    oModel.addTypeObject(new gfc::schema::CClass(L"Test2"));
    oModel.addTypeObject(new gfc::schema::CClass(L"Test3"));
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Test");
    EXPECT_EQ(true, pEntity != nullptr);
    EXPECT_EQ(true, pEntity->entityName() == L"Test");
    delete pEntity;
}

TEST(TestEntityFactory, EntityFactory_create_null)
{
    gfc::schema::CModel oModel;
    oModel.addTypeObject(new gfc::schema::CClass(L"Test"));
    oModel.addTypeObject(new gfc::schema::CClass(L"Test2"));
    oModel.addTypeObject(new gfc::schema::CClass(L"Test3"));
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"xxsdf");
    EXPECT_EQ(true, pEntity == nullptr);
    delete pEntity;
}

TEST(TestEntityFactory, EntityFactory_create_enum)
{
    gfc::schema::CModel oModel;
    oModel.addTypeObject(new gfc::schema::CEnumType(L"Test"));
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Test");
    EXPECT_EQ(true, pEntity == nullptr);
    delete pEntity;
}

TEST(TestEntityFactory, EntityFactory_create_typedef)
{
    gfc::schema::CModel oModel;
    auto pTypeDef = new gfc::schema::CTypeDef(L"Gfc2Double");
    pTypeDef->SetRefType(oModel.findTypeObject(L"REAL"));
    oModel.addTypeObject(pTypeDef);
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Double");
    EXPECT_EQ(true, pEntity == nullptr);
    delete pEntity;
}

TEST(TestEntityFactory, EntityFactory_create_buildin)
{
    gfc::schema::CModel oModel;
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"REAL");
    EXPECT_EQ(true, pEntity == nullptr);
    delete pEntity;
}

TEST(TestEntityFactory, EntityFactory_create_typedef_class)
{
    std::string sCode =
        "SCHEMA GFC2X1;\n"
        "TYPE Gfc2Double = REAL;\n"
        "END_TYPE;\n"
        "TYPE Gfc2Vector3d_Normal = Gfc2Vector3d;\n"
        "END_TYPE;\n"
        "ENTITY Gfc2Vector3d;\n"
        "	X : Gfc2Double;\n"
        "	Y : Gfc2Double;\n"
        "	Z : Gfc2Double;\n"
        "END_ENTITY;\n"
        "END_SCHEMA;"
        ;
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(sCode.c_str(), sCode.length(), &oModel);
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Vector3d_Normal");
    EXPECT_EQ(true, pEntity != nullptr);
    EXPECT_EQ(true, pEntity->entityName() == L"Gfc2Vector3d_Normal");
    EXPECT_EQ(true, pEntity->getClass()->getName() == L"Gfc2Vector3d");
    delete pEntity;
}
