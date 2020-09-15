#ifndef GLODON_OBJECTBUF_WRITER_H
#define GLODON_OBJECTBUF_WRITER_H

#include <string>
#include <memory>
#include <Windows.h>
#include "GfcEngine\Entity.h"
#include "GfcEngine\Document.h"

namespace gfc {
    namespace schema {
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CWriterImp;

class GFCENGINE_API CWriter
{
public:
    // 一般情况下，CodePage不用设置。只有生成老版本GFC时有用
    // 生成老版本时，为兼容以前代码，需要将bUppercase设为false
    CWriter(gfc::schema::CModel* pSchema, const std::wstring& sProductCode = L"", UINT nCodePage = CP_UTF8, bool bUppercase = true);
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
    bool m_bUppercase;
};

GFCENGINE_NAMESPACE_END

#endif
