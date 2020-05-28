#include "gtest\gtest.h"
#include "Parser.h"
#include "BuildinType.h"
#include "TypeDefine.h"

TEST(TestExpParse, TypeDefine)
{
    std::string sCode = std::string("SCHEMA GFC1X9;\n")
        + std::string("TYPE Gfc2Boolean = BOOLEAN;\n")
        + std::string("END_TYPE;\n")
        + std::string("END_SCHEMA;\n")
        ;
    Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    Parser oParser(&oScanner);
    gfc2::schema::CModel oModel, oTempModel;
    oParser.m_pModel = &oModel;
    oParser.m_pTempModel = &oTempModel;

//    oModel.addTypeObject(new gfc2::schema::CBooleanType());

    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(5, oParser.m_pModel->getTypeObjectCount());
    auto pTypeObject = oParser.m_pModel->getTypeObject(4);
    EXPECT_NE(nullptr, dynamic_cast<gfc2::schema::CTypeDef*>(pTypeObject));
    EXPECT_EQ(true, L"Gfc2Boolean" == pTypeObject->getName());
    //EXPECT_EQ(0, oParser.m_oParameterList.getCount());
}

TEST(TestExpParse, Enumeration)
{
    std::string sCode = std::string("SCHEMA GFC1X9;\n")
        + std::string("TYPE Gfc2ArcType = ENUMERATION OF\n")
        + std::string("(AT_LINE\n")
        + std::string(",AT_ACS\n")
        + std::string(",AT_CS\n")
        + std::string(",AT_ACL\n")
        + std::string(",AT_CL);\n")
        + std::string("END_TYPE;\n")
        + std::string("END_SCHEMA;\n")
        ;
    Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    Parser oParser(&oScanner);
    gfc2::schema::CModel oModel, oTempModel;
    oParser.m_pModel = &oModel;
    oParser.m_pTempModel = &oTempModel;

    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(5, oParser.m_pModel->getTypeObjectCount());
    auto pTypeObject = oParser.m_pModel->getTypeObject(4);
    auto pEnum = dynamic_cast<gfc2::schema::CEnumType*>(pTypeObject);
    EXPECT_NE(nullptr, pEnum);
    EXPECT_EQ(5, pEnum->getEnumCount());
}

TEST(TestExpParse, Entity1)
{
    std::string sCode =
        "SCHEMA GFC1X9;\n"
        "TYPE Gfc2Integer = INTEGER;\n"
        "END_TYPE; \n"
        "ENTITY Gfc2BillDetail;\n"
        "FloorNum : Gfc2Integer;\n"
        "EntityID: Gfc2Integer;\n"
        "END_ENTITY; "
        "END_SCHEMA;\n"
        ;
    Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    Parser oParser(&oScanner);
    gfc2::schema::CModel oModel, oTempModel;
    oParser.m_pModel = &oModel;
    oParser.m_pTempModel = &oTempModel;
    //oModel.addTypeObject(new gfc2::schema::CIntegerType());

    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(6, oParser.m_pModel->getTypeObjectCount());
    auto pTypeObject = oParser.m_pModel->getTypeObject(5);
    auto pClass = dynamic_cast<gfc2::schema::CClass*>(pTypeObject);
    EXPECT_NE(nullptr, pClass);
    EXPECT_EQ(2, pClass->getAttributeCount());
}

TEST(TestExpParse, Entity_addType)
{
    std::string sCode =
        "SCHEMA GFC1X9;\n"
        "ENTITY Gfc2BillDetail;\n"
        "FloorNum : Gfc2Integer;\n"
        "EntityID: Gfc2Integer;\n"
        "END_ENTITY; \n"
        "TYPE Gfc2Integer = INTEGER;\n"
        "END_TYPE; \n"
        "END_SCHEMA;\n"
        ;
    Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    Parser oParser(&oScanner);
    gfc2::schema::CModel oModel, oTempModel;
    oParser.m_pModel = &oModel;
    oParser.m_pTempModel = &oTempModel;
    //oModel.addTypeObject(new gfc2::schema::CIntegerType);
    
    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(6, oParser.m_pModel->getTypeObjectCount());
    auto pTypeObject = oParser.m_pModel->getTypeObject(4);
    auto pClass = dynamic_cast<gfc2::schema::CClass*>(pTypeObject);
    EXPECT_NE(nullptr, pClass);
    EXPECT_EQ(2, pClass->getAttributeCount());
    EXPECT_EQ(gfc2::schema::TOE_TYPE, pClass->getAttribute(0)->getType()->getType());
}


TEST(TestExpParse, Entity_SUBTYPE)
{
    std::string sCode =
        "SCHEMA GFC1X9;\n"
        "ENTITY Gfc2Bevel\n"
        "SUBTYPE OF(Gfc2Surface);\n"
        "Coord: Gfc2Coordinates3d;\n"
        "END_ENTITY;\n"
        "ENTITY Gfc2Surface;\n"
        "END_ENTITY;\n"
        "ENTITY Gfc2Coordinates3d;\n"
        "END_ENTITY;\n"
        "END_SCHEMA;\n"
        ;
    Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    Parser oParser(&oScanner);
    gfc2::schema::CModel oModel, oTempModel;
    oParser.m_pModel = &oModel;
    oParser.m_pTempModel = &oTempModel;

    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(7, oParser.m_pModel->getTypeObjectCount());
    auto pTypeObject = oParser.m_pModel->getTypeObject(4);
    auto pClass = dynamic_cast<gfc2::schema::CClass*>(pTypeObject);
    EXPECT_NE(nullptr, pClass);
    EXPECT_EQ(true, pClass->getName() == L"Gfc2Bevel");
    EXPECT_EQ(1, pClass->getAttributeCount());
    EXPECT_NE(nullptr, pClass->getParent());
    EXPECT_EQ(true, pClass->getParent()->getName() == L"Gfc2Surface");
}

TEST(TestExpParse, Entity_SUPERTYPE)
{
    std::string sCode =
        "SCHEMA GFC1X9;\n"
        "ENTITY Gfc2RelationShip\n"
        "SUPERTYPE OF(ONEOF\n"
        "(Gfc2RelDecomposes\n"
        "    , Gfc2RelDefines));\n"
        "Coord: Gfc2Integer;\n"
        "END_ENTITY;\n"
        "ENTITY Gfc2Integer;\n"
        "END_ENTITY;\n"
        "ENTITY Gfc2RelDecomposes;\n"
        "END_ENTITY;\n"
        "ENTITY Gfc2RelDefines;\n"
        "END_ENTITY;\n"
        "END_SCHEMA;\n"
        ;
    Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    Parser oParser(&oScanner);
    gfc2::schema::CModel oModel, oTempModel;
    oParser.m_pModel = &oModel;
    oParser.m_pTempModel = &oTempModel;

    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(8, oParser.m_pModel->getTypeObjectCount());
    auto pTypeObject = oParser.m_pModel->getTypeObject(4);
    auto pClass = dynamic_cast<gfc2::schema::CClass*>(pTypeObject);
    EXPECT_NE(nullptr, pClass);
    EXPECT_EQ(true, pClass->getName() == L"Gfc2RelationShip");
    EXPECT_EQ(2, pClass->getChildCount());
}

TEST(TestExpParse, Entity_ABSTRACT_SUPERTYPE)
{
    std::string sCode =
        "SCHEMA GFC1X9;\n"
        "ENTITY Gfc2RelationShip\n"
        "ABSTRACT SUPERTYPE OF(ONEOF\n"
        "(Gfc2RelDecomposes\n"
        "    , Gfc2RelDefines));\n"
        "Coord: Gfc2Integer;\n"
        "END_ENTITY;\n"
        "ENTITY Gfc2Integer;\n"
        "END_ENTITY;\n"
        "ENTITY Gfc2RelDecomposes;\n"
        "END_ENTITY;\n"
        "ENTITY Gfc2RelDefines;\n"
        "END_ENTITY;\n"
        "END_SCHEMA;\n"
        ;
    Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    Parser oParser(&oScanner);
    gfc2::schema::CModel oModel, oTempModel;
    oParser.m_pModel = &oModel;
    oParser.m_pTempModel = &oTempModel;

    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(8, oParser.m_pModel->getTypeObjectCount());
    auto pTypeObject = oParser.m_pModel->getTypeObject(4);
    auto pClass = dynamic_cast<gfc2::schema::CClass*>(pTypeObject);
    EXPECT_NE(nullptr, pClass);
    EXPECT_EQ(true, pClass->getName() == L"Gfc2RelationShip");
    EXPECT_EQ(true, pClass->getIsAbstract());
    EXPECT_EQ(2, pClass->getChildCount());
}

TEST(TestExpParse, Entity_ABSTRACT_SUPERTYPE_SUBTYPE)
{
    std::string sCode =
        "SCHEMA GFC1X9;\n"
        "ENTITY Gfc2RelationShip\n"
        "ABSTRACT SUPERTYPE OF(ONEOF\n"
        "(Gfc2RelDecomposes\n"
        "    , Gfc2RelDefines))\n"
        " SUBTYPE OF (Gfc2Root);\n"
        "Coord: Gfc2Integer;\n"
        "END_ENTITY;\n"
        "ENTITY Gfc2Integer;\n"
        "END_ENTITY;\n"
        "ENTITY Gfc2RelDecomposes;\n"
        "END_ENTITY;\n"
        "ENTITY Gfc2RelDefines;\n"
        "END_ENTITY;\n"
        "ENTITY Gfc2Root;\n"
        "END_ENTITY;\n"
        "END_SCHEMA;\n"
        ;
    Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    Parser oParser(&oScanner);
    gfc2::schema::CModel oModel, oTempModel;
    oParser.m_pModel = &oModel;
    oParser.m_pTempModel = &oTempModel;

    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(9, oParser.m_pModel->getTypeObjectCount());
    auto pTypeObject = oParser.m_pModel->getTypeObject(4);
    auto pClass = dynamic_cast<gfc2::schema::CClass*>(pTypeObject);
    EXPECT_NE(nullptr, pClass);
    EXPECT_EQ(true, pClass->getName() == L"Gfc2RelationShip");
    EXPECT_EQ(true, pClass->getIsAbstract());
    EXPECT_EQ(2, pClass->getChildCount());
    EXPECT_NE(nullptr, pClass->getParent());
    EXPECT_EQ(true, pClass->getParent()->getIsValid());
}

TEST(TestExpParse, Entity_optional)
{
    std::string sCode =
        "SCHEMA GFC1X9;\n"
        "ENTITY Gfc2BillDetail;\n"
        "FloorNum : Gfc2Integer;\n"
        "EntityID: OPTIONAL Gfc2Integer;\n"
        "END_ENTITY; \n"
        "TYPE Gfc2Integer = INTEGER;\n"
        "END_TYPE; \n"
        "END_SCHEMA;\n"
        ;
    Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    Parser oParser(&oScanner);
    gfc2::schema::CModel oModel, oTempModel;
    oParser.m_pModel = &oModel;
    oParser.m_pTempModel = &oTempModel;
    //oModel.addTypeObject(new gfc2::schema::CIntegerType);

    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(6, oParser.m_pModel->getTypeObjectCount());
    auto pTypeObject = oParser.m_pModel->getTypeObject(4);
    auto pClass = dynamic_cast<gfc2::schema::CClass*>(pTypeObject);
    EXPECT_NE(nullptr, pClass);
    EXPECT_EQ(2, pClass->getAttributeCount());
    EXPECT_EQ(gfc2::schema::TOE_TYPE, pClass->getAttribute(1)->getType()->getType());
    EXPECT_EQ(true, pClass->getAttribute(1)->getOptionalFlag());
}

TEST(TestExpParse, Entity_Array)
{
    std::string sCode =
        "SCHEMA GFC1X9;\n"
        "ENTITY Gfc2BillDetail;\n"
        "FloorNum : Gfc2Integer;\n"
        "EntityID: LIST [0:?] OF Gfc2Integer;\n"
        "END_ENTITY; \n"
        "TYPE Gfc2Integer = INTEGER;\n"
        "END_TYPE; \n"
        "END_SCHEMA;\n"
        ;
    Scanner oScanner((unsigned char*)sCode.c_str(), sCode.length());
    Parser oParser(&oScanner);
    gfc2::schema::CModel oModel, oTempModel;
    oParser.m_pModel = &oModel;
    oParser.m_pTempModel = &oTempModel;
    //oModel.addTypeObject(new gfc2::schema::CIntegerType);

    oParser.Parse();
    EXPECT_EQ(0, oParser.errors->count);
    EXPECT_EQ(6, oParser.m_pModel->getTypeObjectCount());
    auto pTypeObject = oParser.m_pModel->getTypeObject(4);
    auto pClass = dynamic_cast<gfc2::schema::CClass*>(pTypeObject);
    EXPECT_NE(nullptr, pClass);
    EXPECT_EQ(2, pClass->getAttributeCount());
    EXPECT_EQ(gfc2::schema::TOE_TYPE, pClass->getAttribute(1)->getType()->getType());
    EXPECT_EQ(true, pClass->getAttribute(1)->getRepeatFlag());
}