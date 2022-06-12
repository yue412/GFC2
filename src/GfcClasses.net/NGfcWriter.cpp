#include "NGfcWriter.h"
#include <msclr\marshal_cppstd.h>
#include "GfcClasses\x3\Writer.h"

using namespace msclr::interop;

NGfcWriter::NGfcWriter(String^ sProductCode)
{
    m_pWriter = new gfc::classes::x3::CWriter(marshal_as<std::wstring>(sProductCode));
}

NGfcWriter::~NGfcWriter()
{
    delete m_pWriter;
}

bool NGfcWriter::open( String^ sFileName, String^ sFormatType /*= ""*/ )
{
    return m_pWriter->open(marshal_as<std::wstring>(sFileName), marshal_as<std::wstring>(sFormatType));
}

void NGfcWriter::close()
{
    m_pWriter->close();
}

gfc::engine::EntityRef NGfcWriter::writeEntity( NGfcEntity^ pEntity )
{
    return m_pWriter->writeEntity(pEntity->getEntity());
}