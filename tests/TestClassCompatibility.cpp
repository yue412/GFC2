#include "gtest\gtest.h"
#include "AttributeCompatibility.h"
#include "EntityAttribute.h"
#include "BuildinType.h"
#include "EnumType.h"
#include "EntityClass.h"
#include "Converter.h"
#include "AttributeValue.h"
#include "ClassCompatibility.h"

TEST(TestClassCompatibility, Empty)
{
    gfc2::schema::CClass oFromClass, oToClass;
    oFromClass.SetName(L"CTest");
    gfc2::schema::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);
    EXPECT_EQ(true, L"CTest" == oCompatibility.getName());
    EXPECT_EQ(0, oCompatibility.getCount());
}

TEST(TestClassCompatibility, Class1)
{
    gfc2::schema::CClass oFromClass, oToClass;
    gfc2::schema::CAttribute* pFromAttrib1 = new gfc2::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc2::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromClass.addAttribute(pFromAttrib1);

    gfc2::schema::CAttribute* pFromAttrib2 = new gfc2::schema::CAttribute();
    pFromAttrib2->SetName(L"Name");
    gfc2::schema::CStringType oType2;
    pFromAttrib2->SetType(&oType2);
    oFromClass.addAttribute(pFromAttrib2);


    gfc2::schema::CAttribute* pToAttrib1 = new gfc2::schema::CAttribute();
    pToAttrib1->SetName(L"ID");
    //gfc2::schema::CIntegerType oType;
    pToAttrib1->SetType(&oType);
    oToClass.addAttribute(pToAttrib1);

    gfc2::schema::CAttribute* pToAttrib2 = new gfc2::schema::CAttribute();
    pToAttrib2->SetName(L"Name2");
    //gfc2::schema::CBuildinType oType(L"STRING");
    pToAttrib2->SetType(&oType2);
    oToClass.addAttribute(pToAttrib2);

    gfc2::schema::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);
    EXPECT_EQ(3, oCompatibility.getCount());
    EXPECT_EQ(0, oCompatibility.getCompatibilityAttribute(0)->toIndex());
    EXPECT_EQ(-1, oCompatibility.getCompatibilityAttribute(1)->toIndex());
    EXPECT_EQ(1, oCompatibility.getCompatibilityAttribute(2)->toIndex());
}

TEST(TestClassCompatibility, Class2)
{
    gfc2::schema::CClass oFromClass, oToClass;
    gfc2::schema::CClass oFromParentClass, oToParentClass;
    oFromClass.setParent(&oFromParentClass);
    gfc2::schema::CAttribute* pFromAttrib1 = new gfc2::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc2::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromParentClass.addAttribute(pFromAttrib1);

    gfc2::schema::CAttribute* pFromAttrib2 = new gfc2::schema::CAttribute();
    pFromAttrib2->SetName(L"Name");
    gfc2::schema::CStringType oType2;
    pFromAttrib2->SetType(&oType2);
    oFromClass.addAttribute(pFromAttrib2);

    oToClass.setParent(&oToParentClass);
    gfc2::schema::CAttribute* pToAttrib1 = new gfc2::schema::CAttribute();
    pToAttrib1->SetName(L"ID");
    //gfc2::schema::CIntegerType oType;
    pToAttrib1->SetType(&oType);
    oToParentClass.addAttribute(pToAttrib1);

    gfc2::schema::CAttribute* pToAttrib2 = new gfc2::schema::CAttribute();
    pToAttrib2->SetName(L"Name2");
    //gfc2::schema::CBuildinType oType(L"STRING");
    pToAttrib2->SetType(&oType2);
    oToClass.addAttribute(pToAttrib2);

    gfc2::schema::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);
    EXPECT_EQ(3, oCompatibility.getCount());
    EXPECT_EQ(0, oCompatibility.getCompatibilityAttribute(0)->toIndex());
    EXPECT_EQ(-1, oCompatibility.getCompatibilityAttribute(1)->toIndex());
    EXPECT_EQ(1, oCompatibility.getCompatibilityAttribute(2)->toIndex());
}