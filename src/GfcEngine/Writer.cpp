#include "GfcEngine/Writer.h"
//#include "WriterBinaryImp.h"
//#include "WriterTextImp.h"
#include "WriterImp.h"

GFCENGINE_NAMESPACE_BEGIN

Writer::Writer(void): m_pImp(NULL)
{
}


Writer::~Writer(void)
{
    close();
}

bool Writer::open( const string& sFileName, const std::string& sFormatType, const string& sVersion, const string& sProductCode )
{
    close();
    m_pImp = (WriterImp*)WriterImp::GetFactory()->Create(sFormatType);
    return m_pImp->open(sFileName, sProductCode, sVersion);
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