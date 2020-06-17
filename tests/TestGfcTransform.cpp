#include "gtest\gtest.h"
#include "GfcEngine\Writer.h"
#include "GfcEngine\Reader.h"
#include "GfcEngine\Document.h"
#include "GfcEngine\GfcEngineUtils.h"
//#include "Classes\Gfc2EdgeData.h"
#include "Common.h"
#include "GfcSchema/Model.h"
#include "GfcUtils\GfcTransform30to20.h"
#include "GfcEngine\Container.h"
#include "MockWriter.h"

class GfcTransform30to20_Test : public GfcTransform30to20
{
public:
    GfcTransform30to20_Test() : GfcTransform30to20(nullptr) {}
    GfcTransform30to20_Test(gfc::engine::IContainer* pContainer) : GfcTransform30to20(pContainer) {}
    DestEntityPtr doTransformEntity(SrcEntityPtr& pSrcEntity) {
        return GfcTransform30to20::doTransformEntity(pSrcEntity);
    }
    virtual DestEntityPtr doTransformProject(SrcEntityPtr& pSrcEntity) {
        return GfcTransform30to20::doTransformProject(pSrcEntity);
    }
    virtual DestEntityPtr doTransformBuilding(SrcEntityPtr& pSrcEntity) {
        return GfcTransform30to20::doTransformBuilding(pSrcEntity);
    }
    virtual DestEntityPtr doTransformFloor(SrcEntityPtr& pSrcEntity) {
        return GfcTransform30to20::doTransformFloor(pSrcEntity);
    }
    GfcEntityRefMap transformBuilding(gfc::engine::EntityRef nProjectRef)
    {
        return GfcTransform30to20::transformBuilding(nProjectRef);
    }
    GfcEntityRefMap transformFloor(const GfcEntityRefMap& oBuildingRefMap)
    {
        return GfcTransform30to20::transformFloor(oBuildingRefMap);
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
    auto pDestEntity = oTransform.doTransformEntity(gfc::engine::EntityPtr(2, pSrcEntity));
    EXPECT_EQ(12, pDestEntity->asInteger(L"ID"));
   //XPECT_STREQ(L"中国", pDestEntity->asString(L"Name").c_str());
//    delete pSrcEntity;
}

TEST(TestGFCTransform, doTransformEntity_entityref)
{
    gfc::schema::CModel oSrcModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oSrcModel);
    gfc::engine::CDocument Doc(&oSrcModel);
    auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    pIdentity->setAsString(L"Value", L"中国");
    Doc.add(23, pIdentity);
    auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Project");
    pSrcEntity->setAsString(L"ID", L"12");
    pSrcEntity->setAsEntityRef(L"Name", 23);
    Doc.add(3, pSrcEntity);

    GfcTransform30to20_Test oTransform(&Doc);
    gfc::schema::CModel oDestModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    gfc::engine::CMockWriter oWriter;
    oWriter.open(L"test", L"mock");
    oTransform.setWriter(&oWriter);
    //auto result = oTransform.transform();
    auto pDestEntity = oTransform.doTransformEntity(Doc.getEntity(3));
    EXPECT_EQ(12, pDestEntity->asInteger(L"ID"));
    EXPECT_EQ(1, pDestEntity->asEntityRef(L"Name"));
}

TEST(TestGFCTransform, doTransformProject)
{
    gfc::schema::CModel oSrcModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oSrcModel);
    gfc::engine::CDocument Doc(&oSrcModel);
    auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    pIdentity->setAsString(L"Value", L"中国");
    Doc.add(23, pIdentity);
    auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Project");
    pSrcEntity->setAsString(L"ID", L"12");
    pSrcEntity->setAsEntityRef(L"Name", 23);
    Doc.add(3, pSrcEntity);

    GfcTransform30to20_Test oTransform(&Doc);
    gfc::schema::CModel oDestModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    gfc::engine::CMockWriter oWriter;
    oWriter.open(L"test", L"mock");
    oTransform.setWriter(&oWriter);
    //auto result = oTransform.transform();
    auto pDestEntity = oTransform.doTransformProject(Doc.getEntity(3));
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
    auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    pIdentity->setAsString(L"Value", L"中国");
    Doc.add(23, pIdentity);
    auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building");
    pSrcEntity->setAsString(L"ID", L"12");
    pSrcEntity->setAsEntityRef(L"Name", 23);
    Doc.add(3, pSrcEntity);

    GfcTransform30to20_Test oTransform(&Doc);
    gfc::schema::CModel oDestModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    gfc::engine::CMockWriter oWriter;
    oWriter.open(L"test", L"mock");
    oTransform.setWriter(&oWriter);
    //auto result = oTransform.transform();
    auto pDestEntity = oTransform.doTransformBuilding(Doc.getEntity(3));
    EXPECT_EQ(12, pDestEntity->asInteger(L"ID"));
    EXPECT_EQ(1, pDestEntity->asEntityRef(L"Name"));
    EXPECT_EQ(true, pDestEntity->isNull(L"OwnerID"));
}

TEST(TestGFCTransform, doTransformFloor)
{
    gfc::schema::CModel oSrcModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oSrcModel);
    gfc::engine::CDocument Doc(&oSrcModel);
    auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    pIdentity->setAsString(L"Value", L"中国");
    Doc.add(23, pIdentity);
    auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor");
    pSrcEntity->setAsString(L"ID", L"12");
    pSrcEntity->setAsEntityRef(L"Name", 23);
    pSrcEntity->setAsDouble(L"Height", 3.0);
    pSrcEntity->setAsDouble(L"StructuralElevation", 11.5);
    pSrcEntity->setAsInteger(L"StdFloorCount", 1);
    pSrcEntity->setAsInteger(L"StartFloorNo", -1);
    Doc.add(3, pSrcEntity);

    GfcTransform30to20_Test oTransform(&Doc);
    gfc::schema::CModel oDestModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    gfc::engine::CMockWriter oWriter;
    oWriter.open(L"test", L"mock");
    oTransform.setWriter(&oWriter);
    //auto result = oTransform.transform();
    auto pDestEntity = oTransform.doTransformFloor(Doc.getEntity(3));
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
    auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    pIdentity->setAsString(L"Value", L"中国");
    Doc.add(23, pIdentity);
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building");
        pSrcEntity->setAsString(L"ID", L"12");
        pSrcEntity->setAsEntityRef(L"Name", 23);
        Doc.add(3, pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building");
        pSrcEntity->setAsString(L"ID", L"34");
        pSrcEntity->setAsEntityRef(L"Name", 23);
        Doc.add(45, pSrcEntity);
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
    EXPECT_EQ(2, oMap[3]);
    EXPECT_EQ(3, oMap[45]);
    auto oVector = oTransform.getRelAggregates()[1];
    EXPECT_EQ(2, oVector.size());
    EXPECT_EQ(2, oVector[0]);
    EXPECT_EQ(3, oVector[1]);
}

TEST(TestGFCTransform, transformFloor)
{
    //测试building Floor 关系
    gfc::schema::CModel oSrcModel;
    gfc::engine::CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oSrcModel);
    gfc::engine::CDocument Doc(&oSrcModel);
    auto pIdentity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label");
    pIdentity->setAsString(L"Value", L"中国");
    Doc.add(23, pIdentity);
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building");
        pSrcEntity->setAsString(L"ID", L"12");
        pSrcEntity->setAsEntityRef(L"Name", 23);
        Doc.add(10, pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building");
        pSrcEntity->setAsString(L"ID", L"34");
        pSrcEntity->setAsEntityRef(L"Name", 23);
        Doc.add(11, pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor");
        pSrcEntity->setAsString(L"ID", L"101");
        pSrcEntity->setAsEntityRef(L"Name", 23);
        pSrcEntity->setAsDouble(L"Height", 3.0);
        pSrcEntity->setAsDouble(L"StructuralElevation", 11.5);
        pSrcEntity->setAsInteger(L"StdFloorCount", 1);
        pSrcEntity->setAsInteger(L"StartFloorNo", -1);
        Doc.add(101, pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor");
        pSrcEntity->setAsString(L"ID", L"102");
        pSrcEntity->setAsEntityRef(L"Name", 23);
        pSrcEntity->setAsDouble(L"Height", 3.0);
        pSrcEntity->setAsDouble(L"StructuralElevation", 11.5);
        pSrcEntity->setAsInteger(L"StdFloorCount", 1);
        pSrcEntity->setAsInteger(L"StartFloorNo", -1);
        Doc.add(102, pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor");
        pSrcEntity->setAsString(L"ID", L"103");
        pSrcEntity->setAsEntityRef(L"Name", 23);
        pSrcEntity->setAsDouble(L"Height", 3.0);
        pSrcEntity->setAsDouble(L"StructuralElevation", 11.5);
        pSrcEntity->setAsInteger(L"StdFloorCount", 1);
        pSrcEntity->setAsInteger(L"StartFloorNo", -1);
        Doc.add(103, pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2RelAggregates");
        pSrcEntity->setAsEntityRef(L"RelatingObject", 10);
        pSrcEntity->addEntityRef(L"RelatedObjects", 101);
        pSrcEntity->addEntityRef(L"RelatedObjects", 102);
        Doc.add(201, pSrcEntity);
    }
    {
        auto pSrcEntity = gfc::engine::CEngineUtils::createEntity(&oSrcModel, L"Gfc2RelAggregates");
        pSrcEntity->setAsEntityRef(L"RelatingObject", 11);
        pSrcEntity->addEntityRef(L"RelatedObjects", 103);
        Doc.add(202, pSrcEntity);
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
    oMap[10] = 2;
    oMap[11] = 3;
    auto oFloorMap = oTransform.transformFloor(oMap);
    EXPECT_EQ(2, oFloorMap[101]);
    EXPECT_EQ(3, oFloorMap[102]);
    EXPECT_EQ(4, oFloorMap[103]);
    {
        auto oVector = oTransform.getRelAggregates()[2];
        EXPECT_EQ(2, oVector.size());
        EXPECT_EQ(2, oVector[0]);
        EXPECT_EQ(3, oVector[1]);
    }
    {
        auto oVector = oTransform.getRelAggregates()[3];
        EXPECT_EQ(1, oVector.size());
        EXPECT_EQ(4, oVector[0]);
    }
}