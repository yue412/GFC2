#include "gtest\gtest.h"
#include "TextUpdater.h"
#include "EntityClass.h"
#include "EntityAttribute.h"
#include "BuildinType.h"
#include "ClassCompatibility.h"
#include "AttributeValue.h"

TEST(TestTextUpdater, transform_same)
{
    glodon::objectbuf::TextUpdater oUpdater;

    gfc2::schema::CClass oFromClass, oToClass;
    gfc2::schema::CAttribute* pFromAttrib1 = new gfc2::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc2::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromClass.addAttribute(pFromAttrib1);

    gfc2::schema::CAttribute* pToAttrib1 = new gfc2::schema::CAttribute();
    pToAttrib1->SetName(L"ID");
    //gfc2::schema::CIntegerType oType;
    pToAttrib1->SetType(&oType);
    oToClass.addAttribute(pToAttrib1);

    gfc2::schema::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);

    gfc2::schema::CCompositeAttributeValue oParamList;
    oParamList.add(gfc2::schema::CAttributeValuePtr(new gfc2::schema::CLeafAttributeValue(L"123")));
    std::string sLine;
    oUpdater.transform(&oCompatibility, &oParamList, sLine);
    
    EXPECT_STREQ("123", sLine.c_str());
}

TEST(TestTextUpdater, transform_delete)
{
    glodon::objectbuf::TextUpdater oUpdater;

    gfc2::schema::CClass oFromClass, oToClass;
    gfc2::schema::CAttribute* pFromAttrib1 = new gfc2::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc2::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromClass.addAttribute(pFromAttrib1);

    gfc2::schema::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);

    gfc2::schema::CCompositeAttributeValue oParamList;
    oParamList.add(gfc2::schema::CAttributeValuePtr(new gfc2::schema::CLeafAttributeValue(L"123")));
    std::string sLine;
    oUpdater.transform(&oCompatibility, &oParamList, sLine);

    EXPECT_STREQ("", sLine.c_str());
}

TEST(TestTextUpdater, transform_add)
{
    glodon::objectbuf::TextUpdater oUpdater;

    gfc2::schema::CClass oFromClass, oToClass;
    gfc2::schema::CAttribute* pFromAttrib1 = new gfc2::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc2::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromClass.addAttribute(pFromAttrib1);

    gfc2::schema::CAttribute* pToAttrib1 = new gfc2::schema::CAttribute();
    pToAttrib1->SetName(L"Name");
    //gfc2::schema::CIntegerType oType;
    pToAttrib1->SetType(&oType);
    oToClass.addAttribute(pToAttrib1);

    gfc2::schema::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);

    gfc2::schema::CCompositeAttributeValue oParamList;
    oParamList.add(gfc2::schema::CAttributeValuePtr(new gfc2::schema::CLeafAttributeValue(L"123")));
    std::string sLine;
    oUpdater.transform(&oCompatibility, &oParamList, sLine);

    EXPECT_STREQ("$", sLine.c_str());
}

TEST(TestTextUpdater, transform_exchange)
{
    glodon::objectbuf::TextUpdater oUpdater;

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

    gfc2::schema::CAttribute* pToAttrib2 = new gfc2::schema::CAttribute();
    pToAttrib2->SetName(L"Name");
    //gfc2::schema::CBuildinType oType(L"STRING");
    pToAttrib2->SetType(&oType2);

    oToClass.addAttribute(pToAttrib2);
    oToClass.addAttribute(pToAttrib1);

    gfc2::schema::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);

    gfc2::schema::CCompositeAttributeValue oParamList;
    oParamList.add(gfc2::schema::CAttributeValuePtr(new gfc2::schema::CLeafAttributeValue(L"123")));
    oParamList.add(gfc2::schema::CAttributeValuePtr(new gfc2::schema::CLeafAttributeValue(L"'abc'")));
    std::string sLine;
    oUpdater.transform(&oCompatibility, &oParamList, sLine);

    EXPECT_STREQ("'abc',123", sLine.c_str());
}
