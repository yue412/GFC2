#include "NDocument.h"
#include <msclr\marshal_cppstd.h>
#include "GfcClasses\x3\Document.h"

using namespace msclr::interop;
using namespace System;

NDocument::NDocument()
{
    m_pDoc = new gfc::classes::x3::CDocument();
}

NDocument::~NDocument()
{
    delete m_pDoc;
}

NEntity ^ NDocument::getEntity(gfc::engine::EntityRef nId)
{
    auto pEntity = m_pDoc->getEntity(nId);
    if (pEntity)
        return createEntity(pEntity.get());
    else
        return nullptr;
}

List<NEntity^>^ NDocument::getEntities(System::String ^ sType, bool bIncludeSubType)
{
    auto oList = gcnew List<NEntity^>();
    auto itr = m_pDoc->getEntities(marshal_as<std::wstring>(sType), bIncludeSubType);
    itr->first();
    while (!itr->isDone())
    {
        oList->Add(createEntity(itr->current().get()));
        itr->next();
    }
    return oList;
}

gfc::engine::CDocument * NDocument::raw()
{
    return m_pDoc;
}

NEntity ^ NDocument::createEntity(gfc::engine::CEntity * pEntity)
{
    auto t = Type::GetType(marshal_as<String^>(L"N" + pEntity->entityName()));
    if (t)
    {
        auto params = gcnew array<Object^>{false};
        auto dRefEntity = (NEntity^)Activator::CreateInstance(t, params);
        dRefEntity->init(pEntity, false);
        dRefEntity->setDocument(this); // 防止Document在Entity之前提前施放
        return dRefEntity;
    }
    assert(false);
    return nullptr;
}
