#include "GfcEngine/Document.h"
#include "EntityClass.h"
#include "Model.h"
#include "Common.h"
#include "ContainerImp.h"
#include <assert.h>

GFCENGINE_NAMESPACE_BEGIN

Document::Document( gfc2::schema::CModel* pModel, int nEntityInitCount /*= 1000000*/ ): m_pModel(pModel)
{
    m_pContainer = new ContainerImp<EntityPtr>(pModel, nEntityInitCount);
    //m_pEntityTypeTree = new EntityTypeTree(this);
    //m_oEntities.resize(nEntityInitCount, nullptr);
}

Document::~Document(void)
{
    delete m_pContainer;
}

void Document::add( EntityRef nId, EntityPtr pEntity )
{
    m_pContainer->add(nId, pEntity);
}

EntityPtr Document::getEntity( EntityRef nId )
{
    return m_pContainer->getItem(nId);
}

EntityIteratorPtr Document::getIterator()
{
    return m_pContainer->iterator();
}

EntityIteratorPtr Document::getEntities(const std::string& sType, bool bIncludeSubType /*= false*/ )
{
    return m_pContainer->getItems(sType, bIncludeSubType);
}

void Document::linkSchemaByParent()
{
    for (int i = 0; i < m_pModel->getTypeObjectCount(); ++i)
    {
        gfc2::schema::CClass* pSchema = dynamic_cast<gfc2::schema::CClass*>(m_pModel->getTypeObject(i));
        if (pSchema == nullptr)
            continue;
        gfc2::schema::CClass* pParent = pSchema->getParent();
        while (pParent != nullptr)
        {
            auto sTypeKey = pParent->getName();
            sTypeKey = sTypeKey + L'|' + pSchema->getName();
            m_oSchemaInheritSet.insert(toString(sTypeKey));
            pParent = pParent->getParent();
        }
    }
}

bool Document::schemaFilter( gfc2::schema::CClass* pSchema, const std::string& nFilterType, bool bIncludeSubType )
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

GFCENGINE_NAMESPACE_END