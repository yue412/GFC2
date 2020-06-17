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