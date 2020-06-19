#ifndef GLODON_OBJECTBUF_WRITER_H
#define GLODON_OBJECTBUF_WRITER_H

#include <string>
#include <memory>
#include <Windows.h>
#include "GfcEngine\Entity.h"
#include "GfcEngine\Document.h"

GFCENGINE_NAMESPACE_BEGIN

class CWriterImp;

class GFCENGINE_API CWriter
{
public:
    // 一般情况下，CodePage不用设置。只有生成老版本GFC时有用
    CWriter(const std::wstring& sVersion, const std::wstring& sProductCode = L"", UINT nCodePage = CP_UTF8);
    virtual ~CWriter(void);
    virtual bool open(const std::wstring& sFileName, const std::wstring& sFormatType);
    virtual void close();
    virtual bool isOpen();
    virtual EntityRef writeEntity(CEntity* pEntity);
    void addIgnoreDuplicates(const std::wstring& sEntityName);
private:
    CWriterImp* m_pImp;
    std::wstring m_sVersion;
    std::wstring m_sProductCode;
    UINT m_nCodePage;
};

GFCENGINE_NAMESPACE_END

#endif
