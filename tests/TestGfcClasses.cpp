#include "gtest\gtest.h"
#include "GfcEngine\Entity.h"
#include "GfcEngine\EngineException.h"
#include "GfcEngine\PropValue.h"
#include "GfcEngine\Document.h"
#include "Common.h"
#include "GfcSchema/Model.h"
#include "GfcSchema/EntityClass.h"
#include "GfcSchema/EntityAttribute.h"
#include "GfcSchema/BuildinType.h"
#include "GfcSchema/TypeDefine.h"
#include "GfcClasses\x3\GfcVector2d.h"
#include "GfcClasses\x3\GfcFloor.h"
#include "GfcClasses\x3\GfcElement.h"
#include "GfcClasses\x3\GfcSphereShape.h"
#include "GfcEngine\GfcEngineUtils.h"

using namespace gfc::classes::x3;

TEST(TestGfcClasses, Entity_create)
{
    GfcVector2d vec;
    EXPECT_NEAR(0.0, vec.getX(), 1e-7);
    EXPECT_NEAR(0.0, vec.getY(), 1e-7);
    EXPECT_EQ(false, vec.hasX());
    EXPECT_EQ(false, vec.hasY());
}

TEST(TestGfcClasses, Entity_set_double)
{
    GfcVector2d vec;
    vec.setX(25);
    vec.setY(2.5);
    EXPECT_NEAR(25, vec.getX(), 1e-7);
    EXPECT_EQ(true, vec.hasX());

    EXPECT_NEAR(2.5, vec.getY(), 1e-7);
    EXPECT_EQ(true, vec.hasY());
}

TEST(TestGfcClasses, Floor_create)
{
    GfcFloor obj;
    EXPECT_STREQ(L"", obj.getID().c_str());
    EXPECT_EQ(0, obj.getStdFloorCount());
}

TEST(TestGfcClasses, Floor_set_get)
{
    GfcFloor obj;
    obj.setID(L"中华人民共和国");
    EXPECT_STREQ(L"中华人民共和国", obj.getID().c_str());
    obj.setStdFloorCount(12);
    EXPECT_EQ(12, obj.getStdFloorCount());
}

TEST(TestGfcClasses, Element_get)
{
    GfcElement obj;
    EXPECT_EQ(0, obj.getShapesCount());
}

TEST(TestGfcClasses, Element_add)
{
    GfcElement obj;
    obj.addShapes(1000);
    EXPECT_EQ(1, obj.getShapesCount());
    EXPECT_EQ(1000, obj.getShapes(0));
}

#include "GfcClasses\x3\GfcElementShape.h"
#include "GfcClasses\x3\Reader.h"
#include "GfcClasses\x3\Writer.h"
#include "GfcClasses\x3\GfcSimpleLoop.h"

TEST(TestGfcClasses, write_document)
{
    //auto pFactory = gfc::engine::CEngineUtils::createFactory(getFullPath(L"GFC3X0.exp"));
    CWriter oWriter;
    auto result = oWriter.open(getFullPath(L"test.gfc"), L"express");
    GfcSphereShape oShape;
    oShape.setRadius(101.0);
    auto nShapeRef = oWriter.writeEntity(&oShape);
    GfcElementShape oElementShape;
    oElementShape.setShape(nShapeRef);
    auto nElementShapeRef = oWriter.writeEntity(&oElementShape);
    GfcElement oElement;
    oElement.addShapes(nElementShapeRef);
    oWriter.writeEntity(&oElement);
    oWriter.close();
    EXPECT_EQ(true, result);
}

TEST(TestGfcClasses, read_document)
{
    CReader oReader;
    oReader.open(getFullPath(L"test.gfc"));
    auto itr = oReader.getEntities(L"GfcElement");
    itr->first();
    EXPECT_EQ(false, itr->isDone());
    auto pElement = std::dynamic_pointer_cast<GfcElement>(itr->current());
    EXPECT_EQ(true, pElement != nullptr);
    EXPECT_EQ(1, pElement->getShapesCount());
    auto pElementShape = pElement->getShapesPtr(0);
    EXPECT_EQ(true, pElementShape != nullptr);
    auto pShape = std::dynamic_pointer_cast<GfcSphereShape>(pElementShape->getShapePtr());
    EXPECT_EQ(true, pShape != nullptr);
    EXPECT_NEAR(101, pShape->getRadius(), 1e-7);
    itr->next();
    EXPECT_EQ(true, itr->isDone());
}

/*
#include "GfcClasses\x3\Gfc2ArbitrarySection.h"
#include "GfcUtils\GfcGeometryImporter.h"
#include "GfcGeometryImporterOld.h"

TEST(TestGfcClasses, ReadFile_1)
{
    GfcReader oReader;
    oReader.open(getFullPath(L"边缘填充-暗柱.rvt.gfc"));
    auto itr = oReader.getEntities(L"Gfc2ArbitrarySection");
    itr->first();
    EXPECT_EQ(false, itr->isDone());
    auto pAbnormitySection = std::dynamic_pointer_cast<Gfc2ArbitrarySection>(itr->current());
    ggp::CPolygonPtr pPoly = GfcGeometryImporterOld::importPolygon(pAbnormitySection->getPolyPtr().get());
    EXPECT_EQ(true, pPoly != nullptr);
}
*/