#include "gtest\gtest.h"
#include "AttributeCompatibility.h"
#include "GfcSchema/EntityAttribute.h"
#include "GfcSchema/BuildinType.h"
#include "GfcSchema/EnumType.h"
#include "GfcSchema/EntityClass.h"
#include "Converter.h"
#include "GfcEngine\PropValue.h"
#include "ClassCompatibility.h"

using namespace gfc::engine;

TEST(TestClassCompatibility, Empty)
{
    gfc::schema::CClass oFromClass, oToClass;
    oFromClass.SetName(L"CTest");
    CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);
    EXPECT_EQ(true, L"CTest" == oCompatibility.getName());
    EXPECT_EQ(0, oCompatibility.getCount());
}

TEST(TestClassCompatibility, Class1)
{
    gfc::schema::CClass oFromClass, oToClass;
    gfc::schema::CAttribute* pFromAttrib1 = new gfc::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromClass.addAttribute(pFromAttrib1);

    gfc::schema::CAttribute* pFromAttrib2 = new gfc::schema::CAttribute();
    pFromAttrib2->SetName(L"Name");
    gfc::schema::CStringType oType2;
    pFromAttrib2->SetType(&oType2);
    oFromClass.addAttribute(pFromAttrib2);


    gfc::schema::CAttribute* pToAttrib1 = new gfc::schema::CAttribute();
    pToAttrib1->SetName(L"ID");
    //gfc::schema::CIntegerType oType;
    pToAttrib1->SetType(&oType);
    oToClass.addAttribute(pToAttrib1);

    gfc::schema::CAttribute* pToAttrib2 = new gfc::schema::CAttribute();
    pToAttrib2->SetName(L"Name2");
    //gfc::schema::CBuildinType oType(L"STRING");
    pToAttrib2->SetType(&oType2);
    oToClass.addAttribute(pToAttrib2);

    CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);
    EXPECT_EQ(3, oCompatibility.getCount());
    EXPECT_EQ(0, oCompatibility.getCompatibilityAttribute(0)->toIndex());
    EXPECT_EQ(-1, oCompatibility.getCompatibilityAttribute(1)->toIndex());
    EXPECT_EQ(1, oCompatibility.getCompatibilityAttribute(2)->toIndex());
}

TEST(TestClassCompatibility, Class2)
{
    gfc::schema::CClass oFromClass, oToClass;
    gfc::schema::CClass oFromParentClass, oToParentClass;
    oFromClass.setParent(&oFromParentClass);
    gfc::schema::CAttribute* pFromAttrib1 = new gfc::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromParentClass.addAttribute(pFromAttrib1);

    gfc::schema::CAttribute* pFromAttrib2 = new gfc::schema::CAttribute();
    pFromAttrib2->SetName(L"Name");
    gfc::schema::CStringType oType2;
    pFromAttrib2->SetType(&oType2);
    oFromClass.addAttribute(pFromAttrib2);

    oToClass.setParent(&oToParentClass);
    gfc::schema::CAttribute* pToAttrib1 = new gfc::schema::CAttribute();
    pToAttrib1->SetName(L"ID");
    //gfc::schema::CIntegerType oType;
    pToAttrib1->SetType(&oType);
    oToParentClass.addAttribute(pToAttrib1);

    gfc::schema::CAttribute* pToAttrib2 = new gfc::schema::CAttribute();
    pToAttrib2->SetName(L"Name2");
    //gfc::schema::CBuildinType oType(L"STRING");
    pToAttrib2->SetType(&oType2);
    oToClass.addAttribute(pToAttrib2);

    CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);
    EXPECT_EQ(3, oCompatibility.getCount());
    EXPECT_EQ(0, oCompatibility.getCompatibilityAttribute(0)->toIndex());
    EXPECT_EQ(-1, oCompatibility.getCompatibilityAttribute(1)->toIndex());
    EXPECT_EQ(1, oCompatibility.getCompatibilityAttribute(2)->toIndex());
}