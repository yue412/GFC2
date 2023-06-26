#include "gtest/gtest.h"
#include "GfcEngine/Entity.h"
#include "GfcEngine/GfcEngineUtils.h"
#include "GfcEngine/Document.h"
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
    pEntity->setRef(20);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2TShapeSection");
    pEntity->setRef(30);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
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
    pEntity->setRef(20);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2TShapeSection");
    pEntity->setRef(30);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
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
    pEntity->setRef(20);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Element");
    pEntity->setRef(30);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Building");
    pEntity->setRef(25);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
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
    pEntity->setRef(20);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Element");
    pEntity->setRef(30);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Building");
    pEntity->setRef(25);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
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
    pEntity->setRef(20);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Element");
    pEntity->setRef(30);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2Building");
    pEntity->setRef(25);
    oDoc.add(gfc::engine::EntityPtr(pEntity));
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

/*
TEST(TestDocument, Document_ref)
{
    gfc::schema::CModel oModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oModel);
    gfc::engine::CDocument oDoc(&oModel);
    auto pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2ElementShape");
    pEntity->setAsEntityRef(L"Identifier", 30);
    oDoc.add(20, pEntity);
    pEntity = gfc::engine::CEngineUtils::createEntity(&oModel, L"Gfc2String");
    pEntity->setAsString(L"Value", L"hehe");
    oDoc.add(30, pEntity);
    auto p = oDoc.getEntity(20);
    EXPECT_EQ(true, p->entityName() == L"Gfc2ElementShape");
    auto pStr = p->asEntity(L"Identifier");
    EXPECT_EQ(true, pStr != nullptr);
    EXPECT_STREQ(L"hehe", pStr->asString(L"Value").c_str());
}
*/