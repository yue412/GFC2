#include "WriterImp.h"

GFCENGINE_NAMESPACE_BEGIN

GFCENGINE_IMP_FACTORY(CWriterImp, 0)

CWriterImp::CWriterImp(void): m_nCount(0), m_nCodePage(CP_UTF8), m_bUppercase(true)
{
}


CWriterImp::~CWriterImp(void)
{
}

EntityRef CWriterImp::writeEntity(CEntity * pEntity)
{
    if (!inIgnoreDuplicatesEntitySet(pEntity->entityName()))
    {
        return doWriteEntity(pEntity);
    }
    else
    {
        auto sKey = pEntity->toString();
        auto itr = m_oDuplicatesMap.find(sKey);
        if (itr != m_oDuplicatesMap.end())
        {
            return itr->second;
        }
        else
        {
            auto nRef = doWriteEntity(pEntity);
            m_oDuplicatesMap.insert(std::make_pair(sKey, nRef));
            return nRef;
        }
    }
}

void CWriterImp::addIgnoreDuplicates(const std::wstring & sEntityName)
{
    m_oIgnoreDuplicatesEntitySet.insert(sEntityName);
}

void CWriterImp::setCodePage(UINT nCodePage)
{
    m_nCodePage = nCodePage;
}

void CWriterImp::setUppercase(bool bUppercase)
{
    m_bUppercase = bUppercase;
}

bool CWriterImp::inIgnoreDuplicatesEntitySet(const std::wstring & sEntityName)
{
    return m_oIgnoreDuplicatesEntitySet.find(sEntityName) != m_oIgnoreDuplicatesEntitySet.end();
}

GFCENGINE_NAMESPACE_END