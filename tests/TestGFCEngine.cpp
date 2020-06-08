#include "gtest\gtest.h"
#include "GfcEngine\Writer.h"
#include "GfcEngine\Reader.h"
#include "GfcEngine\Document.h"
#include "GfcEngine\GfcEngineUtils.h"
//#include "Classes\Gfc2EdgeData.h"
#include "Common.h"
#include "GfcSchema/Model.h"

TEST(TestGFCEngine, WriteEmptyFile)
{
    gfc::engine::CWriter writer(L"GFC3X0", L"gfc2_unit_test");
    auto result = writer.open(getFullPath(L"empty.gfc"), L"express");
    EXPECT_EQ(true, result);
}

TEST(TestGFCEngine, WriteFile)
{
    gfc::engine::CWriter writer(L"GFC3X0", L"gfc2_unit_test");
    auto result = writer.open(getFullPath(L"one.gfc"), L"express");
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
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

