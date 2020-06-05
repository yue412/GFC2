#include "gtest\gtest.h"
#include "Converter.h"
#include "GfcSchema/EnumType.h"
#include "GfcEngine\PropValue.h"
#include "GfcSchema\BuildinType.h"

using namespace gfc::schema;
using namespace gfc::engine;

TEST(TestConverter, ArrayToArrayConverter_Empty)
{
    CArrayToArrayConverter oConverter;
    CompositePropValue oFrom;
    CompositePropValue oTo;
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
}

TEST(TestConverter, ArrayToArrayConverter)
{
    CArrayToArrayConverter oConverter;
    CIntConverter oIntConverter;
    oConverter.setNext(oIntConverter.clone());
    CIntegerType oInteger;
    oConverter.init(&oInteger, &oInteger);
    CompositePropValue oFrom;
    CompositePropValue oTo;
    oFrom.add(new IntegerValue(1));
    oFrom.add(new IntegerValue(2));
    oFrom.add(new IntegerValue(3));
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(3, oTo.getCount());
    EXPECT_EQ(1, oTo.getItems(0)->asInteger());
    EXPECT_EQ(2, oTo.getItems(1)->asInteger());
    EXPECT_EQ(3, oTo.getItems(2)->asInteger());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, ArrayToOneConverter_Empty)
{
    CArrayToOneConverter oConverter;
    CompositePropValue oFrom;
    IntegerValue oTo;
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
}

TEST(TestConverter, ArrayToOneConverter)
{
    CArrayToOneConverter oConverter;
    CIntConverter oIntConverter;
    oConverter.setNext(oIntConverter.clone());
    CIntegerType oInteger;
    oConverter.init(&oInteger, &oInteger);
    CompositePropValue oFrom;
    IntegerValue oTo;
    oFrom.add(new IntegerValue(111));
    oFrom.add(new IntegerValue(2));
    oFrom.add(new IntegerValue(3));
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(111, oTo.asInteger());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, OneToArrayConverter_Empty)
{
    COneToArrayConverter oConverter;
    IntegerValue oFrom;
    CompositePropValue oTo;
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
}

TEST(TestConverter, OneToArrayConverter)
{
    COneToArrayConverter oConverter;
    CIntConverter oIntConverter;
    oConverter.setNext(oIntConverter.clone());
    CIntegerType oInteger;
    oConverter.init(&oInteger, &oInteger);

    IntegerValue oFrom;
    CompositePropValue oTo;
    oFrom.setAsInteger(1234);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(1, oTo.getCount());
    EXPECT_EQ(1234, oTo.getItems(0)->asInteger());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, OptionalConverter_Empty)
{
    COptionalConverter oConverter;
    IntegerValue oFrom;
    IntegerValue oTo;
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
}

TEST(TestConverter, OptionalConverter)
{
    COptionalConverter oConverter;
    CIntConverter oIntConverter;
    oConverter.setNext(oIntConverter.clone());
    CIntegerType oInteger;
    oConverter.init(&oInteger, &oInteger);

    IntegerValue oFrom;
    IntegerValue oTo;
    oFrom.setAsInteger(1234);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(1234, oTo.asInteger());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, EmptyConverter)
{
    CEmptyConverter oConverter;
    IntegerValue oFrom;
    StringValue oTo;
    oFrom.setAsInteger(1234);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
}

TEST(TestConverter, IntConverter_Bool_Bool)
{
    CIntConverter oConverter;
    BooleanValue oFrom;
    BooleanValue oTo;
    oFrom.setAsBoolean(true);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.asBoolean());
    EXPECT_EQ(false, oTo.isNull());
    oFrom.setAsBoolean(false);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(false, oTo.asBoolean());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, IntConverter_Bool_Int)
{
    CIntConverter oConverter;
    BooleanValue oFrom;
    IntegerValue oTo;
    oFrom.setAsBoolean(true);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(1, oTo.asInteger());
    EXPECT_EQ(false, oTo.isNull());
    oFrom.setAsBoolean(false);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(0, oTo.asInteger());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, IntConverter_Bool_Double)
{
    CIntConverter oConverter;
    BooleanValue oFrom;
    DoubleValue oTo;
    oFrom.setAsBoolean(true);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_NEAR(1, oTo.asDouble(), 1e-7);
    EXPECT_EQ(false, oTo.isNull());
    oFrom.setAsBoolean(false);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_NEAR(0, oTo.asDouble(), 1e-7);
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, IntConverter_Int_Bool)
{
    CIntConverter oConverter;
    IntegerValue oFrom;
    BooleanValue oTo;
    oFrom.setAsInteger(-19);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.asBoolean());
    EXPECT_EQ(false, oTo.isNull());
    oFrom.setAsInteger(0);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(false, oTo.asBoolean());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, IntConverter_Int_Int)
{
    CIntConverter oConverter;
    IntegerValue oFrom;
    IntegerValue oTo;
    oFrom.setAsInteger(-19);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(-19, oTo.asInteger());
    EXPECT_EQ(false, oTo.isNull());
    oFrom.setAsInteger(0);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(0, oTo.asInteger());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, IntConverter_Int_Double)
{
    CIntConverter oConverter;
    IntegerValue oFrom;
    DoubleValue oTo;
    oFrom.setAsInteger(-19);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_NEAR(-19, oTo.asDouble(), 1e-7);
    EXPECT_EQ(false, oTo.isNull());
    oFrom.setAsInteger(0);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_NEAR(0, oTo.asDouble(), 1e-7);
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, BoolToStringConverter)
{
    CBoolToStringConverter oConverter;
    BooleanValue oFrom;
    StringValue oTo;
    oFrom.setAsBoolean(true);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, "1" == oTo.asString());
    EXPECT_EQ(false, oTo.isNull());
    oFrom.setAsBoolean(false);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, "0" == oTo.asString());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, IntToEnumConverter_bool)
{
    CIntToEnumConverter oConverter;
    CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    oConverter.init(nullptr, &oEnum);
    BooleanValue oFrom;
    IntegerValue oTo;
    oFrom.setAsBoolean(true);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(1, oTo.asInteger());
    EXPECT_EQ(false, oTo.isNull());
    oFrom.setAsBoolean(false);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(0, oTo.asInteger());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, IntToEnumConverter_bool_empty)
{
    CIntToEnumConverter oConverter;
    CEnumType oEnum;
    oConverter.init(nullptr, &oEnum);
    BooleanValue oFrom;
    IntegerValue oTo;
    oFrom.setAsBoolean(true);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
    oFrom.setAsBoolean(false);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
}

TEST(TestConverter, IntToEnumConverter_int)
{
    CIntToEnumConverter oConverter;
    CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    oConverter.init(nullptr, &oEnum);
    IntegerValue oFrom;
    IntegerValue oTo;
    oFrom.setAsInteger(2);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(2, oTo.asInteger());
    EXPECT_EQ(false, oTo.isNull());
    oFrom.setAsInteger(0);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(0, oTo.asInteger());
    EXPECT_EQ(false, oTo.isNull());
    oFrom.setAsInteger(43);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(1, oTo.asInteger());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, IntToEnumConverter_int_empty)
{
    CIntToEnumConverter oConverter;
    CEnumType oEnum;
    oConverter.init(nullptr, &oEnum);
    IntegerValue oFrom;
    IntegerValue oTo;
    oFrom.setAsInteger(2);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
    oFrom.setAsInteger(0);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
}

TEST(TestConverter, IntToStringConverter)
{
    CIntToStringConverter oConverter;
    IntegerValue oFrom;
    StringValue oTo;
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
    oFrom.setAsInteger(1234);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, "1234" == oTo.asString());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, FloatToStringConverter)
{
    CFloatToStringConverter oConverter;
    DoubleValue oFrom;
    StringValue oTo;
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
    oFrom.setAsDouble(1234.5);
    oConverter.transform(&oFrom, &oTo);
    auto d = std::stod(oTo.asString());
    EXPECT_NEAR(1234.5, d, 1e-7);
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, FloatConverter)
{
    CFloatConverter oConverter;
    DoubleValue oFrom;
    DoubleValue oTo;
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
    oFrom.setAsDouble(1234.5);
    oConverter.transform(&oFrom, &oTo);
    auto d = oTo.asDouble();
    EXPECT_NEAR(1234.5, d, 1e-7);
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, StringConverter)
{
    CStringConverter oConverter;
    StringValue oFrom;
    StringValue oTo;
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
    oFrom.setAsString("中国");
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, "中国" == oTo.asString());
    EXPECT_EQ(false, oTo.isNull());
}

TEST(TestConverter, EnumConverter)
{
    CEnumConverter oConverter;
    CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    CEnumType oFromEnum;
    oFromEnum.addEnum(L"abc", L"");
    oFromEnum.addEnum(L"de", L"");
    oFromEnum.addEnum(L"gh", L"");
    oConverter.init(&oFromEnum, &oEnum);
    IntegerValue oFrom;
    IntegerValue oTo;
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());

    oFrom.setAsInteger(1);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());

    oFrom.setAsInteger(0);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(false, oTo.isNull());
    EXPECT_EQ(0, oTo.asInteger());
}

TEST(TestConverter, EnumConverter_2)
{
    CEnumConverter oConverter;
    CEnumType oEnum;
    oEnum.addEnum(L"abc", L"");
    oEnum.addEnum(L"def", L"");
    oEnum.addEnum(L"ghi", L"");
    CEnumType oFromEnum;
    oFromEnum.addEnum(L"def", L"");
    oFromEnum.addEnum(L"ghi", L"");
    oFromEnum.addEnum(L"abc", L"");
    oConverter.init(&oFromEnum, &oEnum);
    IntegerValue oFrom;
    IntegerValue oTo;
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());

    oFrom.setAsInteger(1);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(2, oTo.asInteger());
    EXPECT_EQ(false, oTo.isNull());

    oFrom.setAsInteger(2);
    oConverter.transform(&oFrom, &oTo);
    EXPECT_EQ(false, oTo.isNull());
    EXPECT_EQ(0, oTo.asInteger());
}

TEST(TestConverter, CEntityRefConverter)
{
    CEntityRefConverter converter;
    EntityRefValue oFrom;
    EntityRefValue oTo;
    converter.transform(&oFrom, &oTo);
    EXPECT_EQ(true, oTo.isNull());
    oFrom.setAsEntityRef(123);
    converter.transform(&oFrom, &oTo);
    EXPECT_EQ(123, oTo.asEntityRef());
    EXPECT_EQ(false, oTo.isNull());
}