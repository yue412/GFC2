#include "Entity.h"
#include <msclr\marshal_cppstd.h>  
#include <string>
#include "GfcEngine\Entity.h"

namespace gfc { namespace engine { namespace net {

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

String^ Entity::entityName()
{
    return marshal_as<String^>(getEntity()->entityName());
}

bool Entity::isInitialized()
{
    return getEntity()->isInitialized();
}

gfc::engine::CEntity* Entity::getEntity()
{
    return (gfc::engine::CEntity*)m_pEntity;
}

}}}