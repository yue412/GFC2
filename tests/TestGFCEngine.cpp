#include "gtest\gtest.h"
#include "GfcEngine\Writer.h"
#include "GfcEngine\Reader.h"
#include "GfcEngine\Document.h"
#include "GfcEngine\GfcEngineUtils.h"
//#include "Classes\Gfc2EdgeData.h"
#include "Common.h"
#include "GfcSchema/Model.h"
#include "GMath\GCoordinates3.h"
#include "GfcUtils\GfcGeometryExporter.h"

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
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CReader reader(&oModel);
    gfc::engine::CDocument document(&oModel);
    auto result = reader.open(getFullPath(L"GJ_Column.rvt.gfc"));
    EXPECT_EQ(true, result);
    if (result)
    {
        reader.read(&document);
        reader.close();

        auto itr = document.getEntities(L"Gfc2Project");
        itr->first();
        EXPECT_EQ(false, itr->isDone());
        auto pEntity = itr->current();
        EXPECT_EQ(true, pEntity != nullptr);
    }
}
*/