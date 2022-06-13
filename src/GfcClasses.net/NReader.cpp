#include "NReader.h"
#include <msclr\marshal_cppstd.h>
#include "GfcClasses\x3\Reader.h"

using namespace msclr::interop;

NReader::NReader()
{
    m_pReader = new gfc::classes::x3::CReader();
}

NReader::~NReader()
{
    delete m_pReader;
}

void NReader::setSchemaPath(System::String ^ sSchemaPath)
{
    m_pReader->setSchemaPath(marshal_as<std::wstring>(sSchemaPath));
}

bool NReader::open(System::String^ sFileName )
{
    return m_pReader->open(marshal_as<std::wstring>(sFileName));
}

void NReader::close()
{
    m_pReader->close();
}

void NReader::read(NDocument ^ pDoc)
{
    m_pReader->read(pDoc->raw());
}