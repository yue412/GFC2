#ifndef WRITERTEXTIMP_H
#define WRITERTEXTIMP_H

#include <string>
#include "WriterImp.h"
#include <fstream>

GFCENGINE_NAMESPACE_BEGIN

class PropValue;

// 内部实现，不对外公开
class WriterTextImp: public WriterImp
{
    GFCENGINE_DEC_OBJECT(WriterTextImp, WriterImp)
public:
    WriterTextImp(void);
    virtual ~WriterTextImp(void);
    virtual bool open(const std::wstring& sFileName, const std::wstring& sProductCode, const std::wstring& sVersion);
    virtual void close();
    virtual EntityRef writeEntity(Entity* pEntity); 
private:
    void writeHead(const std::wstring& sFileName, const std::wstring& sProductCode, const std::wstring& sVersion);
    void writeValue(gfc::schema::CAttribute* pSchema, PropValue* pValue);
    void writeProperty(Property* pProp);
    std::fstream* m_pTextStream;
};

GFCENGINE_NAMESPACE_END

#endif
