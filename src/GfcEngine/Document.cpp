#include "GfcEngine/Document.h"
#include "GfcSchema\EntityClass.h"
#include "GfcSchema\Model.h"
#include "Common.h"
#include "ContainerImp.h"
#include <assert.h>

GFCENGINE_NAMESPACE_BEGIN

CDocument::CDocument( gfc::schema::CModel* pModel, int nEntityInitCount /*= 1000000*/ ): m_pContainer(nullptr)
{
    m_pContainer = new CContainerImp<EntityPtr>(pModel, nEntityInitCount);
    //m_pEntityTypeTree = new EntityTypeTree(this);
    //m_oEntities.resize(nEntityInitCount, nullptr);
}

CDocument::~CDocument(void)
{
    delete m_pContainer;
}

/*
EntityRef CDocument::add( EntityRef nId, CEntity* pEntity )
{
    assert(pEntity);
    pEntity->setContainer(this);
	auto refId = m_pContainer->add(EntityPtr(nId, pEntity));
	pEntity->setRef(refId);
	return refId;
}
*/

EntityRef CDocument::add(CEntity * pEntity)
{
    return add(EntityPtr(pEntity));
}

EntityRef CDocument::add(std::shared_ptr <CEntity> pEntity)
{
	assert(pEntity.get());
	pEntity->setContainer(this);
	auto refId = m_pContainer->add(pEntity);
	//pEntity->setRef(refId);
	return refId;
}

EntityPtr CDocument::getEntity( EntityRef nId )
{
    return m_pContainer->getItem(nId);
}

gfc::schema::CModel* CDocument::model() const 
{ 
    return m_pContainer->model(); 
}

EntityIteratorPtr CDocument::getIterator()
{
    return m_pContainer->iterator();
}

EntityIteratorPtr CDocument::getEntities(const std::wstring& sType, bool bIncludeSubType /*= false*/ )
{
    return m_pContainer->getItems(sType, bIncludeSubType);
}

bool CDocument::threadsafe() const{
    return m_pContainer->threadsafe();
}

void CDocument::threadsafe(bool b){
    m_pContainer->threadsafe(b);
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
    auto pType = m_pModel->findTypeObject(ACPToUnicode(sTypeName)); // done for typedef class
    return pType ? toString(pType->getBaseType()->getName()) : "";
}
*/

GFCENGINE_NAMESPACE_END