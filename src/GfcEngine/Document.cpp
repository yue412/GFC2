#include "GfcEngine/Document.h"
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\Model.h"
#include "Common.h"
#include "ContainerImp.h"
#include <assert.h>

GFCENGINE_NAMESPACE_BEGIN

Document::Document( gfc::schema::CModel* pModel, int nEntityInitCount /*= 1000000*/ ): m_pContainer(nullptr)
{
    m_pContainer = new ContainerImp<EntityPtr>(pModel, nEntityInitCount);
    //m_pEntityTypeTree = new EntityTypeTree(this);
    //m_oEntities.resize(nEntityInitCount, nullptr);
}

Document::~Document(void)
{
    delete m_pContainer;
}

void Document::add( EntityRef nId, Entity* pEntity )
{
    assert(pEntity);
    pEntity->setContainer(this);
    m_pContainer->add(nId, EntityPtr(pEntity));
}

EntityPtr Document::getEntity( EntityRef nId )
{
    return m_pContainer->getItem(nId);
}

gfc::schema::CModel* Document::model() const 
{ 
    return m_pContainer->model(); 
}

EntityIteratorPtr Document::getIterator()
{
    return m_pContainer->iterator();
}

EntityIteratorPtr Document::getEntities(const std::wstring& sType, bool bIncludeSubType /*= false*/ )
{
    return m_pContainer->getItems(sType, bIncludeSubType);
}

/*
void Document::linkSchemaByParent()
{
    for (int i = 0; i < m_pModel->getTypeObjectCount(); ++i)
    {
        gfc::schema::CClass* pSchema = dynamic_cast<gfc::schema::CClass*>(m_pModel->getTypeObject(i));
        if (pSchema == nullptr)
            continue;
        gfc::schema::CClass* pParent = pSchema->getParent();
        while (pParent != nullptr)
        {
            auto sTypeKey = pParent->getName();
            sTypeKey = sTypeKey + L'|' + pSchema->getName();
            m_oSchemaInheritSet.insert(toString(sTypeKey));
            pParent = pParent->getParent();
        }
    }
}

bool Document::schemaFilter( gfc::schema::CClass* pSchema, const std::string& nFilterType, bool bIncludeSubType )
{
    auto sFilterTypeName = normalizeTypeName(nFilterType); // done for typedef class
    auto nTypeID = toString(pSchema->getName());
    if (nTypeID == sFilterTypeName)
    {
        return true;
    }
    if (bIncludeSubType)
    {
        auto nTypeKey = sFilterTypeName;
        nTypeKey = nTypeKey + "|" + toString(pSchema->getName());
        if (m_oSchemaInheritSet.find(nTypeKey) != m_oSchemaInheritSet.end())
        {
            return true;
        }
    }
    return false;
}

std::string Document::normalizeTypeName(const std::string & sTypeName)
{
    auto pType = m_pModel->findTypeObject(toWstring(sTypeName)); // done for typedef class
    return pType ? toString(pType->getBaseType()->getName()) : "";
}
*/

GFCENGINE_NAMESPACE_END