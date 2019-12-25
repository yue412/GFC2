#include "gtest\gtest.h"
#include "Converter.h"
#include "EnumType.h"

using namespace gfc2::schema;

TEST(TestConverter, ArrayToArrayConverter_Empty)
{
    gfc2::schema::CArrayToArrayConverter oConverter;
    std::wstring sValue = L"$";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestConverter, ArrayToArrayConverter_Empty2)
{
    gfc2::schema::CArrayToArrayConverter oConverter;
    //std::wstring sValue = L"()";
    CAttributeValuePtr pValue(new CCompositeAttributeValue);
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestConverter, ArrayToArrayConverter)
{
    gfc2::schema::CArrayToArrayConverter oConverter;
    //std::wstring sValue = L"(a,b,c)";
    CAttributeValuePtr pValue(new CCompositeAttributeValue);
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"a")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"b")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"c")));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"(a,b,c)" == pValue->asString());
}

TEST(TestConverter, ArrayToOneConverter_Empty)
{
    gfc2::schema::CArrayToOneConverter oConverter;
    std::wstring sValue = L"$";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestConverter, ArrayToOneConverter_Empty2)
{
    gfc2::schema::CArrayToOneConverter oConverter;
//    std::wstring sValue = L"()";
    CAttributeValuePtr pValue(new CCompositeAttributeValue);
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestConverter, ArrayToOneConverter)
{
    gfc2::schema::CArrayToOneConverter oConverter;
//    std::wstring sValue = L"(a,b,c)";
    CAttributeValuePtr pValue(new CCompositeAttributeValue);
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"a")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"b")));
    pValue->add(CAttributeValuePtr(new CLeafAttributeValue(L"c")));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"a" == pValue->asString());
}

TEST(TestConverter, OneToArrayConverter_Empty)
{
    gfc2::schema::COneToArrayConverter oConverter;
    std::wstring sValue = L"$";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestConverter, OneToArrayConverter)
{
    gfc2::schema::COneToArrayConverter oConverter;
    std::wstring sValue = L"a";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"(a)" == pValue->asString());
}

TEST(TestConverter, OptionalConverter)
{
    gfc2::schema::COptionalConverter oConverter;
    std::wstring sValue = L"abc";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"abc" == pValue->asString());
}

TEST(TestConverter, OptionalConverter_Empty)
{
    gfc2::schema::COptionalConverter oConverter;
    std::wstring sValue = L"$";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestConverter, CopyConverter)
{
    gfc2::schema::CCopyConverter oConverter;
    std::wstring sValue = L"abc";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"abc" == pValue->asString());
}

TEST(TestConverter, EmptyConverter)
{
    gfc2::schema::CEmptyConverter oConverter;
    std::wstring sValue = L"abc";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestConverter, BoolToIntConverter_True)
{
    gfc2::schema::CBoolToIntConverter oConverter;
    std::wstring sValue = L".T.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"1" == pValue->asString());
}

TEST(TestConverter, BoolToIntConverter_False)
{
    gfc2::schema::CBoolToIntConverter oConverter;
    std::wstring sValue = L".F.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"0" == pValue->asString());
}

TEST(TestConverter, BoolToStringConverter_True)
{
    gfc2::schema::CBoolToStringConverter oConverter;
    std::wstring sValue = L".T.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"'1'" == pValue->asString());
}

TEST(TestConverter, BoolToStringConverter_False)
{
    gfc2::schema::CBoolToStringConverter oConverter;
    std::wstring sValue = L".F.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"'0'" == pValue->asString());
}

TEST(TestConverter, BoolToEnumConverter_True)
{
    gfc2::schema::CBoolToEnumConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    oConverter.init(nullptr, &oEnum);
    std::wstring sValue = L".T.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L".def." == pValue->asString());
}

TEST(TestConverter, BoolToEnumConverter_False)
{
    gfc2::schema::CBoolToEnumConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    oConverter.init(nullptr, &oEnum);
    std::wstring sValue = L".F.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L".abc." == pValue->asString());
}

TEST(TestConverter, BoolToEnumConverter_True2)
{
    gfc2::schema::CBoolToEnumConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oConverter.init(nullptr, &oEnum);
    std::wstring sValue = L".T.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L".abc." == pValue->asString());
}

TEST(TestConverter, BoolToEnumConverter_True_Empty)
{
    gfc2::schema::CBoolToEnumConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    std::wstring sValue = L".T.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestConverter, IntToBoolConverter_0)
{
    gfc2::schema::CIntToBoolConverter oConverter;
    std::wstring sValue = L"0";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L".F." == pValue->asString());
}

TEST(TestConverter, IntToBoolConverter_not0)
{
    gfc2::schema::CIntToBoolConverter oConverter;
    std::wstring sValue = L"123";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L".T." == pValue->asString());
}

TEST(TestConverter, StringConverter)
{
    gfc2::schema::CStringConverter oConverter;
    std::wstring sValue = L"123";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"'123'" == pValue->asString());
}

TEST(TestConverter, IntToEnumConverter)
{
    gfc2::schema::CIntToEnumConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    oConverter.init(nullptr, &oEnum);
    std::wstring sValue = L"2";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L".ghi." == pValue->asString());
}

TEST(TestConverter, IntToEnumConverter_0)
{
    gfc2::schema::CIntToEnumConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    oConverter.init(nullptr, &oEnum);
    std::wstring sValue = L"4";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L".def." == pValue->asString());
}

TEST(TestConverter, IntToEnumConverter_1)
{
    gfc2::schema::CIntToEnumConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    std::wstring sValue = L"4";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}

TEST(TestConverter, EnumToBoolConverter_false)
{
    gfc2::schema::CEnumToBoolConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    oConverter.init(&oEnum, nullptr);
    std::wstring sValue = L".abc.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L".F." == pValue->asString());
}

TEST(TestConverter, EnumToBoolConverter_true)
{
    gfc2::schema::CEnumToBoolConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    oConverter.init(&oEnum, nullptr);
    std::wstring sValue = L".ghi.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L".T." == pValue->asString());
}

TEST(TestConverter, EnumToIntConverter)
{
    gfc2::schema::CEnumToIntConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    oConverter.init(&oEnum, nullptr);
    std::wstring sValue = L".ghi.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"2" == pValue->asString());
}

TEST(TestConverter, EnumToStringConverter)
{
    gfc2::schema::CEnumToStringConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    oConverter.init(&oEnum, nullptr);
    std::wstring sValue = L".ghi.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"'2'" == pValue->asString());
}

TEST(TestConverter, EnumConverter)
{
    gfc2::schema::CEnumConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    oConverter.init(nullptr, &oEnum);
    std::wstring sValue = L".ghi.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L".ghi." == pValue->asString());
}

TEST(TestConverter, EnumConverter_Empty)
{
    gfc2::schema::CEnumConverter oConverter;
    gfc2::schema::CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    oConverter.init(nullptr, &oEnum);
    std::wstring sValue = L".kkk.";
    CAttributeValuePtr pValue(new CLeafAttributeValue(sValue));
    oConverter.transform(pValue);
    EXPECT_EQ(true, L"$" == pValue->asString());
}