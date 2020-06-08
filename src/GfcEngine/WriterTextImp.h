#ifndef WRITERTEXTIMP_H
#define WRITERTEXTIMP_H

#include <string>
#include "WriterImp.h"
#include <fstream>

GFCENGINE_NAMESPACE_BEGIN

class CPropValue;

// 内部实现，不对外公开
class CWriterTextImp: public CWriterImp
{
    GFCENGINE_DEC_OBJECT(CWriterTextImp, CWriterImp)
public:
    CWriterTextImp(void);
    virtual ~CWriterTextImp(void);
    virtual bool open(const std::wstring& sFileName, const std::wstring& sProductCode, const std::wstring& sVersion);
    virtual void close();
    virtual EntityRef writeEntity(CEntity* pEntity); 
private:
    void writeHead(const std::wstring& sFileName, const std::wstring& sProductCode, const std::wstring& sVersion);
    void writeValue(gfc::schema::CAttribute* pSchema, CPropValue* pValue);
    void writeProperty(CProperty* pProp);
    std::fstream* m_pTextStream;
};

GFCENGINE_NAMESPACE_END

#endif
