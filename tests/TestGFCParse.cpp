#include "gtest\gtest.h"
#include "Parser.h"

TEST(TestGFCParse, Empty)
{
    std::string sCode="#1=Gfc2String();";
    gfc2::Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    gfc2::Parser oParser(&oScanner);
    oParser.Parse();
    EXPECT_EQ(true, L"Gfc2String" == oParser.m_sEntityName);
    EXPECT_EQ(0, oParser.m_oParameterList.getCount());
    EXPECT_EQ(0, oParser.errors->count);
}

TEST(TestGFCParse, Boolean)
{
    std::string sCode = "#1=Gfc2String(.T.);";
    gfc2::Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    gfc2::Parser oParser(&oScanner);
    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(1, oParser.m_oParameterList.getCount());
    EXPECT_EQ(true, L".T." == oParser.m_oParameterList.getItems(0)->asString());
}

TEST(TestGFCParse, Integer)
{
    std::string sCode = "#1=Gfc2String(100);";
    gfc2::Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    gfc2::Parser oParser(&oScanner);
    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(1, oParser.m_oParameterList.getCount());
    EXPECT_EQ(true, L"100" == oParser.m_oParameterList.getItems(0)->asString());
}

TEST(TestGFCParse, Real)
{
    std::string sCode = "#1=Gfc2String(100.0);";
    gfc2::Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    gfc2::Parser oParser(&oScanner);
    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(1, oParser.m_oParameterList.getCount());
    EXPECT_EQ(true, L"100.0" == oParser.m_oParameterList.getItems(0)->asString());
}

TEST(TestGFCParse, Real2)
{
    std::string sCode = "#1=Gfc2String(-1.1e-10);";
    gfc2::Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    gfc2::Parser oParser(&oScanner);
    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(1, oParser.m_oParameterList.getCount());
    EXPECT_EQ(true, L"-1.1e-10" == oParser.m_oParameterList.getItems(0)->asString());
}

TEST(TestGFCParse, String)
{
    std::string sCode = "#1=Gfc2String('abc');";
    gfc2::Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    gfc2::Parser oParser(&oScanner);
    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(1, oParser.m_oParameterList.getCount());
    EXPECT_EQ(true, L"'abc'" == oParser.m_oParameterList.getItems(0)->asString());
}

TEST(TestGFCParse, other1)
{
    std::string sCode = "#1=Gfc2String($);";
    gfc2::Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    gfc2::Parser oParser(&oScanner);
    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(1, oParser.m_oParameterList.getCount());
    EXPECT_EQ(true, L"$" == oParser.m_oParameterList.getItems(0)->asString());
}

TEST(TestGFCParse, other2)
{
    std::string sCode = "#1=Gfc2String(*);";
    gfc2::Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    gfc2::Parser oParser(&oScanner);
    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(1, oParser.m_oParameterList.getCount());
    EXPECT_EQ(true, L"*" == oParser.m_oParameterList.getItems(0)->asString());
}

TEST(TestGFCParse, other3)
{
    std::string sCode = "#1=Gfc2String(#13);";
    gfc2::Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    gfc2::Parser oParser(&oScanner);
    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(1, oParser.m_oParameterList.getCount());
    EXPECT_EQ(true, L"#13" == oParser.m_oParameterList.getItems(0)->asString());
}

TEST(TestGFCParse, Array)
{
    std::string sCode = "#1=Gfc2String((1,2,3));";
    gfc2::Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    gfc2::Parser oParser(&oScanner);
    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(1, oParser.m_oParameterList.getCount());
    EXPECT_EQ(true, L"(1,2,3)" == oParser.m_oParameterList.getItems(0)->asString());
    EXPECT_EQ(3, oParser.m_oParameterList.getItems(0)->getCount());
}

TEST(TestGFCParse, composite)
{
    std::string sCode = "#1=Gfc2String(-123,#13,12.0,$,*,'abc',.abc.,(1,2,3));";
    gfc2::Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    gfc2::Parser oParser(&oScanner);
    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(8, oParser.m_oParameterList.getCount());
}