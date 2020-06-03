#ifndef CONTAINERIMP_H
#define CONTAINERIMP_H

#include <vector>
#include <list>
#include <string>
#include <map>
#include <memory>
#include <functional>
#include <assert.h>
#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\Iterator.h"
#include "Model.h"

namespace gfc {
    namespace schema {
        class CClass;
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

typedef std::vector<std::vector<EntityRef>*> EntityRefListlist;

template<class T>
class ContainerImp
{
public:
    ContainerImp(gfc::schema::CModel* pModel, int nInitSize = 10000): m_pModel(pModel) 
    {
        m_oEntities.resize(nInitSize);
    }
    ~ContainerImp() {}
    void add(EntityRef nId, const T& pEntity) 
    {
        auto nSize = (EntityRef)m_oEntities.size();
        if (nId >= nSize)
        {
            while (nId >= nSize)
            {
                nSize *= 2;
            }
            m_oEntities.resize(nSize);
        }
        m_oEntities[nId] = pEntity;
        gfc::schema::CClass* pSchema = pEntity.get()->getClass();
        auto sType = pSchema->getName();
        auto itr = m_oEntityTypeMap.find(sType);
        if (itr == m_oEntityTypeMap.end())
        {
            m_oEntityTypeMap[sType] = new std::vector<EntityRef>();
        }
        m_oEntityTypeMap[sType]->push_back(nId);
    }

    T getItem(EntityRef nId) 
    {
        if (nId >= 0 && nId < (EntityRef)m_oEntities.size())
        {
            return m_oEntities[nId];
        }
        return T();
    }

    std::shared_ptr<Iterator<T>> getItems(const std::wstring& sType, bool bIncludeSubType = false)
    {
        EntityRefListlist oList;
        if (!bIncludeSubType)
        {
            std::map<std::wstring, std::vector<EntityRef>*>::iterator itr = m_oEntityTypeMap.find(sType);
            if (itr != m_oEntityTypeMap.end())
            {
                if (!itr->second->empty())
                    oList.push_back(itr->second);
            }
        }
        else
        {
            std::function<void(gfc::schema::CClass*, EntityRefListlist&)> pCollectEntitiesFunc;
            pCollectEntitiesFunc = [&](gfc::schema::CClass* pSchema, EntityRefListlist& oCollector)
            {
                std::wstring nID = pSchema->getName();
                std::map<std::wstring, std::vector<EntityRef>*>::iterator itr = m_oEntityTypeMap.find(nID);
                if (itr != m_oEntityTypeMap.end())
                {
                    if (!itr->second->empty())
                        oList.push_back(itr->second);
                }
                for (int i = 0; i < pSchema->getChildCount(); i++)
                {
                    pCollectEntitiesFunc(pSchema->getChild(i), oCollector);
                }
            };

            if (gfc::schema::CClass* pSchema = dynamic_cast<gfc::schema::CClass*>(model()->findTypeObject(sType)))
            {
                pCollectEntitiesFunc(pSchema, oList);
            }
        }
        return std::shared_ptr<Iterator<T>>(new ListIterator<T>(this, oList));
    }
    std::shared_ptr<Iterator<T>> iterator()
    {
        EntityRefListlist oList;
        for each (auto oPair in m_oEntityTypeMap)
        {
            oList.push_back(oPair.second);
        }
        return std::shared_ptr<Iterator<T>>(new ListIterator<T>(this, oList));
    }
    gfc::schema::CModel* model() const { return m_pModel; }
private:
    std::vector<T> m_oEntities;
    std::map<std::wstring, std::vector<EntityRef>*> m_oEntityTypeMap;
    gfc::schema::CModel* m_pModel;
};

template<class T>
class ListIterator : public Iterator<T>
{
public:
    ListIterator(ContainerImp<T>* pContainer, const EntityRefListlist& oList): m_oList(oList), m_nIndex(0), m_pContainer(pContainer) { }
    virtual ~ListIterator() {}
    virtual void first()
    {
        m_oMItr = m_oList.begin();
        m_nIndex = 0;
    }

    virtual void next()
    {
        if (isDone())
            return;
        doNext();
    }

    virtual bool isDone()
    {
        return m_oMItr == m_oList.end();
    }

    virtual T current()
    {
        if (isDone())
            return T();
        assert(m_nIndex < (*m_oMItr)->size());
        if (m_nIndex < (*m_oMItr)->size())
        {
            auto nId = (**m_oMItr)[m_nIndex];
            return m_pContainer->getItem(nId);
        }
        else
            return T();
    }
private:
    void doNext()
    {
        ++m_nIndex;
        if (m_nIndex >= (*m_oMItr)->size())
        {
            ++m_oMItr;
            m_nIndex = 0; // vector always not empty
        }
    }
    std::vector<std::vector<EntityRef>*> m_oList;
    std::vector<std::vector<EntityRef>*>::iterator m_oMItr;
    ContainerImp<T>* m_pContainer;
    std::size_t m_nIndex;
};

GFCENGINE_NAMESPACE_END

#endif // !FILEMAP_H