#include "gtest\gtest.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\GfcEngineUtils.h"
#include "GfcEngine\Document.h"
#include "Common.h"
#include "GfcSchema/EntityClass.h"
#include "GfcSchema/EntityAttribute.h"
#include "GfcSchema/BuildinType.h"
#include "GfcSchema/Model.h"

TEST(TestDocument, Document_add)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CDocument oDoc(&oModel);
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Vector3d");
    oDoc.add(20, pEntity);
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2TShapeSection");
    oDoc.add(30, pEntity);
    auto itr = oDoc.getIterator();
    itr->first();
    EXPECT_EQ(false, itr->isDone());
    itr->next();
    EXPECT_EQ(false, itr->isDone());
    itr->next();
    EXPECT_EQ(true, itr->isDone());
}

TEST(TestDocument, Document_getEntity)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CDocument oDoc(&oModel);
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Vector3d");
    oDoc.add(20, pEntity);
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2TShapeSection");
    oDoc.add(30, pEntity);
    auto p = oDoc.getEntity(30);
    EXPECT_EQ(true, p->entityName() == L"Gfc2TShapeSection");
    p = oDoc.getEntity(1);
    EXPECT_EQ(true, p == nullptr);
}

TEST(TestDocument, Document_getEntities_no_subtype)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CDocument oDoc(&oModel);
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Object");
    oDoc.add(20, pEntity);
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Element");
    oDoc.add(30, pEntity);
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Building");
    oDoc.add(25, pEntity);
    auto itr = oDoc.getEntities(L"Gfc2Object", false);
    itr->first();
    EXPECT_EQ(false, itr->isDone());
    auto p = itr->current();
    EXPECT_EQ(true, p->entityName() == L"Gfc2Object");
    itr->next();
    EXPECT_EQ(true, itr->isDone());
}

TEST(TestDocument, Document_getEntities_subtype)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CDocument oDoc(&oModel);
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Object");
    oDoc.add(20, pEntity);
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Element");
    oDoc.add(30, pEntity);
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Building");
    oDoc.add(25, pEntity);
    auto itr = oDoc.getEntities(L"Gfc2Object", true);
    itr->first();
    EXPECT_EQ(false, itr->isDone());
    auto p = itr->current();
    EXPECT_EQ(true, p->entityName() == L"Gfc2Object");

    itr->next();
    EXPECT_EQ(false, itr->isDone());
    p = itr->current();
    EXPECT_EQ(true, p->entityName() == L"Gfc2Element" || p->entityName() == L"Gfc2Building");

    itr->next();
    EXPECT_EQ(false, itr->isDone());
    p = itr->current();
    EXPECT_EQ(true, p->entityName() == L"Gfc2Element" || p->entityName() == L"Gfc2Building");

    itr->next();
    EXPECT_EQ(true, itr->isDone());
}

TEST(TestDocument, Document_getIterator)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CDocument oDoc(&oModel);
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Object");
    oDoc.add(20, pEntity);
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Element");
    oDoc.add(30, pEntity);
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Building");
    oDoc.add(25, pEntity);
    auto itr = oDoc.getIterator();
    itr->first();
    EXPECT_EQ(false, itr->isDone());
    auto p = itr->current();
    EXPECT_EQ(true, p->entityName() == L"Gfc2Building");

    itr->next();
    EXPECT_EQ(false, itr->isDone());
    p = itr->current();
    EXPECT_EQ(true, p->entityName() == L"Gfc2Element");

    itr->next();
    EXPECT_EQ(false, itr->isDone());
    p = itr->current();
    EXPECT_EQ(true, p->entityName() == L"Gfc2Object");

    itr->next();
    EXPECT_EQ(true, itr->isDone());
}