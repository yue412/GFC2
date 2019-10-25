#include "glodon/objectbuf/Document.h"
#include "glodon/objectbuf/EntitySchema.h"
#include "glodon/objectbuf/EntityTypeTree.h"

namespace glodon {
namespace objectbuf {

Document::Document( int nEntityInitCount /*= 1000000*/ )
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
    EntitySchema* pSchema = pEntity->createSchema();
    EntityTypeNode* pNode = m_pEntityTypeTree->getNode(pSchema);
    pNode->entities.push_back(pEntity);
    //delete pSchema;
}

void Document::remove( EntityRef nId )
{
    if (nId < 0 || nId >= m_oEntities.size())
    {
        return;
    }
    Entity* pEntity = m_oEntities.at(nId);
    if (pEntity == nullptr)
    {
        return;
    }
    m_oEntities[nId] = nullptr;
    EntitySchema* pSchema = pEntity->createSchema();
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
    for (auto oItr = m_oSchemaMap.begin(); oItr != m_oSchemaMap.end(); ++oItr)
    {
        delete oItr->second;
    }
    m_oSchemaMap.clear();

    m_pEntityTypeTree->clear();
    m_oSchemaInheritSet.clear();
}

Entity* Document::find( EntityRef nId )
{
    if (nId >= 0 && nId < m_oEntities.size())
    {
        return m_oEntities[nId];
    }
    return nullptr;
}

glodon::objectbuf::DocumentIterator Document::getIterator()
{
    DocumentIterator oIterator(&this->m_oEntities);
    return oIterator;
}

EntityTypeNode* Document::findByType( int nType )
{
    return m_pEntityTypeTree->find(nType);
}

EntityTypeTree::EntityList Document::getEntities( int nType, bool bIncludeSubType /*= false*/ )
{
    return m_pEntityTypeTree->getEntities(nType, bIncludeSubType);
}

glodon::objectbuf::EntitySchema* Document::findSchemaByID( const int& nId )
{
    auto oItr = m_oSchemaMap.find(nId);
    return oItr == m_oSchemaMap.end() ? NULL : oItr->second;
}

void Document::addSchema( glodon::objectbuf::EntitySchema* pSchema, const int& nId )
{
    assert(m_oSchemaMap.find(nId) == m_oSchemaMap.end());
    m_oSchemaMap.insert(std::make_pair(nId, pSchema));
}

void Document::linkSchemaByParent()
{
    for (auto pIter = m_oSchemaMap.begin(); pIter != m_oSchemaMap.end(); pIter++)
    {
        glodon::objectbuf::EntitySchema* pSchema = pIter->second;
        if (pSchema->getParent() != nullptr)
        {
            pSchema->getParent()->addChild(pSchema);
        }
    }
    for (auto pIter = m_oSchemaMap.begin(); pIter != m_oSchemaMap.end(); pIter++)
    {
        glodon::objectbuf::EntitySchema* pSchema = pIter->second;
        glodon::objectbuf::EntitySchema* pParent = pSchema->getParent();
        while (pParent != nullptr)
        {
            __int64 nTypeKey = pParent->getId();
            nTypeKey = nTypeKey << 32 + pSchema->getId();
            m_oSchemaInheritSet.insert(nTypeKey);
            pParent = pParent->getParent();
        }
    }
}

bool Document::schemaFilter( glodon::objectbuf::EntitySchema* pSchema, int nFilterType, bool bIncludeSubType )
{
    int nTypeID = pSchema->getId();
    if (nTypeID == nFilterType)
    {
        return true;
    }
    if (bIncludeSubType)
    {
        __int64 nTypeKey = nFilterType;
        nTypeKey = nTypeKey << 32 + pSchema->getId();
        if (m_oSchemaInheritSet.find(nTypeKey) != m_oSchemaInheritSet.end())
        {
            return true;
        }
    }
    return false;
}

}
}
