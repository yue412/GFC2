#include "NWriter.h"
#include <msclr\marshal_cppstd.h>
#include "GfcClasses\x3\Writer.h"

using namespace msclr::interop;

NWriter::NWriter(System::String^ sProductCode)
{
    m_pWriter = new gfc::classes::x3::CWriter(marshal_as<std::wstring>(sProductCode));
}

NWriter::~NWriter()
{
    delete m_pWriter;
}

bool NWriter::open(System::String^ sFileName, System::String^ sFormatType /*= ""*/ )
{
    return m_pWriter->open(marshal_as<std::wstring>(sFileName), marshal_as<std::wstring>(sFormatType));
}

void NWriter::close()
{
    m_pWriter->close();
}

gfc::engine::EntityRef NWriter::writeEntity( NEntity^ pEntity )
{
    return m_pWriter->writeEntity(pEntity->getEntity());
}

gfc::engine::CWriter * NWriter::getWriter()
{
    return m_pWriter;
}
