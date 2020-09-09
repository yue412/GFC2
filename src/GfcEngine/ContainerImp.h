#ifndef CONTAINERIMP_H
#define CONTAINERIMP_H

#include <vector>
#include <list>
#include <string>
#include <map>
#include <memory>
#include <mutex>
#include <functional>
#include <assert.h>
#include "GfcEngine\GfcEngine.h"
#include "MutexGuard.h"
#include "GfcEngine\Iterator.h"
#include "GfcSchema\Model.h"

namespace gfc {
    namespace schema {
        class CClass;
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

typedef std::vector<std::vector<EntityRef>*> EntityRefListlist;

template<class T>
class CContainerImp
{
public:
    CContainerImp(gfc::schema::CModel* pModel, int nInitSize = 10000): m_pModel(pModel) , m_nMaxRefId(0), m_mutex(nullptr)
    {
        m_oEntities.resize(nInitSize);
    }
    ~CContainerImp() {
    }

    bool threadsafe() const{
        return m_mutex != nullptr;
    }
    void threadsafe(bool b){
        if(b){
            if(!m_mutex){
                m_mutex = std::make_shared<std::mutex>();
            }
        }
        else{
            m_mutex.reset();
        }
        
    }
   /* void add(EntityRef nId, const T& pEntity) 
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
    }*/

	EntityRef add( T pEntity)
	{
		gfc::schema::CClass* pSchema = pEntity.get()->getClass();
		auto sType = pSchema->getName();

        {
            MutexGuard guard(m_mutex);
            if (pEntity.ref() == -1)
            {
                pEntity.ref(generateRefId());
            }
            else if(pEntity.ref() >= m_nMaxRefId){
                m_nMaxRefId = pEntity.ref();
            }

            auto nId = pEntity.ref();
            auto nSize = (EntityRef)m_oEntities.size();
            if (nId >= nSize)
            {
                while (nId >= nSize)
                {
                    nSize *= 2;
                }
                m_oEntities.resize(nSize);
            }
            assert(m_oEntities[nId].ref() == -1);
            m_oEntities[nId] = pEntity;
            auto itr = m_oEntityTypeMap.find(sType);
            if (itr == m_oEntityTypeMap.end())
            {
                m_oEntityTypeMap[sType] = new std::vector<EntityRef>();
            }
            m_oEntityTypeMap[sType]->push_back(nId);
        }
		
		return pEntity.ref();
	}

    T getItem(EntityRef nId) 
    {
        MutexGuard guard(m_mutex);
        if (nId >= 0 && nId < (EntityRef)m_oEntities.size())
        {
            return m_oEntities[nId];
        }
        return T();
    }

    std::shared_ptr<CIterator<T>> getItems(const std::wstring& sType, bool bIncludeSubType = false)
    {
        MutexGuard guard(m_mutex);
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
        return std::shared_ptr<CIterator<T>>(new CListIterator<T>(this, oList));
    }
    std::shared_ptr<CIterator<T>> iterator()
    {
        MutexGuard guard(m_mutex);
        EntityRefListlist oList;
        for each (auto oPair in m_oEntityTypeMap)
        {
            oList.push_back(oPair.second);
        }
        return std::shared_ptr<CIterator<T>>(new CListIterator<T>(this, oList));
    }
    gfc::schema::CModel* model() const { return m_pModel; }
private:
	EntityRef generateRefId() {
		return m_nMaxRefId = m_nMaxRefId + 1;
	}
private:
    std::vector<T> m_oEntities;
    std::map<std::wstring, std::vector<EntityRef>*> m_oEntityTypeMap;
    gfc::schema::CModel* m_pModel;

	EntityRef m_nMaxRefId;
    bool m_threadsafe;
    std::shared_ptr<std::mutex> m_mutex;
};

template<class T>
class CListIterator : public CIterator<T>
{
public:
    CListIterator(CContainerImp<T>* pContainer, const EntityRefListlist& oList): m_oList(oList), m_nIndex(0), m_pContainer(pContainer) { }
    virtual ~CListIterator() {}
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
    CContainerImp<T>* m_pContainer;
    std::size_t m_nIndex;
};

GFCENGINE_NAMESPACE_END

#endif // !FILEMAP_H