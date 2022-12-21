#ifndef READERTEXTIMP_H
#define READERTEXTIMP_H

#include <map>
#include "ReaderFileMapImp.h"
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

class CReaderTextImp : public CReaderFileMapImp
{
    GFCENGINE_DEC_OBJECT(CReaderTextImp, CReaderImp)
public:
    CReaderTextImp();
    virtual ~CReaderTextImp(void);

    virtual bool preRead(const std::wstring& sFileName); // 判断是否是可以读的格式
    virtual std::wstring readFileVersion();
    virtual std::wstring readStandardVersion();
protected:
    virtual bool getIndex(EntityInfo& oInfo);//顺序读取index
    virtual CEntity* createEntity(__int64 nPos);
};

// 便于测试
class CReaderTextUtils
{
public:
    static bool parseBoolean(const std::string& input, bool& value);
    static bool parseInt(const std::string& input, int& value);
    static bool parseFloat(const std::string& input, double& value);
    static bool parseString(const std::string& input, std::string& value);
    static bool parseEntity(const std::string& input, EntityRef& value);

    static bool parseBooleanField(const std::string& input, CPropValue* pValue);
    static bool parseIntField(const std::string& input, CPropValue* pValue);
    static bool parseFloatField(const std::string& input, CPropValue* pValue);
    static bool parseStringField(const std::string& input, CPropValue* pValue);
    static bool parseEnumField(const std::string& input, gfc::schema::CEnumType* pEnumType, CPropValue* pValue);
    static bool parseEntityField(const std::string& input, CPropValue* pValue);

    static bool parseLine(const std::string & sLine, EntityRef& nId, std::string& sName, std::string& sContent);
    static bool getNextValue(const std::string& input, int nStartPos, std::string& sValue);
    static bool parse(const std::string& input, CEntity* pEntity, std::wstring& error);
    static bool parseField(const std::string& input, gfc::schema::CTypeObject* pType, CPropValue * pValue);

};

GFCENGINE_NAMESPACE_END

#endif
