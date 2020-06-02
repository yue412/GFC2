#include <assert.h>
#include <fstream>
#include "GfcEngine\EntityFactory.h"
#include "GfcEngine\Entity.h"
#include "Model.h"
#include "Common.h"
#include "BuildinType.h"
#include "EntityClass.h"
#include "Parser.h"
#include "Scanner.h"

GFCENGINE_NAMESPACE_BEGIN

GFCENGINE_IMP_FACTORY(EntityFactory, 0)

EntityFactory::EntityFactory(gfc2::schema::CModel * pModel, bool bOwnerModel) : m_pModel(pModel), m_bOwnerModel(bOwnerModel)
{
}

EntityFactory::~EntityFactory()
{
    clear();
}

Entity * EntityFactory::create(const std::wstring & sName)
{
    auto pEntity = EntityFactory::GetFactory()->Create(sName);
    if (pEntity)
        return dynamic_cast<Entity*>(pEntity);
    assert(m_pModel);
    auto pType = m_pModel->findTypeObject(sName);
    if (pType && pType->getDataType() == gfc2::schema::EDT_ENTITY)
    {
        Entity* pEntity = new Entity;
        pEntity->setSchema(pType);
        return pEntity;
    }
    else
    {
        return nullptr;
    }
}

void EntityFactory::clear()
{
    if (m_bOwnerModel)
    {
        delete m_pModel; m_pModel = nullptr;
    }
}

GFCENGINE_NAMESPACE_END
