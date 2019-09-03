#include "glodon/objectbuf/Entity.h"
#include <string>
#include "glodon/objectbuf/EntitySchema.h"
#include "glodon/objectbuf/Document.h"

namespace glodon {
namespace objectbuf {

std::map<std::string, int> g_oOBObjCount;
std::map<std::string, std::map<int, int> > g_nOBObjSize;

OBJECTBUF_IMP_FACTORY(Entity, 0);

std::string Entity::Version()
{
	static std::string version = "GFC2.0";
	return version;
}

Entity::Entity(void): m_pDocument(nullptr)
{
}

Entity::~Entity(void)
{
}

glodon::objectbuf::EntitySchema* Entity::createSchema() const
{
    return NULL;
}

void Entity::setDocument( Document* pDocument )
{
    m_pDocument = pDocument;
}

bool Entity::isInitialized() const
{
    return true;
}

bool Entity::isInherited( int nTypeId )
{
    bool bResult = false;
    EntitySchema* pSchema = createSchema();
    EntitySchema* pTemp = pSchema;
    while(pSchema)
    {
        if (pSchema->typeId() == nTypeId)
        {
            bResult = true;
            break;
        }
        pSchema = pSchema->getParent();
    }
    //delete pTemp;
    return bResult;
}

string Entity::entityName() const
{
    return "Entity";
}

std::map<std::string, int>* getOBObjCount()
{
    return &g_oOBObjCount;
}

std::map<std::string, std::map<int, int> >* getOBObjSize()
{
    return &g_nOBObjSize;
}

}
}