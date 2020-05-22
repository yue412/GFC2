#include "gtest\gtest.h"
#include "glodon\express\EntityFactory.h"
#include "glodon\express\Entity.h"
#include "Common.h"
#include "EntityClass.h"
#include "EntityAttribute.h"
#include "BuildinType.h"

TEST(TestEntityFactory, EntityFactory_create)
{
    glodon::express::EntityFactory oFactory;
    oFactory.loadSchema(toString(getFullPath(L"GFC3X0.exp")));
    auto pEntity = oFactory.create("Gfc2InternalChart");
    EXPECT_EQ(true, pEntity != nullptr);
    EXPECT_EQ(true, pEntity->entityName() == "Gfc2InternalChart");
    delete pEntity;
}

TEST(TestEntityFactory, EntityFactory_initClass_no_parent)
{
    glodon::express::EntityFactory oFactory;
    gfc2::schema::CClass oClass;
    oClass.SetName(L"Gfc2InternalChart");
    gfc2::schema::CBuildinType oDoubleType(L"REAL");
    gfc2::schema::CAttribute* pA1 = new gfc2::schema::CAttribute();
    pA1->SetType(&oDoubleType);
    oClass.addAttribute(pA1);

    gfc2::schema::CAttribute* pA2 = new gfc2::schema::CAttribute();
    pA2->SetType(&oDoubleType);
    oClass.addAttribute(pA2);

    gfc2::schema::CAttribute* pA3 = new gfc2::schema::CAttribute();
    pA3->SetType(&oDoubleType);
    oClass.addAttribute(pA3);
    
    gfc2::schema::CClass oClass2;
    oClass2.SetName(L"Gfc2InternalPt");

    gfc2::schema::CAttribute* pA4 = new gfc2::schema::CAttribute();
    pA4->SetRepeatFlag(true);
    pA4->SetType(&oClass2);
    oClass.addAttribute(pA4);

    oFactory.initClass(&oClass);
    auto n = sizeof(std::vector<int>);
    EXPECT_EQ(n+3*8+4, oClass.getDataSize());
    EXPECT_EQ(0, oClass.getAttribute(0)->getDataHandler()->getOffset());
    EXPECT_EQ(9, oClass.getAttribute(1)->getDataHandler()->getOffset());
    EXPECT_EQ(18, oClass.getAttribute(2)->getDataHandler()->getOffset());
    EXPECT_EQ(27, oClass.getAttribute(3)->getDataHandler()->getOffset());
}

TEST(TestEntityFactory, EntityFactory_initClass_parent)
{
    glodon::express::EntityFactory oFactory;

    gfc2::schema::CClass oParentClass;
    oParentClass.SetName(L"Gfc2Shape");

    gfc2::schema::CClass oClass2;
    oClass2.SetName(L"Gfc2Geometry");

    gfc2::schema::CClass oClass;
    oClass.SetName(L"Gfc2GeometryShape");
    oClass.setParent(&oParentClass);
    gfc2::schema::CAttribute* pA1 = new gfc2::schema::CAttribute();
    pA1->SetType(&oClass2);
    pA1->SetRepeatFlag(true);
    oClass.addAttribute(pA1);

    gfc2::schema::CClass oClass3;
    oClass3.SetName(L"Gfc2Coordinates3d");
    gfc2::schema::CAttribute* pA2 = new gfc2::schema::CAttribute();
    pA2->SetType(&oClass3);
    oParentClass.addAttribute(pA2);

    gfc2::schema::CClass oClass4;
    oClass4.SetName(L"Gfc2Box3d");
    gfc2::schema::CAttribute* pA3 = new gfc2::schema::CAttribute();
    pA3->SetType(&oClass4);
    pA3->SetOptionalFlag(true);
    oParentClass.addAttribute(pA3);

    oFactory.initClass(&oClass);
    auto n = sizeof(std::vector<glodon::express::EntityRef>);
    EXPECT_EQ(n + 2 * sizeof(glodon::express::EntityRef) + 3, oClass.getDataSize());
    EXPECT_EQ(2 * sizeof(glodon::express::EntityRef) + 2, oClass.getAttribute(0)->getDataHandler()->getOffset());
}