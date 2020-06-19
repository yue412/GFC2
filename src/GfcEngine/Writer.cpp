#include "GfcEngine/Writer.h"
//#include "WriterBinaryImp.h"
//#include "WriterTextImp.h"
#include "WriterImp.h"

GFCENGINE_NAMESPACE_BEGIN

CWriter::CWriter(const std::wstring& sVersion, const std::wstring& sProductCode): m_pImp(NULL), m_sVersion(sVersion), m_sProductCode(sProductCode)
{
}


CWriter::~CWriter(void)
{
    close();
}

bool CWriter::open( const std::wstring& sFileName, const std::wstring& sFormatType )
{
    close();
    m_pImp = (CWriterImp*)CWriterImp::GetFactory()->Create(sFormatType);
    auto bResult = m_pImp->open(sFileName, m_sProductCode, m_sVersion);
    if (!bResult)
    {
        delete m_pImp; 
        m_pImp = nullptr;
    }
    return bResult;
}

void CWriter::close()
{
    if (m_pImp)
    {
        m_pImp->close();
        delete m_pImp;
        m_pImp = nullptr;
    }
}

bool CWriter::isOpen()
{
    return m_pImp != nullptr;
}

EntityRef CWriter::writeEntity( CEntity* pEntity )
{
    if (m_pImp)
    {
        //pEntity->setDocument(&m_oDoc);
        return m_pImp->writeEntity(pEntity);
    }
    return -1;
}

void CWriter::addIgnoreDuplicates(const std::wstring & sEntityName)
{
    if (m_pImp)
    {
        m_pImp->addIgnoreDuplicates(sEntityName);
    }
}

GFCENGINE_NAMESPACE_END