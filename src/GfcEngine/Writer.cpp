#include "glodon/objectbuf/Writer.h"
//#include "WriterBinaryImp.h"
//#include "WriterTextImp.h"
#include "WriterImp.h"
#include "SerializerManager.h"

namespace glodon {
namespace objectbuf {

Writer::Writer(void): m_pImp(NULL)
{
}


Writer::~Writer(void)
{
    close();
}

bool Writer::open( const string& sFileName, const std::string& sFormatType, const string& sProductCode )
{
    m_pSerializerManager = SerializerManager::getInstance();
    auto m_pImp = m_pSerializerManager->getWriterImp(sFormatType);
    return m_pImp ? m_pImp->open(sFileName, sProductCode) : false;
}

void Writer::close()
{
    if (m_pImp)
    {
        m_pImp->close();
    }
}

glodon::objectbuf::EntityRef Writer::writeEntity( Entity* pEntity )
{
    if (m_pImp)
    {
        return m_pImp->writeEntity(pEntity);
    }
    return -1;
}

}
}