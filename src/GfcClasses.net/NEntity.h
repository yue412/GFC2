#ifndef NENTITY_NET_H
#define NENTITY_NET_H

#include "GfcEngine/Entity.h"

//using namespace System;

ref class NDocument;

public ref class NEntity
{
public:
    NEntity();
    NEntity(bool bNoCreate);
    void init(gfc::engine::CEntity* pEntity, bool bOwner);
    virtual ~NEntity(void);
    System::String^ entityName();
    bool isInitialized();
    gfc::engine::CEntity* getEntity();
    void setDocument(NDocument^ pDoc);
protected:
    gfc::engine::CEntity* m_pEntity;
    //void* m_pEntity;
    bool m_bOwner;
    NDocument^ m_pDoc;
};

#endif
