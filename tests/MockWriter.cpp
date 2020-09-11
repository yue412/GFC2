#include "MockWriter.h"

GFCENGINE_NAMESPACE_BEGIN

CMockWriter::CMockWriter() : CWriter(nullptr), m_nCount(0)
{
}


CMockWriter::~CMockWriter()
{
}

bool CMockWriter::open(const std::wstring& sFileName, const std::wstring& sFormatType)
{
    m_nCount = 0;
    return true;
}

void CMockWriter::close()
{
}

bool CMockWriter::isOpen()
{
    return true;
}

EntityRef CMockWriter::writeEntity(CEntity * pEntity)
{
    return ++m_nCount;
}

GFCENGINE_NAMESPACE_END