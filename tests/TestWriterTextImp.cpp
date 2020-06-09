#include "gtest\gtest.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\EngineException.h"
#include "GfcEngine\PropValue.h"
#include "WriterTextImp.h"
#include "Common.h"
#include "GfcSchema\BuildinType.h"

TEST(TestWriteTextImp, CWriterEntityUtils_writevalue_Integer)
{
    gfc::schema::CIntegerType oIntegerType;
    {
        std::stringstream ss;
        gfc::engine::CIntegerValue oValue(12);
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oIntegerType, &oValue);
        EXPECT_STREQ("12", ss.str().c_str());
    }

    {
        std::stringstream ss;
        gfc::engine::CIntegerValue oValue(-123);
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oIntegerType, &oValue);
        EXPECT_STREQ("-123", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterEntityUtils_writevalue_Boolean)
{
    gfc::schema::CBooleanType oType;
    {
        std::stringstream ss;
        gfc::engine::CBooleanValue oValue(true);
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(".T.", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CBooleanValue oValue(false);
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(".F.", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterEntityUtils_writevalue_Double)
{
    gfc::schema::CRealType oType;
    {
        std::stringstream ss;
        gfc::engine::CDoubleValue oValue(22.34);
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        auto d = std::stod(ss.str().c_str());
        EXPECT_NEAR(22.34, d, 1e-7);
    }
    {
        std::stringstream ss;
        gfc::engine::CDoubleValue  oValue(22222.123456);
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        auto s = ss.str();
        auto d = std::stod(s.c_str());
        EXPECT_NEAR(22222.123456, d, 1e-8);
    }
}

TEST(TestWriteTextImp, CWriterEntityUtils_writevalue_String)
{
    gfc::schema::CStringType oType;
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"中文");
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("'中文'", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue  oValue(L"'");
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("'''", ss.str().c_str());
    }
}