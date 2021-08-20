#include "gtest\gtest.h"
#include "GfcEngine\Writer.h"
#include "GfcEngine\Reader.h"
#include "GfcEngine\Document.h"
#include "GfcEngine\GfcEngineUtils.h"
//#include "Classes\Gfc2EdgeData.h"
#include "Common.h"
#include "GfcSchema\Model.h"
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\EntityAttribute.h"
#include "GfcSchema\BuildinType.h"
#include "GfcSchema\EnumType.h"
#include "GfcSchema\TypeDefine.h"
#include "GfcUtils\GfcTransform.h"
#include "GfcUtils\GfcFrom2.h"
#include "GfcEngine\Container.h"
#include "GfcEngine\PropValue.h"
#include "MockWriter.h"
#include <string>

using namespace gfc::engine;

class GfcFrom2_Test : public GfcFrom2
{
public:
    GfcFrom2_Test() : GfcFrom2(nullptr) {}
    GfcFrom2_Test(IContainer* pContainer) : GfcFrom2(pContainer) {}
    DestEntityPtr transformEntity(SrcEntityPtr& pSrcEntity) {
        return GfcTransform::transformEntity(pSrcEntity);
    }
    EntityRef transformProject() {
        return GfcTransform::transformProject();
    }

    GfcEntityRefMap transformBuilding(EntityRef nProjectRef)
    {
        return GfcTransform::transformBuilding(nProjectRef);
    }
    GfcEntityRefMap transformFloor(const GfcEntityRefMap& oBuildingRefMap)
    {
        return GfcTransform::transformFloor(oBuildingRefMap);
    }
    GfcTransform::DestEntityPtr attributeToProperty(CProperty* pSrc)
    {
        return GfcFrom2::attributeToProperty(pSrc);
    }
    gfc::engine::EntityRef entityToObject(SrcEntityPtr pSrc)
    {
        return GfcFrom2::entityToObject(pSrc);
    }

    std::map<EntityRef, std::vector<EntityRef>>& getRelAggregates() { return m_oRelAggregates; }
};

// 对象属性转为Property对象
TEST(TestGFCFrom2, attributeToProperty_int)
{
    GfcFrom2_Test oTransform;
    gfc::schema::CModel oSrcModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oSrcModel);
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Project"));
    pSrcEntity->setAsInteger(L"ID", 2021521);
    //pSrcEntity->setAsString(L"Name", L"中国");

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto pProp = pSrcEntity->propByName(L"ID");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2IntegerProperty", pDestEntity->entityName().c_str());
    EXPECT_EQ(2021521, pDestEntity->asInteger(L"Val"));
    EXPECT_STREQ(L"ID", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

TEST(TestGFCFrom2, attributeToProperty_bool)
{
    GfcFrom2_Test oTransform;
    gfc::schema::CModel oSrcModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oSrcModel);
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor"));
    pSrcEntity->setAsBoolean(L"FirstFloorFlag", true);
    //pSrcEntity->setAsString(L"Name", L"中国");

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto pProp = pSrcEntity->propByName(L"FirstFloorFlag");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2BooleanProperty", pDestEntity->entityName().c_str());
    EXPECT_EQ(true, pDestEntity->asBoolean(L"Val"));
    EXPECT_STREQ(L"FirstFloorFlag", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

TEST(TestGFCFrom2, attributeToProperty_double)
{
    GfcFrom2_Test oTransform;
    gfc::schema::CModel oSrcModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oSrcModel);
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor"));
    pSrcEntity->setAsDouble(L"Height", 21.3);
    //pSrcEntity->setAsString(L"Name", L"中国");

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto pProp = pSrcEntity->propByName(L"Height");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2DoubleProperty", pDestEntity->entityName().c_str());
    EXPECT_NEAR(21.3, pDestEntity->asDouble(L"Val"), 1e-7);
    EXPECT_STREQ(L"Height", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

TEST(TestGFCFrom2, attributeToProperty_string)
{
    GfcFrom2_Test oTransform;
    gfc::schema::CModel oSrcModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oSrcModel);
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2String"));
    pSrcEntity->setAsString(L"Value", L"Hehe");
    //pSrcEntity->setAsString(L"Name", L"中国");

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto pProp = pSrcEntity->propByName(L"Value");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Value", pDestEntity->asString(L"Name").c_str());
    EXPECT_STREQ(L"Gfc2StringProperty", pDestEntity->entityName().c_str());
    EXPECT_STREQ(L"Hehe", pDestEntity->asString(L"Val").c_str());
    //    delete pSrcEntity;
}

TEST(TestGFCFrom2, attributeToProperty_enum)
{
    GfcFrom2_Test oTransform;
    gfc::schema::CModel oSrcModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oSrcModel);
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Project"));
    pSrcEntity->setAsInteger(L"StructureType", 2021521);
    //pSrcEntity->setAsString(L"Name", L"中国");

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto pProp = pSrcEntity->propByName(L"StructureType");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2IntegerProperty", pDestEntity->entityName().c_str());
    EXPECT_EQ(2021521, pDestEntity->asInteger(L"Val"));
    EXPECT_STREQ(L"StructureType", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

TEST(TestGFCFrom2, attributeToProperty_ref_string)
{
    gfc::schema::CModel oSrcModel;
    CDocument oSrcDoc(&oSrcModel);
    CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oSrcModel);
    EntityPtr pSrcString = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2String"));
    pSrcString->setAsString(L"Value", L"Test");
    auto nRef = oSrcDoc.add(pSrcString);
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Project"));
    pSrcEntity->setAsEntityRef(L"Name", nRef);
    //pSrcEntity->setAsString(L"Name", L"中国");

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    GfcFrom2_Test oTransform(&oSrcDoc);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto pProp = pSrcEntity->propByName(L"Name");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2StringProperty", pDestEntity->entityName().c_str());
    EXPECT_STREQ(L"Test", pDestEntity->asString(L"Val").c_str());
    EXPECT_STREQ(L"Name", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

class CMockTestWriter : public CMockWriter
{
public:
    CMockTestWriter() {}
    virtual ~CMockTestWriter() {}

    virtual bool open(const std::wstring& sFileName, const std::wstring& sFormatType) { return true; }
    virtual void close() {}
    virtual bool isOpen() { return true; }
    virtual EntityRef writeEntity(CEntity* pEntity) {
        //auto pRefEntity = pEntity->asEntityRef(L"Val");
        EXPECT_NE(nullptr, pEntity);
        EXPECT_STREQ(L"Gfc2PropertySet", pEntity->entityName().c_str());
        EXPECT_STREQ(L"Test", pEntity->asString(L"Name").c_str());
        return CMockWriter::writeEntity(pEntity);
    }
};

TEST(TestGFCFrom2, attributeToProperty_ref_object_1)
{
    gfc::schema::CModel oSrcModel;
    CDocument oSrcDoc(&oSrcModel);
    CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oSrcModel);
    EntityPtr pSrcString = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2String"));
    pSrcString->setAsString(L"Value", L"Test");
    auto nStrRef = oSrcDoc.add(pSrcString);
    EntityPtr pSrcPropertySet = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2PropertySet"));
    pSrcPropertySet->setAsEntityRef(L"Name", nStrRef);
    auto nRef = oSrcDoc.add(pSrcPropertySet);
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor"));
    pSrcEntity->setAsEntityRef(L"EntAseismicGrade", nRef);
    //pSrcEntity->setAsString(L"Name", L"中国");

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    CMockTestWriter oWriter;

    GfcFrom2_Test oTransform(&oSrcDoc);
    oTransform.setWriter(&oWriter);
    oTransform.setSchema(&oSrcModel, &oDestModel);

    auto pProp = pSrcEntity->propByName(L"EntAseismicGrade");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2EntityProperty", pDestEntity->entityName().c_str());
    EXPECT_EQ(1, pDestEntity->asEntityRef(L"Val"));
    EXPECT_STREQ(L"EntAseismicGrade", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

class CMockTestWriter2 : public CMockWriter
{
public:
    CMockTestWriter2() {}
    virtual ~CMockTestWriter2() {}

    virtual bool open(const std::wstring& sFileName, const std::wstring& sFormatType) { return true; }
    virtual void close() {}
    virtual bool isOpen() { return true; }
    virtual EntityRef writeEntity(CEntity* pEntity) {
        //auto pRefEntity = pEntity->asEntityRef(L"Val");
        EXPECT_NE(nullptr, pEntity);
        EXPECT_STREQ(L"Gfc2Object", pEntity->entityName().c_str());
        return CMockWriter::writeEntity(pEntity);
    }
};

TEST(TestGFCFrom2, attributeToProperty_ref_object_2)
{
    gfc::schema::CModel oSrcModel;
    CDocument oSrcDoc(&oSrcModel);
    CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oSrcModel);
    EntityPtr pSrcPropertySet = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Entity"));
    auto nRef = oSrcDoc.add(pSrcPropertySet);
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2RelDefinesByElement"));
    pSrcEntity->setAsEntityRef(L"RelatingElement", nRef);
    //pSrcEntity->setAsString(L"Name", L"中国");

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    CMockTestWriter2 oWriter;

    GfcFrom2_Test oTransform(&oSrcDoc);
    oTransform.setWriter(&oWriter);
    oTransform.setSchema(&oSrcModel, &oDestModel);

    auto pProp = pSrcEntity->propByName(L"RelatingElement");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2EntityProperty", pDestEntity->entityName().c_str());
    EXPECT_EQ(1, pDestEntity->asEntityRef(L"Val"));
    //EXPECT_STREQ(L"RelatingElement", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

// 对象属性转为Property对象
TEST(TestGFCFrom2, attributeToProperty_int_array)
{
    GfcFrom2_Test oTransform;
    gfc::schema::CModel oSrcModel;
    {
        auto pClass = new gfc::schema::CClass;
        pClass->SetName(L"Gfc2Test");
        auto pAttribute = new gfc::schema::CAttribute;
        pAttribute->SetName(L"field1");
        pAttribute->SetRepeatFlag(true);
        pAttribute->SetType(oSrcModel.getTypeObject(1));
        pClass->addAttribute(pAttribute);
        oSrcModel.addTypeObject(pClass);
    }
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Test"));
    pSrcEntity->addInteger(L"field1", 1);
    pSrcEntity->addInteger(L"field1", 12);
    pSrcEntity->addInteger(L"field1", 14);
    pSrcEntity->addInteger(L"field1", 21);
    //pSrcEntity->setAsString(L"Name", L"中国");

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto pProp = pSrcEntity->propByName(L"field1");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2IntegerListProperty", pDestEntity->entityName().c_str());
    auto pValues = pDestEntity->valueByName(L"Values");
    EXPECT_NE(nullptr, pValues);
    EXPECT_EQ(4, pValues->getCount());
    EXPECT_EQ(1, pValues->getItems(0)->asInteger());
    EXPECT_EQ(12, pValues->getItems(1)->asInteger());
    EXPECT_EQ(14, pValues->getItems(2)->asInteger());
    EXPECT_EQ(21, pValues->getItems(3)->asInteger());
    EXPECT_STREQ(L"field1", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

TEST(TestGFCFrom2, attributeToProperty_bool_array)
{
    GfcFrom2_Test oTransform;
    gfc::schema::CModel oSrcModel;
    {
        auto pClass = new gfc::schema::CClass;
        pClass->SetName(L"Gfc2Test");
        auto pAttribute = new gfc::schema::CAttribute;
        pAttribute->SetName(L"field1");
        pAttribute->SetRepeatFlag(true);
        pAttribute->SetType(oSrcModel.getTypeObject(0)); // bool
        pClass->addAttribute(pAttribute);
        oSrcModel.addTypeObject(pClass);
    }
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Test"));
    pSrcEntity->addBoolean(L"field1", true);
    pSrcEntity->addBoolean(L"field1", false);
    pSrcEntity->addBoolean(L"field1", false);
    pSrcEntity->addBoolean(L"field1", true);
    //pSrcEntity->setAsString(L"Name", L"中国");

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto pProp = pSrcEntity->propByName(L"field1");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2BooleanListProperty", pDestEntity->entityName().c_str());
    auto pValues = pDestEntity->valueByName(L"Values");
    EXPECT_NE(nullptr, pValues);
    EXPECT_EQ(4, pValues->getCount());
    EXPECT_EQ(true, pValues->getItems(0)->asBoolean());
    EXPECT_EQ(false, pValues->getItems(1)->asBoolean());
    EXPECT_EQ(false, pValues->getItems(2)->asBoolean());
    EXPECT_EQ(true, pValues->getItems(3)->asBoolean());
    EXPECT_STREQ(L"field1", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

TEST(TestGFCFrom2, attributeToProperty_double_array)
{
    GfcFrom2_Test oTransform;
    gfc::schema::CModel oSrcModel;
    {
        auto pClass = new gfc::schema::CClass;
        pClass->SetName(L"Gfc2Test");
        auto pAttribute = new gfc::schema::CAttribute;
        pAttribute->SetName(L"field1");
        pAttribute->SetRepeatFlag(true);
        pAttribute->SetType(oSrcModel.getTypeObject(2)); // bool
        pClass->addAttribute(pAttribute);
        oSrcModel.addTypeObject(pClass);
    }
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Test"));
    pSrcEntity->addDouble(L"field1", 0.123);
    pSrcEntity->addDouble(L"field1", 12.3);
    pSrcEntity->addDouble(L"field1", 324);
    pSrcEntity->addDouble(L"field1", 2324.678);
    //pSrcEntity->setAsString(L"Name", L"中国");

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto pProp = pSrcEntity->propByName(L"field1");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2DoubleListProperty", pDestEntity->entityName().c_str());
    auto pValues = pDestEntity->valueByName(L"Values");
    EXPECT_NE(nullptr, pValues);
    EXPECT_EQ(4, pValues->getCount());
    EXPECT_NEAR(0.123, pValues->getItems(0)->asDouble(), 1e-7);
    EXPECT_NEAR(12.3, pValues->getItems(1)->asDouble(), 1e-7);
    EXPECT_NEAR(324, pValues->getItems(2)->asDouble(), 1e-7);
    EXPECT_NEAR(2324.678, pValues->getItems(3)->asDouble(), 1e-7);
    EXPECT_STREQ(L"field1", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

TEST(TestGFCFrom2, attributeToProperty_string_array)
{
    GfcFrom2_Test oTransform;
    gfc::schema::CModel oSrcModel;
    {
        auto pClass = new gfc::schema::CClass;
        pClass->SetName(L"Gfc2Test");
        auto pAttribute = new gfc::schema::CAttribute;
        pAttribute->SetName(L"field1");
        pAttribute->SetRepeatFlag(true);
        pAttribute->SetType(oSrcModel.getTypeObject(3)); // bool
        pClass->addAttribute(pAttribute);
        oSrcModel.addTypeObject(pClass);
    }
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Test"));
    pSrcEntity->addString(L"field1", L"abc");
    pSrcEntity->addString(L"field1", L"红领巾");
    pSrcEntity->addString(L"field1", L"hehe");
    pSrcEntity->addString(L"field1", L"中国");

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto pProp = pSrcEntity->propByName(L"field1");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2StringListProperty", pDestEntity->entityName().c_str());
    auto pValues = pDestEntity->valueByName(L"Values");
    EXPECT_NE(nullptr, pValues);
    EXPECT_EQ(4, pValues->getCount());
    EXPECT_STREQ(L"abc", pValues->getItems(0)->asString().c_str());
    EXPECT_STREQ(L"红领巾", pValues->getItems(1)->asString().c_str());
    EXPECT_STREQ(L"hehe", pValues->getItems(2)->asString().c_str());
    EXPECT_STREQ(L"中国", pValues->getItems(3)->asString().c_str());
    EXPECT_STREQ(L"field1", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

TEST(TestGFCFrom2, attributeToProperty_enum_array)
{
    GfcFrom2_Test oTransform;
    gfc::schema::CModel oSrcModel;
    {
        auto pEnum = new gfc::schema::CEnumType(L"Gfc2Enum");
        pEnum->addEnum(L"a", L"");
        pEnum->addEnum(L"B", L"");
        pEnum->addEnum(L"c", L"");
        oSrcModel.addTypeObject(pEnum);

        auto pClass = new gfc::schema::CClass;
        pClass->SetName(L"Gfc2Test");
        auto pAttribute = new gfc::schema::CAttribute;
        pAttribute->SetName(L"field1");
        pAttribute->SetRepeatFlag(true);
        pAttribute->SetType(pEnum);
        pClass->addAttribute(pAttribute);
        oSrcModel.addTypeObject(pClass);
    }
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Test"));
    pSrcEntity->addInteger(L"field1", 1);
    pSrcEntity->addInteger(L"field1", 0);
    pSrcEntity->addInteger(L"field1", 2);
    pSrcEntity->addInteger(L"field1", 1);

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto pProp = pSrcEntity->propByName(L"field1");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2IntegerListProperty", pDestEntity->entityName().c_str());
    auto pValues = pDestEntity->valueByName(L"Values");
    EXPECT_NE(nullptr, pValues);
    EXPECT_EQ(4, pValues->getCount());
    EXPECT_EQ(1, pValues->getItems(0)->asInteger());
    EXPECT_EQ(0, pValues->getItems(1)->asInteger());
    EXPECT_EQ(2, pValues->getItems(2)->asInteger());
    EXPECT_EQ(1, pValues->getItems(3)->asInteger());
    EXPECT_STREQ(L"field1", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

TEST(TestGFCFrom2, attributeToProperty_ref_string_array)
{
    gfc::schema::CModel oSrcModel;
    {
        auto pString = new gfc::schema::CClass;
        pString->SetName(L"Gfc2String");
        {
            auto pAttribute = new gfc::schema::CAttribute;
            pAttribute->SetName(L"Value");
            pAttribute->SetType(oSrcModel.getTypeObject(3)); // string
            pString->addAttribute(pAttribute);
        }
        oSrcModel.addTypeObject(pString);

        auto pLabel = new gfc::schema::CTypeDef(L"Gfc2Label");
        pLabel->SetRefType(pString);
        oSrcModel.addTypeObject(pLabel);

        auto pClass = new gfc::schema::CClass;
        pClass->SetName(L"Gfc2Test");
        auto pAttribute = new gfc::schema::CAttribute;
        pAttribute->SetName(L"field1");
        pAttribute->SetRepeatFlag(true);
        pAttribute->SetType(pLabel);
        pClass->addAttribute(pAttribute);
        oSrcModel.addTypeObject(pClass);
    }
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Test"));
    CDocument oSrcDoc(&oSrcModel);
    {
        EntityPtr pSrcLabel1 = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label"));
        pSrcLabel1->setAsString(L"Value", L"abc");
        pSrcEntity->addEntityRef(L"field1", oSrcDoc.add(pSrcLabel1));
    }
    {
        EntityPtr pSrcLabel1 = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label"));
        pSrcLabel1->setAsString(L"Value", L"红领巾");
        pSrcEntity->addEntityRef(L"field1", oSrcDoc.add(pSrcLabel1));
    }
    {
        EntityPtr pSrcLabel1 = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label"));
        pSrcLabel1->setAsString(L"Value", L"hehe");
        pSrcEntity->addEntityRef(L"field1", oSrcDoc.add(pSrcLabel1));
    }
    {
        EntityPtr pSrcLabel1 = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Label"));
        pSrcLabel1->setAsString(L"Value", L"中国");
        pSrcEntity->addEntityRef(L"field1", oSrcDoc.add(pSrcLabel1));
    }

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);

    GfcFrom2_Test oTransform(&oSrcDoc);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto pProp = pSrcEntity->propByName(L"field1");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2StringListProperty", pDestEntity->entityName().c_str());
    auto pValues = pDestEntity->valueByName(L"Values");
    EXPECT_NE(nullptr, pValues);
    EXPECT_EQ(4, pValues->getCount());
    EXPECT_STREQ(L"abc", pValues->getItems(0)->asString().c_str());
    EXPECT_STREQ(L"红领巾", pValues->getItems(1)->asString().c_str());
    EXPECT_STREQ(L"hehe", pValues->getItems(2)->asString().c_str());
    EXPECT_STREQ(L"中国", pValues->getItems(3)->asString().c_str());
    EXPECT_STREQ(L"field1", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

class CMockWriter_ref_obj_array_1 : public CMockWriter
{
public:
    CMockWriter_ref_obj_array_1(): m_nCount(0) {}
    virtual bool open(const std::wstring& sFileName, const std::wstring& sFormatType) { return true; }
    virtual void close() {}
    virtual bool isOpen() { return true; }
    virtual EntityRef writeEntity(CEntity* pEntity) {
        //auto pRefEntity = pEntity->asEntityRef(L"Val");
        EXPECT_NE(nullptr, pEntity);
        EXPECT_STREQ(L"Gfc2PropertySet", pEntity->entityName().c_str());
        switch (m_nCount)
        {
        case 0: EXPECT_STREQ(L"abc", pEntity->asString(L"Name").c_str());
            break;
        case 1: EXPECT_STREQ(L"红领巾", pEntity->asString(L"Name").c_str());
            break;
        case 2: EXPECT_STREQ(L"hehe", pEntity->asString(L"Name").c_str());
            break;
        case 3: EXPECT_STREQ(L"中国", pEntity->asString(L"Name").c_str());
            break;
        default:
            assert(false);
        }
        ++m_nCount;
        return CMockWriter::writeEntity(pEntity);
    }
private:
    int m_nCount;
};

TEST(TestGFCFrom2, attributeToProperty_ref_obj_array_1)
{
    gfc::schema::CModel oSrcModel;
    {
        auto pPropertySet = new gfc::schema::CClass(L"Gfc2PropertySet");
        {
            auto pAttribute = new gfc::schema::CAttribute;
            pAttribute->SetName(L"Name");
            pAttribute->SetType(oSrcModel.getTypeObject(3));
            pPropertySet->addAttribute(pAttribute);
        }
        oSrcModel.addTypeObject(pPropertySet);

        auto pClass = new gfc::schema::CClass;
        pClass->SetName(L"Gfc2Test");
        auto pAttribute = new gfc::schema::CAttribute;
        pAttribute->SetName(L"field1");
        pAttribute->SetRepeatFlag(true);
        pAttribute->SetType(pPropertySet);
        pClass->addAttribute(pAttribute);
        oSrcModel.addTypeObject(pClass);
    }
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Test"));
    CDocument oSrcDoc(&oSrcModel);
    {
        EntityPtr pSrcObject1 = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2PropertySet"));
        pSrcObject1->setAsString(L"Name", L"abc");
        pSrcEntity->addEntityRef(L"field1", oSrcDoc.add(pSrcObject1));
    }
    {
        EntityPtr pSrcObject1 = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2PropertySet"));
        pSrcObject1->setAsString(L"Name", L"红领巾");
        pSrcEntity->addEntityRef(L"field1", oSrcDoc.add(pSrcObject1));
    }
    {
        EntityPtr pSrcObject1 = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2PropertySet"));
        pSrcObject1->setAsString(L"Name", L"hehe");
        pSrcEntity->addEntityRef(L"field1", oSrcDoc.add(pSrcObject1));
    }
    {
        EntityPtr pSrcObject1 = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2PropertySet"));
        pSrcObject1->setAsString(L"Name", L"中国");
        pSrcEntity->addEntityRef(L"field1", oSrcDoc.add(pSrcObject1));
    }

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);

    GfcFrom2_Test oTransform(&oSrcDoc);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    CMockWriter_ref_obj_array_1 oWriter;
    oTransform.setWriter(&oWriter);
    auto pProp = pSrcEntity->propByName(L"field1");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2EntityListProperty", pDestEntity->entityName().c_str());
    auto pValues = pDestEntity->valueByName(L"Values");
    EXPECT_NE(nullptr, pValues);
    EXPECT_EQ(4, pValues->getCount());
    //EXPECT_STREQ(L"abc", pValues->getItems(0)->asString().c_str());
    //EXPECT_STREQ(L"红领巾", pValues->getItems(1)->asString().c_str());
    //EXPECT_STREQ(L"hehe", pValues->getItems(2)->asString().c_str());
    //EXPECT_STREQ(L"中国", pValues->getItems(3)->asString().c_str());
    EXPECT_STREQ(L"field1", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CMockWriter_ref_obj_array_2 : public CMockWriter
{
public:
    virtual bool open(const std::wstring& sFileName, const std::wstring& sFormatType) { return true; }
    virtual void close() {}
    virtual bool isOpen() { return true; }
    virtual EntityRef writeEntity(CEntity* pEntity) {
        //auto pRefEntity = pEntity->asEntityRef(L"Val");
        EXPECT_NE(nullptr, pEntity);
        EXPECT_STREQ(L"Gfc2Object", pEntity->entityName().c_str());
        return CMockWriter::writeEntity(pEntity);
    }
};

TEST(TestGFCFrom2, attributeToProperty_ref_obj_array_2)
{
    gfc::schema::CModel oSrcModel;
    {
        auto pXClass = new gfc::schema::CClass(L"Gfc2XXX");
        oSrcModel.addTypeObject(pXClass);

        auto pClass = new gfc::schema::CClass;
        pClass->SetName(L"Gfc2Test");
        auto pAttribute = new gfc::schema::CAttribute;
        pAttribute->SetName(L"field1");
        pAttribute->SetRepeatFlag(true);
        pAttribute->SetType(pXClass);
        pClass->addAttribute(pAttribute);
        oSrcModel.addTypeObject(pClass);
    }
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Test"));
    CDocument oSrcDoc(&oSrcModel);
    {
        EntityPtr pSrcObject1 = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2XXX"));
        pSrcEntity->addEntityRef(L"field1", oSrcDoc.add(pSrcObject1));
    }
    {
        EntityPtr pSrcObject1 = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2XXX"));
        pSrcEntity->addEntityRef(L"field1", oSrcDoc.add(pSrcObject1));
    }
    {
        EntityPtr pSrcObject1 = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2XXX"));
        pSrcEntity->addEntityRef(L"field1", oSrcDoc.add(pSrcObject1));
    }
    {
        EntityPtr pSrcObject1 = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2XXX"));
        pSrcEntity->addEntityRef(L"field1", oSrcDoc.add(pSrcObject1));
    }

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);

    GfcFrom2_Test oTransform(&oSrcDoc);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    CMockWriter_ref_obj_array_2 oWriter;
    oTransform.setWriter(&oWriter);
    auto pProp = pSrcEntity->propByName(L"field1");
    auto pDestEntity = oTransform.attributeToProperty(pProp);
    EXPECT_STREQ(L"Gfc2EntityListProperty", pDestEntity->entityName().c_str());
    auto pValues = pDestEntity->valueByName(L"Values");
    EXPECT_NE(nullptr, pValues);
    EXPECT_EQ(4, pValues->getCount());
    //EXPECT_STREQ(L"abc", pValues->getItems(0)->asString().c_str());
    //EXPECT_STREQ(L"红领巾", pValues->getItems(1)->asString().c_str());
    //EXPECT_STREQ(L"hehe", pValues->getItems(2)->asString().c_str());
    //EXPECT_STREQ(L"中国", pValues->getItems(3)->asString().c_str());
    EXPECT_STREQ(L"field1", pDestEntity->asString(L"Name").c_str());
    //    delete pSrcEntity;
}

class CMockWriter_entityToObject : public CMockWriter
{
public:
    virtual bool open(const std::wstring& sFileName, const std::wstring& sFormatType) { return true; }
    virtual void close() {}
    virtual bool isOpen() { return true; }
    virtual EntityRef writeEntity(CEntity* pEntity) {
        //auto pRefEntity = pEntity->asEntityRef(L"Val");
        EXPECT_NE(nullptr, pEntity);
        EXPECT_STREQ(L"Gfc2Object", pEntity->entityName().c_str());
        EXPECT_STREQ(L"Gfc2XXX", pEntity->asString(L"Name").c_str());
        return CMockWriter::writeEntity(pEntity);
    }
};

TEST(TestGFCFrom2, entityToObject)
{
    gfc::schema::CModel oSrcModel;
    {
        auto pXClass = new gfc::schema::CClass(L"Gfc2XXX");
        oSrcModel.addTypeObject(pXClass);
    }
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2XXX"));

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);

    GfcFrom2_Test oTransform;
    oTransform.setSchema(&oSrcModel, &oDestModel);
    CMockWriter_entityToObject oWriter;
    oTransform.setWriter(&oWriter);
    auto nRef = oTransform.entityToObject(pSrcEntity);
    EXPECT_EQ(1, nRef);
}

class CMockWriter_entityToObject_1 : public CMockWriter
{
public:
    CMockWriter_entityToObject_1(): m_nCount(0) {}
    virtual bool open(const std::wstring& sFileName, const std::wstring& sFormatType) { return true; }
    virtual void close() {}
    virtual bool isOpen() { return true; }
    virtual EntityRef writeEntity(CEntity* pEntity) {
        //auto pRefEntity = pEntity->asEntityRef(L"Val");
        EXPECT_NE(nullptr, pEntity);
        if (m_nCount == 0)
        {
            EXPECT_STREQ(L"Gfc2Object", pEntity->entityName().c_str());
            EXPECT_STREQ(L"Gfc2Test", pEntity->asString(L"Name").c_str());
        }
        else if (m_nCount == 1)
        {
            EXPECT_STREQ(L"Gfc2BooleanProperty", pEntity->entityName().c_str());
            EXPECT_STREQ(L"field1", pEntity->asString(L"Name").c_str());
            EXPECT_EQ(true, pEntity->asBoolean(L"Val"));
        }
        else if (m_nCount == 2)
        {
            EXPECT_STREQ(L"Gfc2IntegerProperty", pEntity->entityName().c_str());
            EXPECT_STREQ(L"field2", pEntity->asString(L"Name").c_str());
            EXPECT_EQ(123, pEntity->asInteger(L"Val"));
        }
        else if (m_nCount == 3)
        {
            EXPECT_STREQ(L"Gfc2PropertySet", pEntity->entityName().c_str());
        }
        else
        {
            EXPECT_STREQ(L"Gfc2RelDefinesByProperties", pEntity->entityName().c_str());
            EXPECT_EQ(4, pEntity->asEntityRef(L"RelatingPropertySet"));
            EXPECT_EQ(1, pEntity->getArrayCount(L"RelatedObjects"));
            EXPECT_EQ(1, pEntity->getEntityRef(L"RelatedObjects", 0));
        }
        ++m_nCount;
        return CMockWriter::writeEntity(pEntity);
    }
private:
    int m_nCount;
};

TEST(TestGFCFrom2, entityToObject_1)
{
    gfc::schema::CModel oSrcModel;
    {
        auto pClass = new gfc::schema::CClass;
        pClass->SetName(L"Gfc2Test");
        {
            auto pAttribute = new gfc::schema::CAttribute;
            pAttribute->SetName(L"field1");
            pAttribute->SetType(oSrcModel.getTypeObject(0));
            pClass->addAttribute(pAttribute);
        }
        {
            auto pAttribute = new gfc::schema::CAttribute;
            pAttribute->SetName(L"field2");
            pAttribute->SetType(oSrcModel.getTypeObject(1));
            pClass->addAttribute(pAttribute);
        }
        oSrcModel.addTypeObject(pClass);
    }
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Test"));
    pSrcEntity->setAsBoolean(L"field1", true);
    pSrcEntity->setAsInteger(L"field2", 123);

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);

    GfcFrom2_Test oTransform;
    oTransform.setSchema(&oSrcModel, &oDestModel);
    CMockWriter_entityToObject_1 oWriter;
    oTransform.setWriter(&oWriter);
    auto nRef = oTransform.entityToObject(pSrcEntity);
    EXPECT_EQ(1, nRef);
}

TEST(TestGFCFrom2, transformProject)
{
    gfc::schema::CModel oSrcModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oSrcModel);
    EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Project"));
    pSrcEntity->setAsInteger(L"ID", 2021521);

    gfc::engine::CDocument oSrcDoc(&oSrcModel);
    oSrcDoc.add(pSrcEntity);

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);

    CMockWriter oWriter;
    GfcFrom2_Test oTransform(&oSrcDoc);
    oTransform.setWriter(&oWriter);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto nRef = oTransform.transformProject();
    EXPECT_EQ(1, nRef);
}

TEST(TestGFCFrom2, transformBuilding)
{
    gfc::schema::CModel oSrcModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oSrcModel);
    gfc::engine::CDocument oSrcDoc(&oSrcModel);

    {
        EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Project"));
        pSrcEntity->setAsInteger(L"ID", 2021521);
        oSrcDoc.add(pSrcEntity);
    }
    {
        EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building"));
        pSrcEntity->setAsInteger(L"ID", 11);
        oSrcDoc.add(pSrcEntity);
    }
    {
        EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building"));
        pSrcEntity->setAsInteger(L"ID", 12);
        oSrcDoc.add(pSrcEntity);
    }
    {
        EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2RelAggregates"));
        pSrcEntity->setAsEntityRef(L"RelatingObject", 1);
        pSrcEntity->addEntityRef(L"RelatedObjects", 2);
        pSrcEntity->addEntityRef(L"RelatedObjects", 3);
        oSrcDoc.add(pSrcEntity);
    }

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);

    CMockWriter oWriter;
    GfcFrom2_Test oTransform(&oSrcDoc);
    oTransform.setWriter(&oWriter);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    auto oMap = oTransform.transformBuilding(1);
    EXPECT_EQ(1, oMap[2]); // 没有导入project
    EXPECT_EQ(2, oMap[3]);
}

TEST(TestGFCFrom2, transformFloor)
{
    gfc::schema::CModel oSrcModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC2X0.exp"), &oSrcModel);
    gfc::engine::CDocument oSrcDoc(&oSrcModel);

    {
        EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Project"));
        pSrcEntity->setAsInteger(L"ID", 2021521);
        oSrcDoc.add(pSrcEntity);
    }
    {
        EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building"));
        pSrcEntity->setAsInteger(L"ID", 11);
        oSrcDoc.add(pSrcEntity);
    }
    {
        EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Building"));
        pSrcEntity->setAsInteger(L"ID", 12);
        oSrcDoc.add(pSrcEntity);
    }
    {
        EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor"));
        pSrcEntity->setAsInteger(L"ID", 21);
        oSrcDoc.add(pSrcEntity);
    }
    {
        EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor"));
        pSrcEntity->setAsInteger(L"ID", 22);
        oSrcDoc.add(pSrcEntity);
    }
    {
        EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2RelAggregates"));
        pSrcEntity->setAsEntityRef(L"RelatingObject", 2);
        pSrcEntity->addEntityRef(L"RelatedObjects", 4);
        pSrcEntity->addEntityRef(L"RelatedObjects", 5);
        oSrcDoc.add(pSrcEntity);
    }
    {
        EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2Floor"));
        pSrcEntity->setAsInteger(L"ID", 23);
        oSrcDoc.add(pSrcEntity);
    }
    {
        EntityPtr pSrcEntity = EntityPtr(CEngineUtils::createEntity(&oSrcModel, L"Gfc2RelAggregates"));
        pSrcEntity->setAsEntityRef(L"RelatingObject", 3);
        pSrcEntity->addEntityRef(L"RelatedObjects", 7);
        oSrcDoc.add(pSrcEntity);
    }

    gfc::schema::CModel oDestModel;
    CEngineUtils::loadSchema(getFullPath(L"GFC3X0.exp"), &oDestModel);

    CMockWriter oWriter;
    GfcFrom2_Test oTransform(&oSrcDoc);
    oTransform.setWriter(&oWriter);
    oTransform.setSchema(&oSrcModel, &oDestModel);
    GfcFrom2::GfcEntityRefMap oMap;
    oMap[2] = 102;
    oMap[3] = 103;
    auto oMap1 = oTransform.transformFloor(oMap);
    EXPECT_EQ(1, oMap1[4]); // 没有导入project
    EXPECT_EQ(2, oMap1[5]);
    EXPECT_EQ(3, oMap1[7]);
}