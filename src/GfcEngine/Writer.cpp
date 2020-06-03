#include "GfcEngine/Writer.h"
//#include "WriterBinaryImp.h"
//#include "WriterTextImp.h"
#include "WriterImp.h"

GFCENGINE_NAMESPACE_BEGIN

Writer::Writer(const std::wstring& sVersion, const std::wstring& sProductCode): m_pImp(NULL), m_sVersion(sVersion), m_sProductCode(sProductCode)
{
}


Writer::~Writer(void)
{
    close();
}

bool Writer::open( const std::wstring& sFileName, const std::wstring& sFormatType )
{
    close();
    m_pImp = (WriterImp*)WriterImp::GetFactory()->Create(sFormatType);
    return m_pImp->open(sFileName, m_sProductCode, m_sVersion);
}

void Writer::close()
{
    if (m_pImp)
    {
        m_pImp->close();
        delete m_pImp;
        m_pImp = nullptr;
    }
}

EntityRef Writer::writeEntity( Entity* pEntity )
{
    if (m_pImp)
    {
        //pEntity->setDocument(&m_oDoc);
        return m_pImp->writeEntity(pEntity);
    }
    return -1;
}

GFCENGINE_NAMESPACE_END