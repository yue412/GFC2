#include "GfcEngine\Reader.h"
#include "GfcEngine\EntityFactory.h"
#include "ContainerImp.h"
#include "ReaderImp.h"
#include "FileMap.h"
#include "Common.h"
#include "TypeObject.h"
#include "EntityClass.h"
#include <algorithm>

GFCENGINE_NAMESPACE_BEGIN

GFCENGINE_IMP_FACTORY(ReaderImp, 0)

class ReaderIterator : public Iterator<EntityPtr>
{
public:
    ReaderIterator(ReaderImp* pReader, std::shared_ptr<Iterator<EntityInfo>> pIterator): m_pReader(pReader), m_pIterator(pIterator) {}
    virtual void first() { m_pIterator->first(); }
    virtual void next() { m_pIterator->next(); }
    virtual bool isDone() { return m_pIterator->isDone(); }
    virtual EntityPtr current() { 
        return m_pReader->getEntity(m_pIterator->current().id);
    }
private:
    std::shared_ptr<Iterator<EntityInfo>> m_pIterator;
    ReaderImp* m_pReader;
};

ReaderImp::ReaderImp() : m_pFileMap(nullptr), m_pFactory(nullptr), m_pContainer(nullptr)
{
}


ReaderImp::~ReaderImp(void)
{
}

bool ReaderImp::open(const string & sFileName)
{
    m_pFileMap = new FileMap(toWstring(sFileName));
    if (m_pFileMap->init())
    {
        buildIndex();
        return true;
    }
    return false;
}

void ReaderImp::close()
{
    delete m_pFileMap;
    m_pFileMap = nullptr;
    delete m_pContainer;
    m_pContainer = nullptr;
}

EntityPtr ReaderImp::getEntity(EntityRef nId)
{
    auto oInfo = m_pContainer->getItem(nId);
    return EntityPtr((oInfo.type != nullptr) ? createEntity(oInfo) : nullptr);
}

EntityIteratorPtr ReaderImp::getEntities(const std::string & sType, bool bIncludeSubType)
{
    return EntityIteratorPtr(new ReaderIterator(this, m_pContainer->getItems(sType, bIncludeSubType)));
}

EntityIteratorPtr ReaderImp::getIterator()
{
    return EntityIteratorPtr(new ReaderIterator(this, m_pContainer->iterator()));
}

void ReaderImp::addInfo(const EntityInfo & oInfo)
{
    m_pContainer->add(oInfo.id, oInfo);
}

void ReaderImp::buildIndex()
{
    //std::map<std::string, std::vector<EntityRef>*> o;
    //auto a = o.begin();
    //a->second->empty()
    m_pContainer = new ContainerImp<EntityInfo>(schema());
    EntityInfo oInfo;
    m_pFileMap->setPos(0);
    while (getIndex(oInfo))
    {
        addInfo(oInfo);
    }
    //sort();
}

gfc2::schema::CModel * ReaderImp::schema()
{
    assert(m_pFactory);
    if (m_pFactory)
    {
        return m_pFactory->schema();
    }
    return nullptr;
}

gfc2::schema::CClass * EntityInfo::getClass() const
{
    return dynamic_cast<gfc2::schema::CClass*>(type->getBaseType());
}

EntityInfo * EntityInfo::get() const
{
    return (EntityInfo *)this;
}

GFCENGINE_NAMESPACE_END