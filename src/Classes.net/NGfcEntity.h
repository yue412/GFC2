#ifndef NENTITY_NET_H
#define NENTITY_NET_H

#include "GfcEngine/Entity.h"

//using namespace System;

public ref class NGfcEntity
{
public:
    NGfcEntity();
    NGfcEntity(gfc::engine::CEntity* pEntity, bool bOwner);
    virtual ~NGfcEntity(void);
    System::String^ entityName();
    bool isInitialized();
    gfc::engine::CEntity* getEntity();
protected:
    gfc::engine::CEntity* m_pEntity;
    //void* m_pEntity;
    bool m_bOwner;
};

#endif
