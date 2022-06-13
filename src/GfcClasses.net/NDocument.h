#ifndef NDOCUMENT_NET_H
#define NDOCUMENT_NET_H

#include "GfcEngine\Document.h"
#include "NEntity.h"

using namespace System::Collections::Generic;

public ref class NDocument
{
public:
    NDocument();
    ~NDocument();

    NEntity^ getEntity(gfc::engine::EntityRef nId);
    List<NEntity^>^ getEntities(System::String^ sType, bool bIncludeSubType);

    gfc::engine::CDocument* raw();
private:
    NEntity^ createEntity(gfc::engine::CEntity* pEntity);
    gfc::engine::CDocument* m_pDoc;
};

#endif
