#include "gtest\gtest.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\EngineException.h"
#include "GfcEngine\PropValue.h"
#include "ReaderTextImp.h"
#include "Common.h"
#include "GfcSchema\BuildinType.h"
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\EnumType.h"
#include "GfcSchema\EntityAttribute.h"
#include "GfcSchema\Model.h"

TEST(TestReaderTextImp, CReaderTextImp_preRead)
{
    gfc::engine::CReaderTextImp oReader;
    {
        auto bResult = oReader.preRead(getFullPath(L"one1x9.gfc"));
        EXPECT_EQ(true, bResult);
    }
    {
        auto bResult = oReader.preRead(getFullPath(L"UnitTest.exe"));
        EXPECT_EQ(false, bResult);
    }
    {
        auto bResult = oReader.preRead(getFullPath(L"xxx.xxx"));
        EXPECT_EQ(false, bResult);
    }
}

TEST(TestReaderTextImp, CReaderTextImp_open)
{
    gfc::schema::CModel oModel;
    gfc::engine::CReaderTextImp oReader;
    oReader.setModel(&oModel);
    {
        auto bResult = oReader.open(getFullPath(L"one1x9.gfc"));
        oReader.close();
        EXPECT_EQ(true, bResult);
    }
    {
        auto bResult = oReader.open(getFullPath(L"no_file"));
        oReader.close();
        EXPECT_EQ(false, bResult);
    }
}

TEST(TestReaderTextImp, CReaderTextImp_readFileVersion)
{
    gfc::schema::CModel oModel;
    gfc::engine::CReaderTextImp oReader;
    oReader.setModel(&oModel);
    {
        auto bResult = oReader.open(getFullPath(L"one1x9.gfc"));
        EXPECT_EQ(true, bResult);
        auto sVer = oReader.readFileVersion();
        oReader.close();
        EXPECT_STREQ(L"GFC1X9", sVer.c_str());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseBoolean)
{
    {
        bool value;
        std::string input = ".T.";
        auto result = gfc::engine::CReaderTextUtils::parseBoolean(input, value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(true, value);
    }
    {
        bool value;
        std::string input = ".F.";
        auto result = gfc::engine::CReaderTextUtils::parseBoolean(input, value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value);
    }
    {
        bool value;
        std::string input = ".Fx.";
        auto result = gfc::engine::CReaderTextUtils::parseBoolean(input, value);
        EXPECT_EQ(false, result);
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseInt)
{
    int value;
    {
        std::string input = "123";
        auto result = gfc::engine::CReaderTextUtils::parseInt(input, value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(123, value);
    }
    {
        std::string input = "-123";
        auto result = gfc::engine::CReaderTextUtils::parseInt(input, value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(-123, value);
    }
    {
        std::string input = ".Fx.";
        auto result = gfc::engine::CReaderTextUtils::parseInt(input, value);
        EXPECT_EQ(false, result);
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseFloat)
{
    double value;
    {
        std::string input = "123.55";
        auto result = gfc::engine::CReaderTextUtils::parseFloat(input, value);
        EXPECT_EQ(true, result);
        EXPECT_NEAR(123.55, value, 1e-7);
    }
    {
        std::string input = "-123e-2";
        auto result = gfc::engine::CReaderTextUtils::parseFloat(input, value);
        EXPECT_EQ(true, result);
        EXPECT_NEAR(-1.23, value, 1e-7);
    }
    {
        std::string input = ".Fx.";
        auto result = gfc::engine::CReaderTextUtils::parseFloat(input, value);
        EXPECT_EQ(false, result);
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseString)
{
    std::string value;
    {
        std::string input = "'1234567890abcXYZ'";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("1234567890abcXYZ", value.c_str());
    }
    {
        std::string input = "'中文'";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("中文", value.c_str());
    }
    {
        std::string input = "'\\''";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("'", value.c_str());
    }
    {
        std::string input = "'\\n'";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("\n", value.c_str());
    }
    {
        std::string input = "'\\r'";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("\r", value.c_str());
    }
    {
        std::string input = "'\\\\'";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("\\", value.c_str());
    }
    {
        std::string input = "'中文=\\'abc\\'\\n\\r英文=\\\\'";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("中文='abc'\n\r英文=\\", value.c_str());
    }
    {
        std::string input = "''";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("", value.c_str());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseString_error)
{
    std::string value;
    {
        std::string input = "a";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(false, result);
    }
    {
        std::string input = "'.Fx.";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(false, result);
    }
    {
        std::string input = ".Fx.'";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(false, result);
    }
    {
        std::string input = "'.Fx.\\'";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(false, result);
    }
    {
        std::string input = "'.F\\x.'";
        auto result = gfc::engine::CReaderTextUtils::parseString(input, value);
        EXPECT_EQ(false, result);
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseEntity)
{
    gfc::engine::EntityRef value;
    {
        std::string input = "#123";
        auto result = gfc::engine::CReaderTextUtils::parseEntity(input, value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(123, value);
    }
    {
        std::string input = "123";
        auto result = gfc::engine::CReaderTextUtils::parseEntity(input, value);
        EXPECT_EQ(false, result);
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseBooleanField)
{
    {
        gfc::engine::CBooleanValue value;
        std::string input = ".T.";
        auto result = gfc::engine::CReaderTextUtils::parseBooleanField(input, &value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value.isNull());
        EXPECT_EQ(true, value.asBoolean());
    }
    {
        gfc::engine::CBooleanValue value;
        std::string input = ".Fx.";
        auto result = gfc::engine::CReaderTextUtils::parseBooleanField(input, &value);
        EXPECT_EQ(false, result);
        EXPECT_EQ(true, value.isNull());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseIntField)
{
    {
        gfc::engine::CIntegerValue value;
        std::string input = "123";
        auto result = gfc::engine::CReaderTextUtils::parseIntField(input, &value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value.isNull());
        EXPECT_EQ(123, value.asInteger());
    }
    {
        gfc::engine::CIntegerValue value;
        std::string input = "abvc";
        auto result = gfc::engine::CReaderTextUtils::parseIntField(input, &value);
        EXPECT_EQ(false, result);
        EXPECT_EQ(true, value.isNull());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseFloatField)
{
    {
        gfc::engine::CDoubleValue value;
        std::string input = "123.11";
        auto result = gfc::engine::CReaderTextUtils::parseFloatField(input, &value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value.isNull());
        EXPECT_NEAR(123.11, value.asDouble(), 1e-7);
    }
    {
        gfc::engine::CDoubleValue value;
        std::string input = "abvc";
        auto result = gfc::engine::CReaderTextUtils::parseFloatField(input, &value);
        EXPECT_EQ(false, result);
        EXPECT_EQ(true, value.isNull());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseStringField)
{
    {
        gfc::engine::CStringValue value;
        std::string input = UnicodeToUtf8(L"'中华人民'");
        auto result = gfc::engine::CReaderTextUtils::parseStringField(input, &value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value.isNull());
        EXPECT_STREQ(L"中华人民", value.asString().c_str());
    }
    {
        gfc::engine::CStringValue value;
        std::string input = "abvc";
        auto result = gfc::engine::CReaderTextUtils::parseStringField(input, &value);
        EXPECT_EQ(false, result);
        EXPECT_EQ(true, value.isNull());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseEnumField)
{
    gfc::schema::CEnumType oType;
    oType.addEnum(L"abc", L"");
    oType.addEnum(L"ddd", L"");
    oType.addEnum(L"eee", L"");
    {
        gfc::engine::CIntegerValue value;
        std::string input = ".ddd.";
        auto result = gfc::engine::CReaderTextUtils::parseEnumField(input, &oType, &value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value.isNull());
        EXPECT_EQ(1, value.asInteger());
    }
    {
        gfc::engine::CIntegerValue value;
        std::string input = ".abvc.";
        auto result = gfc::engine::CReaderTextUtils::parseEnumField(input, &oType, &value);
        EXPECT_EQ(false, result);
        EXPECT_EQ(true, value.isNull());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseEntityField)
{
    {
        gfc::engine::CEntityRefValue value;
        std::string input = "#123";
        auto result = gfc::engine::CReaderTextUtils::parseEntityField(input, &value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value.isNull());
        EXPECT_EQ(123, value.asEntityRef());
    }
    {
        gfc::engine::CEntityRefValue  value;
        std::string input = "123";
        auto result = gfc::engine::CReaderTextUtils::parseEntityField(input, &value);
        EXPECT_EQ(false, result);
        EXPECT_EQ(true, value.isNull());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseField_int)
{
    gfc::schema::CIntegerType oType;
    gfc::engine::CIntegerValue value;
    {
        std::string input = "123";
        auto result = gfc::engine::CReaderTextUtils::parseField(input, &oType, &value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value.isNull());
        EXPECT_EQ(123, value.asInteger());
    }
    {
        std::string input = "abc";
        auto result = gfc::engine::CReaderTextUtils::parseField(input, &oType, &value);
        EXPECT_EQ(false, result);
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseField_boolean)
{
    gfc::schema::CBooleanType oType;
    gfc::engine::CBooleanValue value;
    {
        std::string input = ".T.";
        auto result = gfc::engine::CReaderTextUtils::parseField(input, &oType, &value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value.isNull());
        EXPECT_EQ(true, value.asBoolean());
    }
    {
        std::string input = "abc";
        auto result = gfc::engine::CReaderTextUtils::parseField(input, &oType, &value);
        EXPECT_EQ(false, result);
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseField_float)
{
    gfc::schema::CRealType oType;
    gfc::engine::CDoubleValue value;
    {
        std::string input = "123.12343";
        auto result = gfc::engine::CReaderTextUtils::parseField(input, &oType, &value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value.isNull());
        EXPECT_NEAR(123.12343, value.asDouble(), 1e-7);
    }
    {
        std::string input = "abc";
        auto result = gfc::engine::CReaderTextUtils::parseField(input, &oType, &value);
        EXPECT_EQ(false, result);
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseField_string)
{
    gfc::schema::CStringType oType;
    gfc::engine::CStringValue value;
    {
        std::string input = UnicodeToUtf8(L"'中文'");
        auto result = gfc::engine::CReaderTextUtils::parseField(input, &oType, &value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value.isNull());
        EXPECT_STREQ(L"中文", value.asString().c_str());
    }
    {
        std::string input = "abc";
        auto result = gfc::engine::CReaderTextUtils::parseField(input, &oType, &value);
        EXPECT_EQ(false, result);
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseField_enum)
{
    gfc::schema::CEnumType oType;
    oType.addEnum(L"abc", L"");
    oType.addEnum(L"ddd", L"");
    oType.addEnum(L"eee", L"");
    gfc::engine::CIntegerValue value;
    {
        std::string input = UnicodeToUtf8(L".eee.");
        auto result = gfc::engine::CReaderTextUtils::parseField(input, &oType, &value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value.isNull());
        EXPECT_EQ(2, value.asInteger());
    }
    {
        std::string input = "abc";
        auto result = gfc::engine::CReaderTextUtils::parseField(input, &oType, &value);
        EXPECT_EQ(false, result);
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseField_class)
{
    gfc::schema::CClass oType;
    gfc::engine::CEntityRefValue value;
    {
        std::string input = UnicodeToUtf8(L"#123");
        auto result = gfc::engine::CReaderTextUtils::parseField(input, &oType, &value);
        EXPECT_EQ(true, result);
        EXPECT_EQ(false, value.isNull());
        EXPECT_EQ(123, value.asEntityRef());
    }
    {
        std::string input = "123";
        auto result = gfc::engine::CReaderTextUtils::parseField(input, &oType, &value);
        EXPECT_EQ(false, result);
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_getNextValue)
{
    std::string input = UnicodeToUtf8(L"123,12,34");
    std::string value;
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 0, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("123", value.c_str());
    }
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 4, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("12", value.c_str());
    }
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 7, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("34", value.c_str());
    }
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 9, value);
        EXPECT_EQ(false, result);
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_getNextValue_blank)
{
    std::string input = UnicodeToUtf8(L" 123 , 12 , 34 ");
    std::string value;
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 0, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ(" 123 ", value.c_str());
    }
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 6, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ(" 12 ", value.c_str());
    }
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 11, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ(" 34 ", value.c_str());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_getNextValue_one)
{
    std::string input = UnicodeToUtf8(L" 123  ");
    std::string value;
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 0, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ(" 123  ", value.c_str());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_getNextValue_Bracket)
{
    std::string input = UnicodeToUtf8(L"(1,2,3),(3,5),(6,7)");
    std::string value;
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 0, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("(1,2,3)", value.c_str());
    }
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 8, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("(3,5)", value.c_str());
    }
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 14, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("(6,7)", value.c_str());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_getNextValue_string)
{
    std::string input = UnicodeToUtf8(L"','");
    std::string value;
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 0, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("','", value.c_str());
    }
}


TEST(TestReaderTextImp, CReaderTextUtils_getNextValue_string2)
{
    std::string input = UnicodeToUtf8(L"',',',a'");
    std::string value;
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 0, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("','", value.c_str());
    }
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 4, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("',a'", value.c_str());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_getNextValue_string3)
{
    std::string input = UnicodeToUtf8(L"'\\','");
    std::string value;
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 0, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("'\\','", value.c_str());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_getNextValue_string4)
{
    std::string input = UnicodeToUtf8(L"'(,','abc'");
    std::string value;
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 0, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("'(,'", value.c_str());
    }
}


TEST(TestReaderTextImp, CReaderTextUtils_getNextValue_string5)
{
    std::string input = UnicodeToUtf8(L"'),','abc'");
    std::string value;
    {
        auto result = gfc::engine::CReaderTextUtils::getNextValue(input, 0, value);
        EXPECT_EQ(true, result);
        EXPECT_STREQ("'),'", value.c_str());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parse_simple)
{
    std::wstring sError;
    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CClass oClass;
    auto pAttr1 = new gfc::schema::CAttribute();
    pAttr1->SetName(L"ID");
    pAttr1->SetType(&oIntegerType);
    oClass.addAttribute(pAttr1);

    gfc::engine::CEntity oEntity;
    oEntity.setSchema(&oClass);
    std::string input = UnicodeToUtf8(L"123");
    std::string value;
    {
        auto result = gfc::engine::CReaderTextUtils::parse(input, &oEntity, sError);
        EXPECT_EQ(true, result);
        EXPECT_EQ(123, oEntity.asInteger(L"ID"));
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parse_two)
{
    std::wstring sError;
    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CStringType oStringType;
    gfc::schema::CClass oClass;
    {
        auto pAttr1 = new gfc::schema::CAttribute();
        pAttr1->SetName(L"ID");
        pAttr1->SetType(&oIntegerType);
        oClass.addAttribute(pAttr1);
    }
    {
        auto pAttr1 = new gfc::schema::CAttribute();
        pAttr1->SetName(L"Name");
        pAttr1->SetType(&oStringType);
        oClass.addAttribute(pAttr1);
    }

    gfc::engine::CEntity oEntity;
    oEntity.setSchema(&oClass);
    std::string input = UnicodeToUtf8(L"123,'广联达'");
    std::string value;
    {
        auto result = gfc::engine::CReaderTextUtils::parse(input, &oEntity, sError);
        EXPECT_EQ(true, result);
        EXPECT_EQ(123, oEntity.asInteger(L"ID"));
        EXPECT_STREQ(L"广联达", oEntity.asString(L"Name").c_str());
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parse_empty)
{
    std::wstring sError;
    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CStringType oStringType;
    gfc::schema::CClass oClass;
    {
        auto pAttr1 = new gfc::schema::CAttribute();
        pAttr1->SetName(L"ID");
        pAttr1->SetType(&oIntegerType);
        oClass.addAttribute(pAttr1);
    }
    {
        auto pAttr1 = new gfc::schema::CAttribute();
        pAttr1->SetName(L"Name");
        pAttr1->SetType(&oStringType);
        oClass.addAttribute(pAttr1);
    }
    {
        auto pAttr1 = new gfc::schema::CAttribute();
        pAttr1->SetName(L"Width");
        pAttr1->SetType(&oIntegerType);
        pAttr1->SetOptionalFlag(true);
        oClass.addAttribute(pAttr1);
    }

    {
        gfc::engine::CEntity oEntity;
        oEntity.setSchema(&oClass);
        std::string input = UnicodeToUtf8(L"123,'广联达',$");
        std::string value;
        {
            auto result = gfc::engine::CReaderTextUtils::parse(input, &oEntity, sError);
            EXPECT_EQ(true, result);
            EXPECT_EQ(123, oEntity.asInteger(L"ID"));
            EXPECT_STREQ(L"广联达", oEntity.asString(L"Name").c_str());
            EXPECT_EQ(true, oEntity.isNull(L"Width"));
        }
    }
    {
        gfc::engine::CEntity oEntity;
        oEntity.setSchema(&oClass);
        std::string input = UnicodeToUtf8(L" 123 , '广联达' , $ ");
        std::string value;
        {
            auto result = gfc::engine::CReaderTextUtils::parse(input, &oEntity, sError);
            EXPECT_EQ(true, result);
            EXPECT_EQ(123, oEntity.asInteger(L"ID"));
            EXPECT_STREQ(L"广联达", oEntity.asString(L"Name").c_str());
            EXPECT_EQ(true, oEntity.isNull(L"Width"));
        }
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parse_repeat)
{
    std::wstring sError;
    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CStringType oStringType;
    gfc::schema::CClass oClass;
    {
        auto pAttr1 = new gfc::schema::CAttribute();
        pAttr1->SetName(L"ID");
        pAttr1->SetType(&oIntegerType);
        oClass.addAttribute(pAttr1);
    }
    {
        auto pAttr1 = new gfc::schema::CAttribute();
        pAttr1->SetName(L"Name");
        pAttr1->SetType(&oStringType);
        oClass.addAttribute(pAttr1);
    }
    {
        auto pAttr1 = new gfc::schema::CAttribute();
        pAttr1->SetName(L"Width");
        pAttr1->SetType(&oIntegerType);
        pAttr1->SetOptionalFlag(true);
        oClass.addAttribute(pAttr1);
    }
    {
        auto pAttr1 = new gfc::schema::CAttribute();
        pAttr1->SetName(L"List");
        pAttr1->SetType(&oIntegerType);
        pAttr1->SetRepeatFlag(true);
        oClass.addAttribute(pAttr1);
    }

    {
        gfc::engine::CEntity oEntity;
        oEntity.setSchema(&oClass);
        std::string input = UnicodeToUtf8(L"123,'广联达',$,(1,2,3)");
        std::string value;
        {
            auto result = gfc::engine::CReaderTextUtils::parse(input, &oEntity, sError);
            EXPECT_EQ(true, result);
            EXPECT_EQ(123, oEntity.asInteger(L"ID"));
            EXPECT_STREQ(L"广联达", oEntity.asString(L"Name").c_str());
            EXPECT_EQ(true, oEntity.isNull(L"Width"));
            auto pValue = oEntity.valueByName(L"List");
            EXPECT_EQ(3, pValue->getCount());
            EXPECT_EQ(1, pValue->getItems(0)->asInteger());
            EXPECT_EQ(2, pValue->getItems(1)->asInteger());
            EXPECT_EQ(3, pValue->getItems(2)->asInteger());
        }
    }
    {
        gfc::engine::CEntity oEntity;
        oEntity.setSchema(&oClass);
        std::string input = UnicodeToUtf8(L" 123 , '广联达' , $ , ( 12 , 32 , 45 )");
        std::string value;
        {
            auto result = gfc::engine::CReaderTextUtils::parse(input, &oEntity, sError);
            EXPECT_EQ(true, result);
            EXPECT_EQ(123, oEntity.asInteger(L"ID"));
            EXPECT_STREQ(L"广联达", oEntity.asString(L"Name").c_str());
            EXPECT_EQ(true, oEntity.isNull(L"Width"));
            auto pValue = oEntity.valueByName(L"List");
            EXPECT_EQ(3, pValue->getCount());
            EXPECT_EQ(12, pValue->getItems(0)->asInteger());
            EXPECT_EQ(32, pValue->getItems(1)->asInteger());
            EXPECT_EQ(45, pValue->getItems(2)->asInteger());
        }
    }
    {
        gfc::engine::CEntity oEntity;
        oEntity.setSchema(&oClass);
        std::string input = UnicodeToUtf8(L"123,'广联达',$,()");
        std::string value;
        {
            auto result = gfc::engine::CReaderTextUtils::parse(input, &oEntity, sError);
            EXPECT_EQ(true, result);
            EXPECT_EQ(123, oEntity.asInteger(L"ID"));
            EXPECT_STREQ(L"广联达", oEntity.asString(L"Name").c_str());
            EXPECT_EQ(true, oEntity.isNull(L"Width"));
            auto pValue = oEntity.valueByName(L"List");
            EXPECT_EQ(true, pValue->isNull());
        }
    }
    {
        gfc::engine::CEntity oEntity;
        oEntity.setSchema(&oClass);
        std::string input = UnicodeToUtf8(L"123,'广联达',$,$");
        std::string value;
        {
            auto result = gfc::engine::CReaderTextUtils::parse(input, &oEntity, sError);
            EXPECT_EQ(true, result);
            EXPECT_EQ(123, oEntity.asInteger(L"ID"));
            EXPECT_STREQ(L"广联达", oEntity.asString(L"Name").c_str());
            EXPECT_EQ(true, oEntity.isNull(L"Width"));
            auto pValue = oEntity.valueByName(L"List");
            EXPECT_EQ(true, pValue->isNull());
        }
    }
}

TEST(TestReaderTextImp, CReaderTextUtils_parseLine)
{
    std::string input = UnicodeToUtf8(L"#101=Gfc2Vector2d(1,2,3);");
    std::string context;
    std::string name;
    {
        gfc::engine::EntityRef nRef;
        auto result = gfc::engine::CReaderTextUtils::parseLine(input, nRef, name, context);
        EXPECT_EQ(true, result);
        EXPECT_EQ(101, nRef);
        EXPECT_STREQ("Gfc2Vector2d", name.c_str());
        EXPECT_STREQ("1,2,3", context.c_str());
    }
}


TEST(TestReaderTextImp, CReaderTextUtils_parseLine_error)
{
    std::string context;
    std::string name;
    gfc::engine::EntityRef nRef;
    {
        std::string input = UnicodeToUtf8(L"#1=();");
        auto result = gfc::engine::CReaderTextUtils::parseLine(input, nRef, name, context);
        EXPECT_EQ(false, result);
    }
    {
        std::string input = UnicodeToUtf8(L"1=G(1,2);");
        auto result = gfc::engine::CReaderTextUtils::parseLine(input, nRef, name, context);
        EXPECT_EQ(false, result);
    }
    {
        std::string input = UnicodeToUtf8(L"#1=G(1,2)");
        auto result = gfc::engine::CReaderTextUtils::parseLine(input, nRef, name, context);
        EXPECT_EQ(false, result);
    }
    {
        std::string input = UnicodeToUtf8(L"#1=G1,2);");
        auto result = gfc::engine::CReaderTextUtils::parseLine(input, nRef, name, context);
        EXPECT_EQ(false, result);
    }
    {
        std::string input = UnicodeToUtf8(L"#1=G(1,2;");
        auto result = gfc::engine::CReaderTextUtils::parseLine(input, nRef, name, context);
        EXPECT_EQ(false, result);
    }
    {
        std::string input = UnicodeToUtf8(L"#=G(1,2);");
        auto result = gfc::engine::CReaderTextUtils::parseLine(input, nRef, name, context);
        EXPECT_EQ(false, result);
    }
}