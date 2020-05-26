#ifndef ENTITYTYPETREE_H
#define ENTITYTYPETREE_H

#include <vector>
#include <map>
#include <list>
#include "GfcEngine/GfcEngine.h"

namespace gfc2 {
    namespace schema {
        class CClass;
    }
}

GFCENGINE_NAMESPACE_BEGIN

struct EntityTypeNode;
class Entity;
class Document;

class GFCENGINE_API EntityTypeTree
{
public:
    EntityTypeTree(Document* pDoc);
    ~EntityTypeTree(void);
    EntityTypeNode* find(const std::string& sType);
    EntityTypeNode* getNode(gfc2::schema::CClass* pSchema);
    typedef std::list<std::vector<Entity*>*> EntityList;
    EntityList getEntities(const std::string& sType, bool bIncludeSubType);
    void clear();
private:
    std::map<std::string, EntityTypeNode*> m_oEntityTypeMap;
    Document* m_pDoc;
};

struct GFCENGINE_API EntityTypeNode 
{
    //EntityTypeNode* firstChild;
    //EntityTypeNode* nextBrother;
    std::vector<Entity*> entities;
    EntityTypeNode()/*: firstChild(NULL), nextBrother(NULL)*/ {}
};

class GFCENGINE_API EntityListIterator
{
public:
    EntityListIterator(EntityTypeTree::EntityList* pList) : m_pList(pList), m_nIndex(0) {first();}
    void first(); 
    void next();
    Entity* current();
    bool isDone();
    void setFilterTypeId(const std::string& sType) { m_sFilterType = sType;}
private:
    void doNext();
    void doFilter();

    EntityTypeTree::EntityList* m_pList;
    EntityTypeTree::EntityList::iterator m_oMItr;
    int m_nIndex;
    std::string m_sFilterType;
};

GFCENGINE_API void entityListToVector(EntityTypeTree::EntityList& oSrc, std::vector<Entity*>& oDest);

GFCENGINE_NAMESPACE_END

#endif
