#include "gtest\gtest.h"
#include "GfcEngine\Writer.h"
#include "GfcEngine\Reader.h"
#include "GfcEngine\Document.h"
#include "GfcEngine\EntityFactory.h"
//#include "Classes\Gfc2EdgeData.h"
#include "Common.h"

TEST(TestGFCEngine, WriteEmptyFile)
{
    gfc2::engine::Writer writer;
    auto result = writer.open(UnicodeToUtf8(getFullPath(L"empty.gfc")), "express", "gfc2_unit_test");
    EXPECT_EQ(true, result);
}

TEST(TestGFCEngine, WriteFile)
{
    gfc2::engine::Writer writer;
    auto result = writer.open(UnicodeToUtf8(getFullPath(L"one.gfc")), "express", "gfc2_unit_test");
    gfc2::engine::EntityFactory oFactory;
    oFactory.loadSchema(UnicodeToUtf8(getFullPath(L"GFC3X0.exp")));
    auto pEntity = oFactory.create("Gfc2Vector3d");
    //Gfc2Vector3d oVector;
    //oVector.setX(1.0);
    //oVector.setY(2.0);
    //oVector.setZ(3.0);
    pEntity->setAsDouble("X", 1.0);
    pEntity->setAsDouble("Y", 2.0);
    pEntity->setAsDouble("Z", 3.0);
    writer.writeEntity(pEntity);
    EXPECT_EQ(true, result);
}

TEST(TestGFCEngine, ReadFile)
{
    gfc2::engine::EntityFactory oFactory;
    oFactory.loadSchema(UnicodeToUtf8(getFullPath(L"GFC3X0.exp")));
    gfc2::engine::Reader reader(&oFactory);
    gfc2::engine::Document document(oFactory.schema());
    auto result = reader.open(UnicodeToUtf8(getFullPath(L"one.gfc")));
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
        EXPECT_NEAR(1.0, pEntity->asDouble("X"), 1e-6);
        EXPECT_NEAR(2.0, pEntity->asDouble("Y"), 1e-6);
        EXPECT_NEAR(3.0, pEntity->asDouble("Z"), 1e-6);
    }
}

TEST(TestGFCEngine, ReadEmptyFile)
{
    gfc2::engine::EntityFactory oFactory;
    oFactory.loadSchema(UnicodeToUtf8(getFullPath(L"GFC3X0.exp")));
    gfc2::engine::Reader reader(&oFactory);
    gfc2::engine::Document document(oFactory.schema());
    auto result = reader.open(UnicodeToUtf8(getFullPath(L"empty.gfc")));
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
//    gfc2::engine::Writer writer;
//    auto result = writer.open(UnicodeToUtf8(getFullPath(L"empty_bin.gfc")), "bin", "gfc2_unit_test");
//    EXPECT_EQ(true, result);
//}
//
//TEST(BinaryWriterTest, WriteFile)
//{
//    gfc2::engine::Writer writer;
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
//    gfc2::engine::Reader reader;
//    gfc2::engine::Document document(1);
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
//    gfc2::engine::Reader reader;
//    gfc2::engine::Document document;
//    auto result = reader.read(UnicodeToUtf8(getFullPath(L"empty_bin.gfc")), &document);
//    EXPECT_EQ(true, result);
//    //EXPECT_EQ(0, document
//}
//
//TEST(TextReaderTest, ReadFile_update_add_attribute)
//{
//    gfc2::engine::Reader reader;
//    gfc2::engine::Document document(1);
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
//    gfc2::engine::Reader reader;
//    gfc2::engine::Document document(1);
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
//    gfc2::engine::Reader reader;
//    gfc2::engine::Document document(1);
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

