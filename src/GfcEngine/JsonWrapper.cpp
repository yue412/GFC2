#include "GfcEngine\JsonWrapper.h"
#include "rapidjson\writer.h"

GFCENGINE_NAMESPACE_BEGIN

bool JsonWrapper::Parse(const std::string& strJson)
{
    rapidjson::Document* pDocument = (rapidjson::Document*)m_pValue;
    pDocument->Parse(strJson.c_str());

    m_bParseError = pDocument->HasParseError();
    return !m_bParseError;
}

bool JsonWrapper::Parse(rapidjson::FileReadStream& fileStream)
{
    rapidjson::Document* pDocument = (rapidjson::Document*)m_pValue;
    pDocument->ParseStream(fileStream);

    m_bParseError = pDocument->HasParseError();
    return !m_bParseError;
}

bool JsonWrapper::GetValueAsString(const std::string& strKey, std::string& strValue) const
{
    assert(IsObject());
    rapidjson::Value::MemberIterator iterMember = m_pValue->FindMember(strKey.c_str());
    if (iterMember == m_pValue->MemberEnd())
    {
        return false;
    }

    const auto& value = iterMember->value;
    if (value.IsString())
    {
        strValue = value.GetString();
    }
    else if (value.IsInt64())
    {
        strValue = std::to_string(value.GetInt64());
    }
    else if (value.IsInt())
    {
        strValue = std::to_string(value.GetInt());
    }
    else if (value.IsNumber())
    {
        strValue = std::to_string(value.GetDouble());
    }
    else
    {
        return false;
    }

    return true;
}

bool JsonWrapper::Get(const std::string& strKey, std::string& strValue) const
{
    assert(IsObject());
    rapidjson::Value::MemberIterator iterMember = m_pValue->FindMember(strKey.c_str());
    if (iterMember == m_pValue->MemberEnd())
    {
        return false;
    }

    const auto& value = iterMember->value;
    if (!value.IsString())
    {
        return false;
    }

    strValue = value.GetString();

    return true;
}

bool JsonWrapper::Get(const std::string& strKey, int& iValue) const
{
    assert(IsObject());
    rapidjson::Value::MemberIterator iterMember = m_pValue->FindMember(strKey.c_str());
    if (iterMember == m_pValue->MemberEnd())
    {
        return false;
    }

    const auto& value = iterMember->value;
    if (!value.IsInt())
    {
        return false;
    }
    iValue = value.GetInt();

    return true;
}

bool JsonWrapper::Get(const std::string& strKey, int64_t& llValue) const
{
    assert(IsObject());
    rapidjson::Value::MemberIterator iterMember = m_pValue->FindMember(strKey.c_str());
    if (iterMember == m_pValue->MemberEnd())
    {
        return false;
    }

    const auto& value = iterMember->value;
    if (!value.IsInt64())
    {
        return false;
    }
    llValue = value.GetInt64();

    return true;
}

bool JsonWrapper::Get(const std::string& strKey, JsonWrapper& oJsonObject) const
{
    assert(IsObject());
    rapidjson::Value::MemberIterator iterMember = m_pValue->FindMember(strKey.c_str());
    if (iterMember == m_pValue->MemberEnd())
    {
        return false;
    }

    auto& value = iterMember->value;
    if (!value.IsObject() && !value.IsArray())
    {
        return false;
    }
    oJsonObject.SetValue(&value);
    oJsonObject.m_pAllocator = m_pAllocator;
    oJsonObject.m_bParseError = m_bParseError;

    return true;
}

bool JsonWrapper::Get(const std::string& strKey, double& dValue) const
{
    assert(IsObject());
    rapidjson::Value::MemberIterator iterMember = m_pValue->FindMember(strKey.c_str());
    if (iterMember == m_pValue->MemberEnd())
    {
        return false;
    }

    const auto& value = iterMember->value;
    if (value.IsNumber())
    {
        dValue = value.GetDouble();
    }
    else 
    {
        std::string dbg = ToString();
        assert(false);
        return false;
    }

    return true;
}

bool JsonWrapper::GetBool(const std::string& strKey, bool& bValue) const
{
    assert(IsObject());
    rapidjson::Value::MemberIterator iterMember = m_pValue->FindMember(strKey.c_str());
    if (iterMember == m_pValue->MemberEnd())
    {
        return false;
    }

    const auto& value = iterMember->value;
    if (value.IsBool())
    {
        bValue = value.GetBool();
    }
    else 
    {
        assert(false);
        return false;
    }

    return true;
}

bool JsonWrapper::Get(int iWhich, int& iValue) const
{
    assert(IsArray());
    if (m_pValue->Empty())
    {
        return false;
    }

    const auto& value = (*m_pValue)[iWhich];
    iValue = value.GetInt();

    return value.IsInt();
}

bool JsonWrapper::Get(int iWhich, int64_t& llValue) const
{
    assert(IsArray());
    if (m_pValue->Empty())
    {
        return false;
    }

    const auto& value = (*m_pValue)[iWhich];
    llValue = value.GetInt64();

    return value.IsInt64();
}

bool JsonWrapper::Get(int iWhich, double& dValue) const
{
    assert(IsArray());
    if (m_pValue->Empty())
    {
        return false;
    }

    const auto& value = (*m_pValue)[iWhich];
    dValue = value.GetDouble();

    return value.IsDouble();
}

bool JsonWrapper::Get(int iWhich, std::string& strValue) const
{
    assert(IsArray());
    if (m_pValue->Empty())
    {
        return false;
    }
    const auto& value = (*m_pValue)[iWhich];
    if (!value.IsString())
    {
        return false;
    }
    strValue = value.GetString();

    return true;
}

bool JsonWrapper::GetBool(int iWhich, bool& bValue) const{
    assert(IsArray());
    if (m_pValue->Empty())
    {
        return false;
    }

    auto& value = (*m_pValue)[iWhich];
    bValue = value.GetBool();

    return value.IsBool();
}

bool JsonWrapper::Get(int iWhich, JsonWrapper& oJsonObject) const
{
    assert(IsArray());
    if (m_pValue->Empty())
    {
        return false;
    }

    oJsonObject.SetValue(&((*m_pValue)[iWhich]));
    oJsonObject.m_pAllocator = m_pAllocator;
    oJsonObject.m_bParseError = m_bParseError;

    return true;
}

bool JsonWrapper::IsArray() const
{
    bool result = m_pValue->IsArray();
    return result;
}

bool JsonWrapper::IsObject() const
{
    bool result = m_pValue->IsObject();
    return result;
}

int JsonWrapper::GetArraySize() const
{
    assert(IsArray());
    return m_pValue->Size();
}

JsonWrapper JsonWrapper::operator[](unsigned int index)
{
    assert(IsArray());
    JsonWrapper jsWrapper;
    jsWrapper.SetValue(&((*m_pValue)[index]));
    jsWrapper.m_pAllocator = m_pAllocator;
    jsWrapper.m_bParseError = m_bParseError;
    return jsWrapper;
}

JsonWrapper JsonWrapper::operator[](const std::string& strKey) const
{
    assert(IsObject());
    JsonWrapper jsWrapper;
    Get(strKey, jsWrapper);
    return jsWrapper;
}

std::string JsonWrapper::operator()(const std::string& strKey) const
{
    assert(IsObject());
    std::string strValue;
    if (!Get(strKey, strValue))
    {
        return "";
    }

    return strValue;
}

bool JsonWrapper::Add(const std::string& strKey, int iValue)
{
    assert(IsObject());
    rapidjson::Value memberKey(strKey.c_str(), *m_pAllocator);
    m_pValue->AddMember(memberKey, rapidjson::Value(iValue).Move(), *m_pAllocator);
    return true;
}

bool JsonWrapper::Add(const std::string& strKey, int64_t llValue)
{
    assert(IsObject());
    rapidjson::Value memberKey(strKey.c_str(), *m_pAllocator);
    m_pValue->AddMember(memberKey, rapidjson::Value(llValue).Move(), *m_pAllocator);
    return true;
}

bool JsonWrapper::Add(const std::string& strKey, const std::string& strValue)
{
    assert(IsObject());
    rapidjson::Value memberKey(strKey.c_str(), (rapidjson::SizeType)strKey.size(), *m_pAllocator);
    rapidjson::Value memberValue(strValue.c_str(), (rapidjson::SizeType)strValue.size(), *m_pAllocator);
    m_pValue->AddMember(memberKey, memberValue, *m_pAllocator);
    return true;
}

bool JsonWrapper::Add(const std::string& strKey, double dValue)
{
    assert(IsObject());
    rapidjson::Value memberKey(strKey.c_str(), *m_pAllocator);
    m_pValue->AddMember(memberKey, rapidjson::Value(dValue).Move(), *m_pAllocator);
    return true;
}

bool JsonWrapper::Add(const std::string& strKey, const JsonWrapper& oJsonObject)
{
    assert(IsObject());
    rapidjson::Value memberKey(strKey.c_str(), *m_pAllocator);
    rapidjson::Value memberValue(*oJsonObject.m_pValue, *m_pAllocator);
    m_pValue->AddMember(memberKey, memberValue, *m_pAllocator);

    return true;
}

bool JsonWrapper::AddBool(const std::string& strKey, bool bValue)
{
    assert(IsObject());
    rapidjson::Value memberKey(strKey.c_str(), *m_pAllocator);
    m_pValue->AddMember(memberKey, rapidjson::Value(bValue).Move(), *m_pAllocator);

    return true;
}

bool JsonWrapper::Add(const JsonWrapper& oJsonObject)
{
    assert(IsArray());
    rapidjson::Value memberValue(*oJsonObject.m_pValue, *m_pAllocator);
    m_pValue->PushBack(memberValue, *m_pAllocator);

    return true;
}
bool JsonWrapper::Add(int iValue)
{
    assert(IsArray());
    m_pValue->PushBack(iValue, *m_pAllocator);

    return true;
}
bool JsonWrapper::AddBool(bool bValue)
{
    assert(IsArray());
    m_pValue->PushBack(bValue, *m_pAllocator);

    return true;
}
bool JsonWrapper::Add(int64_t llValue)
{
    assert(IsArray());
    m_pValue->PushBack(llValue, *m_pAllocator);

    return true;
}

bool JsonWrapper::Add(double dValue)
{
    assert(IsArray());
    m_pValue->PushBack(dValue, *m_pAllocator);

    return true;
}

bool JsonWrapper::Add(const std::string& strValue)
{
    assert(IsArray());
    m_pValue->PushBack(rapidjson::Value{}.SetString(strValue.c_str(), 
        (rapidjson::SizeType)strValue.length(), *m_pAllocator), *m_pAllocator);

    return true;
}

bool JsonWrapper::AddEmptySubObject(const std::string& strKey)
{
    rapidjson::Value memberKey(strKey.c_str(), *m_pAllocator);
    rapidjson::Value object(rapidjson::kObjectType);
    m_pValue->AddMember(memberKey, object, *m_pAllocator);

    return true;
}

bool JsonWrapper::AddEmptySubArray(const std::string& strKey)
{
    rapidjson::Value memberKey(strKey.c_str(), *m_pAllocator);
    rapidjson::Value object(rapidjson::kArrayType);
    m_pValue->AddMember(memberKey, object, *m_pAllocator);

    return true;
}

std::string JsonWrapper::ToString() const
{
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    m_pValue->Accept(writer);
    return std::string(buffer.GetString(), buffer.GetSize());
}

void JsonWrapper::BeginIterator()
{
    rapidjson::Type type = m_pValue->GetType();
    switch (type)
    {
    case rapidjson::kObjectType:
        m_iterMember = m_pValue->MemberEnd();
        break;
    default:
        break;
    }
}

bool JsonWrapper::GetKey(std::string& strKey)
{
    rapidjson::Type type = m_pValue->GetType();
    switch (type)
    {
    case rapidjson::kObjectType:
    {
        if (&(*m_iterMember) == nullptr)
        {
            BeginIterator();
        }

        if (m_iterMember == m_pValue->MemberEnd())
        {
            m_iterMember = m_pValue->MemberBegin();
        }
        else
        {
            ++m_iterMember;
        }

        if (m_iterMember == m_pValue->MemberEnd())
        {
            return false;
        }

        strKey = m_iterMember->name.GetString();
    }
    break;
    case rapidjson::kArrayType:
    {
        // TODO: assert
        return false;
    }
    break;
    default:
        break;
    }

    return true;
}
bool JsonWrapper::GetValue(std::string& strValue) const
{
    const auto& value = m_iterMember->value;
    if (!value.IsString())
    {
        return false;
    }
    strValue = value.GetString();

    return true;
}
bool JsonWrapper::GetValue(int& iValue) const
{
    const auto& value = m_iterMember->value;
    if (!value.IsInt())
    {
        return false;
    }
    iValue = value.GetInt();

    return true;
}
bool JsonWrapper::GetValue(int64_t& llValue) const
{
    const auto& value = m_iterMember->value;
    if (!value.IsInt64())
    {
        return false;
    }
    llValue = value.GetInt64();

    return true;
}
bool JsonWrapper::GetValue(JsonWrapper& oJsonObject) const
{
    auto& value = m_iterMember->value;
    if (!value.IsObject() && !value.IsArray())
    {
        return false;
    }
    oJsonObject.SetValue(&(value));
    oJsonObject.m_pAllocator = m_pAllocator;

    return true;
}

bool JsonWrapper::Replace(const std::string& strKey, int iValue)
{
    rapidjson::Value::MemberIterator iterMember = m_pValue->FindMember(strKey.c_str());
    if (iterMember == m_pValue->MemberEnd())
    {
        Add(strKey, iValue);
    }
    else
    {
        iterMember->value.SetInt(iValue);
    }

    return true;
}
bool JsonWrapper::Replace(const std::string& strKey, int64_t llValue)
{
    rapidjson::Value::MemberIterator iterMember = m_pValue->FindMember(strKey.c_str());
    if (iterMember == m_pValue->MemberEnd())
    {
        Add(strKey, llValue);
    }
    else
    {
        iterMember->value.SetInt64(llValue);
    }

    return true;
}

bool JsonWrapper::Replace(const std::string& strKey, const std::string& strValue)
{
    rapidjson::Value::MemberIterator iterMember = m_pValue->FindMember(strKey.c_str());
    if (iterMember == m_pValue->MemberEnd())
    {
        Add(strKey, strValue);
    }
    else
    {
        iterMember->value.SetString(strValue.c_str(), *m_pAllocator);
    }

    return true;
}

bool JsonWrapper::Clear()
{
    assert(IsArray());
    if (!IsArray())
    {
        return false;
    }

    m_pValue->Clear();
    return true;
}

JsonWrapper::JsonWrapper(const JsonWrapper* pJsonObject)
{
    SetValue(*pJsonObject);
    m_pAllocator = pJsonObject->m_pAllocator;
    m_bParseError = pJsonObject->m_bParseError;
}
JsonWrapper::JsonWrapper(const JsonWrapper& oJsonObject)
{
    SetValue(oJsonObject);
    m_pAllocator = oJsonObject.m_pAllocator;
    m_bParseError = oJsonObject.m_bParseError;
}

JsonWrapper::JsonWrapper(rapidjson::Document::AllocatorType* pAllocator, rapidjson::Type type)
{
    if (type != rapidjson::kNullType)
    {
        m_pValue = new rapidjson::Value(type);
        m_bRef = false;
    }

    m_pAllocator = pAllocator;
    m_bParseError = false;
}

JsonWrapper::JsonWrapper(rapidjson::Document* pDoc)
{
    assert(pDoc);
    pDoc->SetObject();
    m_pValue = pDoc;
    m_pAllocator = &pDoc->GetAllocator();
    m_bParseError = false;
}

JsonWrapper::JsonWrapper()
{
    m_pValue = nullptr;
    m_pAllocator = nullptr;
    m_bParseError = false;
}

JsonWrapper::~JsonWrapper()
{
    SetValue(nullptr);
}

bool JsonWrapper::HasParseError() const
{
    return m_bParseError;
}

void JsonWrapper::SetValue(rapidjson::Value* pValue)
{
    if (!m_bRef && m_pValue)
        delete m_pValue;
    m_pValue = pValue;
    m_bRef = true;
}

void JsonWrapper::SetValue(const JsonWrapper& oJsonObject)
{
    if (oJsonObject.m_bRef)
        SetValue(oJsonObject.m_pValue);
    else
    {
        assert(false);
        SetValue(nullptr);
    }
}
GFCENGINE_NAMESPACE_END