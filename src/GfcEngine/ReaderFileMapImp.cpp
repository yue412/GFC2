#include "GfcEngine/Reader.h"
#include "ContainerImp.h"
#include "ReaderFileMapImp.h"
#include "FileMap.h"
#include "Common.h"
#include "GfcSchema/TypeObject.h"
#include "GfcSchema/EntityClass.h"
#include "GfcEngine/GfcEngineUtils.h"
#include "GfcEngine/Document.h"
#include "GfcEngine/EntityUpgrader.h"
#include <algorithm>
#include <assert.h>

GFCENGINE_NAMESPACE_BEGIN

class ReaderIterator : public CIterator<EntityPtr>
{
public:
    ReaderIterator(CReaderImp* pReader, std::shared_ptr<CIterator<EntityInfo>> pIterator): m_pReader(pReader), m_pIterator(pIterator) {}
    virtual void first() { m_pIterator->first(); }
    virtual void next() { m_pIterator->next(); }
    virtual bool isDone() { return m_pIterator->isDone(); }
    virtual EntityPtr current() { 
        return m_pReader->getEntity(m_pIterator->current().id);
    }
private:
    std::shared_ptr<CIterator<EntityInfo>> m_pIterator;
    CReaderImp* m_pReader;
};

CReaderFileMapImp::CReaderFileMapImp() : m_pFileMap(nullptr), m_pContainer(nullptr)
{
}


CReaderFileMapImp::~CReaderFileMapImp(void)
{
}

bool CReaderFileMapImp::open(const std::wstring & sFileName)
{
    assert(m_pModel);
    if (m_pModel == nullptr)
        return false;
    m_pFileMap = new CFileMap(sFileName);
    if (m_pFileMap->init())
    {
        initUpgrader();
        buildIndex();
        return true;
    }
    return false;
}

void CReaderFileMapImp::close()
{
    delete m_pFileMap;
    m_pFileMap = nullptr;
    delete m_pContainer;
    m_pContainer = nullptr;
    CReaderImp::close();
}

void CReaderFileMapImp::read(CDocument * pDoc)
{
    if (m_pFileMap == nullptr)
    {
        // 添加log日志
        log(L"文件未打开");
        return;
    }
    m_pFileMap->setPos(0);
    while (!m_pFileMap->eof())
    {
        //EntityRef nId = -1;
        auto pEntity = createEntity(m_pFileMap->pos());
        if (pEntity)
        {
            if (needUpdate())
            {
                CEntity* pOldEntity = pEntity;
                pEntity = m_pUpgrader->update(pEntity, m_bUseStaticClass);
                delete pOldEntity;
            }
            if (pEntity)
            {
                if (!pDoc->getNeedAddEntityFunc() || pDoc->getNeedAddEntityFunc()(pDoc, pEntity))
                {
                    pDoc->add(EntityPtr(pEntity));
                }
                else
                {
                    delete pEntity;
                }
            }
        }
    }
    if (pDoc->getAfterReadDocFunc())
    {
        pDoc->getAfterReadDocFunc()(pDoc);
    }
}

EntityPtr CReaderFileMapImp::getEntity(EntityRef nId)
{
    if (m_pContainer)
    {
        auto oInfo = m_pContainer->getItem(nId);
        auto pEntity = (oInfo.type != nullptr) ? createEntity(oInfo.pos) : nullptr;
        if (pEntity)
        {
            if (needUpdate()) 
            {
                auto pOldEntity = pEntity;
                pEntity = m_pUpgrader->update(pEntity, m_bUseStaticClass);
                delete pOldEntity;
                if (pEntity == nullptr) // 可能无法升级
                    return nullptr;
            }
            pEntity->setContainer(this);
        }
        return EntityPtr(pEntity);
    }
    else
    {
        return nullptr;
    }
}

EntityIteratorPtr CReaderFileMapImp::getEntities(const std::wstring & sType, bool bIncludeSubType)
{
    if (m_pContainer)
        return EntityIteratorPtr(new ReaderIterator(this, m_pContainer->getItems(sType, bIncludeSubType)));
    else
        return nullptr;
}

EntityIteratorPtr CReaderFileMapImp::getIterator()
{
    if (m_pContainer)
        return EntityIteratorPtr(new ReaderIterator(this, m_pContainer->iterator()));
    else
        return nullptr;
}

void CReaderFileMapImp::addInfo(const EntityInfo & oInfo)
{
    if (m_pContainer)
        m_pContainer->add(oInfo);
}

void CReaderFileMapImp::buildIndex()
{
    //std::map<std::string, std::vector<EntityRef>*> o;
    //auto a = o.begin();
    //a->second->empty()
    m_pContainer = new CContainerImp<EntityInfo>(schema());
    EntityInfo oInfo;
    m_pFileMap->setPos(0);
    while (getIndex(oInfo))
    {
        if (oInfo.type)
        {
            addInfo(oInfo);
        }
    }
    //sort();
}

gfc::schema::CClass * EntityInfo::getClass() const
{
    return dynamic_cast<gfc::schema::CClass*>(type->getBaseType());
}

EntityInfo * EntityInfo::get() const
{
    return (EntityInfo *)this;
}

GFCENGINE_NAMESPACE_END