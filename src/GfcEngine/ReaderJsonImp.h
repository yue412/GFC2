#ifndef READERTEXTIMP_H
#define READERTEXTIMP_H

#include <map>
#include "ReaderImp.h"
#include "GfcEngine\GfcEngine.h"
#include "GfcEngine\JsonWrapper.h"

namespace gfc {
    namespace schema {
        class CEnumType;
        class CTypeObject;
        class CModel;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CEntity;
class CPropValue;

class CReaderJsonImp : public CReaderImp
{
    GFCENGINE_DEC_OBJECT(CReaderJsonImp, CReaderImp)
public:
    CReaderJsonImp();
    virtual ~CReaderJsonImp(void);

    virtual bool preRead(const std::wstring& sFileName);
    virtual bool open(const std::wstring& sFileName);
    virtual std::wstring readFileVersion();
    virtual std::wstring readStandardVersion();
    virtual void read(CDocument* pDoc);

private:
    JsonWrapper* getRootDocument();
    bool initRootDocument(const std::wstring& sFileName);

private:
    rapidjson::Document* m_pDocument;
    JsonWrapper* m_pRootDocument;

private:
};

GFCENGINE_NAMESPACE_END

#endif
