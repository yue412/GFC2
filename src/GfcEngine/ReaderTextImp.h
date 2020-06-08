#ifndef READERTEXTIMP_H
#define READERTEXTIMP_H

#include <map>
#include "ReaderImp.h"
#include "GfcEngine\GfcEngine.h"

namespace gfc {
    namespace schema {
        class CEnumType;
        class CTypeObject;
    }
}

GFCENGINE_NAMESPACE_BEGIN

class CEntity;
class CPropValue;

class CReaderTextImp: public CReaderImp
{
    GFCENGINE_DEC_OBJECT(CReaderTextImp, CReaderImp)
public:
    CReaderTextImp();
    virtual ~CReaderTextImp(void);

    virtual bool preRead(const std::wstring& sFileName); // 判断是否是可以读的格式
    virtual std::wstring readFileVersion();
protected:
    virtual bool getIndex(EntityInfo& oInfo);//顺序读取index
    virtual CEntity* createEntity(__int64 nPos, EntityRef& nId);
private:
    bool parseLine(const std::string & sLine, EntityRef& nId, std::string& sName, std::string& sContent);
    bool getNextValue(const std::string& input, int nStartPos, std::string& sValue);
    bool parse(const std::string& input, CEntity* pEntity, std::wstring& error);
    bool parseField(const std::string& input, gfc::schema::CTypeObject* pType, CPropValue * pValue);
    bool parseBoolean(const std::string& input, bool& value);
    bool parseInt(const std::string& input, int& value);
    bool parseFloat(const std::string& input, double& value);
    bool parseString(const std::string& input, std::string& value);
    bool parseEntity(const std::string& input, EntityRef& value);

    bool parseBooleanField(const std::string& input, CPropValue* pValue);
    bool parseIntField(const std::string& input, CPropValue* pValue);
    bool parseFloatField(const std::string& input, CPropValue* pValue);
    bool parseStringField(const std::string& input, CPropValue* pValue);
    bool parseEnumField(const std::string& input, gfc::schema::CEnumType* pEnumType, CPropValue* pValue);
    bool parseEntityField(const std::string& input, CPropValue* pValue);

};

GFCENGINE_NAMESPACE_END

#endif
