#ifndef ENTITYTYPETREE_H
#define ENTITYTYPETREE_H

#include <vector>
#include <map>
#include <list>
#include "GfcEngine/GfcEngine.h"

GFCENGINE_NAMESPACE_BEGIN

struct EntityTypeNode;
class EntitySchema;
class Entity;
class Document;

class GFCENGINE_API EntityTypeTree
{
public:
    EntityTypeTree(Document* pDoc);
    ~EntityTypeTree(void);
    EntityTypeNode* find(int nType);
    EntityTypeNode* getNode(EntitySchema* pSchema);
    typedef std::list<std::vector<Entity*>*> EntityList;
    EntityList getEntities(int nType, bool bIncludeSubType);
    void clear();
private:
    std::map<int, EntityTypeNode*> m_oEntityTypeMap;
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
    EntityListIterator(EntityTypeTree::EntityList* pList) : m_pList(pList), m_nIndex(0), m_nFilterTypeId(-1) {first();}
    void first(); 
    void next();
    Entity* current();
    bool isDone();
    void setFilterTypeId(int nTypeId) {m_nFilterTypeId = nTypeId;}
private:
    void doNext();
    void doFilter();

    EntityTypeTree::EntityList* m_pList;
    EntityTypeTree::EntityList::iterator m_oMItr;
    int m_nIndex;
    int m_nFilterTypeId;
};

GFCENGINE_API void entityListToVector(EntityTypeTree::EntityList& oSrc, std::vector<Entity*>& oDest);

GFCENGINE_NAMESPACE_END

#endif
