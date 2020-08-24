#include "gtest\gtest.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\EngineException.h"
#include "GfcEngine\PropValue.h"
#include "GfcEngine\GfcEngineUtils.h"
#include "GfcEngine\Writer.h"
#include "WriterTextImp.h"
#include "Common.h"
#include "GfcSchema\BuildinType.h"
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\EnumType.h"
#include "GfcSchema\EntityAttribute.h"
#include "GfcSchema\Model.h"

TEST(TestWriteTextImp, CWriterTextUtils_writevalue_Integer)
{
    gfc::schema::CIntegerType oIntegerType;
    {
        std::stringstream ss;
        gfc::engine::CIntegerValue oValue(12);
        gfc::engine::CWriterTextUtils::writeValue(ss, &oIntegerType, &oValue);
        EXPECT_STREQ("12", ss.str().c_str());
    }

    {
        std::stringstream ss;
        gfc::engine::CIntegerValue oValue(-123);
        gfc::engine::CWriterTextUtils::writeValue(ss, &oIntegerType, &oValue);
        EXPECT_STREQ("-123", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterTextUtils_writevalue_Boolean)
{
    gfc::schema::CBooleanType oType;
    {
        std::stringstream ss;
        gfc::engine::CBooleanValue oValue(true);
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(".T.", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CBooleanValue oValue(false);
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(".F.", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterTextUtils_writevalue_Double)
{
    gfc::schema::CRealType oType;
    {
        std::stringstream ss;
        gfc::engine::CDoubleValue oValue(22.34);
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        auto d = std::stod(ss.str().c_str());
        EXPECT_NEAR(22.34, d, 1e-7);
    }
    {
        std::stringstream ss;
        gfc::engine::CDoubleValue  oValue(22222.123456);
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        auto s = ss.str();
        auto d = std::stod(s.c_str());
        EXPECT_NEAR(22222.123456, d, 1e-8);
    }
}

TEST(TestWriteTextImp, CWriterTextUtils_writevalue_String)
{
    gfc::schema::CStringType oType;
    {
        std::stringstream ss;
        gfc::engine::CStringValue  oValue(L"1234567890abcXYZ");
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("'1234567890abcXYZ'", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"中文");
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(UnicodeToUtf8(L"'中文'").c_str(), ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"'");
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("'\\''", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"\n");
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("'\\n'", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"\r");
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("'\\r'", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"\\");
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("'\\\\'", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CStringValue oValue(L"中文='abc'\n\r英文=\\");
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(UnicodeToUtf8(L"'中文=\\'abc\\'\\n\\r英文=\\\\'").c_str(), ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterTextUtils_writevalue_Entity)
{
    gfc::schema::CClass oType;
    {
        std::stringstream ss;
        gfc::engine::CEntityRefValue oValue(12);
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ("#12", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterTextUtils_writevalue_Enum)
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
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(".abc.", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CIntegerValue oValue(4);
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(".nop.", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CIntegerValue oValue(12);
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(".hij.", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CIntegerValue oValue(-12);
        gfc::engine::CWriterTextUtils::writeValue(ss, &oType, &oValue);
        EXPECT_STREQ(".klm.", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterTextUtils_writeProperty)
{
    gfc::schema::CIntegerType oType;
    gfc::schema::CAttribute oAttrib;
    oAttrib.SetType(&oType);
    {
        std::stringstream ss;
        gfc::engine::CProperty oProp(&oAttrib, new gfc::engine::CIntegerValue(12));
        gfc::engine::CWriterTextUtils::writeProperty(ss, &oProp);
        EXPECT_STREQ("12", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CProperty oProp(&oAttrib, new gfc::engine::CIntegerValue());
        gfc::engine::CWriterTextUtils::writeProperty(ss, &oProp);
        EXPECT_STREQ("$", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterTextUtils_writeProperty_list)
{
    gfc::schema::CIntegerType oType;
    gfc::schema::CAttribute oAttrib;
    oAttrib.SetRepeatFlag(true);
    oAttrib.SetType(&oType);
    {
        std::stringstream ss;
        auto pValue = new gfc::engine::CCompositePropValue;
        gfc::engine::CProperty oProp(&oAttrib, pValue);
        gfc::engine::CWriterTextUtils::writeProperty(ss, &oProp);
        EXPECT_STREQ("$", ss.str().c_str());
    }
    {
        std::stringstream ss;
        auto pValue = new gfc::engine::CCompositePropValue;
        pValue->add(new gfc::engine::CIntegerValue(12));
        gfc::engine::CProperty oProp(&oAttrib, pValue);
        gfc::engine::CWriterTextUtils::writeProperty(ss, &oProp);
        EXPECT_STREQ("(12)", ss.str().c_str());
    }
    {
        std::stringstream ss;
        auto pValue = new gfc::engine::CCompositePropValue;
        pValue->add(new gfc::engine::CIntegerValue(12));
        pValue->add(new gfc::engine::CIntegerValue(34));
        pValue->add(new gfc::engine::CIntegerValue(90));
        gfc::engine::CProperty oProp(&oAttrib, pValue);
        gfc::engine::CWriterTextUtils::writeProperty(ss, &oProp);
        EXPECT_STREQ("(12,34,90)", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterTextUtils_writeEntity)
{
    gfc::schema::CClass oClass;
    oClass.SetName(L"Gfc2Test");
    {
        std::stringstream ss;
        gfc::engine::CEntity* pEntity = new gfc::engine::CEntity;
        pEntity->setSchema(&oClass);
        gfc::engine::CWriterTextUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test();", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterTextUtils_writeEntity_one_attribute)
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
        gfc::engine::CWriterTextUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test($);", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CEntity* pEntity = new gfc::engine::CEntity;
        pEntity->setSchema(&oClass);
        pEntity->setAsInteger(L"ID", 123);
        gfc::engine::CWriterTextUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test(123);", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterTextUtils_writeEntity_more_attribute)
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
        gfc::engine::CWriterTextUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test($,$);", ss.str().c_str());
    }
    {
        std::stringstream ss;
        gfc::engine::CEntity* pEntity = new gfc::engine::CEntity;
        pEntity->setSchema(&oClass);
        pEntity->setAsInteger(L"ID", 123);
        pEntity->setAsInteger(L"Flag", true);
        gfc::engine::CWriterTextUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test(123,.T.);", ss.str().c_str());
    }
}

TEST(TestWriteTextImp, CWriterTextUtils_writeEntity_more_attribute2)
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
        gfc::engine::CWriterTextUtils::writeEntity(ss, pEntity, 101);
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
        gfc::engine::CWriterTextUtils::writeEntity(ss, pEntity, 101);
        EXPECT_STREQ("#101=Gfc2Test(123,.T.,(.abc.,.kkk.,.dtdg.));", ss.str().c_str());
    }
}

class CMockWriterImp : public gfc::engine::CWriterImp
{
public:
    virtual bool open(const std::wstring& sFileName, const std::wstring& sProductCode, const std::wstring& sVersion)
    {
        return true;
    }
    virtual void close() 
    {

    }
protected:
    virtual gfc::engine::EntityRef doWriteEntity(gfc::engine::CEntity* pEntity) 
    {
        return ++m_nCount;
    }
};

/*
TEST(TestWriteTextImp, CWriter_addIgnoreDuplicates)
{
    CMockWriterImp oWriter;
    oWriter.addIgnoreDuplicates(L"Gfc2String");
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    auto pStr = std::shared_ptr<gfc::engine::CEntity>(gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2String"));
    pStr->setAsString(L"Value", L"中国");
    auto nRef = oWriter.writeEntity(pStr.get());
    auto pStr2 = std::shared_ptr<gfc::engine::CEntity>(gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2String"));
    pStr2->setAsString(L"Value", L"中国");
    auto nRef2 = oWriter.writeEntity(pStr2.get());
    auto pStr3 = std::shared_ptr<gfc::engine::CEntity>(gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2String"));
    pStr3->setAsString(L"Value", L"中国1");
    auto nRef3 = oWriter.writeEntity(pStr3.get());
    auto pLabel = std::shared_ptr<gfc::engine::CEntity>(gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Label"));
    pLabel->setAsString(L"Value", L"中国");
    auto nRef4 = oWriter.writeEntity(pLabel.get());
    EXPECT_EQ(nRef, nRef2);
    EXPECT_NE(nRef, nRef3);
    EXPECT_NE(nRef, nRef4);
    EXPECT_NE(nRef3, nRef4);
}
*/

/*
TEST(TestWriteTextImp, CWriter_2)
{
    gfc::schema::CModel oModel;
    gfc::engine::CWriter oWriter(L"2X0", L"", CP_ACP);
    if (oWriter.open(L"d:\\0805.gfc", L"express"))
    {
        gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oModel);
        auto pColumn = std::shared_ptr<gfc::engine::CEntity>(gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2PointColumn"));
        auto pStr2 = std::shared_ptr<gfc::engine::CEntity>(gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2String"));
        pStr2->setAsString(L"Value", L"Z-1");
        pColumn->setAsInteger(L"ID", 1234);
        pColumn->setAsEntityRef(L"Name", oWriter.writeEntity(pStr2.get()));
        oWriter.writeEntity(pColumn.get());
        oWriter.close();
    }
}
*/