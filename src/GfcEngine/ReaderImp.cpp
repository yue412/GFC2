#include "GfcEngine\Reader.h"
#include "GfcEngine\EntityFactory.h"
#include "ReaderImp.h"
#include "FileMap.h"
#include "Common.h"
#include "TypeObject.h"
#include <algorithm>

GFCENGINE_NAMESPACE_BEGIN

GFCENGINE_IMP_FACTORY(ReaderImp, 0)

ReaderImp::ReaderImp() : m_pFileMap(nullptr), m_pFactory(nullptr)
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
}

EntityPtr ReaderImp::getEntity(EntityRef nId)
{
    EntityInfo oTempInfo;
    oTempInfo.id = nId;
    auto itr = std::lower_bound(m_oEntityInfos.begin(), m_oEntityInfos.end(), oTempInfo, [](const EntityInfo& oInfo1, const EntityInfo& oInfo2) {
        return oInfo1.id < oInfo2.id;
    });
    return std::shared_ptr<Entity>((itr != m_oEntityInfos.end() && itr->id == nId) ? createEntity(*itr) : nullptr);
}

void ReaderImp::addInfo(const EntityInfo & oInfo)
{
    m_oEntityInfos.push_back(oInfo);
}

void ReaderImp::buildIndex()
{
    EntityInfo oInfo;
    m_pFileMap->setPos(0);
    while (getIndex(oInfo))
    {
        addInfo(oInfo);
    }
    sort();
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

void ReaderImp::sort()
{
    std::sort(m_oEntityInfos.begin(), m_oEntityInfos.end(), [](EntityInfo& oInfo1, EntityInfo& oInfo2) {
        return oInfo1.id < oInfo2.id;
    });
    auto nCount = m_oEntityInfos.size();
    for (std::size_t i = 0; i < nCount; ++i)
    {
        EntityInfo& oInfo = m_oEntityInfos[i];
        auto sTypeName = toString(oInfo.type->getBaseType()->getName());
        auto itr = m_oEntityInfoMap.find(sTypeName);
        if (itr == m_oEntityInfoMap.end())
        {
            m_oEntityInfoMap[sTypeName] = new std::vector<std::size_t>();
        }
        m_oEntityInfoMap[sTypeName]->push_back(i);
    }
}


GFCENGINE_NAMESPACE_END