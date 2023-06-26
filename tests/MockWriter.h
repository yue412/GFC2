#ifndef MOCKWRITER_H
#define MOCKWRITER_H

#include "GfcEngine/Writer.h"
#include "GfcEngine/SysMarco.h"

GFCENGINE_NAMESPACE_BEGIN

class CMockWriter :
    public CWriter
{
public:
    CMockWriter();
    virtual ~CMockWriter();

    virtual bool open(const std::wstring& sFileName, const std::wstring& sFormatType);
    virtual void close();
    virtual bool isOpen();
    virtual EntityRef writeEntity(CEntity* pEntity);
private:
    gfc::engine::EntityRef m_nCount;
};

class CMockDocWriter :
    public CWriter
{
public:
    CMockDocWriter(gfc::engine::CDocument* pDoc);
    virtual ~CMockDocWriter();

    virtual bool open(const std::wstring& sFileName, const std::wstring& sFormatType);
    virtual void close();
    virtual bool isOpen();
    virtual EntityRef writeEntity(CEntity* pEntity);
private:
    gfc::engine::CDocument* m_pDoc;
};

GFCENGINE_NAMESPACE_END

#endif // !MOCKWRITERIMP_H
