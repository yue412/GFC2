#include "Writer.h"
#include <msclr\marshal_cppstd.h>
#include "GfcClasses\x3\GfcWriter.h"

using namespace msclr::interop;

namespace gfc { namespace engine { namespace net {

Writer::Writer(String^ sProductCode)
{
    m_pWriter = new gfc::classes::x3::GfcWriter(marshal_as<std::wstring>(sProductCode));
}

Writer::~Writer()
{
    delete m_pWriter;
}

bool Writer::open( String^ sFileName, String^ sFormatType /*= ""*/ )
{
    return m_pWriter->open(marshal_as<std::wstring>(sFileName), marshal_as<std::wstring>(sFormatType));
}

void Writer::close()
{
    m_pWriter->close();
}

gfc::engine::EntityRef Writer::writeEntity( Entity^ pEntity )
{
    return m_pWriter->writeEntity(pEntity->getEntity());
}

}}}
