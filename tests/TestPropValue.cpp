#include "gtest\gtest.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\EngineException.h"
#include "GfcEngine\PropValue.h"
#include "Common.h"

TEST(TestPropValue, CLeafPropValue_create)
{
    gfc::engine::CLeafPropValue* pValue = new gfc::engine::CLeafPropValue;
    EXPECT_EQ(true, pValue != nullptr);
    delete pValue;
}

TEST(TestPropValue, CLeafPropValue_isNull_default)
{
    gfc::engine::CLeafPropValue oValue;
    EXPECT_EQ(true, oValue.isNull());
}

TEST(TestPropValue, CCompositePropValue_isNull)
{
    gfc::engine::CCompositePropValue oValue;
    EXPECT_EQ(true, oValue.isNull());

    oValue.add(new gfc::engine::CIntegerValue);
    EXPECT_EQ(false, oValue.isNull());
}

TEST(TestPropValue, CCompositePropValue_add)
{
    gfc::engine::CCompositePropValue oValue;
    EXPECT_EQ(true, oValue.isNull());
    EXPECT_EQ(0, oValue.getCount());

    oValue.add(new gfc::engine::CIntegerValue);
    EXPECT_EQ(1, oValue.getCount());
}

TEST(TestPropValue, CCompositePropValue_getItems)
{
    gfc::engine::CCompositePropValue oValue;
    oValue.add(new gfc::engine::CIntegerValue(13));
    EXPECT_EQ(1, oValue.getCount());
    EXPECT_EQ(13, oValue.getItems(0)->asInteger());

    EXPECT_EQ(true, oValue.getItems(3) == nullptr);
}

TEST(TestPropValue, CCompositePropValue_setItems)
{
    gfc::engine::CCompositePropValue oValue;
    oValue.add(new gfc::engine::CIntegerValue(13));
    oValue.setItems(0, new gfc::engine::CIntegerValue(55));
    EXPECT_EQ(1, oValue.getCount());
    EXPECT_EQ(55, oValue.getItems(0)->asInteger());

    auto p = new gfc::engine::CIntegerValue(50);
    oValue.setItems(11, p);
    EXPECT_EQ(1, oValue.getCount());
    EXPECT_EQ(55, oValue.getItems(0)->asInteger());
    delete p;
}

TEST(TestPropValue, CCompositePropValue_clear)
{
    gfc::engine::CCompositePropValue oValue;
    oValue.add(new gfc::engine::CIntegerValue(13));
    EXPECT_EQ(1, oValue.getCount());

    oValue.clear();
    EXPECT_EQ(0, oValue.getCount());
}


TEST(TestPropValue, CBooleanValue_create)
{
    {
        gfc::engine::CBooleanValue oValue;
        EXPECT_EQ(false, oValue.asBoolean());
        EXPECT_EQ(true, oValue.isNull());
    }

    {
        gfc::engine::CBooleanValue oValue(true);
        EXPECT_EQ(true, oValue.asBoolean());
        EXPECT_EQ(false, oValue.isNull());
    }
}

TEST(TestPropValue, CBooleanValue_setAsBoolean)
{
    gfc::engine::CBooleanValue oValue;
    EXPECT_EQ(false, oValue.asBoolean());
    oValue.setAsBoolean(true);
    EXPECT_EQ(true, oValue.asBoolean());
    EXPECT_EQ(false, oValue.isNull());
}

TEST(TestPropValue, CBooleanValue_setAsInteger)
{
    gfc::engine::CBooleanValue oValue;
    EXPECT_EQ(false, oValue.asBoolean());
    oValue.setAsInteger(12);
    EXPECT_EQ(true, oValue.asBoolean());
    EXPECT_EQ(false, oValue.isNull());
    oValue.setAsInteger(0);
    EXPECT_EQ(false, oValue.asBoolean());
}

TEST(TestPropValue, CBooleanValue_setAsDouble)
{
    gfc::engine::CBooleanValue oValue;
    EXPECT_THROW(oValue.setAsDouble(12), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CBooleanValue_setAsString)
{
    gfc::engine::CBooleanValue oValue;
    EXPECT_THROW(oValue.setAsString(L"12"), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CBooleanValue_setAsEntityRef)
{
    gfc::engine::CBooleanValue oValue;
    EXPECT_THROW(oValue.setAsEntityRef(12), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CBooleanValue_asInteger)
{
    gfc::engine::CBooleanValue oValue;
    EXPECT_EQ(0, oValue.asInteger());
    oValue.setAsBoolean(true);
    EXPECT_EQ(1, oValue.asInteger());
}

TEST(TestPropValue, CBooleanValue_asInteger2)
{
    gfc::engine::CBooleanValue oValue;
    EXPECT_EQ(0, oValue.asInteger());
    oValue.setAsInteger(122);
    EXPECT_EQ(1, oValue.asInteger());
}

TEST(TestPropValue, CBooleanValue_asDouble)
{
    gfc::engine::CBooleanValue oValue;
    EXPECT_NEAR(0, oValue.asDouble(), 1e-7);
    oValue.setAsBoolean(true);
    EXPECT_NEAR(1, oValue.asDouble(), 1e-7);
}

TEST(TestPropValue, CBooleanValue_asDouble2)
{
    gfc::engine::CBooleanValue oValue;
    EXPECT_NEAR(0, oValue.asDouble(), 1e-7);
    oValue.setAsInteger(-1);
    EXPECT_NEAR(1, oValue.asDouble(), 1e-7);
}

TEST(TestPropValue, CBooleanValue_asString)
{
    gfc::engine::CBooleanValue oValue;
    EXPECT_THROW(oValue.asString(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CBooleanValue_asEntityRef)
{
    gfc::engine::CBooleanValue oValue;
    EXPECT_THROW(oValue.asEntityRef(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CIntegerValue_create)
{
    {
        gfc::engine::CIntegerValue oValue;
        EXPECT_EQ(0, oValue.asInteger());
        EXPECT_EQ(true, oValue.isNull());
    }

    {
        gfc::engine::CIntegerValue oValue(-12);
        EXPECT_EQ(-12, oValue.asInteger());
        EXPECT_EQ(false, oValue.isNull());
    }
}

TEST(TestPropValue, CIntegerValue_setAsInteger)
{
    gfc::engine::CIntegerValue oValue;
    EXPECT_EQ(0, oValue.asInteger());
    oValue.setAsInteger(101);
    EXPECT_EQ(101, oValue.asInteger());
    EXPECT_EQ(false, oValue.isNull());
}

TEST(TestPropValue, CIntegerValue_setAsBoolean)
{
    gfc::engine::CIntegerValue oValue;
    EXPECT_EQ(0, oValue.asInteger());
    oValue.setAsBoolean(true);
    EXPECT_EQ(1, oValue.asInteger());
    EXPECT_EQ(false, oValue.isNull());
    oValue.setAsBoolean(false);
    EXPECT_EQ(0, oValue.asInteger());
    EXPECT_EQ(false, oValue.isNull());
}

TEST(TestPropValue, CIntegerValue_setAsDouble)
{
    gfc::engine::CIntegerValue oValue;
    EXPECT_THROW(oValue.setAsDouble(12), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CIntegerValue_setAsString)
{
    gfc::engine::CIntegerValue oValue;
    EXPECT_THROW(oValue.setAsString(L"12"), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CIntegerValue_setAsEntityRef)
{
    gfc::engine::CIntegerValue oValue;
    EXPECT_THROW(oValue.setAsEntityRef(12), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CIntegerValue_asBoolean)
{
    gfc::engine::CIntegerValue oValue;
    EXPECT_EQ(false, oValue.asBoolean());
    oValue.setAsBoolean(true);
    EXPECT_EQ(true, oValue.asBoolean());
    oValue.setAsBoolean(false);
    EXPECT_EQ(false, oValue.asBoolean());
}

TEST(TestPropValue, CIntegerValue_asBoolean2)
{
    gfc::engine::CIntegerValue oValue;
    EXPECT_EQ(false, oValue.asBoolean());
    oValue.setAsInteger(123);
    EXPECT_EQ(true, oValue.asBoolean());
    oValue.setAsInteger(0);
    EXPECT_EQ(false, oValue.asBoolean());
}

TEST(TestPropValue, CIntegerValue_asDouble)
{
    gfc::engine::CIntegerValue oValue;
    EXPECT_NEAR(0.0, oValue.asDouble(), 1e-7);
    oValue.setAsBoolean(true);
    EXPECT_NEAR(1.0, oValue.asDouble(), 1e-7);
    oValue.setAsBoolean(false);
    EXPECT_NEAR(0.0, oValue.asDouble(), 1e-7);
}

TEST(TestPropValue, CIntegerValue_asDouble2)
{
    gfc::engine::CIntegerValue oValue;
    EXPECT_NEAR(0.0, oValue.asDouble(), 1e-7);
    oValue.setAsInteger(123);
    EXPECT_NEAR(123.0, oValue.asDouble(), 1e-7);
    oValue.setAsInteger(0);
    EXPECT_NEAR(0.0, oValue.asDouble(), 1e-7);
}

TEST(TestPropValue, CIntegerValue_asString)
{
    gfc::engine::CIntegerValue oValue;
    EXPECT_THROW(oValue.asString(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CIntegerValue_asEntityRef)
{
    gfc::engine::CIntegerValue oValue;
    EXPECT_THROW(oValue.asEntityRef(), gfc::engine::ETypeMatchError);
}


TEST(TestPropValue, CDoubleValue_create)
{
    {
        gfc::engine::CDoubleValue oValue;
        EXPECT_NEAR(0, oValue.asDouble(), 1e-7);
        EXPECT_EQ(true, oValue.isNull());
    }

    {
        gfc::engine::CDoubleValue oValue(-12.3);
        EXPECT_NEAR(-12.3, oValue.asDouble(), 1e-7);
        EXPECT_EQ(false, oValue.isNull());
    }
}

TEST(TestPropValue, CDoubleValue_setAsDouble)
{
    gfc::engine::CDoubleValue oValue;
    EXPECT_NEAR(0, oValue.asDouble(), 1e-7);
    oValue.setAsDouble(101.23);
    EXPECT_NEAR(101.23, oValue.asDouble(), 1e-7);
    EXPECT_EQ(false, oValue.isNull());
}

TEST(TestPropValue, CDoubleValue_setAsInteger)
{
    gfc::engine::CDoubleValue oValue;
    EXPECT_NEAR(0, oValue.asDouble(), 1e-7);
    oValue.setAsInteger(101);
    EXPECT_NEAR(101, oValue.asDouble(), 1e-7);
    EXPECT_EQ(false, oValue.isNull());
}

TEST(TestPropValue, CDoubleValue_setAsBoolean)
{
    gfc::engine::CDoubleValue oValue;
    EXPECT_NEAR(0, oValue.asDouble(), 1e-7);
    oValue.setAsBoolean(true);
    EXPECT_NEAR(1, oValue.asDouble(), 1e-7);
    EXPECT_EQ(false, oValue.isNull());
    oValue.setAsBoolean(false);
    EXPECT_NEAR(0.0, oValue.asDouble(), 1e-7);
    EXPECT_EQ(false, oValue.isNull());
}

TEST(TestPropValue, CDoubleValue_setAsString)
{
    gfc::engine::CDoubleValue oValue;
    EXPECT_THROW(oValue.setAsString(L"12"), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CDoubleValue_setAsEntityRef)
{
    gfc::engine::CDoubleValue oValue;
    EXPECT_THROW(oValue.setAsEntityRef(12), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CDoubleValue_asBoolean)
{
    gfc::engine::CDoubleValue oValue;
    EXPECT_THROW(oValue.asBoolean(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CDoubleValue_asInteger)
{
    gfc::engine::CDoubleValue oValue;
    EXPECT_THROW(oValue.asInteger(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CDoubleValue_asString)
{
    gfc::engine::CDoubleValue oValue;
    EXPECT_THROW(oValue.asString(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CDoubleValue_asEntityRef)
{
    gfc::engine::CDoubleValue oValue;
    EXPECT_THROW(oValue.asEntityRef(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CStringValue_create)
{
    {
        gfc::engine::CStringValue oValue;
        EXPECT_STREQ(L"", oValue.asString().c_str());
        EXPECT_EQ(true, oValue.isNull());
    }

    {
        gfc::engine::CStringValue oValue(L"-12.3");
        EXPECT_STREQ(L"-12.3", oValue.asString().c_str());
        EXPECT_EQ(false, oValue.isNull());
    }
}

TEST(TestPropValue, CStringValue_setAsString)
{
    gfc::engine::CStringValue oValue;
    EXPECT_STREQ(L"", oValue.asString().c_str());
    oValue.setAsString(L"101.23");
    EXPECT_STREQ(L"101.23", oValue.asString().c_str());
    EXPECT_EQ(false, oValue.isNull());
}

TEST(TestPropValue, CStringValue_setAsInteger)
{
    gfc::engine::CStringValue oValue;
    EXPECT_THROW(oValue.setAsInteger(12), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CStringValue_setAsBoolean)
{
    gfc::engine::CStringValue oValue;
    EXPECT_THROW(oValue.setAsBoolean(true), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CStringValue_setAsDouble)
{
    gfc::engine::CStringValue oValue;
    EXPECT_THROW(oValue.setAsDouble(12.5), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CStringValue_setAsEntityRef)
{
    gfc::engine::CStringValue oValue;
    EXPECT_THROW(oValue.setAsEntityRef(12), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CStringValue_asBoolean)
{
    gfc::engine::CStringValue oValue;
    EXPECT_THROW(oValue.asBoolean(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CStringValue_asInteger)
{
    gfc::engine::CStringValue oValue;
    EXPECT_THROW(oValue.asInteger(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CStringValue_asDouble)
{
    gfc::engine::CStringValue oValue;
    EXPECT_THROW(oValue.asDouble(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CStringValue_asEntityRef)
{
    gfc::engine::CStringValue oValue;
    EXPECT_THROW(oValue.asEntityRef(), gfc::engine::ETypeMatchError);
}

//

TEST(TestPropValue, CEntityRefValue_create)
{
    {
        gfc::engine::CEntityRefValue oValue;
        EXPECT_EQ(-1, oValue.asEntityRef());
        EXPECT_EQ(true, oValue.isNull());
    }

    {
        gfc::engine::CEntityRefValue oValue(108);
        EXPECT_EQ(108, oValue.asEntityRef());
        EXPECT_EQ(false, oValue.isNull());
    }
}

TEST(TestPropValue, CEntityRefValue_setAsString)
{
    gfc::engine::CEntityRefValue oValue;
    EXPECT_THROW(oValue.setAsString(L"12"), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CEntityRefValue_setAsInteger)
{
    gfc::engine::CEntityRefValue oValue;
    EXPECT_THROW(oValue.setAsInteger(12), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CEntityRefValue_setAsBoolean)
{
    gfc::engine::CEntityRefValue oValue;
    EXPECT_THROW(oValue.setAsBoolean(true), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CEntityRefValue_setAsDouble)
{
    gfc::engine::CEntityRefValue oValue;
    EXPECT_THROW(oValue.setAsDouble(12.5), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CEntityRefValue_setAsEntityRef)
{
    gfc::engine::CEntityRefValue oValue;
    EXPECT_EQ(-1, oValue.asEntityRef());
    oValue.setAsEntityRef(1013);
    EXPECT_EQ(1013, oValue.asEntityRef());
    EXPECT_EQ(false, oValue.isNull());
}

TEST(TestPropValue, CEntityRefValue_asBoolean)
{
    gfc::engine::CEntityRefValue oValue;
    EXPECT_THROW(oValue.asBoolean(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CEntityRefValue_asInteger)
{
    gfc::engine::CEntityRefValue oValue;
    EXPECT_THROW(oValue.asInteger(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CEntityRefValue_asDouble)
{
    gfc::engine::CEntityRefValue oValue;
    EXPECT_THROW(oValue.asDouble(), gfc::engine::ETypeMatchError);
}

TEST(TestPropValue, CEntityRefValue_asString)
{
    gfc::engine::CEntityRefValue oValue;
    EXPECT_THROW(oValue.asString(), gfc::engine::ETypeMatchError);
}