#include "NGfcEntity.h"
#include <msclr\marshal_cppstd.h>  
#include <string>

using namespace msclr::interop;

NGfcEntity::NGfcEntity(gfc::engine::CEntity* pEntity, bool bOwner): m_pEntity(pEntity), m_bOwner(bOwner)
{
}

NGfcEntity::NGfcEntity(): m_pEntity(0), m_bOwner(false)
{

}

NGfcEntity::~NGfcEntity(void)
{
    if (m_bOwner)
    {
        delete getEntity();
    }
}

System::String^ NGfcEntity::entityName()
{
    return marshal_as<System::String^>(getEntity()->entityName());
}

bool NGfcEntity::isInitialized()
{
    return getEntity()->isInitialized();
}

gfc::engine::CEntity* NGfcEntity::getEntity()
{
    return (gfc::engine::CEntity*)m_pEntity;
}