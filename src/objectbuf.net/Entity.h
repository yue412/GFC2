#ifndef ENTITY_NET_H
#define ENTITY_NET_H

#include "glodon/objectbuf/Entity.h"

namespace glodon {
namespace objectbufnet {

using namespace System;

public ref class Entity
{
public:
    Entity();
    Entity(void* pEntity, bool bOwner);
    virtual ~Entity(void);
    bool isInherited(int nTypeId);
    String^ entityName();
    int typeId();
    bool isInitialized();
    glodon::objectbuf::Entity* getEntity();
protected:
    //glodon::objectbuf::Entity* m_pEntity;
    void* m_pEntity;
    bool m_bOwner;
};

}
}

#endif
