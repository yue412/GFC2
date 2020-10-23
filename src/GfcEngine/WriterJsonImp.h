#ifndef WRITERJSONIMP_H
#define WRITERJSONIMP_H

#include <string>
#include <fstream>

#include "WriterImp.h"
#include "GfcEngine\JsonWrapper.h"

GFCENGINE_NAMESPACE_BEGIN

class CPropValue;

// 内部实现，不对外公开
class CWriterJsonImp: public CWriterImp
{
    GFCENGINE_DEC_OBJECT(CWriterJsonImp, CWriterImp)
public:
    CWriterJsonImp(void);
    virtual ~CWriterJsonImp(void);
    virtual bool open(const std::wstring& sFileName, const std::wstring& sProductCode, const std::wstring& sVersion);
    virtual void close();
protected:
    virtual void doWriteEntity(EntityRef nId, CEntity* pEntity);
private:
    void writeHead(JsonWrapper& rootJson, const std::wstring& sFileName, const std::wstring& sProductCode, const std::wstring& sVersion);
    std::string toString(const std::wstring& str);
    std::fstream* m_pJsonStream;
    rapidjson::Document* m_pDocument;
    JsonWrapper* m_pRootDocument;
};

GFCENGINE_NAMESPACE_END

#endif
