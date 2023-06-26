#ifdef GFCUTILS

#include "gtest/gtest.h"
#include "GfcEngine/Writer.h"
#include "GfcEngine/Reader.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/GfcEngineUtils.h"
//#include "Classes/Gfc2EdgeData.h"
#include "Common.h"
#include "GfcSchema/Model.h"
#include "GfcUtils/GfcTransform.h"
#include "GfcUtils/GfcTo2.h"
#include "GfcEngine/Container.h"
#include "MockWriter.h"

class GfcTransform30to20_Test : public GfcTo2
{
public:
    GfcTransform30to20_Test() : GfcTo2(nullptr) {}
    GfcTransform30to20_Test(gfc::engine::IContainer* pContainer) : GfcTo2(pContainer) {}
    DestEntityPtr transformEntity(SrcEntityPtr& pSrcEntity) {
        return GfcTransform::transformEntity(pSrcEntity);
    }
    GfcEntityRefMap transformBuilding(gfc::engine::EntityRef nProjectRef)
    {
        return GfcTransform::transformBuilding(nProjectRef);
    }
    GfcEntityRefMap transformFloor(const GfcEntityRefMap& oBuildingRefMap)
    {
        return GfcTransform::transformFloor(oBuildingRefMap);
    }
    std::map<gfc::engine::EntityRef, std::vector<gfc::engine::EntityRef>>& getRelAggregates() { return m_oRelAggregates; }
};

TEST(TestGFCTransform, doTransformEntity_id)
{
    GfcTransform30to20_Test oTransform;
    gfc::schema::CModel oSrcModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oSrcModel);
    auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Project");
    pSrcEntity->setAsString(L"ID", L"12");
    //pSrcEntity->setAsString(L"Name", L"中国");

    gfc::schema::CModel oDestModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    pSrcEntity->setRef(2);
    auto p = GfcTransform::SrcEntityPtr(pSrcEntity);
    auto pDestEntity = oTransform.transformEntity(p);
    EXPECT_EQ(12, pDestEntity->asInteger(L"ID"));
//    delete pSrcEntity;
}

TEST(TestGFCTransform, doTransformEntity_string)
{
    gfc::schema::CModel oSrcModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oSrcModel);
    gfc::engine::CDocument Doc(&oSrcModel);
    //auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    //pIdentity->setAsString(L"Value", L"中国");
    //Doc.add(23, pIdentity);
    auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Project");
    pSrcEntity->setAsString(L"ID", L"12");
    pSrcEntity->setAsString(L"Name", L"中国");
    pSrcEntity->setRef(3);
    Doc.add(pSrcEntity);

    GfcTransform30to20_Test oTransform(&Doc);
    gfc::schema::CModel oDestModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    gfc::engine::CMockWriter oWriter;
    oWriter.open(L"test", L"mock");
    oTransform.setWriter(&oWriter);
    //auto result = oTransform.transform();
    auto  p = Doc.getEntity(3);
    auto pDestEntity = oTransform.transformEntity(p);
    EXPECT_EQ(12, pDestEntity->asInteger(L"ID"));
    EXPECT_EQ(1, pDestEntity->asEntityRef(L"Name"));
}


TEST(TestGFCTransform, doTransformEntity_entityref)
{
    gfc::schema::CModel oSrcModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oSrcModel);
    gfc::engine::CDocument Doc(&oSrcModel);
    //auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    //pIdentity->setAsString(L"Value", L"中国");
    //Doc.add(23, pIdentity);
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Coordinates3d");
        pSrcEntity->setRef(3);
        Doc.add(pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Shape");
        //pSrcEntity->setAsString(L"Identifier", L"Solid");
        pSrcEntity->setAsEntityRef(L"LocalCoordinate", 3);
        pSrcEntity->setRef(5);
        Doc.add(pSrcEntity);
    }

    GfcTransform30to20_Test oTransform(&Doc);
    gfc::schema::CModel oDestModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    gfc::engine::CMockWriter oWriter;
    oWriter.open(L"test", L"mock");
    oTransform.setWriter(&oWriter);
    //auto result = oTransform.transform();
    auto p = Doc.getEntity(5);
    auto pDestEntity = oTransform.transformEntity(p);
    //EXPECT_EQ(12, pDestEntity->asInteger(L"ID"));
    EXPECT_EQ(1, pDestEntity->asEntityRef(L"LocalCoordinate"));
}

TEST(TestGFCTransform, doTransformProject)
{
    gfc::schema::CModel oSrcModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oSrcModel);
    gfc::engine::CDocument Doc(&oSrcModel);
    //auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    //pIdentity->setAsString(L"Value", L"中国");
    //Doc.add(23, pIdentity);
    auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Project");
    pSrcEntity->setAsString(L"ID", L"12");
    pSrcEntity->setAsString(L"Name", L"中国");
    pSrcEntity->setRef(3);
    Doc.add(pSrcEntity);

    GfcTransform30to20_Test oTransform(&Doc);
    gfc::schema::CModel oDestModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    gfc::engine::CMockWriter oWriter;
    oWriter.open(L"test", L"mock");
    oTransform.setWriter(&oWriter);
    //auto result = oTransform.transform();
    auto p = Doc.getEntity(3);
    auto pDestEntity = oTransform.transformEntity(p);
    EXPECT_EQ(12, pDestEntity->asInteger(L"ID"));
    EXPECT_EQ(1, pDestEntity->asEntityRef(L"Name"));
    EXPECT_EQ(true, pDestEntity->isNull(L"OwnerID"));
    EXPECT_EQ(true, pDestEntity->isNull(L"Code"));
    EXPECT_EQ(true, pDestEntity->isNull(L"ProjectType"));
    EXPECT_EQ(true, pDestEntity->isNull(L"StructureType"));
    EXPECT_EQ(true, pDestEntity->isNull(L"FDType"));
    EXPECT_EQ(true, pDestEntity->isNull(L"ArchiFeature"));
    EXPECT_EQ(true, pDestEntity->isNull(L"BelowGroundFloorCount"));
    EXPECT_EQ(true, pDestEntity->isNull(L"AboveGroundFloorCount"));
    EXPECT_EQ(true, pDestEntity->isNull(L"EavesHeight"));
    EXPECT_EQ(true, pDestEntity->isNull(L"FloorArea"));
    EXPECT_EQ(true, pDestEntity->isNull(L"AseismicGrade"));
    EXPECT_EQ(true, pDestEntity->isNull(L"ProtectedIntensity"));
    EXPECT_EQ(true, pDestEntity->isNull(L"Quantities"));
    EXPECT_EQ(true, pDestEntity->isNull(L"GroundElev"));
    EXPECT_EQ(true, pDestEntity->isNull(L"ProjectSize"));
    EXPECT_EQ(true, pDestEntity->isNull(L"FrozenEarthThickness"));
    EXPECT_EQ(true, pDestEntity->isNull(L"WetEarthThickness"));
    EXPECT_EQ(true, pDestEntity->isNull(L"WaterElev"));
}

TEST(TestGFCTransform, doTransformBuilding)
{
    gfc::schema::CModel oSrcModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oSrcModel);
    gfc::engine::CDocument Doc(&oSrcModel);
    //auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    //pIdentity->setAsString(L"Value", L"中国");
    //Doc.add(23, pIdentity);
    auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building");
    pSrcEntity->setAsString(L"ID", L"12");
    pSrcEntity->setAsString(L"Name", L"中国");
    pSrcEntity->setRef(3);
    Doc.add(pSrcEntity);

    GfcTransform30to20_Test oTransform(&Doc);
    gfc::schema::CModel oDestModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    gfc::engine::CMockWriter oWriter;
    oWriter.open(L"test", L"mock");
    oTransform.setWriter(&oWriter);
    //auto result = oTransform.transform();
    auto p = Doc.getEntity(3);
    auto pDestEntity = oTransform.transformEntity(p);
    EXPECT_EQ(12, pDestEntity->asInteger(L"ID"));
    EXPECT_EQ(1, pDestEntity->asEntityRef(L"Name"));
    EXPECT_EQ(true, pDestEntity->isNull(L"OwnerID"));
}

TEST(TestGFCTransform, doTransformFloor)
{
    gfc::schema::CModel oSrcModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oSrcModel);
    gfc::engine::CDocument Doc(&oSrcModel);
    //auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    //pIdentity->setAsString(L"Value", L"中国");
    //Doc.add(23, pIdentity);
    auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor");
    pSrcEntity->setAsString(L"ID", L"12");
    pSrcEntity->setAsString(L"Name", L"中国");
    pSrcEntity->setAsDouble(L"Height", 3.0);
    pSrcEntity->setAsDouble(L"StructuralElevation", 11.5);
    pSrcEntity->setAsInteger(L"StdFloorCount", 1);
    pSrcEntity->setAsInteger(L"StartFloorNo", -1);
    pSrcEntity->setRef(3);
    Doc.add(pSrcEntity);

    GfcTransform30to20_Test oTransform(&Doc);
    gfc::schema::CModel oDestModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    gfc::engine::CMockWriter oWriter;
    oWriter.open(L"test", L"mock");
    oTransform.setWriter(&oWriter);
    //auto result = oTransform.transform();
    auto p = Doc.getEntity(3);
    auto pDestEntity = oTransform.transformEntity(p);
    EXPECT_EQ(12, pDestEntity->asInteger(L"ID"));
    EXPECT_EQ(1, pDestEntity->asEntityRef(L"Name"));
    EXPECT_EQ(true, pDestEntity->isNull(L"OwnerID"));
    EXPECT_EQ(true, pDestEntity->isNull(L"FirstFloorFlag"));
    EXPECT_EQ(1, pDestEntity->asInteger(L"StdFloorCount"));
    EXPECT_EQ(-1, pDestEntity->asInteger(L"StartFloorNo"));
    EXPECT_NEAR(3.0, pDestEntity->asDouble(L"Height"), 1e-7);
    EXPECT_NEAR(11.5, pDestEntity->asDouble(L"StructuralElevation"), 1e-7);
    EXPECT_EQ(true, pDestEntity->isNull(L"FloorArea"));
    EXPECT_EQ(true, pDestEntity->isNull(L"SlabThickness"));
    EXPECT_EQ(true, pDestEntity->isNull(L"Remark"));
    EXPECT_EQ(true, pDestEntity->isNull(L"EntAseismicGrade"));
    EXPECT_EQ(true, pDestEntity->isNull(L"EntProtectiveThickness"));
}

TEST(TestGFCTransform, transformBuilding)
{
    // 测试Building-Project关系
    gfc::schema::CModel oSrcModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oSrcModel);
    gfc::engine::CDocument Doc(&oSrcModel);
    //auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    //pIdentity->setAsString(L"Value", L"中国");
    //Doc.add(23, pIdentity);
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building");
        pSrcEntity->setAsString(L"ID", L"12");
        //pSrcEntity->setAsString(L"Name", L"中国");
        pSrcEntity->setRef(3);
        Doc.add(pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building");
        pSrcEntity->setAsString(L"ID", L"34");
        //pSrcEntity->setAsString(L"Name", L"中国");
        pSrcEntity->setRef(45);
        Doc.add(pSrcEntity);
    }


    GfcTransform30to20_Test oTransform(&Doc);
    gfc::schema::CModel oDestModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    gfc::engine::CMockWriter oWriter;
    oWriter.open(L"test", L"mock");
    oTransform.setWriter(&oWriter);
    //auto result = oTransform.transform();
    auto oMap = oTransform.transformBuilding(1);
    EXPECT_EQ(1, oMap[3]);
    EXPECT_EQ(2, oMap[45]);
    auto oVector = oTransform.getRelAggregates()[1];
    EXPECT_EQ(2, oVector.size());
    EXPECT_EQ(1, oVector[0]);
    EXPECT_EQ(2, oVector[1]);
}

TEST(TestGFCTransform, transformFloor)
{
    //测试building Floor 关系
    gfc::schema::CModel oSrcModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oSrcModel);
    gfc::engine::CDocument Doc(&oSrcModel);
    //auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    //pIdentity->setAsString(L"Value", L"中国");
    //Doc.add(23, pIdentity);
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building");
        pSrcEntity->setAsString(L"ID", L"12");
        //pSrcEntity->setAsString(L"Name", L"中国");
        pSrcEntity->setRef(10);
        Doc.add(pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building");
        pSrcEntity->setAsString(L"ID", L"34");
        //pSrcEntity->setAsString(L"Name", L"中国");
        pSrcEntity->setRef(11);
        Doc.add(pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor");
        pSrcEntity->setAsString(L"ID", L"101");
        //pSrcEntity->setAsString(L"Name", L"中国");
        pSrcEntity->setAsDouble(L"Height", 3.0);
        pSrcEntity->setAsDouble(L"StructuralElevation", 11.5);
        pSrcEntity->setAsInteger(L"StdFloorCount", 1);
        pSrcEntity->setAsInteger(L"StartFloorNo", -1);
        pSrcEntity->setRef(101);
        Doc.add(pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor");
        pSrcEntity->setAsString(L"ID", L"102");
        //pSrcEntity->setAsString(L"Name", L"中国");
        pSrcEntity->setAsDouble(L"Height", 3.0);
        pSrcEntity->setAsDouble(L"StructuralElevation", 11.5);
        pSrcEntity->setAsInteger(L"StdFloorCount", 1);
        pSrcEntity->setAsInteger(L"StartFloorNo", -1);
        pSrcEntity->setRef(102);
        Doc.add(pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor");
        pSrcEntity->setAsString(L"ID", L"103");
        //pSrcEntity->setAsString(L"Name", L"中国");
        pSrcEntity->setAsDouble(L"Height", 3.0);
        pSrcEntity->setAsDouble(L"StructuralElevation", 11.5);
        pSrcEntity->setAsInteger(L"StdFloorCount", 1);
        pSrcEntity->setAsInteger(L"StartFloorNo", -1);
        pSrcEntity->setRef(103);
        Doc.add(pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2RelAggregates");
        pSrcEntity->setAsEntityRef(L"RelatingObject", 10);
        pSrcEntity->addEntityRef(L"RelatedObjects", 101);
        pSrcEntity->addEntityRef(L"RelatedObjects", 102);
        pSrcEntity->setRef(201);
        Doc.add(pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2RelAggregates");
        pSrcEntity->setAsEntityRef(L"RelatingObject", 11);
        pSrcEntity->addEntityRef(L"RelatedObjects", 103);
        pSrcEntity->setRef(202);
        Doc.add(pSrcEntity);
    }

    GfcTransform30to20_Test oTransform(&Doc);
    gfc::schema::CModel oDestModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    gfc::engine::CMockWriter oWriter;
    oWriter.open(L"test", L"mock");
    oTransform.setWriter(&oWriter);
    //auto result = oTransform.transform();
    GfcTransform::GfcEntityRefMap oMap;
    oMap[10] = 1;
    oMap[11] = 2;
    auto oFloorMap = oTransform.transformFloor(oMap);
    EXPECT_EQ(1, oFloorMap[101]);
    EXPECT_EQ(2, oFloorMap[102]);
    EXPECT_EQ(3, oFloorMap[103]);
    {
        auto oVector = oTransform.getRelAggregates()[1];
        EXPECT_EQ(2, oVector.size());
        EXPECT_EQ(1, oVector[0]);
        EXPECT_EQ(2, oVector[1]);
    }
    {
        auto oVector = oTransform.getRelAggregates()[2];
        EXPECT_EQ(1, oVector.size());
        EXPECT_EQ(3, oVector[0]);
    }
}
#endif // 0
