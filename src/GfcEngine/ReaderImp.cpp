#include "GfcEngine\Reader.h"
#include "ContainerImp.h"
#include "ReaderImp.h"
#include "FileMap.h"
#include "Common.h"
#include "GfcSchema\TypeObject.h"
#include "GfcSchema\EntityClass.h"
#include "GfcEngine\GfcEngineUtils.h"
#include "GfcEngine\Document.h"
#include "GfcEngine\Upgrader.h"
#include <algorithm>

GFCENGINE_NAMESPACE_BEGIN

GFCENGINE_IMP_FACTORY(CReaderImp, 0)

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

CReaderImp::CReaderImp() : m_pFileMap(nullptr), m_pModel(nullptr), m_pContainer(nullptr), m_pFileModel(nullptr), m_pUpgrader(nullptr), m_bUseStaticClass(false)
{
}


CReaderImp::~CReaderImp(void)
{
}

void CReaderImp::initUpgrader()
{
    if (m_pModel)
    {
        auto sFileVer = readFileVersion();
        if (sFileVer != m_pModel->version())
        {
            // 版本不同，需要升级或降级
            if (!openFileModel(sFileVer))
                return;
            m_pUpgrader = new CEntityUpgrader;
            m_pUpgrader->init(m_pModel, m_pFileModel);
        }
    }
}


bool CReaderImp::open(const std::wstring & sFileName)
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

void CReaderImp::close()
{
    delete m_pFileMap;
    m_pFileMap = nullptr;
    delete m_pContainer;
    m_pContainer = nullptr;
    delete m_pUpgrader; 
    m_pUpgrader = nullptr;
    delete m_pFileModel; 
    m_pFileModel = nullptr;
}

void CReaderImp::read(CDocument * pDoc)
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
        EntityRef nId = -1;
        auto pEntity = createEntity(m_pFileMap->pos(), nId);
        if (pEntity)
        {
            if (needUpdate())
            {
                CEntity* pOldEntity = pEntity;
                pEntity = m_pUpgrader->update(pEntity);
                delete pOldEntity;
            }
            if (pEntity)
            {
                if (!pDoc->getNeedAddEntityFunc() || pDoc->getNeedAddEntityFunc()(pDoc, nId, pEntity))
                {
                    pDoc->add(nId, pEntity);
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

EntityPtr CReaderImp::getEntity(EntityRef nId)
{
    if (m_pContainer)
    {
        auto oInfo = m_pContainer->getItem(nId);
        auto pEntity = (oInfo.type != nullptr) ? createEntity(oInfo.pos, nId) : nullptr;
        if (pEntity)
        {
            if (needUpdate()) 
            {
                auto pOldEntity = pEntity;
                pEntity = m_pUpgrader->update(pEntity);
                delete pOldEntity;
                if (pEntity == nullptr) // 可能无法升级
                    return nullptr;
            }
            pEntity->setContainer(this);
        }
        return EntityPtr(nId, pEntity);
    }
    else
    {
        return nullptr;
    }
}

EntityIteratorPtr CReaderImp::getEntities(const std::wstring & sType, bool bIncludeSubType)
{
    if (m_pContainer)
        return EntityIteratorPtr(new ReaderIterator(this, m_pContainer->getItems(sType, bIncludeSubType)));
    else
        return nullptr;
}

EntityIteratorPtr CReaderImp::getIterator()
{
    if (m_pContainer)
        return EntityIteratorPtr(new ReaderIterator(this, m_pContainer->iterator()));
    else
        return nullptr;
}

void CReaderImp::addInfo(const EntityInfo & oInfo)
{
    if (m_pContainer)
        m_pContainer->add(oInfo.id, oInfo);
}

bool CReaderImp::openFileModel(const std::wstring & sFileVer)
{
    auto sFileName = getFullPath(m_sSchemaPath + L"\\" + sFileVer + L".exp");
    if (!fileExists(sFileName))
        return false;
    m_pFileModel = new gfc::schema::CModel();
    return CEngineUtils::loadSchema(sFileName, m_pFileModel);
}

bool CReaderImp::needUpdate()
{
    return m_pUpgrader != nullptr;
}

void CReaderImp::buildIndex()
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

void CReaderImp::log(const std::wstring & sError)
{
    m_oErrors.push_back(sError);
}

gfc::schema::CModel * CReaderImp::schema()
{
    return m_pUpgrader ? m_pFileModel : m_pModel;
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