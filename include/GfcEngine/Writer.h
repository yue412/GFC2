#ifndef GLODON_OBJECTBUF_WRITER_H
#define GLODON_OBJECTBUF_WRITER_H

#include <string>
#include <memory>
#include "GfcEngine\Entity.h"
#include "GfcEngine\Document.h"

GFCENGINE_NAMESPACE_BEGIN

class CWriterImp;

class GFCENGINE_API CWriter
{
public:
    CWriter(const std::wstring& sVersion, const std::wstring& sProductCode = L"");
    ~CWriter(void);
    bool open(const std::wstring& sFileName, const std::wstring& sFormatType);
    void close();
    EntityRef writeEntity(CEntity* pEntity); 
private:
    CWriterImp* m_pImp;
    std::wstring m_sVersion;
    std::wstring m_sProductCode;
};

GFCENGINE_NAMESPACE_END

#endif