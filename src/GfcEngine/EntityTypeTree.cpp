#include "GfcEngine/EntityTypeTree.h"
#include "GfcEngine/Document.h"
#include "EntityClass.h"
#include "Model.h"
#include "Common.h"
#include <functional>
#include <assert.h>

GFCENGINE_NAMESPACE_BEGIN

EntityTypeTree::EntityTypeTree(Document* pDoc): m_pDoc(pDoc)
{
}


EntityTypeTree::~EntityTypeTree(void)
{
    clear();
}

EntityTypeNode* EntityTypeTree::find(const std::string& sType)
{
    auto oItr = m_oEntityTypeMap.find(sType);
    if (oItr != m_oEntityTypeMap.end())
    {
        return oItr->second;
    }
    else
    {
        return NULL;
    }
}

EntityTypeNode* EntityTypeTree::getNode(gfc2::schema::CClass* pSchema )
{
    std::string sType = pSchema == NULL ? "" : toString(pSchema->getName());
    EntityTypeNode* pNode = find(sType);
    if (!pNode)
    {
        pNode = new EntityTypeNode;
        m_oEntityTypeMap.insert(std::make_pair(sType, pNode));
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

EntityTypeTree::EntityList EntityTypeTree::getEntities(const std::string& sType, bool bIncludeSubType )
{
    EntityList oList;
    if (!bIncludeSubType)
    {
        if (EntityTypeNode* pNode = find(sType))
        {
            if (!pNode->entities.empty())
                oList.push_back(&pNode->entities);
        }
    }
    else
    {
        std::function<void (gfc2::schema::CClass*, EntityList&)> pCollectEntitiesFunc;
        pCollectEntitiesFunc = [&](gfc2::schema::CClass* pSchema, EntityList& oCollector)
        {
            std::string nID = toString(pSchema->getName());
            if (EntityTypeNode* pNode = find(nID))
            {
                if (!pNode->entities.empty())
                    oList.push_back(&pNode->entities);
            }
            std::vector<gfc2::schema::CClass*> oSubSchemas;
            //pSchema->getChildren(oSubSchemas);
            for (int i = 0; i < pSchema->getChildCount(); i++)
            {
                pCollectEntitiesFunc(pSchema->getChild(i), oCollector);
            }
        };

        if (gfc2::schema::CClass* pSchema = dynamic_cast<gfc2::schema::CClass*>(m_pDoc->model()->findTypeObject(toWstring(sType))))
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
    if (!m_sFilterType.empty())
    {
        while (!isDone() && !current()->getClass()->isInherited(toWstring(m_sFilterType)))
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