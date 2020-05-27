#ifndef GLODON_OBJECTBUF_DOCUMENT_H
#define GLODON_OBJECTBUF_DOCUMENT_H

#include <string>
#include <map>
#include <vector>
#include <set>
#include "GfcEngine/Entity.h"
#include "GfcEngine/GfcEngine.h"
#include "GfcEngine\Container.h"
#include <functional>

namespace gfc2 {
    namespace schema {
        class CClass;
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class DocumentIterator;

typedef std::function<bool (Document*, EntityRef, Entity*)> needAddEntityFunc;
typedef std::function<void (Document*)> afterReadDocFunc;

template<class T> class ContainerImp;

class GFCENGINE_API Document: public IContainer
{
public:
    Document(gfc2::schema::CModel* pModel, int nEntityInitCount = 1000000);
    ~Document(void);
    void add(EntityRef nId, EntityPtr pEntity);
    gfc2::schema::CModel* model() const { return m_pModel; }

    virtual EntityPtr getEntity(EntityRef nId) = 0;
    virtual EntityIteratorPtr getEntities(const std::string& nType, bool bIncludeSubType = false) = 0;
    virtual EntityIteratorPtr getIterator() = 0;


    void linkSchemaByParent();
    bool schemaFilter(gfc2::schema::CClass* pSchema, const std::string& nFilterType, bool bIncludeSubType);
    void setNeedAddEntityFunc(needAddEntityFunc pFunc){m_pNeedAddEntityFunc = pFunc;}
    needAddEntityFunc getNeedAddEntityFunc(){return m_pNeedAddEntityFunc;}
    void setAfterReadDocFunc(afterReadDocFunc pFunc){m_pAfterReadDocFunc = pFunc;}
    afterReadDocFunc getAfterReadDocFunc(){return m_pAfterReadDocFunc;}
private:
    //std::tr1::unordered_map<EntityRef, Entity*> m_oEntityMap;
    std::string normalizeTypeName(const std::string& sTypeName);
    gfc2::schema::CModel* m_pModel;
    //std::vector<Entity*> m_oEntities;
    //std::map<std::string, std::vector<Entity*>> m_oEntityTypeMap;
    ContainerImp<EntityPtr>* m_pContainer;
    std::set<std::string> m_oSchemaInheritSet; //parent, child
    needAddEntityFunc m_pNeedAddEntityFunc;
    afterReadDocFunc m_pAfterReadDocFunc;
};

class GFCENGINE_API DocumentIterator
{
public:
    DocumentIterator(std::vector<Entity*>* pEntityMap): m_pEntityMap(pEntityMap) {}
    void first() {m_oItr = m_pEntityMap->begin();}
    void next() {++m_oItr;}
    bool isDone() {return m_oItr == m_pEntityMap->end();}
    Entity* current() {return *m_oItr;}
private:
    std::vector<Entity*>* m_pEntityMap;
    std::vector<Entity*>::iterator m_oItr;
};

GFCENGINE_NAMESPACE_END

#endif

