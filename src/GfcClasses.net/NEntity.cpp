#include "NEntity.h"
#include <msclr\marshal_cppstd.h>  
#include <string>

using namespace msclr::interop;

NEntity::NEntity(bool bNoCreate): m_pEntity(nullptr), m_bOwner(false)
{
}

NEntity::NEntity(): m_pEntity(0), m_bOwner(false)
{

}

void NEntity::init(gfc::engine::CEntity * pEntity, bool bOwner)
{
    if(m_pEntity && m_bOwner)
        delete getEntity();
    m_pEntity = pEntity;
    m_bOwner = bOwner;
}

NEntity::~NEntity(void)
{
    if (m_bOwner)
    {
        delete getEntity();
    }
}

System::String^ NEntity::entityName()
{
    return marshal_as<System::String^>(getEntity()->entityName());
}

bool NEntity::isInitialized()
{
    return getEntity()->isInitialized();
}

gfc::engine::EntityRef NEntity::ref()
{
    return m_pEntity->ref();
}

gfc::engine::CEntity* NEntity::getEntity()
{
    return (gfc::engine::CEntity*)m_pEntity;
}

void NEntity::setDocument(NDocument ^ pDoc)
{
    m_pDoc = pDoc;
}
