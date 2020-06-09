#include "gtest\gtest.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\EngineException.h"
#include "GfcEngine\PropValue.h"
#include "WriterTextImp.h"
#include "Common.h"
#include "GfcSchema\BuildinType.h"
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\EnumType.h"
#include "GfcSchema\EntityAttribute.h"

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
        gfc::engine::CStringValue  oValue(L"1234567890abcXYZ");
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("'1234567890abcXYZ'", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"中文");
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(UnicodeToUtf8(L"'中文'").c_str(), ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"'");
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("'\\''", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"\n");
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("'\\n'", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"\r");
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("'\\r'", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"\\");
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("'\\\\'", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"中文='abc'\n\r英文=\\");
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(UnicodeToUtf8(L"'中文=\\'abc\\'\\n\\r英文=\\\\'").c_str(), ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterEntityUtils_writevalue_Entity)
{
    gfc::schema::CClass oType;
    {
        std::stringstream ss;
        gfc::engine::CEntityRefValue oValue(12);
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("#12", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterEntityUtils_writevalue_Enum)
{
    gfc::schema::CEnumType oType;
    oType.addEnum(L"abc", L"");
    oType.addEnum(L"efg", L"");
    oType.addEnum(L"hij", L"");
    oType.addEnum(L"klm", L"");
    oType.addEnum(L"nop", L"");
    {
        std::stringstream ss;
        gfc::engine::CIntegerValue oValue(0);
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(".abc.", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CIntegerValue oValue(4);
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(".nop.", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CIntegerValue oValue(12);
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(".hij.", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CIntegerValue oValue(-12);
        gfc::engine::CWriterEntityUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(".klm.", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterEntityUtils_writeProperty)
{
    gfc::schema::CIntegerType oType;
    gfc::schema::CAttribute oAttrib;
    oAttrib.SetType(&oType);
    {
        std::stringstream ss;
        gfc::engine::CProperty oProp(&oAttrib, new gfc::engine::CIntegerValue(12));
        gfc::engine::CWriterEntityUtils::writeProperty(ss, &oProp);
        EXPECT_STREQ("12", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CProperty oProp(&oAttrib, new gfc::engine::CIntegerValue());
        gfc::engine::CWriterEntityUtils::writeProperty(ss, &oProp);
        EXPECT_STREQ("$", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterEntityUtils_writeProperty_list)
{
    gfc::schema::CIntegerType oType;
    gfc::schema::CAttribute oAttrib;
    oAttrib.SetRepeatFlag(true);
    oAttrib.SetType(&oType);
    {
        std::stringstream ss;
        auto pValue = new gfc::engine::CCompositePropValue;
        gfc::engine::CProperty oProp(&oAttrib, pValue);
        gfc::engine::CWriterEntityUtils::writeProperty(ss, &oProp);
        EXPECT_STREQ("$", ss.str().c_str());
    }
    {
        std::stringstream ss;
        auto pValue = new gfc::engine::CCompositePropValue;
        pValue->add(new gfc::engine::CIntegerValue(12));
        gfc::engine::CProperty oProp(&oAttrib, pValue);
        gfc::engine::CWriterEntityUtils::writeProperty(ss, &oProp);
        EXPECT_STREQ("(12)", ss.str().c_str());
    }
    {
        std::stringstream ss;
        auto pValue = new gfc::engine::CCompositePropValue;
        pValue->add(new gfc::engine::CIntegerValue(12));
        pValue->add(new gfc::engine::CIntegerValue(34));
        pValue->add(new gfc::engine::CIntegerValue(90));
        gfc::engine::CProperty oProp(&oAttrib, pValue);
        gfc::engine::CWriterEntityUtils::writeProperty(ss, &oProp);
        EXPECT_STREQ("(12,34,90)", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterEntityUtils_writeEntity)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Gfc2Test");
    {
        std::stringstream ss;
        gfc::engine::CEntity* pEntity = new gfc::engine::CEntity;
        pEntity->setSchema(&oClass);
        gfc::engine::CWriterEntityUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test();", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterEntityUtils_writeEntity_one_attribute)
{
    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CClass oClass;
    oClass.SetName(L"Gfc2Test");
    auto pAttrb = new gfc::schema::CAttribute;
    pAttrb->SetType(&oIntegerType);
    pAttrb->SetName(L"ID");
    oClass.addAttribute(pAttrb);
    {
        std::stringstream ss;
        gfc::engine::CEntity* pEntity = new gfc::engine::CEntity;
        pEntity->setSchema(&oClass);
        gfc::engine::CWriterEntityUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test($);", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CEntity* pEntity = new gfc::engine::CEntity;
        pEntity->setSchema(&oClass);
        pEntity->setAsInteger(L"ID", 123);
        gfc::engine::CWriterEntityUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test(123);", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterEntityUtils_writeEntity_more_attribute)
{
    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CBooleanType oBooleanType;
    gfc::schema::CClass oClass;
    oClass.SetName(L"Gfc2Test");
    {
        auto pAttrb = new gfc::schema::CAttribute;
        pAttrb->SetType(&oIntegerType);
        pAttrb->SetName(L"ID");
        oClass.addAttribute(pAttrb);
    }
    {
        auto pAttrb = new gfc::schema::CAttribute;
        pAttrb->SetType(&oBooleanType);
        pAttrb->SetName(L"Flag");
        oClass.addAttribute(pAttrb);
    }
    {
        std::stringstream ss;
        gfc::engine::CEntity* pEntity = new gfc::engine::CEntity;
        pEntity->setSchema(&oClass);
        gfc::engine::CWriterEntityUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test($,$);", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CEntity* pEntity = new gfc::engine::CEntity;
        pEntity->setSchema(&oClass);
        pEntity->setAsInteger(L"ID", 123);
        pEntity->setAsInteger(L"Flag", true);
        gfc::engine::CWriterEntityUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test(123,.T.);", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterEntityUtils_writeEntity_more_attribute2)
{
    gfc::schema::CIntegerType oIntegerType;
    gfc::schema::CBooleanType oBooleanType;
    gfc::schema::CEnumType oEnumType;
    oEnumType.addEnum(L"abc", L"");
    oEnumType.addEnum(L"kkk", L"");
    oEnumType.addEnum(L"dtdg", L"");
    gfc::schema::CClass oClass;
    oClass.SetName(L"Gfc2Test");
    {
        auto pAttrb = new gfc::schema::CAttribute;
        pAttrb->SetType(&oIntegerType);
        pAttrb->SetName(L"ID");
        oClass.addAttribute(pAttrb);
    }
    {
        auto pAttrb = new gfc::schema::CAttribute;
        pAttrb->SetType(&oBooleanType);
        pAttrb->SetName(L"Flag");
        oClass.addAttribute(pAttrb);
    }
    {
        auto pAttrb = new gfc::schema::CAttribute;
        pAttrb->SetType(&oEnumType);
        pAttrb->SetName(L"List");
        pAttrb->SetRepeatFlag(true);
        oClass.addAttribute(pAttrb);
    }
    {
        std::stringstream ss;
        gfc::engine::CEntity* pEntity = new gfc::engine::CEntity;
        pEntity->setSchema(&oClass);
        gfc::engine::CWriterEntityUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test($,$,$);", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CEntity* pEntity = new gfc::engine::CEntity;
        pEntity->setSchema(&oClass);
        pEntity->setAsInteger(L"ID", 123);
        pEntity->setAsInteger(L"Flag", true);
        pEntity->addInteger(L"List", 0);
        pEntity->addInteger(L"List", 1);
        pEntity->addInteger(L"List", 2);
        gfc::engine::CWriterEntityUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test(123,.T.,(.abc.,.kkk.,.dtdg.));", ss.str().c_str());
    }
}