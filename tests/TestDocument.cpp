#include "gtest\gtest.h"
#include "GfcEngine\EntityFactory.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\GfcEngineUtils.h"
#include "GfcEngine\Document.h"
#include "Common.h"
#include "EntityClass.h"
#include "EntityAttribute.h"
#include "BuildinType.h"

TEST(TestDocument, Document_add)
{
    gfc2::engine::EntityFactory* pFactory = gfc2::engine::GfcEngineUtils::createFactory(toString(getFullPath(L"GFC3X0.exp")));
    gfc2::engine::Document oDoc(pFactory->schema());
    auto pEntity = pFactory->create("Gfc2Vector3d");
    oDoc.add(20, pEntity);
    pEntity = pFactory->create("Gfc2TShapeSection");
    oDoc.add(30, pEntity);
    auto itr = oDoc.getIterator();
    itr->first();
    EXPECT_EQ(false, itr->isDone());
    itr->next();
    EXPECT_EQ(false, itr->isDone());
    itr->next();
    EXPECT_EQ(true, itr->isDone());
    delete pFactory;
}

TEST(TestDocument, Document_getEntity)
{
    gfc2::engine::EntityFactory* pFactory = gfc2::engine::GfcEngineUtils::createFactory(toString(getFullPath(L"GFC3X0.exp")));
    gfc2::engine::Document oDoc(pFactory->schema());
    auto pEntity = pFactory->create("Gfc2Vector3d");
    oDoc.add(20, pEntity);
    pEntity = pFactory->create("Gfc2TShapeSection");
    oDoc.add(30, pEntity);
    auto p = oDoc.getEntity(30);
    EXPECT_EQ(true, p->entityName() == "Gfc2TShapeSection");
    p = oDoc.getEntity(1);
    EXPECT_EQ(true, p == nullptr);
    delete pFactory;
}

TEST(TestDocument, Document_getEntities_no_subtype)
{
    gfc2::engine::EntityFactory* pFactory = gfc2::engine::GfcEngineUtils::createFactory(toString(getFullPath(L"GFC3X0.exp")));
    gfc2::engine::Document oDoc(pFactory->schema());
    auto pEntity = pFactory->create("Gfc2Object");
    oDoc.add(20, pEntity);
    pEntity = pFactory->create("Gfc2Element");
    oDoc.add(30, pEntity);
    pEntity = pFactory->create("Gfc2Building");
    oDoc.add(25, pEntity);
    auto itr = oDoc.getEntities("Gfc2Object", false);
    itr->first();
    EXPECT_EQ(false, itr->isDone());
    auto p = itr->current();
    EXPECT_EQ(true, p->entityName() == "Gfc2Object");
    itr->next();
    EXPECT_EQ(true, itr->isDone());
    delete pFactory;
}

TEST(TestDocument, Document_getEntities_subtype)
{
    gfc2::engine::EntityFactory* pFactory = gfc2::engine::GfcEngineUtils::createFactory(toString(getFullPath(L"GFC3X0.exp")));
    gfc2::engine::Document oDoc(pFactory->schema());
    auto pEntity = pFactory->create("Gfc2Object");
    oDoc.add(20, pEntity);
    pEntity = pFactory->create("Gfc2Element");
    oDoc.add(30, pEntity);
    pEntity = pFactory->create("Gfc2Building");
    oDoc.add(25, pEntity);
    auto itr = oDoc.getEntities("Gfc2Object", true);
    itr->first();
    EXPECT_EQ(false, itr->isDone());
    auto p = itr->current();
    EXPECT_EQ(true, p->entityName() == "Gfc2Object");

    itr->next();
    EXPECT_EQ(false, itr->isDone());
    p = itr->current();
    EXPECT_EQ(true, p->entityName() == "Gfc2Element" || p->entityName() == "Gfc2Building");

    itr->next();
    EXPECT_EQ(false, itr->isDone());
    p = itr->current();
    EXPECT_EQ(true, p->entityName() == "Gfc2Element" || p->entityName() == "Gfc2Building");

    itr->next();
    EXPECT_EQ(true, itr->isDone());
    delete pFactory;
}

TEST(TestDocument, Document_getIterator)
{
    gfc2::engine::EntityFactory* pFactory = gfc2::engine::GfcEngineUtils::createFactory(toString(getFullPath(L"GFC3X0.exp")));
    gfc2::engine::Document oDoc(pFactory->schema());
    auto pEntity = pFactory->create("Gfc2Object");
    oDoc.add(20, pEntity);
    pEntity = pFactory->create("Gfc2Element");
    oDoc.add(30, pEntity);
    pEntity = pFactory->create("Gfc2Building");
    oDoc.add(25, pEntity);
    auto itr = oDoc.getIterator();
    itr->first();
    EXPECT_EQ(false, itr->isDone());
    auto p = itr->current();
    EXPECT_EQ(true, p->entityName() == "Gfc2Building");

    itr->next();
    EXPECT_EQ(false, itr->isDone());
    p = itr->current();
    EXPECT_EQ(true, p->entityName() == "Gfc2Element");

    itr->next();
    EXPECT_EQ(false, itr->isDone());
    p = itr->current();
    EXPECT_EQ(true, p->entityName() == "Gfc2Object");

    itr->next();
    EXPECT_EQ(true, itr->isDone());
    delete pFactory;
}