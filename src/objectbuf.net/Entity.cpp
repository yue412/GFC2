#include "Entity.h"
#include <msclr\marshal_cppstd.h>  
#include <string>
#include "glodon/objectbuf/Entity.h"

namespace glodon {
namespace objectbufnet {

using namespace msclr::interop;

Entity::Entity(void* pEntity, bool bOwner): m_pEntity(pEntity), m_bOwner(bOwner)
{
}

Entity::Entity(): m_pEntity(0), m_bOwner(false)
{

}


Entity::~Entity(void)
{
    if (m_bOwner)
    {
        delete getEntity();
    }
}

bool Entity::isInherited( int nTypeId )
{
    return getEntity()->isInherited(nTypeId);
}

String^ Entity::entityName()
{
    return marshal_as<String^>(getEntity()->entityName());
}

int Entity::typeId()
{
    return getEntity()->typeId();
}

bool Entity::isInitialized()
{
    return getEntity()->isInitialized();
}

glodon::objectbuf::Entity* Entity::getEntity()
{
    return (glodon::objectbuf::Entity*)m_pEntity;
}

}
}