#include "gtest/gtest.h"
#include "GfcEngine/Writer.h"
#include "GfcEngine/Reader.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/GfcEngineUtils.h"
//#include "Classes/Gfc2EdgeData.h"
#include "Common.h"
#include "GfcSchema/Model.h"
//#if (defined _WIN32 || defined _WIN64)
#include "GMath/GCoordinates3.h"
#include "GfcUtils/GfcGeometryExporter.h"
#include "GfcUtils/GfcGeometryImporter.h"
//#endif

TEST(TestGFCEngine, WriteEmptyFile)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CWriter writer(&oModel, L"gfc2_unit_test");
    auto result = writer.open(getFullPath(L"empty.gfc"), L"express");
    EXPECT_EQ(true, result);
}

TEST(TestGFCEngine, WriteFile)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CWriter writer(&oModel, L"gfc2_unit_test");
    auto result = writer.open(getFullPath(L"one.gfc"), L"express");
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Vector3d");
    //Gfc2Vector3d oVector;
    //oVector.setX(1.0);
    //oVector.setY(2.0);
    //oVector.setZ(3.0);
    pEntity->setAsDouble(L"X", 1.0);
    pEntity->setAsDouble(L"Y", 2.0);
    pEntity->setAsDouble(L"Z", 3.0);
    writer.writeEntity(pEntity);
    EXPECT_EQ(true, result);
}

TEST(TestGFCEngine, ReadFile)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    gfc::engine::CDocument document(&oModel);
    auto result = reader.open(getFullPath(L"one.gfc"));
    EXPECT_EQ(true, result);
    if (result)
    {
        reader.read(&document);
        reader.close();

        auto itr = document.getIterator();
        itr->first();
        EXPECT_EQ(false, itr->isDone());
        auto pEntity = itr->current();
        EXPECT_EQ(true, pEntity != nullptr);
        EXPECT_NEAR(1.0, pEntity->asDouble(L"X"), 1e-6);
        EXPECT_NEAR(2.0, pEntity->asDouble(L"Y"), 1e-6);
        EXPECT_NEAR(3.0, pEntity->asDouble(L"Z"), 1e-6);
    }
}

TEST(TestGFCEngine, WriteFile_old)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CWriter writer(&oModel, L"gfc2_unit_test", CP_UTF8, false);
    auto result = writer.open(getFullPath(L"WriteFile_old.gfc"), L"express");
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Vector3d");
    //Gfc2Vector3d oVector;
    //oVector.setX(1.0);
    //oVector.setY(2.0);
    //oVector.setZ(3.0);
    pEntity->setAsDouble(L"X", 1.0);
    pEntity->setAsDouble(L"Y", 2.0);
    pEntity->setAsDouble(L"Z", 3.0);
    writer.writeEntity(pEntity);
    EXPECT_EQ(true, result);
}

TEST(TestGFCEngine, ReadFile_old)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    gfc::engine::CDocument document(&oModel);
    auto result = reader.open(getFullPath(L"WriteFile_old.gfc"));
    EXPECT_EQ(true, result);
    if (result)
    {
        reader.read(&document);
        reader.close();

        auto itr = document.getIterator();
        itr->first();
        EXPECT_EQ(false, itr->isDone());
        auto pEntity = itr->current();
        EXPECT_EQ(true, pEntity != nullptr);
        EXPECT_NEAR(1.0, pEntity->asDouble(L"X"), 1e-6);
        EXPECT_NEAR(2.0, pEntity->asDouble(L"Y"), 1e-6);
        EXPECT_NEAR(3.0, pEntity->asDouble(L"Z"), 1e-6);
    }
}

TEST(TestGFCEngine, ReadEmptyFile)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    gfc::engine::CDocument document(&oModel);
    auto result = reader.open(getFullPath(L"empty.gfc"));
    EXPECT_EQ(true, result);
    if (result)
    {
        reader.read(&document);
        auto itr = document.getIterator();
        itr->first();
        EXPECT_EQ(true, itr->isDone());
    }
}

TEST(TestGFCEngine, WriteFile2)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CWriter writer(&oModel, L"gfc2_unit_test");
    auto result = writer.open(getFullPath(L"two.gfc"), L"express");
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Vector3d");
        pEntity->setAsDouble(L"X", 1.0);
        pEntity->setAsDouble(L"Y", 2.0);
        pEntity->setAsDouble(L"Z", 3.0);
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Vector2d");
        pEntity->setAsDouble(L"X", 11.0);
        pEntity->setAsDouble(L"Y", 22.0);
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
}

TEST(TestGFCEngine, Read_getEntity)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    gfc::engine::CDocument document(&oModel);
    auto result = reader.open(getFullPath(L"two.gfc"));
    EXPECT_EQ(true, result);
    if (result)
    {
        {
            auto pEntity = reader.getEntity(1);

            EXPECT_EQ(true, pEntity != nullptr);
            EXPECT_NEAR(1.0, pEntity->asDouble(L"X"), 1e-6);
            EXPECT_NEAR(2.0, pEntity->asDouble(L"Y"), 1e-6);
            EXPECT_NEAR(3.0, pEntity->asDouble(L"Z"), 1e-6);
        }
        {
            auto pEntity = reader.getEntity(2);

            EXPECT_EQ(true, pEntity != nullptr);
            EXPECT_NEAR(11.0, pEntity->asDouble(L"X"), 1e-6);
            EXPECT_NEAR(22.0, pEntity->asDouble(L"Y"), 1e-6);
        }
        {
            auto pEntity = reader.getEntity(3);

            EXPECT_EQ(false, pEntity != nullptr);
        }
        reader.close();
    }
}

TEST(TestGFCEngine, WriteFile3)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CWriter writer(&oModel, L"gfc2_unit_test");
    auto result = writer.open(getFullPath(L"three.gfc"), L"express");
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Floor");
        pEntity->setAsDouble(L"Height", 1.0);
        pEntity->setAsInteger(L"StdFloorCount", 2);
        pEntity->setAsDouble(L"StructuralElevation", 3.0);
        pEntity->setAsInteger(L"StartFloorNo", 2);
        pEntity->setAsString(L"ID", L"2");
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Building");
        pEntity->setAsString(L"ID", L"3");
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Element");
        pEntity->setAsString(L"ID", L"4");
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
}

TEST(TestGFCEngine, Read_getEntities)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    gfc::engine::CDocument document(&oModel);
    auto result = reader.open(getFullPath(L"three.gfc"));
    EXPECT_EQ(true, result);
    if (result)
    {
        {
            auto itr = reader.getEntities(L"Gfc2Object", true);
            itr->first();
            EXPECT_EQ(false, itr->isDone());
            {
                auto pEntity = itr->current();
                EXPECT_EQ(true, pEntity != nullptr);
                EXPECT_STREQ(L"Gfc2Element", pEntity->entityName().c_str());
                EXPECT_STREQ(L"4", pEntity->asString(L"ID").c_str());
                EXPECT_EQ(true, pEntity->isNull(L"Name"));
                EXPECT_EQ(true, pEntity->isNull(L"EType"));
                EXPECT_EQ(true, pEntity->isNull(L"Representations"));
                EXPECT_EQ(true, pEntity->isNull(L"Shapes"));
            }
            itr->next();
            EXPECT_EQ(false, itr->isDone());
            {
                auto pEntity = itr->current();
                EXPECT_EQ(true, pEntity != nullptr);
                EXPECT_STREQ(L"Gfc2Building", pEntity->entityName().c_str());
                EXPECT_STREQ(L"3", pEntity->asString(L"ID").c_str());
                EXPECT_EQ(true, pEntity->isNull(L"Name"));
            }
            itr->next();
            EXPECT_EQ(false, itr->isDone());
            {
                auto pEntity = itr->current();
                EXPECT_EQ(true, pEntity != nullptr);
                EXPECT_STREQ(L"Gfc2Floor", pEntity->entityName().c_str());
                EXPECT_STREQ(L"2", pEntity->asString(L"ID").c_str());
                EXPECT_EQ(true, pEntity->isNull(L"Name"));
                EXPECT_NEAR(1.0, pEntity->asDouble(L"Height"), 1e-7);
                EXPECT_EQ(2, pEntity->asInteger(L"StdFloorCount"));
                EXPECT_NEAR(3.0, pEntity->asDouble(L"StructuralElevation"), 1e-7);
                EXPECT_EQ(2, pEntity->asInteger(L"StartFloorNo"));
            }
            itr->next();
            EXPECT_EQ(true, itr->isDone());
        }
        {
            auto itr = reader.getEntities(L"Gfc2Site", true);
            itr->first();
            EXPECT_EQ(true, itr->isDone());
        }
        reader.close();
    }
}

TEST(TestGFCEngine, Read_getIterator)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    gfc::engine::CDocument document(&oModel);
    auto result = reader.open(getFullPath(L"three.gfc"));
    EXPECT_EQ(true, result);
    if (result)
    {
        {
            auto itr = reader.getIterator();
            itr->first();
            EXPECT_EQ(false, itr->isDone());
            {
                auto pEntity = itr->current();
                EXPECT_EQ(true, pEntity != nullptr);
                EXPECT_STREQ(L"Gfc2Building", pEntity->entityName().c_str());
                EXPECT_STREQ(L"3", pEntity->asString(L"ID").c_str());
                EXPECT_EQ(true, pEntity->isNull(L"Name"));
            }
            itr->next();
            EXPECT_EQ(false, itr->isDone());
            {
                auto pEntity = itr->current();
                EXPECT_EQ(true, pEntity != nullptr);
                EXPECT_STREQ(L"Gfc2Element", pEntity->entityName().c_str());
                EXPECT_STREQ(L"4", pEntity->asString(L"ID").c_str());
                EXPECT_EQ(true, pEntity->isNull(L"Name"));
                EXPECT_EQ(true, pEntity->isNull(L"EType"));
                EXPECT_EQ(true, pEntity->isNull(L"Representations"));
                EXPECT_EQ(true, pEntity->isNull(L"Shapes"));
            }
            itr->next();
            EXPECT_EQ(false, itr->isDone());
            {
                auto pEntity = itr->current();
                EXPECT_EQ(true, pEntity != nullptr);
                EXPECT_STREQ(L"Gfc2Floor", pEntity->entityName().c_str());
                EXPECT_STREQ(L"2", pEntity->asString(L"ID").c_str());
                EXPECT_EQ(true, pEntity->isNull(L"Name"));
                EXPECT_NEAR(1.0, pEntity->asDouble(L"Height"), 1e-7);
                EXPECT_EQ(2, pEntity->asInteger(L"StdFloorCount"));
                EXPECT_NEAR(3.0, pEntity->asDouble(L"StructuralElevation"), 1e-7);
                EXPECT_EQ(2, pEntity->asInteger(L"StartFloorNo"));
            }
            itr->next();
            EXPECT_EQ(true, itr->isDone());
        }
        reader.close();
    }
}

TEST(TestGFCEngine, WriteRefFile)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CWriter writer(&oModel, L"gfc2_unit_test");
    auto result = writer.open(getFullPath(L"ref.gfc"), L"express");
    gfc::engine::EntityRef /*nRef1,*/ nRef2, /*nRef3, */nRef4;
    //{
    //    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2String");
    //    pEntity->setAsString(L"Value", L"中国");
    //    nRef1 = writer.writeEntity(pEntity);
    //    EXPECT_EQ(true, result);
    //}
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2ElementShape");
        pEntity->setAsString(L"Identifier", L"中国");
        nRef2 = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    //{
    //    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2String");
    //    pEntity->setAsString(L"Value", L"人民");
    //    nRef3 = writer.writeEntity(pEntity);
    //    EXPECT_EQ(true, result);
    //}
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2ElementShape");
        pEntity->setAsString(L"Identifier", L"人民");
        nRef4 = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Element");
        pEntity->setAsString(L"ID", L"4");
        pEntity->addEntityRef(L"Shapes", nRef2);
        pEntity->addEntityRef(L"Shapes", nRef4);
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
}

TEST(TestGFCEngine, Read_getRef)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    gfc::engine::CDocument document(&oModel);
    auto result = reader.open(getFullPath(L"ref.gfc"));
    EXPECT_EQ(true, result);
    if (result)
    {
        {
            auto itr = reader.getEntities(L"Gfc2Element");

            itr->first();

            EXPECT_EQ(false, itr->isDone());
            auto pElement = itr->current();
            EXPECT_STREQ(L"4", pElement->asString(L"ID").c_str());
            EXPECT_EQ(2, pElement->getArrayCount(L"Shapes"));
            {
                auto pShape1 = pElement->getEntity(L"Shapes", 0);
                EXPECT_EQ(true, pShape1 != nullptr);
                EXPECT_EQ(true, pShape1->isNull(L"Shape"));
                EXPECT_STREQ(L"中国", pShape1->asString(L"Identifier").c_str());
            }
            {
                auto pShape1 = pElement->getEntity(L"Shapes", 1);
                EXPECT_EQ(true, pShape1 != nullptr);
                EXPECT_EQ(true, pShape1->isNull(L"Shape"));
                EXPECT_STREQ(L"人民", pShape1->asString(L"Identifier").c_str());
            }

            itr->next();
            EXPECT_EQ(true, itr->isDone());
        }
        reader.close();
    }
}
#if (defined _WIN32 || defined _WIN64)
TEST(TestGFCEngine, WriteColumnDemoFile)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CWriter writer(&oModel, L"demo");
    auto result = writer.open(getFullPath(L"column.gfc"), L"express");
    gfc::engine::EntityRef nProjectRef = -1;
    gfc::engine::EntityRef nBuildingRef = -1;
    std::vector<gfc::engine::EntityRef> oFloorRefList;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Project");
        pEntity->setAsString(L"ID", generateGuid());
        pEntity->setAsString(L"Name", L"Demo");
        nProjectRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Building");
        pEntity->setAsString(L"ID", generateGuid());
        pEntity->setAsString(L"Name", L"Building");
        nBuildingRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2RelAggregates");
        pEntity->setAsEntityRef(L"RelatingObject", nProjectRef);
        pEntity->addEntityRef(L"RelatedObjects", nBuildingRef);
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Floor");
        pEntity->setAsDouble(L"Height", 0);
        pEntity->setAsInteger(L"StdFloorCount", 1);
        pEntity->setAsDouble(L"StructuralElevation", 3.0);
        pEntity->setAsInteger(L"StartFloorNo", 1);
        pEntity->setAsString(L"Name", L"first floor");
        pEntity->setAsString(L"ID", generateGuid());
        oFloorRefList.push_back(writer.writeEntity(pEntity));
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Floor");
        pEntity->setAsDouble(L"Height", 3000);
        pEntity->setAsInteger(L"StdFloorCount", 3);
        pEntity->setAsDouble(L"StructuralElevation", 3.0);
        pEntity->setAsInteger(L"StartFloorNo", 2);
        pEntity->setAsString(L"Name", L"2~3 floor");
        pEntity->setAsString(L"ID", generateGuid());
        oFloorRefList.push_back(writer.writeEntity(pEntity));
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2RelAggregates");
        pEntity->setAsEntityRef(L"RelatingObject", nBuildingRef);
        for each (auto nRef in oFloorRefList)
        {
            pEntity->addEntityRef(L"RelatedObjects", nRef);
        }
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    auto nSectionRef = -1;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2RectangleSection");
        ggp::CCoordinates2d oCoord;
        oCoord.Origin.Set(500, 100);
        pEntity->setAsEntityRef(L"Position", GfcGeometryExporter::exportCoordinates2d(&writer, &oCoord));
        pEntity->setAsDouble(L"XLength", 300);
        pEntity->setAsDouble(L"YLength", 400);
        nSectionRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    auto nShapeRef = -1;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2ExtrudedAreaSolidShape");
        ggp::CCoordinates3d oCoord;
        pEntity->setAsEntityRef(L"LocalCoordinate", GfcGeometryExporter::exportCoordinates3d(&writer, &oCoord));
        pEntity->setAsEntityRef(L"SweptArea", nSectionRef);
        pEntity->setAsEntityRef(L"ExtrudedDirection", GfcGeometryExporter::exportVector3d(&writer, &ggp::CVector3d(0.0, 0.0, 1.0)));
        pEntity->setAsDouble(L"Len", 3000);
        nShapeRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    auto nElementShapeRef = -1;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2ElementShape");
        pEntity->setAsString(L"Identifier", L"body");
        pEntity->setAsEntityRef(L"Shape", nShapeRef);
        nElementShapeRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    gfc::engine::EntityRef nElementRef = -1;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Element");
        pEntity->setAsString(L"ID", generateGuid());
        pEntity->setAsString(L"Name", L"KZ-1");
        pEntity->setAsString(L"EType", L"14-07.35.07");
        pEntity->addEntityRef(L"Shapes", nElementShapeRef);
        nElementRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2RelAggregates");
        pEntity->setAsEntityRef(L"RelatingObject", oFloorRefList[0]);
        pEntity->addEntityRef(L"RelatedObjects", nElementRef);
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    std::vector<gfc::engine::EntityRef> oPropRefList;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2StringProperty");
        pEntity->setAsString(L"Name", L"名称");
        pEntity->setAsString(L"Code", L"Description");
        pEntity->setAsString(L"Val", L"KZ-1");
        oPropRefList.push_back(writer.writeEntity(pEntity));
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2StringProperty");
        pEntity->setAsString(L"Name", L"类别");
        pEntity->setAsString(L"Code", L"Type");
        pEntity->setAsString(L"Val", L"框架柱");
        oPropRefList.push_back(writer.writeEntity(pEntity));
        EXPECT_EQ(true, result);
    }
    auto nPropertySetRef = -1;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2PropertySet");
        for each (auto nRef in oPropRefList)
        {
            pEntity->addEntityRef(L"HasProperties", nRef);
        }
        nPropertySetRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2RelDefinesByProperties");
        pEntity->setAsEntityRef(L"RelatingPropertySet", nPropertySetRef);
        pEntity->addEntityRef(L"RelatedObjects", nElementRef);
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
}

TEST(TestGFCEngine2, WriteColumnDemoFile)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CWriter writer(&oModel, L"demo");
    auto result = writer.open(getFullPath(L"column.gfc"), L"express");
    gfc::engine::EntityRef nProjectRef = -1;
    gfc::engine::EntityRef nBuildingRef = -1;
    std::vector<gfc::engine::EntityRef> oFloorRefList;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Project");
        pEntity->setAsString(L"ID", generateGuid());
        pEntity->setAsString(L"Name", L"Demo");
        nProjectRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Building");
        pEntity->setAsString(L"ID", generateGuid());
        pEntity->setAsString(L"Name", L"Building");
        nBuildingRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2RelAggregates");
        pEntity->setAsEntityRef(L"RelatingObject", nProjectRef);
        pEntity->addEntityRef(L"RelatedObjects", nBuildingRef);
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Floor");
        pEntity->setAsDouble(L"Height", 0);
        pEntity->setAsInteger(L"StdFloorCount", 1);
        pEntity->setAsDouble(L"StructuralElevation", 3.0);
        pEntity->setAsInteger(L"StartFloorNo", 1);
        pEntity->setAsString(L"Name", L"first floor");
        pEntity->setAsString(L"ID", generateGuid());
        oFloorRefList.push_back(writer.writeEntity(pEntity));
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Floor");
        pEntity->setAsDouble(L"Height", 3000);
        pEntity->setAsInteger(L"StdFloorCount", 3);
        pEntity->setAsDouble(L"StructuralElevation", 3.0);
        pEntity->setAsInteger(L"StartFloorNo", 2);
        pEntity->setAsString(L"Name", L"2~3 floor");
        pEntity->setAsString(L"ID", generateGuid());
        oFloorRefList.push_back(writer.writeEntity(pEntity));
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2RelAggregates");
        pEntity->setAsEntityRef(L"RelatingObject", nBuildingRef);
        for each (auto nRef in oFloorRefList)
        {
            pEntity->addEntityRef(L"RelatedObjects", nRef);
        }
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    auto nSectionRef = -1;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2RectangleSection");
        ggp::CCoordinates2d oCoord;
        oCoord.Origin.Set(500, 100);
        pEntity->setAsEntityRef(L"Position", GfcGeometryExporter::exportCoordinates2d(&writer, &oCoord));
        pEntity->setAsDouble(L"XLength", 300);
        pEntity->setAsDouble(L"YLength", 400);
        nSectionRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    auto nShapeRef = -1;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2ExtrudedAreaSolidShape");
        ggp::CCoordinates3d oCoord;
        pEntity->setAsEntityRef(L"LocalCoordinate", GfcGeometryExporter::exportCoordinates3d(&writer, &oCoord));
        pEntity->setAsEntityRef(L"SweptArea", nSectionRef);
        pEntity->setAsEntityRef(L"ExtrudedDirection", GfcGeometryExporter::exportVector3d(&writer, &ggp::CVector3d(0.0, 0.0, 1.0)));
        pEntity->setAsDouble(L"Len", 3000);
        nShapeRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    auto nElementShapeRef = -1;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2ElementShape");
        pEntity->setAsString(L"Identifier", L"body");
        pEntity->setAsEntityRef(L"Shape", nShapeRef);
        nElementShapeRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    gfc::engine::EntityRef nElementRef = -1;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Element");
        pEntity->setAsString(L"ID", generateGuid());
        pEntity->setAsString(L"Name", L"KZ-1");
        pEntity->setAsString(L"EType", L"14-07.35.07");
        pEntity->addEntityRef(L"Shapes", nElementShapeRef);
        nElementRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2RelAggregates");
        pEntity->setAsEntityRef(L"RelatingObject", oFloorRefList[0]);
        pEntity->addEntityRef(L"RelatedObjects", nElementRef);
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    std::vector<gfc::engine::EntityRef> oPropRefList;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2StringProperty");
        pEntity->setAsString(L"Name", L"名称");
        pEntity->setAsString(L"Code", L"Description");
        pEntity->setAsString(L"Val", L"KZ-1");
        oPropRefList.push_back(writer.writeEntity(pEntity));
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2StringProperty");
        pEntity->setAsString(L"Name", L"类别");
        pEntity->setAsString(L"Code", L"Type");
        pEntity->setAsString(L"Val", L"框架柱");
        oPropRefList.push_back(writer.writeEntity(pEntity));
        EXPECT_EQ(true, result);
    }
    auto nPropertySetRef = -1;
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2PropertySet");
        for each (auto nRef in oPropRefList)
        {
            pEntity->addEntityRef(L"HasProperties", nRef);
        }
        nPropertySetRef = writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
    {
        auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2RelDefinesByProperties");
        pEntity->setAsEntityRef(L"RelatingPropertySet", nPropertySetRef);
        pEntity->addEntityRef(L"RelatedObjects", nElementRef);
        writer.writeEntity(pEntity);
        EXPECT_EQ(true, result);
    }
}
#endif
//TEST(BinaryWriterTest, WriteEmptyFile)
//{
//    gfc::engine::CWriter writer;
//    auto result = writer.open(UnicodeToUtf8(getFullPath(L"empty_bin.gfc")), "bin", "gfc2_unit_test");
//    EXPECT_EQ(true, result);
//}
//
//TEST(BinaryWriterTest, WriteFile)
//{
//    gfc::engine::CWriter writer;
//    auto result = writer.open(UnicodeToUtf8(getFullPath(L"one_bin.gfc")), "bin", "gfc2_unit_test");
//    Gfc2Vector3d oVector;
//    oVector.setX(1.0);
//    oVector.setY(2.0);
//    oVector.setZ(3.0);
//    writer.writeEntity(&oVector);
//    EXPECT_EQ(true, result);
//}
//
//TEST(BinaryReaderTest, ReadFile)
//{
//    gfc::engine::CReader reader;
//    gfc::engine::CDocument document(1);
//    auto result = reader.read(UnicodeToUtf8(getFullPath(L"one_bin.gfc")), &document);
//    EXPECT_EQ(true, result);
//    auto itr = document.getIterator();
//    itr.first();
//    itr.next();
//    itr.next();
//    EXPECT_EQ(false, itr.isDone());
//    Gfc2Vector3d* vec = (Gfc2Vector3d*)itr.current();
//    EXPECT_NEAR(1.0, vec->getX(), 1e-6);
//    EXPECT_NEAR(2.0, vec->getY(), 1e-6);
//    EXPECT_NEAR(3.0, vec->getZ(), 1e-6);
//}
//
//TEST(BinaryReaderTest, ReadEmptyFile)
//{
//    gfc::engine::CReader reader;
//    gfc::engine::CDocument document;
//    auto result = reader.read(UnicodeToUtf8(getFullPath(L"empty_bin.gfc")), &document);
//    EXPECT_EQ(true, result);
//    //EXPECT_EQ(0, document
//}
//
//TEST(TextReaderTest, ReadFile_update_add_attribute)
//{
//    gfc::engine::CReader reader;
//    gfc::engine::CDocument document(1);
//    auto result = reader.read(UnicodeToUtf8(getFullPath(L"one1x9.gfc")), &document);
//    EXPECT_EQ(true, result);
//    auto itr = document.getIterator();
//    itr.first();
//    itr.next();
//    EXPECT_EQ(false, itr.isDone());
//    Gfc2Vector3d* vec = (Gfc2Vector3d*)itr.current();
//    EXPECT_NEAR(1.0, vec->getX(), 1e-6);
//    EXPECT_NEAR(2.0, vec->getY(), 1e-6);
//    EXPECT_NEAR(3.0, vec->getZ(), 1e-6);
//}
//
//TEST(TextReaderTest, ReadFile_update_remove_attribute)
//{
//    gfc::engine::CReader reader;
//    gfc::engine::CDocument document(1);
//    auto result = reader.read(UnicodeToUtf8(getFullPath(L"one1x91.gfc")), &document);
//    EXPECT_EQ(true, result);
//    auto itr = document.getIterator();
//    itr.first();
//    itr.next();
//    EXPECT_EQ(false, itr.isDone());
//    /*
//    Gfc2EdgeData* vec = (Gfc2EdgeData*)itr.current();
//    EXPECT_EQ(1, vec->getEdgeIndex());
//    EXPECT_EQ(2, vec->getLoopIndex());
//    EXPECT_EQ(3, vec->getType());
//    EXPECT_STREQ("abc", vec->getEdgeInfoPtr()->getValue().c_str());
//    EXPECT_STREQ("def", vec->getParamPtr()->getValue().c_str());
//    EXPECT_EQ(4, vec->getBaseType());
//    */
//}
//
//TEST(TextReaderTest, ReadFile_update_exchange_attribute)
//{
//    gfc::engine::CReader reader;
//    gfc::engine::CDocument document(1);
//    auto result = reader.read(UnicodeToUtf8(getFullPath(L"one1x92.gfc")), &document);
//    EXPECT_EQ(true, result);
//    auto itr = document.getIterator();
//    itr.first();
//    itr.next();
//    EXPECT_EQ(false, itr.isDone());
//    Gfc2Vector2d* vec = (Gfc2Vector2d*)itr.current();
//    EXPECT_NEAR(2.0, vec->getX(), 1e-6);
//    EXPECT_NEAR(1.0, vec->getY(), 1e-6);
//}
/*
TEST(TestGFCEngine, ReadFile_1)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X1.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    gfc::engine::CDocument document(&oModel);
    auto result = reader.open(L"D:\\Files\\test8.gfc");
    EXPECT_EQ(true, result);
    if (result)
    {
        reader.read(&document);
        reader.close();

        auto itr = document.getEntities(L"GfcBrepBody");
        itr->first();
        EXPECT_EQ(false, itr->isDone());
        auto pEntity = itr->current();
        EXPECT_EQ(true, pEntity != nullptr);
        auto pBody = GfcGeometryImporter::importBrepBody(pEntity.get());
        EXPECT_EQ(true, pBody != nullptr);
    }
}
*/
TEST(TestGFCEngine, WriteDemo)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X1.exp"), &oModel);
    gfc::engine::CWriter writer(&oModel, L"gfc2_unit_test");
    auto result = writer.open(getFullPath(L"demo.gfc"), L"express");

    gfc::engine::EntityRef nVertex[4];
    {
        auto pVector = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcVector2d");
        pVector->setAsDouble(L"X", 0.0);
        pVector->setAsDouble(L"Y", 0.0);
        auto nVector = writer.writeEntity(pVector);
        auto pVertex = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcSimpleVertex");
        pVertex->setAsEntityRef(L"Point", nVector);
        nVertex[0] = writer.writeEntity(pVertex);
    }
    {
        auto pVector = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcVector2d");
        pVector->setAsDouble(L"X", 1000.0);
        pVector->setAsDouble(L"Y", 0.0);
        auto nVector = writer.writeEntity(pVector);
        auto pVertex = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcSimpleVertex");
        pVertex->setAsEntityRef(L"Point", nVector);
        nVertex[1] = writer.writeEntity(pVertex);
    }
    {
        auto pVector = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcVector2d");
        pVector->setAsDouble(L"X", 1000.0);
        pVector->setAsDouble(L"Y", 1000.0);
        auto nVector = writer.writeEntity(pVector);
        auto pVertex = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcSimpleVertex");
        pVertex->setAsEntityRef(L"Point", nVector);
        nVertex[2] = writer.writeEntity(pVertex);
    }
    {
        auto pVector = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcVector2d");
        pVector->setAsDouble(L"X", 0.0);
        pVector->setAsDouble(L"Y", 1000.0);
        auto nVector = writer.writeEntity(pVector);
        auto pVertex = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcSimpleVertex");
        pVertex->setAsEntityRef(L"Point", nVector);
        nVertex[3] = writer.writeEntity(pVertex);
    }

    auto pGfcSimpleLoop = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcSimpleLoop");
    pGfcSimpleLoop->addEntityRef(L"Vertexes", nVertex[0]);
    pGfcSimpleLoop->addEntityRef(L"Vertexes", nVertex[1]);
    pGfcSimpleLoop->addEntityRef(L"Vertexes", nVertex[2]);
    pGfcSimpleLoop->addEntityRef(L"Vertexes", nVertex[3]);
    auto nGfcSimpleLoop = writer.writeEntity(pGfcSimpleLoop);

    auto pGfcSimplePolygon = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcSimplePolygon");
    pGfcSimplePolygon->addEntityRef(L"Loops", nGfcSimpleLoop);
    auto nGfcSimplePolygon = writer.writeEntity(pGfcSimplePolygon);

    auto pGfcGeometryShape1 = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcGeometryShape");
    pGfcGeometryShape1->addEntityRef(L"Geos", nGfcSimplePolygon);
    auto nGfcGeometryShape1 = writer.writeEntity(pGfcGeometryShape1);

    auto pElementShape1 = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcElementShape");
    pElementShape1->setAsString(L"Identifier", L"Profile");
    pElementShape1->setAsEntityRef(L"Shape", nGfcGeometryShape1);
    auto nElementShape1 = writer.writeEntity(pElementShape1);

    auto pGfcVector2d = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcVector2d");
    pGfcVector2d->setAsDouble(L"X", 3000);
    pGfcVector2d->setAsDouble(L"X", 4000);
    auto nGfcVector2d = writer.writeEntity(pGfcVector2d);

    auto pGfcGeometryShape2 = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcGeometryShape");
    pGfcGeometryShape2->addEntityRef(L"Geos", nGfcVector2d);
    auto nGfcGeometryShape2 = writer.writeEntity(pGfcGeometryShape2);

    auto pElementShape2 = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcElementShape");
    pElementShape2->setAsString(L"Identifier", L"Location");
    pElementShape2->setAsEntityRef(L"Shape", nGfcGeometryShape2);
    auto nElementShape2 = writer.writeEntity(pElementShape2);

    auto pElement = gfc::engine::CEngineUtils::createEntity(&oModel, L"GfcElement");
    pElement->setAsString(L"ID", L"1");
    pElement->setAsString(L"Name", L"KZ-1");
    pElement->setAsString(L"EType", L"14-07.35.00");
    pElement->addEntityRef(L"Shapes", nElementShape1);
    pElement->addEntityRef(L"Shapes", nElementShape2);
    writer.writeEntity(pElement);
    EXPECT_EQ(true, result);
}

/*
TEST(TestGFCEngine, ReadFile1216)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X1.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    gfc::engine::CDocument document(&oModel);
    auto result = reader.open(getFullPath(L"D:\\Files\\正负零以上相同部分1-发甲方.rvt.gfc"));
    EXPECT_EQ(true, result);
    if (result)
    {
        reader.read(&document);
        reader.close();

        auto itr = document.getIterator();
        itr->first();
        while (!itr->isDone())
        {
            auto pEntity = itr->current();
            if (pEntity->ref() == 2956)
            {
                auto g = GfcGeometryImporter::importBrepBody(pEntity.get());
                g->Free();
            }
            itr->next();
        }
    }
}
*/

TEST(TestGFCEngine, WriteStandardVersion)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CWriter writer(&oModel, L"gfc2_unit_test", CP_UTF8, true, L"3.2");
    auto result = writer.open(getFullPath(L"empty_sv.gfc"), L"express");
    EXPECT_EQ(true, result);
}

TEST(TestGFCEngine, ReadStandardVersion)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    auto result = reader.open(getFullPath(L"empty_sv.gfc"));
    EXPECT_EQ(true, result);
    auto sv = reader.readStandardVersion();
    EXPECT_EQ(true, sv == L"3.2");
}

TEST(TestGFCEngine, WriteStandardVersion2)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CWriter writer(&oModel, L"gfc2_unit_test");
    auto result = writer.open(getFullPath(L"empty_sv2.gfc"), L"express");
    EXPECT_EQ(true, result);
}

TEST(TestGFCEngine, ReadStandardVersion2)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    auto result = reader.open(getFullPath(L"empty_sv2.gfc"));
    EXPECT_EQ(true, result);
    auto sv = reader.readStandardVersion();
    EXPECT_EQ(true, sv == L"GFC3X0");
}


TEST(TestDocument, linux_bug)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X2.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    auto result = reader.open(getFullPath(L"P0P1-origin.gfc"));
    EXPECT_EQ(true, result);
    gfc::engine::CDocument oDoc(&oModel);
    reader.read(&oDoc);
    auto itr = oDoc.getEntities(L"GfcBrepBody");
    itr->first();
    int nCount = 0;
    while (!itr->isDone())
    {
        ++nCount;
        auto pEntity = itr->current();
        auto pBody = GfcGeometryImporter::importBrepBody(pEntity.get());
        EXPECT_EQ(true, pBody != nullptr);
        pBody->Free();
        itr->next();
    }
    EXPECT_EQ(161, nCount);
}
