#include "gtest\gtest.h"
#include "glodon\objectbuf\Writer.h"
#include "glodon\objectbuf\Reader.h"
#include "glodon\objectbuf\Document.h"
#include "Classes\Gfc2Vector3d.h"

TEST(TextWriterTest, WriteEmptyFile)
{
    glodon::objectbuf::Writer writer;
    auto result = writer.open("D:\\GFC2\\bin\\empty.gfc", "express", "gfc2_unit_test");
    EXPECT_EQ(true, result);
}

TEST(TextWriterTest, WriteFile)
{
    glodon::objectbuf::Writer writer;
    auto result = writer.open("D:\\GFC2\\bin\\one.gfc", "express", "gfc2_unit_test");
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
    auto result = reader.read("D:\\GFC2\\bin\\one.gfc", &document);
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
    auto result = reader.read("D:\\GFC2\\bin\\empty.gfc", &document);
    EXPECT_EQ(true, result);
    //EXPECT_EQ(0, document
}

TEST(BinaryWriterTest, WriteEmptyFile)
{
    glodon::objectbuf::Writer writer;
    auto result = writer.open("D:\\GFC2\\bin\\empty_bin.gfc", "bin", "gfc2_unit_test");
    EXPECT_EQ(true, result);
}

TEST(BinaryWriterTest, WriteFile)
{
    glodon::objectbuf::Writer writer;
    auto result = writer.open("D:\\GFC2\\bin\\one_bin.gfc", "bin", "gfc2_unit_test");
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
    auto result = reader.read("D:\\GFC2\\bin\\one_bin.gfc", &document);
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
    auto result = reader.read("D:\\GFC2\\bin\\empty_bin.gfc", &document);
    EXPECT_EQ(true, result);
    //EXPECT_EQ(0, document
}