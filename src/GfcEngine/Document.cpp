#include "GfcEngine/Document.h"
#include "GfcEngine/EntityTypeTree.h"
#include "EntityClass.h"
#include "Model.h"
#include "Common.h"
#include <assert.h>

GFCENGINE_NAMESPACE_BEGIN

Document::Document( gfc2::schema::CModel* pModel, int nEntityInitCount /*= 1000000*/ ): m_pModel(pModel)
{
    m_pEntityTypeTree = new EntityTypeTree(this);
    m_oEntities.resize(nEntityInitCount, nullptr);
}


Document::~Document(void)
{
    clear();
    delete m_pEntityTypeTree;
}

void Document::add( EntityRef nId, Entity* pEntity )
{
    //m_oEntityMap.insert(std::make_pair(nId, pEntity));
    int nSize = m_oEntities.size();
    if (nId >= nSize)
    {
        while (nId >= nSize)
        {
            nSize *= 2;
        }
        m_oEntities.resize(nSize, nullptr);
    }
    m_oEntities[nId] = pEntity;
    gfc2::schema::CClass* pSchema = pEntity->getClass();
    EntityTypeNode* pNode = m_pEntityTypeTree->getNode(pSchema);
    pNode->entities.push_back(pEntity);
    //delete pSchema;
}

void Document::remove( EntityRef nId )
{
    if (nId < 0 || nId >= (EntityRef)m_oEntities.size())
    {
        return;
    }
    Entity* pEntity = m_oEntities.at(nId);
    if (pEntity == nullptr)
    {
        return;
    }
    m_oEntities[nId] = nullptr;
    gfc2::schema::CClass* pSchema = pEntity->getClass();
    EntityTypeNode* pNode = m_pEntityTypeTree->getNode(pSchema);
    for (std::vector<Entity*>::iterator oItr = pNode->entities.begin(); oItr != pNode->entities.end(); ++oItr)
    {
        if (*oItr == pEntity)
        {
            pNode->entities.erase(oItr);
            break;
        }
    }
    delete pEntity;
}

void Document::clear()
{
    for (auto oItr = m_oEntities.begin(); oItr != m_oEntities.end(); ++oItr)
    {
        delete *oItr;
    }
    m_oEntities.clear();

    m_pEntityTypeTree->clear();
    m_oSchemaInheritSet.clear();
}

Entity* Document::find( EntityRef nId )
{
    if (nId >= 0 && nId < (EntityRef)m_oEntities.size())
    {
        return m_oEntities[nId];
    }
    return nullptr;
}

gfc2::engine::DocumentIterator Document::getIterator()
{
    DocumentIterator oIterator(&this->m_oEntities);
    return oIterator;
}

EntityTypeNode* Document::findByType( const std::string& sType )
{
    return m_pEntityTypeTree->find(normalizeTypeName(sType));
}

EntityTypeTree::EntityList Document::getEntities(const std::string& sType, bool bIncludeSubType /*= false*/ )
{
    return m_pEntityTypeTree->getEntities(normalizeTypeName(sType), bIncludeSubType);
}

void Document::linkSchemaByParent()
{
    for (int i = 0; i < m_pModel->getTypeObjectCount(); ++i)
    {
        gfc2::schema::CClass* pSchema = dynamic_cast<gfc2::schema::CClass*>(m_pModel->getTypeObject(i));
        if (pSchema == nullptr)
            continue;
        gfc2::schema::CClass* pParent = pSchema->getParent();
        while (pParent != nullptr)
        {
            auto sTypeKey = pParent->getName();
            sTypeKey = sTypeKey + L'|' + pSchema->getName();
            m_oSchemaInheritSet.insert(toString(sTypeKey));
            pParent = pParent->getParent();
        }
    }
}

bool Document::schemaFilter( gfc2::schema::CClass* pSchema, const std::string& nFilterType, bool bIncludeSubType )
{
    auto sFilterTypeName = normalizeTypeName(nFilterType); // done for typedef class
    auto nTypeID = toString(pSchema->getName());
    if (nTypeID == sFilterTypeName)
    {
        return true;
    }
    if (bIncludeSubType)
    {
        auto nTypeKey = sFilterTypeName;
        nTypeKey = nTypeKey + "|" + toString(pSchema->getName());
        if (m_oSchemaInheritSet.find(nTypeKey) != m_oSchemaInheritSet.end())
        {
            return true;
        }
    }
    return false;
}

std::string Document::normalizeTypeName(const std::string & sTypeName)
{
    auto pType = m_pModel->findTypeObject(toWstring(sTypeName)); // done for typedef class
    return pType ? toString(pType->getBaseType()->getName()) : "";
}

GFCENGINE_NAMESPACE_END