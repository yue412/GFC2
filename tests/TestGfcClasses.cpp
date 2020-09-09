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
#include "Gfc2Vector2d.h"
#include "Gfc2Floor.h"
#include "Gfc2Element.h"
#include "Gfc2SphereShape.h"
#include "GfcEngine\GfcEngineUtils.h"

using namespace gfc::classes::x3;

TEST(TestGfcClasses, Entity_create)
{
    Gfc2Vector2d vec;
    EXPECT_NEAR(0.0, vec.getX(), 1e-7);
    EXPECT_NEAR(0.0, vec.getY(), 1e-7);
    EXPECT_EQ(false, vec.hasX());
    EXPECT_EQ(false, vec.hasY());
}

TEST(TestGfcClasses, Entity_set_double)
{
    Gfc2Vector2d vec;
    vec.setX(25);
    vec.setY(2.5);
    EXPECT_NEAR(25, vec.getX(), 1e-7);
    EXPECT_EQ(true, vec.hasX());

    EXPECT_NEAR(2.5, vec.getY(), 1e-7);
    EXPECT_EQ(true, vec.hasY());
}

TEST(TestGfcClasses, Floor_create)
{
    Gfc2Floor obj;
    EXPECT_STREQ(L"", obj.getID().c_str());
    EXPECT_EQ(0, obj.getStdFloorCount());
}

TEST(TestGfcClasses, Floor_set_get)
{
    Gfc2Floor obj;
    obj.setID(L"中华人民共和国");
    EXPECT_STREQ(L"中华人民共和国", obj.getID().c_str());
    obj.setStdFloorCount(12);
    EXPECT_EQ(12, obj.getStdFloorCount());
}

TEST(TestGfcClasses, Element_get)
{
    Gfc2Element obj;
    EXPECT_EQ(0, obj.getShapesCount());
}

TEST(TestGfcClasses, Element_add)
{
    Gfc2Element obj;
    obj.addShapes(1000);
    EXPECT_EQ(1, obj.getShapesCount());
    EXPECT_EQ(1000, obj.getShapes(0));
}

#include "Gfc2ElementShape.h"
#include "GfcReader.h"
#include "GfcWriter.h"

TEST(TestGfcClasses, write_document)
{
    //auto pFactory = gfc::engine::CEngineUtils::createFactory(getFullPath(L"GFC3X0.exp"));
    GfcWriter oWriter;
    auto result = oWriter.open(getFullPath(L"test.gfc"), L"express");
    Gfc2SphereShape oShape;
    oShape.setRadius(101.0);
    auto nShapeRef = oWriter.writeEntity(&oShape);
    Gfc2ElementShape oElementShape;
    oElementShape.setShape(nShapeRef);
    auto nElementShapeRef = oWriter.writeEntity(&oElementShape);
    Gfc2Element oElement;
    oElement.addShapes(nElementShapeRef);
    oWriter.writeEntity(&oElement);
    oWriter.close();
    EXPECT_EQ(true, result);
}

TEST(TestGfcClasses, read_document)
{
    GfcReader oReader;
    oReader.open(getFullPath(L"test.gfc"));
    auto itr = oReader.getEntities(L"Gfc2Element");
    itr->first();
    EXPECT_EQ(false, itr->isDone());
    auto pElement = gfc::engine::dynamic_entity_cast<Gfc2Element>(itr->current());
    EXPECT_EQ(true, pElement != nullptr);
    EXPECT_EQ(1, pElement->getShapesCount());
    auto pElementShape = pElement->getShapesPtr(0);
    EXPECT_EQ(true, pElementShape != nullptr);
    auto pShape = gfc::engine::dynamic_entity_cast<Gfc2SphereShape>(pElementShape->getShapePtr());
    EXPECT_EQ(true, pShape != nullptr);
    EXPECT_NEAR(101, pShape->getRadius(), 1e-7);
    itr->next();
    EXPECT_EQ(true, itr->isDone());
}