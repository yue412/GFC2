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

    gfc::schema::CClass oFromClass, oToClass;
    gfc::schema::CAttribute* pFromAttrib1 = new gfc::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromClass.addAttribute(pFromAttrib1);

    gfc::schema::CAttribute* pToAttrib1 = new gfc::schema::CAttribute();
    pToAttrib1->SetName(L"ID");
    //gfc::schema::CIntegerType oType;
    pToAttrib1->SetType(&oType);
    oToClass.addAttribute(pToAttrib1);

    gfc::schema::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);

    gfc::schema::CCompositeAttributeValue oParamList;
    oParamList.add(gfc::schema::CAttributeValuePtr(new gfc::schema::CLeafAttributeValue(L"123")));
    std::string sLine;
    oUpdater.transform(&oCompatibility, &oParamList, sLine);
    
    EXPECT_STREQ("123", sLine.c_str());
}

TEST(TestTextUpdater, transform_delete)
{
    glodon::objectbuf::TextUpdater oUpdater;

    gfc::schema::CClass oFromClass, oToClass;
    gfc::schema::CAttribute* pFromAttrib1 = new gfc::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromClass.addAttribute(pFromAttrib1);

    gfc::schema::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);

    gfc::schema::CCompositeAttributeValue oParamList;
    oParamList.add(gfc::schema::CAttributeValuePtr(new gfc::schema::CLeafAttributeValue(L"123")));
    std::string sLine;
    oUpdater.transform(&oCompatibility, &oParamList, sLine);

    EXPECT_STREQ("", sLine.c_str());
}

TEST(TestTextUpdater, transform_add)
{
    glodon::objectbuf::TextUpdater oUpdater;

    gfc::schema::CClass oFromClass, oToClass;
    gfc::schema::CAttribute* pFromAttrib1 = new gfc::schema::CAttribute();
    pFromAttrib1->SetName(L"ID");
    gfc::schema::CIntegerType oType;
    pFromAttrib1->SetType(&oType);
    oFromClass.addAttribute(pFromAttrib1);

    gfc::schema::CAttribute* pToAttrib1 = new gfc::schema::CAttribute();
    pToAttrib1->SetName(L"Name");
    //gfc::schema::CIntegerType oType;
    pToAttrib1->SetType(&oType);
    oToClass.addAttribute(pToAttrib1);

    gfc::schema::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);

    gfc::schema::CCompositeAttributeValue oParamList;
    oParamList.add(gfc::schema::CAttributeValuePtr(new gfc::schema::CLeafAttributeValue(L"123")));
    std::string sLine;
    oUpdater.transform(&oCompatibility, &oParamList, sLine);

    EXPECT_STREQ("$", sLine.c_str());
}

TEST(TestTextUpdater, transform_exchange)
{
    glodon::objectbuf::TextUpdater oUpdater;

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

    gfc::schema::CAttribute* pToAttrib2 = new gfc::schema::CAttribute();
    pToAttrib2->SetName(L"Name");
    //gfc::schema::CBuildinType oType(L"STRING");
    pToAttrib2->SetType(&oType2);

    oToClass.addAttribute(pToAttrib2);
    oToClass.addAttribute(pToAttrib1);

    gfc::schema::CClassCompatibility oCompatibility;
    oCompatibility.init(&oFromClass, &oToClass);

    gfc::schema::CCompositeAttributeValue oParamList;
    oParamList.add(gfc::schema::CAttributeValuePtr(new gfc::schema::CLeafAttributeValue(L"123")));
    oParamList.add(gfc::schema::CAttributeValuePtr(new gfc::schema::CLeafAttributeValue(L"'abc'")));
    std::string sLine;
    oUpdater.transform(&oCompatibility, &oParamList, sLine);

    EXPECT_STREQ("'abc',123", sLine.c_str());
}
