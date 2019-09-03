#include "Writer.h"
#include <msclr\marshal_cppstd.h>

using namespace msclr::interop;

namespace glodon {
namespace objectbufnet {

Writer::Writer(void)
{
    m_pWriter = new glodon::objectbuf::Writer();
}

Writer::~Writer()
{
    delete m_pWriter;
}

bool Writer::open( String^ sFileName, bool bIsBinary /*= true*/, String^ sProductCode /*= ""*/ )
{
    return m_pWriter->open(marshal_as<std::string>(sFileName), bIsBinary,  marshal_as<std::string>(sProductCode));
}

void Writer::close()
{
    m_pWriter->close();
}

glodon::objectbuf::EntityRef Writer::writeEntity( Entity^ pEntity )
{
    return m_pWriter->writeEntity(pEntity->getEntity());
}

}
}
