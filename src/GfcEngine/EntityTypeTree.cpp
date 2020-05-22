#include "GfcEngine/EntityTypeTree.h"
#include "GfcEngine/EntitySchema.h"
#include "GfcEngine/Document.h"
#include <functional>

GFCENGINE_NAMESPACE_BEGIN

EntityTypeTree::EntityTypeTree(Document* pDoc): m_pDoc(pDoc)
{
}


EntityTypeTree::~EntityTypeTree(void)
{
    clear();
}

EntityTypeNode* EntityTypeTree::find( int nType )
{
    auto oItr = m_oEntityTypeMap.find(nType);
    if (oItr != m_oEntityTypeMap.end())
    {
        return oItr->second;
    }
    else
    {
        return NULL;
    }
}

EntityTypeNode* EntityTypeTree::getNode( EntitySchema* pSchema )
{
    int nType = pSchema == NULL ? -1 : pSchema->getId(); 
    EntityTypeNode* pNode = find(nType);
    if (!pNode)
    {
        pNode = new EntityTypeNode;
        m_oEntityTypeMap.insert(std::make_pair(nType, pNode));
    }
    return pNode;
}

void EntityTypeTree::clear()
{
    for (auto oItr = m_oEntityTypeMap.begin(); oItr != m_oEntityTypeMap.end(); ++oItr)
    {
        delete oItr->second;
    }
    m_oEntityTypeMap.clear();
}

EntityTypeTree::EntityList EntityTypeTree::getEntities( int nType, bool bIncludeSubType )
{
    EntityList oList;
    if (!bIncludeSubType)
    {
        if (EntityTypeNode* pNode = find(nType))
        {
            if (!pNode->entities.empty())
                oList.push_back(&pNode->entities);
        }
    }
    else
    {
        std::function<void (EntitySchema*, EntityList&)> pCollectEntitiesFunc;
        pCollectEntitiesFunc = [&](EntitySchema* pSchema, EntityList& oCollector)
        {
            int nID = pSchema->getId();
            if (EntityTypeNode* pNode = find(nID))
            {
                if (!pNode->entities.empty())
                    oList.push_back(&pNode->entities);
            }
            std::vector<EntitySchema*> oSubSchemas;
            pSchema->getChildren(oSubSchemas);
            for each (auto pSubSchema in oSubSchemas)
            {
                pCollectEntitiesFunc(pSubSchema, oCollector);
            }
        };

        if (EntitySchema* pSchema = m_pDoc->findSchemaByID(nType))
        {
            pCollectEntitiesFunc(pSchema, oList);
        }
    }
    return oList;
}

void EntityListIterator::first()
{
    m_oMItr = m_pList->begin(); 
    m_nIndex = 0;
    doFilter();
}

void EntityListIterator::next()
{
    if (isDone())
        return;
    doNext();
    doFilter();
}

Entity* EntityListIterator::current()
{
    if (isDone())
        return NULL;
    assert(m_nIndex < (*m_oMItr)->size());
    if (m_nIndex < (*m_oMItr)->size())
        return (**m_oMItr)[m_nIndex];
    else
        return NULL;
}

bool EntityListIterator::isDone()
{
    return m_oMItr == m_pList->end();
}

void EntityListIterator::doNext()
{
    ++m_nIndex;
    if (m_nIndex >= (*m_oMItr)->size())
    {
        ++m_oMItr;
        m_nIndex = 0; // vector always not empty
    }
}

void EntityListIterator::doFilter()
{
    if (m_nFilterTypeId != -1)
    {
        while (!isDone() && !current()->isInherited(m_nFilterTypeId))
        {
            doNext();
        }
    }
}

void entityListToVector( EntityTypeTree::EntityList& oSrc, std::vector<Entity*>& oDest )
{
    for (auto oItr1 = oSrc.begin(); oItr1 != oSrc.end(); ++oItr1)
    {
        for (auto oItr2 = (*oItr1)->begin(); oItr2 != (*oItr1)->end(); ++oItr2)
        {
            oDest.push_back(*oItr2);
        }
    }
}

GFCENGINE_NAMESPACE_END