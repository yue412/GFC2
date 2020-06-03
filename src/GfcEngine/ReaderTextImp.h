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

class Entity;
class PropValue;

class ReaderTextImp: public ReaderImp
{
    GFCENGINE_DEC_OBJECT(ReaderTextImp, ReaderImp)
public:
    ReaderTextImp();
    virtual ~ReaderTextImp(void);

    virtual bool preRead(const std::wstring& sFileName); // 判断是否是可以读的格式
    virtual void read(Document* pDoc, std::vector<std::wstring>& errors);
protected:
    virtual bool getIndex(EntityInfo& oInfo);//顺序读取index
    virtual Entity* createEntity(EntityInfo& oInfo);
private:
    bool parseLine(const std::string & sLine, EntityRef& nId, std::string& sName, std::string& sContent);
    bool getNextValue(const std::string& input, int nStartPos, std::string& sValue);
    bool parse(const std::string& input, Entity* pEntity, std::wstring& error);
    bool parseField(const std::string& input, gfc::schema::CTypeObject* pType, PropValue * pValue);
    bool parseBoolean(const std::string& input, bool& value);
    bool parseInt(const std::string& input, int& value);
    bool parseFloat(const std::string& input, double& value);
    bool parseString(const std::string& input, std::string& value);
    bool parseEntity(const std::string& input, EntityRef& value);

    bool parseBooleanField(const std::string& input, PropValue* pValue);
    bool parseIntField(const std::string& input, PropValue* pValue);
    bool parseFloatField(const std::string& input, PropValue* pValue);
    bool parseStringField(const std::string& input, PropValue* pValue);
    bool parseEnumField(const std::string& input, gfc::schema::CEnumType* pEnumType, PropValue* pValue);
    bool parseEntityField(const std::string& input, PropValue* pValue);

};

GFCENGINE_NAMESPACE_END

#endif
