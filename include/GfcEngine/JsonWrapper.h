#pragma once
#pragma warning(push)
#pragma warning(disable : 4251)
#pragma warning(disable : 4003)

#include <memory>
#include <string>
#include "rapidjson/document.h"
#include "GfcEngine/GfcEngine.h"
#include "rapidjson/filereadstream.h"

GFCENGINE_NAMESPACE_BEGIN

typedef long long int64;

class GFCENGINE_API JsonWrapper
{
public:  // method of ordinary json object or json array
    bool Parse(const std::string& strJson);
    bool Parse(rapidjson::FileReadStream& fileStream);

    bool GetValueAsString(const std::string& strKey, std::string& strValue) const;
    bool Get(const std::string& strKey, std::string& strValue) const;
    bool Get(const std::string& strKey, int& iValue) const;
    bool Get(const std::string& strKey, int64_t& llValue) const;
    bool Get(const std::string& strKey, JsonWrapper& oJsonObject) const;
    bool Get(const std::string& strKey, double& dValue) const;
    bool GetBool(const std::string& strKey, bool& bValue) const;
    bool Get(int iWhich, JsonWrapper& oJsonObject) const;
    bool Get(int iWhich, int& iValue) const;
    bool Get(int iWhich, int64_t& llValue) const;
    bool Get(int iWhich, double& dValue) const;
    bool Get(int iWhich, std::string& strValue) const;
    bool GetBool(int iWhich, bool& bValue) const;
    bool IsArray() const;
    bool IsObject() const;
    int GetArraySize() const;
    JsonWrapper operator[](unsigned int index);
    JsonWrapper operator[](const std::string& strKey) const;
    std::string operator()(const std::string& strKey) const;

    // bool Add(const std::string& strKey, bool bValue);
    bool Add(const std::string& strKey, int iValue);
    bool Add(const std::string& strKey, int64_t llValue);
    bool Add(const std::string& strKey, const std::string& strValue);
    bool Add(const std::string& strKey, double dValue);
    bool Add(const std::string& strKey, const JsonWrapper& oJsonObject);
    bool AddBool(const std::string& strKey, bool bValue);
    bool Add(const JsonWrapper& oJsonObject);
    bool AddEmptySubObject(const std::string& strKey);
    bool AddEmptySubArray(const std::string& strKey);
    bool Add(int iValue);
    bool AddBool(bool bValue);
    bool Add(int64_t llValue);
    bool Add(double dValue);
    bool Add(const std::string& strValue);

    std::string ToString() const;
    void BeginIterator();
    bool GetKey(std::string& strKey);
    bool GetValue(std::string& strValue) const;
    bool GetValue(int& iValue) const;
    bool GetValue(int64_t& llValue) const;
    bool GetValue(JsonWrapper& oJsonObject) const;

    bool Replace(const std::string& strKey, int iValue);
    bool Replace(const std::string& strKey, int64_t llValue);
    bool Replace(const std::string& strKey, const std::string& strValue);

    bool Clear();

    bool HasParseError() const;

    bool HasMember(const std::string& strKey) const
    {
        return m_pValue->IsObject() && m_pValue->HasMember(strKey.c_str());
    }

    bool HasError() const { return m_bParseError; }

    rapidjson::Document::AllocatorType* GetAllocator() const { return m_pAllocator; }

    explicit JsonWrapper(const JsonWrapper* pJsonObject);
    JsonWrapper(const JsonWrapper& oJsonObject);
    virtual ~JsonWrapper();
    explicit JsonWrapper(rapidjson::Document::AllocatorType* pAllocator, rapidjson::Type type = rapidjson::kNullType);
    explicit JsonWrapper(rapidjson::Document* pDoc);

private:
    JsonWrapper();

    void SetValue(rapidjson::Value* pValue);
    void SetValue(const JsonWrapper& oJsonObject);

private:
    rapidjson::Value* m_pValue;
    rapidjson::Document::AllocatorType* m_pAllocator;
    rapidjson::Value::MemberIterator m_iterMember;
    bool m_bParseError;
    bool m_bRef = true;
};

GFCENGINE_NAMESPACE_END

#pragma warning(pop)
