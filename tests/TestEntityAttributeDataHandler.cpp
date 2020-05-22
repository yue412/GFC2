#include "gtest\gtest.h"
#include "glodon\express\EntityFactory.h"
#include "glodon\express\Entity.h"
#include "Common.h"
#include "EntityClass.h"
#include "EntityAttribute.h"
#include "BuildinType.h"
#include "EntityAttributeDataHandler.h"

TEST(TestEntityAttibuteDataHandler, BooleanAttributeDataHandler_setIsNull)
{
    glodon::express::EntityAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[5];
    oHandler.setIsNull(pData, true);
    EXPECT_EQ(0, pData[0]);
    oHandler.setIsNull(pData, false);
    EXPECT_EQ(1, pData[0]);
}

TEST(TestEntityAttibuteDataHandler, BooleanAttributeDataHandler_isNull)
{
    glodon::express::EntityAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[5];
    oHandler.setIsNull(pData, true);
    EXPECT_EQ(true, oHandler.isNull(pData));
    oHandler.setIsNull(pData, false);
    EXPECT_EQ(false, oHandler.isNull(pData));
}

TEST(TestEntityAttibuteDataHandler, BooleanAttributeDataHandler_setAsInteger)
{
    glodon::express::BooleanAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[5];
    oHandler.setAsInteger(pData, 123);
    EXPECT_EQ(1, pData[1]);
    oHandler.setAsInteger(pData, 0);
    EXPECT_EQ(0, pData[1]);
}

TEST(TestEntityAttibuteDataHandler, BooleanAttributeDataHandler_setAsBoolean)
{
    glodon::express::BooleanAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[5];
    oHandler.setAsBoolean(pData, true);
    EXPECT_EQ(1, pData[1]);
    oHandler.setAsBoolean(pData, false);
    EXPECT_EQ(0, pData[1]);
}

TEST(TestEntityAttibuteDataHandler, BooleanAttributeDataHandler_asBoolean)
{
    glodon::express::BooleanAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);

    char pData[5];
    oHandler.setAsBoolean(pData, true);
    EXPECT_EQ(true, oHandler.asBoolean(pData));
    oHandler.setAsBoolean(pData, false);
    EXPECT_EQ(false, oHandler.asBoolean(pData));
}

TEST(TestEntityAttibuteDataHandler, BooleanAttributeDataHandler_asInteger)
{
    glodon::express::BooleanAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[5];
    oHandler.setAsBoolean(pData, true);
    EXPECT_EQ(1, oHandler.asInteger(pData));
    oHandler.setAsBoolean(pData, false);
    EXPECT_EQ(0, oHandler.asInteger(pData));
}

TEST(TestEntityAttibuteDataHandler, BooleanAttributeDataHandler_asDouble)
{
    glodon::express::BooleanAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[5];
    oHandler.setAsBoolean(pData, true);
    EXPECT_NEAR(1.0, oHandler.asDouble(pData), 1e-7);
    oHandler.setAsBoolean(pData, false);
    EXPECT_NEAR(0.0, oHandler.asDouble(pData), 1e-7);
}

TEST(TestEntityAttibuteDataHandler, BooleanListAttributeDataHandler_asBooleanList)
{
    glodon::express::BooleanListAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);

    char pData[100];
    oHandler.init(pData);
    auto oList = oHandler.asBooleanList(pData);
    EXPECT_EQ(0, oList.size());
    oHandler.free(pData);
}

TEST(TestEntityAttibuteDataHandler, IntegerAttributeDataHandler_setAsInteger)
{
    glodon::express::IntegerAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.setAsInteger(pData, 1456328);
    EXPECT_EQ(1456328, *(int*)&pData[1]);
}

TEST(TestEntityAttibuteDataHandler, IntegerAttributeDataHandler_setAsBoolean)
{
    glodon::express::IntegerAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.setAsBoolean(pData, true);
    EXPECT_EQ(1, *(int*)&pData[1]);
}

TEST(TestEntityAttibuteDataHandler, IntegerAttributeDataHandler_asInteger)
{
    glodon::express::IntegerAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.setAsInteger(pData, 123234);
    EXPECT_EQ(123234, oHandler.asInteger(pData));
}

TEST(TestEntityAttibuteDataHandler, IntegerAttributeDataHandler_asBoolean)
{
    glodon::express::IntegerAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.setAsInteger(pData, 123234);
    EXPECT_EQ(true, oHandler.asBoolean(pData));
}

TEST(TestEntityAttibuteDataHandler, IntegerAttributeDataHandler_asDouble)
{
    glodon::express::IntegerAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.setAsInteger(pData, 123234);
    EXPECT_NEAR(123234.0, oHandler.asDouble(pData), 1e-7);
}


TEST(TestEntityAttibuteDataHandler, IntegerListAttributeDataHandler_asBooleanList)
{
    glodon::express::IntegerListAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);

    char pData[100];
    oHandler.init(pData);
    auto oList = oHandler.asIntegerList(pData);
    EXPECT_EQ(0, oList.size());
    oHandler.free(pData);
}

TEST(TestEntityAttibuteDataHandler, DoubleAttributeDataHandler_setAsDouble)
{
    glodon::express::DoubleAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.setAsDouble(pData, -24.5);
    EXPECT_NEAR(-24.5, *(double*)&pData[1], 1e-7);
}

TEST(TestEntityAttibuteDataHandler, DoubleAttributeDataHandler_setAsInteger)
{
    glodon::express::DoubleAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.setAsInteger(pData, 5678912);
    EXPECT_NEAR(5678912.0, *(double*)&pData[1], 1e-7);
}

TEST(TestEntityAttibuteDataHandler, DoubleAttributeDataHandler_setAsBoolean)
{
    glodon::express::DoubleAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.setAsBoolean(pData, true);
    EXPECT_NEAR(1.0, *(double*)&pData[1], 1e-7);
}

TEST(TestEntityAttibuteDataHandler, DoubleAttributeDataHandler_asDouble)
{
    glodon::express::DoubleAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.setAsDouble(pData, 345.567);
    EXPECT_NEAR(345.567, oHandler.asDouble(pData), 1e-7);
}

TEST(TestEntityAttibuteDataHandler, DoubleListAttributeDataHandler_asDoubleList)
{
    glodon::express::DoubleListAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);

    char pData[100];
    oHandler.init(pData);
    auto oList = oHandler.asDoubleList(pData);
    EXPECT_EQ(0, oList.size());
    oHandler.free(pData);
}

TEST(TestEntityAttibuteDataHandler, StringAttributeDataHandler_setAsString)
{
    glodon::express::StringAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.init(pData);
    oHandler.setAsString(pData, "abc中文");
    EXPECT_STREQ("abc中文", (*(std::string*)&pData[1]).c_str());
    oHandler.free(pData);
}

TEST(TestEntityAttibuteDataHandler, StringAttributeDataHandler_setAsInteger)
{
    glodon::express::StringAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.init(pData);
    oHandler.setAsInteger(pData, 23523456);
    EXPECT_STREQ("23523456", (*(std::string*)&pData[1]).c_str());
    oHandler.free(pData);
}

TEST(TestEntityAttibuteDataHandler, StringAttributeDataHandler_setAsDouble)
{
    glodon::express::StringAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.init(pData);
    oHandler.setAsDouble(pData, 23523.456);
    auto d = std::stod(*(std::string*)&pData[1]);
    EXPECT_NEAR(23523.456, d, 1e-7);
    oHandler.free(pData);
}

TEST(TestEntityAttibuteDataHandler, StringAttributeDataHandler_setAsBoolean)
{
    glodon::express::StringAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.init(pData);
    oHandler.setAsBoolean(pData, true);
    EXPECT_STREQ("1", (*(std::string*)&pData[1]).c_str());
    oHandler.free(pData);
}

TEST(TestEntityAttibuteDataHandler, StringAttributeDataHandler_asString)
{
    glodon::express::StringAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.init(pData);
    oHandler.setAsString(pData, "abc中文");
    EXPECT_STREQ("abc中文", oHandler.asString(pData).c_str());
    oHandler.free(pData);
}

TEST(TestEntityAttibuteDataHandler, StringListAttributeDataHandler_asStringList)
{
    glodon::express::StringListAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);

    char pData[100];
    oHandler.init(pData);
    auto oList = oHandler.asStringList(pData);
    EXPECT_EQ(0, oList.size());
    oHandler.free(pData);
}

TEST(TestEntityAttibuteDataHandler, EntityRefAttributeDataHandler_setAsEntityRef)
{
    glodon::express::EntityRefAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.setAsEntityRef(pData, 11234567);
    EXPECT_EQ(11234567, (*(glodon::express::EntityRef*)&pData[1]));
}

TEST(TestEntityAttibuteDataHandler, EntityRefAttributeDataHandler_asEntityRef)
{
    glodon::express::EntityRefAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);
    char pData[100];
    oHandler.setAsEntityRef(pData, 11234567);
    EXPECT_EQ(11234567, oHandler.asEntityRef(pData));
}

TEST(TestEntityAttibuteDataHandler, EntityRefListAttributeDataHandler_asEntityRefList)
{
    glodon::express::EntityRefListAttributeDataHandler oHandler(nullptr);
    oHandler.setOffset(0);

    char pData[100];
    oHandler.init(pData);
    auto oList = oHandler.asEntityRefList(pData);
    EXPECT_EQ(0, oList.size());
    oHandler.free(pData);
}
