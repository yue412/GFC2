#include "gtest\gtest.h"
#include "AttributeCompatibility.h"
#include "EntityAttribute.h"
#include "BuildinType.h"
#include "EnumType.h"
#include "EntityClass.h"
#include "Converter.h"
#include "AttributeValue.h"

using namespace gfc2::schema;

TEST(TestAttributeCompatibility, FromIsNil)
{
    gfc2::schema::CAttribute oToAttrib;
    oToAttrib.SetName(L"abc");
    gfc2::schema::CAttributeCompatibility oCompatibility;
    oCompatibility.init(nullptr, &oToAttrib, 0);
    EXPECT_EQ(true, L"abc" == oCompatibility.getName());
    EXPECT_EQ(false, oCompatibility.isCompatible());
    EXPECT_EQ(nullptr, oCompatibility.converter());
}

TEST(TestAttributeCompatibility, FromIsNil_ToOptional)
{
    gfc2::schema::CAttribute oToAttrib;
    oToAttrib.SetOptionalFlag(true);
    gfc2::schema::CAttributeCompatibility oCompatibility;
    oCompatibility.init(nullptr, &oToAttrib, 0);
    EXPECT_EQ(true, oCompatibility.isCompatible());
}

TEST(TestAttributeCompatibility, FromIsNil_ToRepeat)
{
    gfc2::schema::CAttribute oToAttrib;
    oToAttrib.SetRepeatFlag(true);
    gfc2::schema::CAttributeCompatibility oCompatibility;
    oCompatibility.init(nullptr, &oToAttrib, 0);
    EXPECT_EQ(true, oCompatibility.isCompatible());
}

TEST(TestAttributeCompatibility, ToIsNil)
{
    gfc2::schema::CAttribute oFromAttrib;
    oFromAttrib.SetName(L"abc");
    gfc2::schema::CAttributeCompatibility oCompatibility;
    oCompatibility.init(&oFromAttrib, nullptr, -1);
    EXPECT_EQ(true, L"abc" == oCompatibility.getName());
    EXPECT_EQ(true, oCompatibility.isCompatible());
    EXPECT_EQ(nullptr, oCompatibility.converter());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Bool_Int)
{
    gfc2::schema::CBuildinType oFrom(L"BOOLEAN");
    gfc2::schema::CBuildinType oTo(L"INTEGER");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L".T.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"1" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Bool_Bool)
{
    gfc2::schema::CBuildinType oFrom(L"BOOLEAN");
    gfc2::schema::CBuildinType oTo(L"BOOLEAN");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L".T.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L".T." == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Bool_Real)
{
    gfc2::schema::CBuildinType oFrom(L"BOOLEAN");
    gfc2::schema::CBuildinType oTo(L"REAL");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L".T.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    auto dVal = std::stod(pValue->asString());
    EXPECT_NEAR(1.0, dVal, 1e-6);
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Bool_String)
{
    gfc2::schema::CBuildinType oFrom(L"BOOLEAN");
    gfc2::schema::CBuildinType oTo(L"STRING");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L".T.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"'1'" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Bool_Enum)
{
    gfc2::schema::CBuildinType oFrom(L"BOOLEAN");
    gfc2::schema::CEnumType oTo;
    oTo.addEnum(L"abc", L"");
    oTo.addEnum(L"def", L"");
    oTo.addEnum(L"hig", L"");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L".T.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L".def." == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Bool_Entity)
{
    gfc2::schema::CBuildinType oFrom(L"BOOLEAN");
    gfc2::schema::CClass oTo(L"CTest");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L".T.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Int_Bool)
{
    gfc2::schema::CBuildinType oFrom(L"INTEGER");
    gfc2::schema::CBuildinType oTo(L"BOOLEAN");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"12";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L".T." == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Int_Int)
{
    gfc2::schema::CBuildinType oFrom(L"INTEGER");
    gfc2::schema::CBuildinType oTo(L"INTEGER");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"12";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"12" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Int_Real)
{
    gfc2::schema::CBuildinType oFrom(L"INTEGER");
    gfc2::schema::CBuildinType oTo(L"REAL");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"12";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    auto dVal = std::stod(pValue->asString());
    EXPECT_NEAR(12, dVal, 1e-6);
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Int_String)
{
    gfc2::schema::CBuildinType oFrom(L"INTEGER");
    gfc2::schema::CBuildinType oTo(L"STRING");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"12";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"'12'" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Int_Enum)
{
    gfc2::schema::CBuildinType oFrom(L"INTEGER");
    gfc2::schema::CEnumType oTo;
    oTo.addEnum(L"abc", L"");
    oTo.addEnum(L"def", L"");
    oTo.addEnum(L"hig", L"");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"11";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L".hig." == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Int_Entity)
{
    gfc2::schema::CBuildinType oFrom(L"INTEGER");
    gfc2::schema::CClass oTo(L"CTest");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"12";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Real_Bool)
{
    gfc2::schema::CBuildinType oFrom(L"REAL");
    gfc2::schema::CBuildinType oTo(L"BOOLEAN");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"12.3";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Real_Int)
{
    gfc2::schema::CBuildinType oFrom(L"REAL");
    gfc2::schema::CBuildinType oTo(L"INTEGER");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"12.3";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Real_Real)
{
    gfc2::schema::CBuildinType oFrom(L"REAL");
    gfc2::schema::CBuildinType oTo(L"REAL");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"12.3";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    auto dVal = std::stod(pValue->asString());
    EXPECT_NEAR(12.3, dVal, 1e-6);
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Real_String)
{
    gfc2::schema::CBuildinType oFrom(L"REAL");
    gfc2::schema::CBuildinType oTo(L"STRING");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"12.3";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"'12.3'" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Real_Enum)
{
    gfc2::schema::CBuildinType oFrom(L"REAL");
    gfc2::schema::CEnumType oTo;
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"12.3";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Real_Entity)
{
    gfc2::schema::CBuildinType oFrom(L"REAL");
    gfc2::schema::CClass oTo;
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"12.3";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_String_bool)
{
    gfc2::schema::CBuildinType oFrom(L"STRING");
    gfc2::schema::CBuildinType oTo(L"BOOLEAN");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"'.T.'";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_String_Int)
{
    gfc2::schema::CBuildinType oFrom(L"STRING");
    gfc2::schema::CBuildinType oTo(L"INTEGER");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"'12'";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_String_Real)
{
    gfc2::schema::CBuildinType oFrom(L"STRING");
    gfc2::schema::CBuildinType oTo(L"REAL");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"'12.3'";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_String_String)
{
    gfc2::schema::CBuildinType oFrom(L"STRING");
    gfc2::schema::CBuildinType oTo(L"STRING");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"'abdasf'";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"'abdasf'" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_String_Enum)
{
    gfc2::schema::CBuildinType oFrom(L"STRING");
    gfc2::schema::CEnumType oTo;
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"'.abdasf.'";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_String_Entity)
{
    gfc2::schema::CBuildinType oFrom(L"STRING");
    gfc2::schema::CClass oTo;
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"'abdasf'";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Enum_Bool)
{
    gfc2::schema::CEnumType oFrom;
    oFrom.addEnum(L"abc", L"");
    oFrom.addEnum(L"def", L"");
    oFrom.addEnum(L"hig", L"");
    gfc2::schema::CBuildinType oTo(L"BOOLEAN");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L".hig.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L".T." == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Enum_Int)
{
    gfc2::schema::CEnumType oFrom;
    oFrom.addEnum(L"abc", L"");
    oFrom.addEnum(L"def", L"");
    oFrom.addEnum(L"hig", L"");
    gfc2::schema::CBuildinType oTo(L"INTEGER");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L".hig.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"2" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Enum_Real)
{
    gfc2::schema::CEnumType oFrom;
    oFrom.addEnum(L"abc", L"");
    oFrom.addEnum(L"def", L"");
    oFrom.addEnum(L"hig", L"");
    gfc2::schema::CBuildinType oTo(L"REAL");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L".hig.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    auto dVal = std::stod(pValue->asString());
    EXPECT_NEAR(2, dVal, 1e-6);
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Enum_Enum_1)
{
    gfc2::schema::CEnumType oFrom;
    oFrom.addEnum(L"abc", L"");
    oFrom.addEnum(L"def", L"");
    oFrom.addEnum(L"hig", L"");
    gfc2::schema::CEnumType oTo;
    oTo.addEnum(L"abc", L"");
    oTo.addEnum(L"def", L"");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L".hig.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
    sValue = L".abc.";
    pValue->setAsString(sValue);
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L".abc." == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Enum_Enum_2)
{
    gfc2::schema::CEnumType oFrom;
    oFrom.addEnum(L"abc", L"");
    oFrom.addEnum(L"def", L"");
    oFrom.addEnum(L"hig", L"");
    gfc2::schema::CEnumType oTo;
    oTo.addEnum(L"abc", L"");
    oTo.addEnum(L"def", L"");
    oTo.addEnum(L"hig", L"");
    oTo.addEnum(L"klm", L"");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L".hig.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L".hig." == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Enum_Class)
{
    gfc2::schema::CEnumType oFrom;
    oFrom.addEnum(L"abc", L"");
    oFrom.addEnum(L"def", L"");
    oFrom.addEnum(L"hig", L"");
    gfc2::schema::CClass oTo;
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L".hig.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Class_Bool)
{
    gfc2::schema::CClass oFrom;
    gfc2::schema::CBuildinType oTo(L"BOOLEAN");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"#123";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Class_Int)
{
    gfc2::schema::CClass oFrom;
    gfc2::schema::CBuildinType oTo(L"INTEGER");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"#123";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Class_Real)
{
    gfc2::schema::CClass oFrom;
    gfc2::schema::CBuildinType oTo(L"REAL");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"#123";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Class_String)
{
    gfc2::schema::CClass oFrom;
    gfc2::schema::CBuildinType oTo(L"STRING");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"#123";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Class_Enum)
{
    gfc2::schema::CClass oFrom;
    gfc2::schema::CEnumType oTo;
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"#123";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Class_Class)
{
    gfc2::schema::CClass oFrom(L"CTest");
    gfc2::schema::CClass oTo(L"CTest");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"#123";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"#123" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Class_Class_1)
{
    gfc2::schema::CClass oFrom(L"CTest");
    gfc2::schema::CClass oTo(L"CTest2");
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"#123";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getTypeCompatibility_Class_Class_2)
{
    gfc2::schema::CClass oParent2(L"CTest2");
    gfc2::schema::CClass oParent(L"CTest1");
    gfc2::schema::CClass oFrom(L"CTest");
    gfc2::schema::CClass oTo(L"CTest2");
    oFrom.setParent(&oParent);
    oParent.setParent(&oParent2);
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getTypeCompatibility(&oFrom, &oTo);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"#123";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"#123" == pValue->asString());
}

TEST(TestAttributeCompatibility, getMultiCompatibility_Array_Array)
{
    gfc2::schema::CAttribute oFromAttribute;
    oFromAttribute.SetRepeatFlag(true);
    gfc2::schema::CAttribute oToAttribute;
    oToAttribute.SetRepeatFlag(true);
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getMultiCompatibility(&oFromAttribute, &oToAttribute);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
//    std::wstring sValue = L"(1,2,3)";
    CAttributeValuePtr pValue(new CCompositeAttributeValue);
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"1")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"2")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"3")));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"(1,2,3)" == pValue->asString());
}

TEST(TestAttributeCompatibility, getMultiCompatibility_Array_Optional)
{
    gfc2::schema::CAttribute oFromAttribute;
    oFromAttribute.SetRepeatFlag(true);
    gfc2::schema::CAttribute oToAttribute;
    oToAttribute.SetOptionalFlag(true);
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getMultiCompatibility(&oFromAttribute, &oToAttribute);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
//    std::wstring sValue = L"(1,2,3)";
    CAttributeValuePtr pValue(new CCompositeAttributeValue);
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"1")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"2")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"3")));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"1" == pValue->asString());
}

TEST(TestAttributeCompatibility, getMultiCompatibility_Array_Required)
{
    gfc2::schema::CAttribute oFromAttribute;
    oFromAttribute.SetRepeatFlag(true);
    gfc2::schema::CAttribute oToAttribute;
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getMultiCompatibility(&oFromAttribute, &oToAttribute);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
//    std::wstring sValue = L"(1,2,3)";
    CAttributeValuePtr pValue(new CCompositeAttributeValue);
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"1")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"2")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"3")));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"1" == pValue->asString());
}

TEST(TestAttributeCompatibility, getMultiCompatibility_Array_Required_2)
{
    gfc2::schema::CAttribute oFromAttribute;
    oFromAttribute.SetRepeatFlag(true);
    gfc2::schema::CAttribute oToAttribute;
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getMultiCompatibility(&oFromAttribute, &oToAttribute);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
//    std::wstring sValue = L"()";
    CAttributeValuePtr pValue(new CCompositeAttributeValue);
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestAttributeCompatibility, getMultiCompatibility_Optional_Array)
{
    gfc2::schema::CAttribute oFromAttribute;
    oFromAttribute.SetOptionalFlag(true);
    gfc2::schema::CAttribute oToAttribute;
    oToAttribute.SetRepeatFlag(true);
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getMultiCompatibility(&oFromAttribute, &oToAttribute);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"$";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());

    sValue = L"1";
    pValue = CAttributeValuePtr(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"(1)" == pValue->asString());
}

TEST(TestAttributeCompatibility, getMultiCompatibility_Optional_Optional)
{
    gfc2::schema::CAttribute oFromAttribute;
    oFromAttribute.SetOptionalFlag(true);
    gfc2::schema::CAttribute oToAttribute;
    oToAttribute.SetOptionalFlag(true);
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getMultiCompatibility(&oFromAttribute, &oToAttribute);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"$";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());

    sValue = L"1";
    pValue = CAttributeValuePtr(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"1" == pValue->asString());
}

TEST(TestAttributeCompatibility, getMultiCompatibility_Optional_Required)
{
    gfc2::schema::CAttribute oFromAttribute;
    oFromAttribute.SetOptionalFlag(true);
    gfc2::schema::CAttribute oToAttribute;
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getMultiCompatibility(&oFromAttribute, &oToAttribute);
    EXPECT_EQ(false, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"$";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());

    sValue = L"1";
    pValue = CAttributeValuePtr(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"1" == pValue->asString());
}

TEST(TestAttributeCompatibility, getMultiCompatibility_Required_Array)
{
    gfc2::schema::CAttribute oFromAttribute;
    gfc2::schema::CAttribute oToAttribute;
    oToAttribute.SetRepeatFlag(true);
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getMultiCompatibility(&oFromAttribute, &oToAttribute);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"1";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"(1)" == pValue->asString());
}

TEST(TestAttributeCompatibility, getMultiCompatibility_Required_Optional)
{
    gfc2::schema::CAttribute oFromAttribute;
    gfc2::schema::CAttribute oToAttribute;
    oToAttribute.SetOptionalFlag(true);
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getMultiCompatibility(&oFromAttribute, &oToAttribute);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"1";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"1" == pValue->asString());
}

TEST(TestAttributeCompatibility, getMultiCompatibility_Required_Required)
{
    gfc2::schema::CAttribute oFromAttribute;
    gfc2::schema::CAttribute oToAttribute;
    auto oTypeCompatibility = gfc2::schema::CAttributeCompatibility::getMultiCompatibility(&oFromAttribute, &oToAttribute);
    EXPECT_EQ(true, oTypeCompatibility.isCompatibility);
    std::wstring sValue = L"1";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oTypeCompatibility.converter->transform(pValue);
    EXPECT_EQ(true, L"1" == pValue->asString());
}

TEST(TestAttributeCompatibility, Compose)
{
    gfc2::schema::CAttribute oFromAttrib;
    oFromAttrib.SetName(L"abc");
    oFromAttrib.SetRepeatFlag(true);
    gfc2::schema::CEnumType oFrom;
    oFrom.addEnum(L"abc", L"");
    oFrom.addEnum(L"def", L"");
    oFrom.addEnum(L"hig", L"");
    oFromAttrib.SetType(&oFrom);
    gfc2::schema::CAttribute oToAttrib;
    oToAttrib.SetRepeatFlag(true);
    gfc2::schema::CBuildinType oTo(L"INTEGER");
    oToAttrib.SetType(&oTo);
    gfc2::schema::CAttributeCompatibility oCompatibility;
    oCompatibility.init(&oFromAttrib, &oToAttrib, -1);
    EXPECT_EQ(true, L"abc" == oCompatibility.getName());
    EXPECT_EQ(true, oCompatibility.isCompatible());
    //std::wstring sValue = L"(.abc.,.hig.,.abc.)";
    CAttributeValuePtr pValue(new CCompositeAttributeValue);
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L".abc.")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L".hig.")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L".abc.")));
    oCompatibility.converter()->transform(pValue);
    EXPECT_EQ(true, L"(0,2,0)" == pValue->asString());
}

TEST(TestAttributeCompatibility, Compose_string)
{
    gfc2::schema::CAttribute oFromAttrib;
    oFromAttrib.SetName(L"abc");
    oFromAttrib.SetRepeatFlag(true);
    gfc2::schema::CBuildinType oFrom(L"STRING");
    oFromAttrib.SetType(&oFrom);
    gfc2::schema::CAttribute oToAttrib;
    oToAttrib.SetRepeatFlag(true);
    gfc2::schema::CBuildinType oTo(L"STRING");
    oToAttrib.SetType(&oTo);
    gfc2::schema::CAttributeCompatibility oCompatibility;
    oCompatibility.init(&oFromAttrib, &oToAttrib, -1);
    EXPECT_EQ(true, L"abc" == oCompatibility.getName());
    EXPECT_EQ(true, oCompatibility.isCompatible());
    //std::wstring sValue = L"('abc','abc,ef','abc')";
    CAttributeValuePtr pValue(new CCompositeAttributeValue);
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"'abc'")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"'abc,ef'")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"'abc'")));
    oCompatibility.converter()->transform(pValue);
    EXPECT_EQ(true, L"('abc','abc,ef','abc')" == pValue->asString());
}

TEST(TestAttributeCompatibility, Compose_string2)
{
    gfc2::schema::CAttribute oFromAttrib;
    oFromAttrib.SetName(L"abc");
    oFromAttrib.SetRepeatFlag(true);
    gfc2::schema::CBuildinType oFrom(L"STRING");
    oFromAttrib.SetType(&oFrom);
    gfc2::schema::CAttribute oToAttrib;
    oToAttrib.SetRepeatFlag(true);
    gfc2::schema::CBuildinType oTo(L"INTEGER");
    oToAttrib.SetType(&oTo);
    gfc2::schema::CAttributeCompatibility oCompatibility;
    oCompatibility.init(&oFromAttrib, &oToAttrib, -1);
    EXPECT_EQ(true, L"abc" == oCompatibility.getName());
    EXPECT_EQ(false, oCompatibility.isCompatible());
    //std::wstring sValue = L"('abc','abc,ef','abc')";
    CAttributeValuePtr pValue(new CCompositeAttributeValue);
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"'abc'")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"'abc,ef'")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"'abc'")));
    oCompatibility.converter()->transform(pValue);
    EXPECT_EQ(true, L"($,$,$)" == pValue->asString());
}

