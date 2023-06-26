#include "MockWriter.h"
#include "GfcEngine/Document.h"

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

CMockDocWriter::CMockDocWriter(gfc::engine::CDocument* pDoc) : CWriter(nullptr), m_pDoc(pDoc)
{
}

CMockDocWriter::~CMockDocWriter()
{
}

bool CMockDocWriter::open(const std::wstring & sFileName, const std::wstring & sFormatType)
{
    return true;
}

void CMockDocWriter::close()
{
}

bool CMockDocWriter::isOpen()
{
    return true;
}

EntityRef CMockDocWriter::writeEntity(CEntity * pEntity)
{
    pEntity->setContainer(m_pDoc);
    return m_pDoc->add(pEntity);
}


GFCENGINE_NAMESPACE_END

