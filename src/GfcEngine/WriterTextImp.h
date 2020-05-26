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
    virtual bool open(const string& sFileName, const string& sProductCode, const string& sVersion);
    virtual void close();
    virtual EntityRef writeEntity(Entity* pEntity); 
private:
    void writeHead(const string& sFileName, const string& sProductCode, const string& sVersion);
    void writeValue(gfc2::schema::CAttribute* pSchema, PropValue* pValue);
    void writeProperty(Property* pProp);
    std::fstream* m_pTextStream;
};

GFCENGINE_NAMESPACE_END

#endif
