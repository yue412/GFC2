#ifndef GLODON_OBJECTBUF_DOCUMENT_H
#define GLODON_OBJECTBUF_DOCUMENT_H

#include <string>
#include <map>
#include <vector>
#include <set>
#include "glodon/objectbuf/Entity.h"
#include "glodon/objectbuf/Objectbuf.h"
#include "glodon/objectbuf/EntityTypeTree.h"
#include <functional>

namespace glodon {
namespace objectbuf {

class DocumentIterator;
class EntitySchema;

typedef std::function<bool (Document*, EntityRef, Entity*)> needAddEntityFunc;
typedef std::function<void (Document*)> afterReadDocFunc;


class OBJECTBUF_API Document
{
public:
    Document(int nEntityInitCount = 1000000);
    ~Document(void);
    void add(EntityRef nId, Entity* pEntity);
    void remove(EntityRef nID);
    Entity* find(EntityRef nId);
    EntityTypeNode* findByType(int nType);
    EntityTypeTree::EntityList getEntities(int nType, bool bIncludeSubType = false);
    DocumentIterator getIterator();
    void clear();
    glodon::objectbuf::EntitySchema* findSchemaByID(const int& nId);
    void addSchema(glodon::objectbuf::EntitySchema* pSchema, const int& nId);
    void linkSchemaByParent();
    bool schemaFilter(glodon::objectbuf::EntitySchema* pSchema, int nFilterType, bool bIncludeSubType);
    void setNeedAddEntityFunc(needAddEntityFunc pFunc){m_pNeedAddEntityFunc = pFunc;}
    needAddEntityFunc getNeedAddEntityFunc(){return m_pNeedAddEntityFunc;}
    void setAfterReadDocFunc(afterReadDocFunc pFunc){m_pAfterReadDocFunc = pFunc;}
    afterReadDocFunc getAfterReadDocFunc(){return m_pAfterReadDocFunc;}
private:
    //std::tr1::unordered_map<EntityRef, Entity*> m_oEntityMap;
    std::vector<Entity*> m_oEntities;
    std::map<int, glodon::objectbuf::EntitySchema*> m_oSchemaMap;
    EntityTypeTree* m_pEntityTypeTree;
    std::set<__int64> m_oSchemaInheritSet; //parent, child
    needAddEntityFunc m_pNeedAddEntityFunc;
    afterReadDocFunc m_pAfterReadDocFunc;
};

class OBJECTBUF_API DocumentIterator
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

}
}

#endif

