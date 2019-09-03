#include "glodon/objectbuf/Writer.h"
#include "WriterBinaryImp.h"
#include "WriterTextImp.h"

namespace glodon {
namespace objectbuf {

Writer::Writer(void): m_pImp(NULL)
{
}


Writer::~Writer(void)
{
    close();
}

bool Writer::open( const string& sFileName, bool bIsBinary,const string& sProductCode )
{
    if (bIsBinary)
    {
        m_pImp = new WriterBinaryImp();
    }
    else
    {
        m_pImp = new WriterTextImp();
    }
    return m_pImp->open(sFileName, sProductCode);
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