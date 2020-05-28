#include "gtest\gtest.h"
#include "GfcEngine\EntityFactory.h"
#include "GfcEngine\Entity.h"
#include "Common.h"
#include "EntityClass.h"
#include "EntityAttribute.h"
#include "BuildinType.h"

TEST(TestEntityFactory, EntityFactory_create)
{
    gfc2::engine::EntityFactory oFactory;
    oFactory.loadSchema(toString(getFullPath(L"GFC3X0.exp")));
    auto pEntity = oFactory.create("Gfc2InternalChart");
    EXPECT_EQ(true, pEntity != nullptr);
    EXPECT_EQ(true, pEntity->entityName() == "Gfc2InternalChart");
    delete pEntity;
}