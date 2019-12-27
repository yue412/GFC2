#include "gtest\gtest.h"
#include "glodon\objectbuf\Writer.h"
#include "glodon\objectbuf\Reader.h"
#include "glodon\objectbuf\Document.h"
#include "Classes\Gfc2Vector3d.h"
#include "Classes\Gfc2Vector2d.h"
#include "Classes\Gfc2EdgeData.h"
#include "Common.h"

TEST(TextWriterTest, WriteEmptyFile)
{
    glodon::objectbuf::Writer writer;
    auto result = writer.open(UnicodeToUtf8(getFullPath(L"empty.gfc")), "express", "gfc2_unit_test");
    EXPECT_EQ(true, result);
}

TEST(TextWriterTest, WriteFile)
{
    glodon::objectbuf::Writer writer;
    auto result = writer.open(UnicodeToUtf8(getFullPath(L"one.gfc")), "express", "gfc2_unit_test");
    Gfc2Vector3d oVector;
    oVector.setX(1.0);
    oVector.setY(2.0);
    oVector.setZ(3.0);
    writer.writeEntity(&oVector);
    EXPECT_EQ(true, result);
}

TEST(TextReaderTest, ReadFile)
{
    glodon::objectbuf::Reader reader;
    glodon::objectbuf::Document document(1);
    auto result = reader.read(UnicodeToUtf8(getFullPath(L"one.gfc")), &document);
    EXPECT_EQ(true, result);
    auto itr = document.getIterator();
    itr.first();
    itr.next();
    EXPECT_EQ(false, itr.isDone());
    Gfc2Vector3d* vec = (Gfc2Vector3d*)itr.current();
    EXPECT_NEAR(1.0, vec->getX(), 1e-6);
    EXPECT_NEAR(2.0, vec->getY(), 1e-6);
    EXPECT_NEAR(3.0, vec->getZ(), 1e-6);
}

TEST(TextReaderTest, ReadEmptyFile)
{
    glodon::objectbuf::Reader reader;
    glodon::objectbuf::Document document;
    auto result = reader.read(UnicodeToUtf8(getFullPath(L"empty.gfc")), &document);
    EXPECT_EQ(true, result);
    //EXPECT_EQ(0, document
}

TEST(BinaryWriterTest, WriteEmptyFile)
{
    glodon::objectbuf::Writer writer;
    auto result = writer.open(UnicodeToUtf8(getFullPath(L"empty_bin.gfc")), "bin", "gfc2_unit_test");
    EXPECT_EQ(true, result);
}

TEST(BinaryWriterTest, WriteFile)
{
    glodon::objectbuf::Writer writer;
    auto result = writer.open(UnicodeToUtf8(getFullPath(L"one_bin.gfc")), "bin", "gfc2_unit_test");
    Gfc2Vector3d oVector;
    oVector.setX(1.0);
    oVector.setY(2.0);
    oVector.setZ(3.0);
    writer.writeEntity(&oVector);
    EXPECT_EQ(true, result);
}

TEST(BinaryReaderTest, ReadFile)
{
    glodon::objectbuf::Reader reader;
    glodon::objectbuf::Document document(1);
    auto result = reader.read(UnicodeToUtf8(getFullPath(L"one_bin.gfc")), &document);
    EXPECT_EQ(true, result);
    auto itr = document.getIterator();
    itr.first();
    itr.next();
    itr.next();
    EXPECT_EQ(false, itr.isDone());
    Gfc2Vector3d* vec = (Gfc2Vector3d*)itr.current();
    EXPECT_NEAR(1.0, vec->getX(), 1e-6);
    EXPECT_NEAR(2.0, vec->getY(), 1e-6);
    EXPECT_NEAR(3.0, vec->getZ(), 1e-6);
}

TEST(BinaryReaderTest, ReadEmptyFile)
{
    glodon::objectbuf::Reader reader;
    glodon::objectbuf::Document document;
    auto result = reader.read(UnicodeToUtf8(getFullPath(L"empty_bin.gfc")), &document);
    EXPECT_EQ(true, result);
    //EXPECT_EQ(0, document
}

TEST(TextReaderTest, ReadFile_update_add_attribute)
{
    glodon::objectbuf::Reader reader;
    glodon::objectbuf::Document document(1);
    auto result = reader.read(UnicodeToUtf8(getFullPath(L"one1x9.gfc")), &document);
    EXPECT_EQ(true, result);
    auto itr = document.getIterator();
    itr.first();
    itr.next();
    EXPECT_EQ(false, itr.isDone());
    Gfc2Vector3d* vec = (Gfc2Vector3d*)itr.current();
    EXPECT_NEAR(1.0, vec->getX(), 1e-6);
    EXPECT_NEAR(2.0, vec->getY(), 1e-6);
    EXPECT_NEAR(3.0, vec->getZ(), 1e-6);
}

TEST(TextReaderTest, ReadFile_update_remove_attribute)
{
    glodon::objectbuf::Reader reader;
    glodon::objectbuf::Document document(1);
    auto result = reader.read(UnicodeToUtf8(getFullPath(L"one1x91.gfc")), &document);
    EXPECT_EQ(true, result);
    auto itr = document.getIterator();
    itr.first();
    itr.next();
    EXPECT_EQ(false, itr.isDone());
    Gfc2EdgeData* vec = (Gfc2EdgeData*)itr.current();
    EXPECT_EQ(1, vec->getEdgeIndex());
    EXPECT_EQ(2, vec->getLoopIndex());
    EXPECT_EQ(3, vec->getType());
    EXPECT_STREQ("abc", vec->getEdgeInfoPtr()->getValue().c_str());
    EXPECT_STREQ("def", vec->getParamPtr()->getValue().c_str());
    EXPECT_EQ(4, vec->getBaseType());
}

TEST(TextReaderTest, ReadFile_update_exchange_attribute)
{
    glodon::objectbuf::Reader reader;
    glodon::objectbuf::Document document(1);
    auto result = reader.read(UnicodeToUtf8(getFullPath(L"one1x92.gfc")), &document);
    EXPECT_EQ(true, result);
    auto itr = document.getIterator();
    itr.first();
    itr.next();
    EXPECT_EQ(false, itr.isDone());
    Gfc2Vector2d* vec = (Gfc2Vector2d*)itr.current();
    EXPECT_NEAR(2.0, vec->getX(), 1e-6);
    EXPECT_NEAR(1.0, vec->getY(), 1e-6);
}

