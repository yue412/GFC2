#include "gtest\gtest.h"
#include "GfcEngine\EntityFactory.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\GfcEngineUtils.h"
#include "Common.h"
#include "EntityClass.h"
#include "EntityAttribute.h"
#include "BuildinType.h"
#include "Model.h"
#include "EnumType.h"
#include "TypeDefine.h"

TEST(TestEntityFactory, EntityFactory_create)
{
    gfc2::schema::CModel oModel;
    oModel.addTypeObject(new gfc2::schema::CClass(L"Test"));
    oModel.addTypeObject(new gfc2::schema::CClass(L"Test2"));
    oModel.addTypeObject(new gfc2::schema::CClass(L"Test3"));
    gfc2::engine::EntityFactory oFactory(&oModel, false);
    auto pEntity = oFactory.create(L"Test");
    EXPECT_EQ(true, pEntity != nullptr);
    EXPECT_EQ(true, pEntity->entityName() == L"Test");
    delete pEntity;
}

TEST(TestEntityFactory, EntityFactory_create_null)
{
    gfc2::schema::CModel oModel;
    oModel.addTypeObject(new gfc2::schema::CClass(L"Test"));
    oModel.addTypeObject(new gfc2::schema::CClass(L"Test2"));
    oModel.addTypeObject(new gfc2::schema::CClass(L"Test3"));
    gfc2::engine::EntityFactory oFactory(&oModel, false);
    auto pEntity = oFactory.create(L"xxsdf");
    EXPECT_EQ(true, pEntity == nullptr);
    delete pEntity;
}

TEST(TestEntityFactory, EntityFactory_create_enum)
{
    gfc2::schema::CModel oModel;
    oModel.addTypeObject(new gfc2::schema::CEnumType(L"Test"));
    gfc2::engine::EntityFactory oFactory(&oModel, false);
    auto pEntity = oFactory.create(L"Test");
    EXPECT_EQ(true, pEntity == nullptr);
    delete pEntity;
}

TEST(TestEntityFactory, EntityFactory_create_typedef)
{
    gfc2::schema::CModel oModel;
    auto pTypeDef = new gfc2::schema::CTypeDef(L"Gfc2Double");
    pTypeDef->SetRefType(oModel.findTypeObject(L"REAL"));
    oModel.addTypeObject(pTypeDef);
    gfc2::engine::EntityFactory oFactory(&oModel, false);
    auto pEntity = oFactory.create(L"Gfc2Double");
    EXPECT_EQ(true, pEntity == nullptr);
    delete pEntity;
}

TEST(TestEntityFactory, EntityFactory_create_buildin)
{
    gfc2::schema::CModel oModel;
    gfc2::engine::EntityFactory oFactory(&oModel, false);
    auto pEntity = oFactory.create(L"REAL");
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
    gfc2::engine::EntityFactory* pFactory = gfc2::engine::GfcEngineUtils::createFactory(sCode.c_str(), sCode.length());
    auto pEntity = pFactory->create(L"Gfc2Vector3d_Normal");
    EXPECT_EQ(true, pEntity != nullptr);
    EXPECT_EQ(true, pEntity->entityName() == L"Gfc2Vector3d_Normal");
    EXPECT_EQ(true, pEntity->getClass()->getName() == L"Gfc2Vector3d");
    delete pEntity;
    delete pFactory;
}
