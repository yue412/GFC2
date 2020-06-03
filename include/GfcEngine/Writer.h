#ifndef GLODON_OBJECTBUF_WRITER_H
#define GLODON_OBJECTBUF_WRITER_H

#include <string>
#include <memory>
#include "GfcEngine\Entity.h"
#include "GfcEngine\Document.h"

GFCENGINE_NAMESPACE_BEGIN

class WriterImp;

class GFCENGINE_API Writer
{
public:
    Writer(const std::wstring& sVersion, const std::wstring& sProductCode = L"");
    ~Writer(void);
    bool open(const std::wstring& sFileName, const std::wstring& sFormatType);
    void close();
    EntityRef writeEntity(Entity* pEntity); 
private:
    WriterImp* m_pImp;
    std::wstring m_sVersion;
    std::wstring m_sProductCode;
};

GFCENGINE_NAMESPACE_END

#endif
