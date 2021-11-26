#ifndef ENTITY_NET_H
#define ENTITY_NET_H

#include "GfcEngine/Entity.h"

namespace gfc { namespace engine { namespace net {

using namespace System;

public ref class Entity
{
public:
    Entity();
    Entity(void* pEntity, bool bOwner);
    virtual ~Entity(void);
    String^ entityName();
    bool isInitialized();
    gfc::engine::CEntity* getEntity();
protected:
    //glodon::objectbuf::Entity* m_pEntity;
    void* m_pEntity;
    bool m_bOwner;
};

}
}
}

#endif
